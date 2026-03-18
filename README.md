# CSE MIT Lab Repository

Coursework, lab practice, and supporting tooling for CSE labs.

This repository currently contains:

- Semester 1 C programming work
- Semester 2 Data Visualization and OOP work
- A React + Vite code browser app (`code-portal`) that indexes and displays code files

## Current Top-Level Layout

```text
CSE_mit_lab/
|- SEM1/
|- SEM2/
|- code-portal/
|- README.md
|- LICENSE
```

## Semester 1 (`SEM1`)

Main folders:

- `Assignments/`
- `labExps/`
- `labMidTermPractice/`
- `endSemPrep/`
- `endSemLabPractice/`

Approximate C file coverage in SEM1:

- `labExps`: 48 `.c` files
- `labMidTermPractice`: 29 `.c` files
- `endSemPrep` (combined): 67 `.c` files
- `endSemLabPractice`: 43 `.c` files
- `Assignments`: 1 `.c` file

## Semester 2 (`SEM2`)

Main folders:

- `dv_lab/`
- `oops_lab/`
- `emergency/`

### Data Visualization Lab (`SEM2/dv_lab`)

Key folders:

- `datasets/`
- `lessons/`
- `questions/`
- `venv/`

Current lesson notebooks in `lessons/`:

- `week1.ipynb`
- `week2.ipynb`
- `week3.ipynb`
- `week4.ipynb`
- `week5.ipynb`
- `week6.ipynb`
- `week7.ipynb`
- `week8.ipynb`

### OOP Lab (`SEM2/oops_lab`)

Key folders:

- `questions/`
- `pract/`
- `midex_pract/`
- `weekly_exerc/`

In `weekly_exerc/src/`:

- Java exercise files from `lab1_1.java` through `lab6_2.java` (and related variants)
- Several compiled `.class` files are also present

## Code Portal App (`code-portal`)

`code-portal` is a React + Vite app for browsing repository code via a generated index.

Important folders/files:

- `src/` (React UI)
- `public/index.json` (generated file index)
- `public/codes/` and `public/codes_temp/` (mirrored code content)
- `scripts/build-index.mjs`
- `scripts/watch-index.mjs`
- `vite.config.js`, `eslint.config.js`, `vercel.json`

## How to Run

### C files (SEM1)

```bash
gcc file.c -o out
./out
```

### Java files (SEM2 OOP)

```bash
cd SEM2/oops_lab/weekly_exerc/src
javac labX_Y.java
java labX_Y
```

Example:

```bash
javac lab6_1.java
java lab6_1
```

### Jupyter notebooks (SEM2 DV)

```bash
cd SEM2/dv_lab
jupyter notebook
```

### Code Portal

```bash
cd code-portal
npm install
npm run dev
```

Build production bundle:

```bash
npm run build
```

## Notes

- This repo currently includes generated/dependency-heavy folders in places (for example `code-portal/node_modules` and `SEM2/dv_lab/venv`).
- For cleaner source-only tracking, these can be excluded from version control later if desired.

## License

See `LICENSE`.
