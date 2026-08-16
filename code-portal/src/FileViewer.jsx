import { Prism as SyntaxHighlighter } from 'react-syntax-highlighter'
import { vscDarkPlus } from 'react-syntax-highlighter/dist/esm/styles/prism'
import ReactMarkdown from 'react-markdown'
import remarkGfm from 'remark-gfm'

const IMAGE_EXTENSIONS = new Set(['.png', '.jpg', '.jpeg', '.gif', '.webp', '.bmp', '.svg'])

function getOutputDataValue(value) {
  if (Array.isArray(value)) {
    return value.join('')
  }

  return typeof value === 'string' ? value : ''
}

function renderNotebookImage(output, index) {
  const imagePng = getOutputDataValue(output?.data?.['image/png'])
  if (imagePng) {
    return <img key={index} className="notebook-output-image" src={`data:image/png;base64,${imagePng}`} alt="Notebook output" />
  }

  const imageJpeg = getOutputDataValue(output?.data?.['image/jpeg'])
  if (imageJpeg) {
    return <img key={index} className="notebook-output-image" src={`data:image/jpeg;base64,${imageJpeg}`} alt="Notebook output" />
  }

  const imageSvg = getOutputDataValue(output?.data?.['image/svg+xml'])
  if (imageSvg) {
    const encodedSvg = encodeURIComponent(imageSvg)
    return <img key={index} className="notebook-output-image" src={`data:image/svg+xml;utf8,${encodedSvg}`} alt="Notebook output" />
  }

  return null
}

function getLanguageFromExt(ext) {
  switch (ext) {
    case '.c':
    case '.h':
      return 'c'
    case '.cpp':
    case '.hpp':
    case '.cc':
      return 'cpp'
    case '.py':
      return 'python'
    case '.js':
      return 'javascript'
    case '.ts':
      return 'typescript'
    case '.jsx':
      return 'jsx'
    case '.tsx':
      return 'tsx'
    case '.java':
      return 'java'
    case '.json':
      return 'json'
    case '.md':
      return 'markdown'
    default:
      return 'text'
  }
}

export function FileViewer({ file, content, fileUrl }) {
  const ext = file?.ext?.toLowerCase()
  const isLargeFile = typeof file?.size === 'number' && file.size > 200000

  if (ext && IMAGE_EXTENSIONS.has(ext) && fileUrl) {
    return (
      <div className="image-viewer">
        <img className="file-image" src={fileUrl} alt={file?.name || 'Image file'} loading="lazy" />
      </div>
    )
  }

  if (ext === '.md') {
    return (
      <div className="markdown-body">
        <ReactMarkdown remarkPlugins={[remarkGfm]}>{content}</ReactMarkdown>
      </div>
    )
  }

  if (ext === '.ipynb') {
    let notebook
    try {
      notebook = JSON.parse(content)
    } catch (e) {
      return <div className="error">Failed to parse notebook JSON</div>
    }

    const cells = notebook.cells || []

    return (
      <div className="notebook-body">
        {cells.map((cell, index) => {
          const source = Array.isArray(cell.source) ? cell.source.join('') : cell.source || ''
          
          if (cell.cell_type === 'markdown') {
            return (
              <div key={index} className="notebook-cell markdown-cell">
                <ReactMarkdown remarkPlugins={[remarkGfm]}>{source}</ReactMarkdown>
              </div>
            )
          }
          
          if (cell.cell_type === 'code') {
            return (
              <div key={index} className="notebook-cell code-cell">
                <div className="cell-header">In [{cell.execution_count || ' '}]:</div>
                <SyntaxHighlighter
                  language="python"
                  style={vscDarkPlus}
                  customStyle={{ margin: 0, borderRadius: '8px', fontSize: '0.9rem' }}
                >
                  {source}
                </SyntaxHighlighter>
                {cell.outputs && cell.outputs.length > 0 && (
                  <div className="cell-outputs">
                    {cell.outputs.map((out, outIndex) => {
                      const renderedImage = renderNotebookImage(out, outIndex)
                      if (renderedImage) {
                        return renderedImage
                      }

                      if (out.output_type === 'stream') {
                        const outText = Array.isArray(out.text) ? out.text.join('') : out.text
                        return <pre key={outIndex} className="output-stream">{outText}</pre>
                      }
                      if (out.data && out.data['text/plain']) {
                        const outText = Array.isArray(out.data['text/plain']) ? out.data['text/plain'].join('') : out.data['text/plain']
                        return <pre key={outIndex} className="output-data">{outText}</pre>
                      }
                      return null
                    })}
                  </div>
                )}
              </div>
            )
          }

          return null
        })}
      </div>
    )
  }

  // Fallback for code files
  const lang = getLanguageFromExt(ext)

  if (isLargeFile) {
    return (
      <div className="code-viewer">
        <pre className="large-file">{content}</pre>
      </div>
    )
  }

  return (
    <div className="code-viewer">
      <SyntaxHighlighter
        language={lang}
        style={vscDarkPlus}
        customStyle={{ margin: 0, padding: '20px' }}
        showLineNumbers={true}
      >
        {content}
      </SyntaxHighlighter>
    </div>
  )
}
