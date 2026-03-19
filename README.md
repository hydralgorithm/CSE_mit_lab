# CSE MIT Lab Repository

Coursework, lab practice, and supporting tooling for CSE labs.

## Overview

This repository contains:

- Semester 1 C programming assignments and lab practice
- Semester 2 Data Visualization and OOP lab work (Python/Jupyter and Java)
- A React + Vite code browser app (`code-portal`) for indexing and browsing source files

Snapshot date: March 19, 2026

## Repository Snapshot

Raw repository file counts include dependency/generated directories (for example `node_modules` and Python `venv`).

- Top-level folders: `.github`, `.vite`, `.vscode`, `SEM1`, `SEM2`, `code-portal`
- Total files by major top-level folder:
	- `SEM1`: 201
	- `SEM2`: 19,738
	- `code-portal`: 14,326

Source-focused counts (excluding `.git`, `.vite`, `node_modules`, `venv`, `__pycache__`):

- `SEM1`: 201 files
- `SEM2`: 172 files
- `code-portal`: 1,076 files

## Top-Level Layout

```text
CSE_mit_lab/
|- .github/
|- .vite/
|- .vscode/
|- code-portal/
|- SEM1/
|- SEM2/
|- .gitignore
|- LICENSE
|- README.md
```

## Semester 1 (`SEM1`)

Primary focus: C programming practice and exam preparation.

Folders:

- `Assignments/`
- `labExps/`
- `labMidTermPractice/`
- `endSemPrep/`
- `endSemLabPractice/`

Verified `.c` file counts:

- `Assignments`: 1
- `labExps`: 48
- `labMidTermPractice`: 29
- `endSemPrep`: 67
- `endSemLabPractice`: 43

Other files present include `.txt` and compiled `.exe` files.

## Semester 2 (`SEM2`)

Primary focus: Data Visualization and Object-Oriented Programming labs.

Folders:

- `dv_lab/`
- `oops_lab/`
- `emergency/`

### Data Visualization Lab (`SEM2/dv_lab`)

Subfolders and file counts:

- `datasets/`: 8 files
- `lessons/`: 8 files
- `questions/`: 2 files
- `venv/`: 19,566 files (Python virtual environment)

Lesson notebooks in `lessons/`:

- `week1.ipynb` to `week8.ipynb`

### OOP Lab (`SEM2/oops_lab`)

Subfolders and file counts:

- `midex_pract/`: 82 files
- `pract/`: 12 files
- `questions/`: 1 file
- `weekly_exerc/`: 56 files

`weekly_exerc/src/` contains:

- 31 Java source files (`.java`), including `lab1_1.java` through `lab6_3re.java`
- 21 compiled Java class files (`.class`)

### Emergency Notes (`SEM2/emergency`)

Contains quick-reference text files:

- `L1.txt`
- `L2.txt`
- `L3.txt`

## Code Portal App (`code-portal`)

`code-portal` is a React + Vite app used to browse indexed code content.

Key folders:

- `src/` (frontend application: `App.jsx`, `FileViewer.jsx`, `main.jsx`, CSS)
- `scripts/` (`build-index.mjs`, `watch-index.mjs`)
- `public/index.json` (generated searchable index)
- `public/codes/` and `public/codes_temp/` (mirrored code trees used by the viewer)

Directory stats:

- `src/`: 8 files
- `scripts/`: 2 files
- `public/`: 530 files
- `public/codes/`: 265 files
- `public/codes_temp/`: 262 files
- `node_modules/`: 13,246 files

Build/config files:

- `package.json`
- `vite.config.js`
- `eslint.config.js`
- `vercel.json`

## Run Instructions

### Run C Programs

```bash
gcc path/to/file.c -o out
./out
```

### Run Java Programs (OOP Lab)

```bash
cd SEM2/oops_lab/weekly_exerc/src
javac labX_Y.java
java labX_Y
```

Example:

```bash
javac lab1_4.java
java lab1_4
```

### Run Data Visualization Notebooks

```bash
cd SEM2/dv_lab
jupyter notebook
```

### Run Code Portal

```bash
cd code-portal
npm install
npm run dev
```

Build for production:

```bash
npm run build
```

## Notes

- This repository currently includes dependency/generated folders (`SEM2/dv_lab/venv`, `code-portal/node_modules`, and `.vite`).
- If you want a source-only Git history, these folders can be excluded via `.gitignore` and regenerated locally.

## License

This project is licensed under the terms in `LICENSE`.
