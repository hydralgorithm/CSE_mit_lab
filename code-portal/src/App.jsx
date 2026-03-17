import { useEffect, useMemo, useState } from 'react'
import { FileViewer } from './FileViewer'
import './App.css'

function makeFileUrl(relativePath) {
  return `/codes/${relativePath
    .split('/')
    .map((part) => encodeURIComponent(part))
    .join('/')}`
}

function buildTree(files) {
  const root = {
    name: '',
    path: '',
    folders: new Map(),
    files: [],
  }

  for (const file of files) {
    const parts = file.path.split('/')
    let node = root

    for (let index = 0; index < parts.length - 1; index += 1) {
      const part = parts[index]
      const nextPath = node.path ? `${node.path}/${part}` : part

      if (!node.folders.has(part)) {
        node.folders.set(part, {
          name: part,
          path: nextPath,
          folders: new Map(),
          files: [],
        })
      }

      node = node.folders.get(part)
    }

    node.files.push(file)
  }

  function finalize(node) {
    return {
      name: node.name,
      path: node.path,
      folders: [...node.folders.values()]
        .sort((a, b) => a.name.localeCompare(b.name))
        .map(finalize),
      files: [...node.files].sort((a, b) => a.name.localeCompare(b.name)),
    }
  }

  return finalize(root)
}

function TreeFolder({ folder, depth, selectedPath, onSelect }) {
  const hasSelectedChild =
    selectedPath && folder.path && selectedPath.startsWith(`${folder.path}/`)
  const [expanded, setExpanded] = useState(depth < 1 || hasSelectedChild)

  useEffect(() => {
    if (hasSelectedChild) {
      setExpanded(true)
    }
  }, [hasSelectedChild])

  return (
    <li>
      {folder.path ? (
        <button
          type="button"
          className="tree-row folder"
          onClick={() => setExpanded((current) => !current)}
          style={{ paddingLeft: `${12 + depth * 14}px` }}
        >
          <span className="caret">{expanded ? '▾' : '▸'}</span>
          <span>{folder.name}</span>
        </button>
      ) : null}

      {expanded ? (
        <ul className="tree-list">
          {folder.folders.map((childFolder) => (
            <TreeFolder
              key={childFolder.path}
              folder={childFolder}
              depth={depth + 1}
              selectedPath={selectedPath}
              onSelect={onSelect}
            />
          ))}

          {folder.files.map((file) => {
            const isSelected = selectedPath === file.path
            return (
              <li key={file.path}>
                <button
                  type="button"
                  className={`tree-row file${isSelected ? ' selected' : ''}`}
                  style={{ paddingLeft: `${12 + (depth + 1) * 14}px` }}
                  onClick={() => onSelect(file.path)}
                  title={file.path}
                >
                  {file.name}
                </button>
              </li>
            )
          })}
        </ul>
      ) : null}
    </li>
  )
}

function App() {
  const [indexData, setIndexData] = useState(null)
  const [indexError, setIndexError] = useState('')
  const [query, setQuery] = useState('')
  const [selectedPath, setSelectedPath] = useState('')
  const [fileContent, setFileContent] = useState('')
  const [fileError, setFileError] = useState('')
  const [fileLoading, setFileLoading] = useState(false)

  useEffect(() => {
    let ignore = false

    async function loadIndex() {
      try {
        setIndexError('')
        const response = await fetch('/index.json')
        if (!response.ok) {
          throw new Error(`Failed to load index.json (${response.status})`)
        }
        const payload = await response.json()
        if (ignore) {
          return
        }

        setIndexData(payload)
        if (payload.files.length > 0) {
          setSelectedPath((current) => current || payload.files[0].path)
        }
      } catch (error) {
        if (!ignore) {
          setIndexError(error.message)
        }
      }
    }

    loadIndex()

    return () => {
      ignore = true
    }
  }, [])

  const files = indexData?.files ?? []

  const filteredFiles = useMemo(() => {
    const normalizedQuery = query.trim().toLowerCase()
    if (!normalizedQuery) {
      return files
    }

    return files.filter((file) => file.path.toLowerCase().includes(normalizedQuery))
  }, [files, query])

  useEffect(() => {
    if (filteredFiles.length === 0) {
      setSelectedPath('')
      return
    }

    const hasSelectedFile = filteredFiles.some((file) => file.path === selectedPath)
    if (!hasSelectedFile) {
      setSelectedPath(filteredFiles[0].path)
    }
  }, [filteredFiles, selectedPath])

  const tree = useMemo(() => buildTree(filteredFiles), [filteredFiles])

  useEffect(() => {
    if (!selectedPath) {
      setFileContent('')
      return
    }

    let ignore = false

    async function loadFile() {
      setFileLoading(true)
      setFileError('')

      try {
        const response = await fetch(makeFileUrl(selectedPath))
        if (!response.ok) {
          throw new Error(`Failed to load file (${response.status})`)
        }
        
        const contentType = response.headers.get('content-type')
        if (contentType && contentType.includes('text/html')) {
          throw new Error(`File not found or still generating: ${selectedPath}`)
        }

        const content = await response.text()
        if (!ignore) {
          setFileContent(content)
        }
      } catch (error) {
        if (!ignore) {
          setFileError(error.message)
          setFileContent('')
        }
      } finally {
        if (!ignore) {
          setFileLoading(false)
        }
      }
    }

    loadFile()

    return () => {
      ignore = true
    }
  }, [selectedPath])

  const selectedFile = files.find((file) => file.path === selectedPath)
  const generatedAt = indexData?.generatedAt
    ? new Date(indexData.generatedAt).toLocaleString()
    : ''

  return (
    <div className="app-shell">
      <header className="topbar">
        <div>
          <h1>CSE MIT Lab Code Portal</h1>
          <p>{files.length} files indexed</p>
        </div>
        <div className="generated-at">Updated: {generatedAt || 'Loading...'}</div>
      </header>

      <section className="content-shell">
        <aside className="sidebar">
          <label htmlFor="search">Search file or path</label>
          <input
            id="search"
            type="text"
            value={query}
            onChange={(event) => setQuery(event.target.value)}
            placeholder="ex: sem1/pr1.c"
          />

          {indexError ? <p className="error">{indexError}</p> : null}

          <div className="tree-wrap">
            {filteredFiles.length === 0 ? (
              <p className="empty">No matching files.</p>
            ) : (
              <ul className="tree-list">
                {tree.folders.map((folder) => (
                  <TreeFolder
                    key={folder.path}
                    folder={folder}
                    depth={0}
                    selectedPath={selectedPath}
                    onSelect={setSelectedPath}
                  />
                ))}
                {tree.files.map((file) => {
                  const isSelected = selectedPath === file.path
                  return (
                    <li key={file.path}>
                      <button
                        type="button"
                        className={`tree-row file${isSelected ? ' selected' : ''}`}
                        onClick={() => setSelectedPath(file.path)}
                        title={file.path}
                        style={{ paddingLeft: '12px' }}
                      >
                        {file.name}
                      </button>
                    </li>
                  )
                })}
              </ul>
            )}
          </div>
        </aside>

        <main className="viewer">
          <div className="viewer-head">
            <strong>{selectedFile?.name || 'Select a file'}</strong>
            <span>{selectedFile?.path || ''}</span>
          </div>

          {fileLoading ? <p className="state">Loading file...</p> : null}
          {fileError ? <p className="error">{fileError}</p> : null}

          {!fileLoading && !fileError && selectedPath ? (
            <div className="file-content-container">
              <FileViewer file={selectedFile} content={fileContent} />
            </div>
          ) : null}

          {!selectedPath && !fileLoading ? (
            <p className="state">Pick a file from the sidebar.</p>
          ) : null}
        </main>
      </section>
    </div>
  )
}

export default App
