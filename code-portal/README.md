# Code Portal (React + Vite)

This app builds a browsable website for your repository code with:

- Folder-wise navigation
- Search by filename/path
- File viewer

No manual updates are needed when new folders/files are added.

## How automatic updates work

- `scripts/build-index.mjs` scans the workspace root (`../`) for code files (SEM1 + SEM2).
- It copies them to `public/codes/...` and writes `public/index.json`.
- The React app reads `index.json` and displays the folder tree + search.

## Routes

- `/` Landing page
- `/portal` File browser
- `/changelog` Recent updates
- `*` Not found page

## Excluding files from the portal

Create or edit the repo-level `.code-portalignore` file (next to this README's parent folder).
It uses gitignore-style patterns and keeps files in GitHub while skipping them in the portal.

Example:

```text
SEM1/private/**
SEM2/tmp/**
**/draft-*.md
```

## Local development

From `code-portal`:

```bash
npm install
npm run dev
```

`npm run dev` starts both:

- Vite dev server
- File watcher (`scripts/watch-index.mjs`) that rebuilds index whenever files change

So if you create a new code file/folder in your main repo, it appears in the site automatically.

## Build

```bash
npm run build
```

Before build, `prebuild` runs `npm run index:build` automatically.

## Vercel deployment

Set project root to `code-portal` in Vercel.

- Build command: `npm run build`
- Output directory: `dist`

For continuous updates on the live site:

1. Add new file/folder in repo
2. Commit and push to GitHub
3. Vercel auto-deploys from the push
4. New files appear on website after deployment

Note: The live Vercel site cannot update from your local machine instantly without a new deploy. Auto update happens on each push/deploy.
