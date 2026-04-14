# CSE_mit_lab Website Update Guide

This repo hosts a static website called "Code Portal" inside the `code-portal/` folder. The site is auto-generated from the SEM1/SEM2 folders and deployed on Vercel. Use the steps below so any future AI can update it safely.

## What the website does

- Builds a browsable file portal from the repo root.
- Scans only `SEM1/` and `SEM2/` and copies supported files to `code-portal/public/codes/`.
- Generates `code-portal/public/index.json` with file metadata.
- Generates `code-portal/public/changelog.json` from recent git commits.

## Quick update checklist

1. Add or edit files under `SEM1/` or `SEM2/`.
2. Ensure the files are not excluded by `.code-portalignore`.
3. Run `npm run dev` for local preview, or `npm run build` for a production build.
4. Commit and push so Vercel deploys the update.

## Local development

From `code-portal/`:

- Install: `npm install`
- Dev server + watcher: `npm run dev`

Notes:
- `npm run dev` runs `scripts/watch-index.mjs` so the portal updates when you edit files.
- `npm run build` runs `prebuild`, which rebuilds the index and changelog before Vite builds.

## Where to change things

### Content (student code)

- Put files in `SEM1/` or `SEM2/`.
- Supported extensions are in `code-portal/scripts/build-index.mjs` (see `INCLUDED_EXTENSIONS`).
- If you add a new top-level folder (e.g., `SEM3/`), update `INCLUDED_ROOTS`.

### Ignore rules

- Edit `.code-portalignore` at the repo root.
- It uses gitignore-style patterns and only affects the portal, not Git.

### UI/UX and routes

- Main app UI lives in `code-portal/src/`.
- Page routing is handled by React Router.
- The landing page is `/`, portal is `/portal`, changelog is `/changelog`.

### Branding and assets

- Public assets live in `code-portal/public/`.
- Favicon/logo is currently `code-portal/public/mitarchive.png` and referenced in `code-portal/index.html`.

### Changelog

- Build script: `code-portal/scripts/build-changelog.mjs`.
- It reads last 15 git commits and writes `public/changelog.json`.
- Rebuild with `npm run changelog:build` or run `npm run build`.

## Deployment (Vercel)

- Vercel project root: `code-portal/`.
- Build command: `npm run build`.
- Output: `dist`.
- SPA rewrite is configured in `code-portal/vercel.json` so deep links work.
- `ignoreCommand` is set to skip deploys unless files in `code-portal/` changed.

To force a deploy when only SEM1/SEM2 content changes:
- Touch a file in `code-portal/` (for example, add a small README change) and push.

## If something looks wrong

- Run `npm run index:build` to regenerate `public/index.json`.
- Check `.code-portalignore` for overly broad patterns.
- Confirm files are under `SEM1/` or `SEM2/` and use supported extensions.
