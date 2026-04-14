import { watch } from 'node:fs'
import { readFile } from 'node:fs/promises'
import path from 'node:path'
import ignore from 'ignore'
import { buildIndex, workspaceRoot, EXCLUDED_DIRS, INCLUDED_ROOTS } from './build-index.mjs'

function toPosixPath(value) {
  return value.split(path.sep).join('/')
}

const ignoreFilePath = path.join(workspaceRoot, '.code-portalignore')
let ignoreRules = ignore()

async function loadIgnoreRules() {
  try {
    const raw = await readFile(ignoreFilePath, 'utf8')
    ignoreRules = ignore().add(raw)
  } catch (error) {
    ignoreRules = ignore()
  }
}

function isIgnored(relativePosixPath) {
  if (!relativePosixPath) {
    return false
  }

  return (
    ignoreRules.ignores(relativePosixPath) ||
    ignoreRules.ignores(`${relativePosixPath}/`)
  )
}

function shouldIgnore(relativePath) {
  if (!relativePath) {
    return false
  }

  const normalizedPath = toPosixPath(relativePath)
  const topLevel = normalizedPath.split('/')[0]

  if (!INCLUDED_ROOTS.includes(topLevel)) {
    return true
  }

  if (EXCLUDED_DIRS.has(topLevel) || normalizedPath.startsWith('code-portal/')) {
    return true
  }

  return isIgnored(normalizedPath)
}

let timer = null
let running = false
let pending = false

async function runBuild(reason) {
  if (running) {
    pending = true
    return
  }

  running = true
  try {
    const result = await buildIndex()
    console.log(`[index] ${reason}: ${result.totalFiles} files`)
  } catch (error) {
    console.error('[index] rebuild failed')
    console.error(error)
  } finally {
    running = false
    if (pending) {
      pending = false
      await runBuild('queued-change')
    }
  }
}

function scheduleBuild(reason) {
  if (timer) {
    clearTimeout(timer)
  }

  timer = setTimeout(() => {
    runBuild(reason)
  }, 400)
}

await loadIgnoreRules()
await runBuild('initial-build')

watch(workspaceRoot, { recursive: true }, (eventType, filename) => {
  const relativePath = typeof filename === 'string' ? filename : ''
  if (relativePath && toPosixPath(relativePath) === '.code-portalignore') {
    loadIgnoreRules().then(() => runBuild('ignore-updated'))
    return
  }

  if (shouldIgnore(relativePath)) {
    return
  }

  const reason = `${eventType}:${relativePath || 'unknown'}`
  scheduleBuild(reason)
})

console.log('[index] watching for code file changes...')
