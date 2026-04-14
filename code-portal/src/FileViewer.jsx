import { useMemo } from 'react'
import { Prism as SyntaxHighlighter } from 'react-syntax-highlighter'
import { vscDarkPlus } from 'react-syntax-highlighter/dist/esm/styles/prism'
import ReactMarkdown from 'react-markdown'
import remarkGfm from 'remark-gfm'

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

export function FileViewer({ file, content }) {
  const ext = file?.ext?.toLowerCase()
  const isLargeFile = typeof file?.size === 'number' && file.size > 200000

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
