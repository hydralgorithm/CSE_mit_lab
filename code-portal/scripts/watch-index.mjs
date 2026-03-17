import { watch } from 'node:fs'
import path from 'node:path'
import { buildIndex, workspaceRoot, EXCLUDED_DIRS } from './build-index.mjs'

function toPosixPath(value) {
  return value.split(path.sep).join('/')
}

function shouldIgnore(relativePath) {
  if (!relativePath) {
    return false
  }

  const normalizedPath = toPosixPath(relativePath)
  const topLevel = normalizedPath.split('/')[0]

  return EXCLUDED_DIRS.has(topLevel) || normalizedPath.startsWith('code-portal/')
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

await runBuild('initial-build')

watch(workspaceRoot, { recursive: true }, (eventType, filename) => {
  const relativePath = typeof filename === 'string' ? filename : ''
  if (shouldIgnore(relativePath)) {
    return
  }

  const reason = `${eventType}:${relativePath || 'unknown'}`
  scheduleBuild(reason)
})

console.log('[index] watching for code file changes...')
