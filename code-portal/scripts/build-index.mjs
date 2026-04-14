import { readdir, mkdir, copyFile, writeFile, stat, rename, readFile } from 'node:fs/promises'
import path from 'node:path'
import { fileURLToPath } from 'node:url'
import ignore from 'ignore'

const __filename = fileURLToPath(import.meta.url)
const __dirname = path.dirname(__filename)

export const projectRoot = path.resolve(__dirname, '..')
export const workspaceRoot = path.resolve(projectRoot, '..')
const outputRoot = path.join(projectRoot, 'public')
const outputCodesRoot = path.join(outputRoot, 'codes')
const outputIndexPath = path.join(outputRoot, 'index.json')
const cacheRoot = path.join(projectRoot, '.cache')
const cachePath = path.join(cacheRoot, 'index-cache.json')
const ignoreFilePath = path.join(workspaceRoot, '.code-portalignore')

export const INCLUDED_ROOTS = ['SEM1', 'SEM2']

export const EXCLUDED_DIRS = new Set([
  '.git',
  '.github',
  '.vscode',
  'node_modules',
  'code-portal',
  'venv',
  '.venv',
  'env',
  '__pycache__',
  '.ipynb_checkpoints',
])

const INCLUDED_EXTENSIONS = new Set([
  '.c',
  '.cpp',
  '.cc',
  '.h',
  '.hpp',
  '.java',
  '.py',
  '.js',
  '.ts',
  '.txt',
  '.csv',
  '.json',
  '.ipynb',
  '.md',
])

function toPosixPath(value) {
  return value.split(path.sep).join('/')
}

async function loadIgnoreRules() {
  try {
    const raw = await readFile(ignoreFilePath, 'utf8')
    return ignore().add(raw)
  } catch (error) {
    return ignore()
  }
}

function isIgnored(ig, relativePosixPath) {
  if (!ig || !relativePosixPath) {
    return false
  }

  return ig.ignores(relativePosixPath) || ig.ignores(`${relativePosixPath}/`)
}

async function walk(dirPath, collector, ig) {
  const entries = await readdir(dirPath, { withFileTypes: true })

  for (const entry of entries) {
    const fullPath = path.join(dirPath, entry.name)
    const relativePath = path.relative(workspaceRoot, fullPath)
    const relativePosixPath = toPosixPath(relativePath)
    const topLevel = relativePosixPath.split('/')[0]

    if (!INCLUDED_ROOTS.includes(topLevel)) {
      continue
    }

    if (isIgnored(ig, relativePosixPath)) {
      continue
    }

    if (entry.isDirectory()) {
      if (EXCLUDED_DIRS.has(entry.name)) {
        continue
      }
      await walk(fullPath, collector, ig)
      continue
    }

    if (!entry.isFile()) {
      continue
    }

    const ext = path.extname(entry.name).toLowerCase()
    if (!INCLUDED_EXTENSIONS.has(ext)) {
      continue
    }

    if (relativePosixPath.startsWith('code-portal/')) {
      continue
    }

    const fileStats = await stat(fullPath)

    collector.push({
      id: relativePosixPath,
      path: relativePosixPath,
      name: entry.name,
      dir: toPosixPath(path.dirname(relativePath)),
      ext,
      size: fileStats.size,
      mtimeMs: fileStats.mtimeMs,
      updatedAt: fileStats.mtime.toISOString(),
      absolutePath: fullPath,
    })
  }
}

async function cleanOutputFolder() {
  // We no longer nuke the directory to avoid Vite watch locks on Windows (EPERM).
  // Stale files will be ignored by index.json, but physically cleaning them is omitted here
  // for simplicity/robustness in dev. For production, `npm run build` is enough.
}

async function copyFiles(files) {
  const maxConcurrent = 16
  let index = 0

  async function worker() {
    while (index < files.length) {
      const current = files[index]
      index += 1
      const destination = path.join(outputCodesRoot, current.path)
      await mkdir(path.dirname(destination), { recursive: true })
      await copyFile(current.absolutePath, destination)
    }
  }

  const workers = Array.from({ length: Math.min(maxConcurrent, files.length) }, () => worker())
  await Promise.all(workers)
}

async function loadCache() {
  try {
    const data = await readFile(cachePath, 'utf8')
    return JSON.parse(data)
  } catch (error) {
    return { files: {} }
  }
}

async function saveCache(cache) {
  await mkdir(cacheRoot, { recursive: true })
  const tempPath = cachePath + '.tmp'
  await writeFile(tempPath, JSON.stringify(cache, null, 2), 'utf8')
  await rename(tempPath, cachePath)
}

export async function buildIndex() {
  const ig = await loadIgnoreRules()
  const cache = await loadCache()
  const cachedFiles = cache.files || {}
  const files = []
  await walk(workspaceRoot, files, ig)

  files.sort((a, b) => a.path.localeCompare(b.path))

  await cleanOutputFolder()

  const filesToCopy = []
  const nextCache = { files: {} }

  for (const file of files) {
    const cached = cachedFiles[file.path]
    const isSame = cached && cached.mtimeMs === file.mtimeMs && cached.size === file.size
    if (!isSame) {
      filesToCopy.push(file)
    }

    nextCache.files[file.path] = {
      mtimeMs: file.mtimeMs,
      size: file.size,
    }
  }

  await copyFiles(filesToCopy)
  await saveCache(nextCache)

  const serializableFiles = files.map(({ absolutePath, mtimeMs, ...rest }) => rest)
  const payload = {
    generatedAt: new Date().toISOString(),
    totalFiles: serializableFiles.length,
    files: serializableFiles,
  }

  const outputIndexTemp = outputIndexPath + '.tmp'
  await writeFile(outputIndexTemp, JSON.stringify(payload, null, 2), 'utf8')
  await rename(outputIndexTemp, outputIndexPath)

  return payload
}

if (process.argv[1] && path.resolve(process.argv[1]) === __filename) {
  buildIndex()
    .then((result) => {
      console.log(`Indexed ${result.totalFiles} files.`)
    })
    .catch((error) => {
      console.error('Failed to build code index.')
      console.error(error)
      process.exitCode = 1
    })
}
