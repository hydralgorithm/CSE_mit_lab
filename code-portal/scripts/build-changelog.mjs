import { execSync } from 'node:child_process'
import { mkdir, writeFile } from 'node:fs/promises'
import path from 'node:path'
import { fileURLToPath } from 'node:url'

const __filename = fileURLToPath(import.meta.url)
const __dirname = path.dirname(__filename)

const projectRoot = path.resolve(__dirname, '..')
const workspaceRoot = path.resolve(projectRoot, '..')
const outputRoot = path.join(projectRoot, 'public')
const outputPath = path.join(outputRoot, 'changelog.json')

function loadGitLog() {
  try {
    const raw = execSync('git log -n 15 --pretty=format:%ad|%s --date=short', {
      cwd: workspaceRoot,
      stdio: ['ignore', 'pipe', 'ignore'],
    })
      .toString()
      .trim()

    if (!raw) {
      return []
    }

    return raw.split('\n').map((line) => {
      const [date, ...rest] = line.split('|')
      const title = rest.join('|').trim()

      return {
        date: date || '',
        tag: 'Update',
        title: title || 'Repository update',
        summary: title || 'Repository update',
      }
    })
  } catch (error) {
    return []
  }
}

const entries = loadGitLog()
const payload = {
  generatedAt: new Date().toISOString(),
  entries,
}

await mkdir(outputRoot, { recursive: true })
await writeFile(outputPath, JSON.stringify(payload, null, 2), 'utf8')

console.log(`[changelog] wrote ${entries.length} entries`)
