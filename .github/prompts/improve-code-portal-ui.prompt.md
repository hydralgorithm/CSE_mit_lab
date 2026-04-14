---
description: "Analyze code-portal UX, fix search behavior, add copy button, and modernize UI"
name: "Improve Code Portal UI"
argument-hint: "Theme or constraints (optional)"
agent: "agent"
---
You are improving the `code-portal/` app. Use the design skills in the repo's `skills/` folder to deliver a modern, coding-themed UI/UX.

Task goals:
- Explain how `code-portal/` works at a high level (routing, data flow, file loading).
- Identify why search does not open a file directly and fix it.
- Add a copy button on each code file view to copy the file contents.
- Propose and implement UI/UX improvements so the app feels modern and cohesive.

Process:
1. Read the `code-portal/` sources (including `README.md`, `src/`, and `public/index.json`).
2. Summarize key components, data flow, and where search and file opening are handled.
3. Locate the search issue, explain the root cause, and fix it.
4. Implement the copy button with clear affordance and accessible labels.
5. Apply a coding-themed UI/UX using the skills in `skills/` (typography, color system, layout, motion).

Output format:
- First: brief explanation of changes and where they were made.
- Then: list of files edited with reasons.
- Finally: suggest next steps (tests, build, or preview).

Constraints:
- Keep changes production-ready and maintainable.
- It's okay to use `shadcn/ui`, `framer-motion`, or similar UI libraries if they improve the result.
- Prefer CSS variables and a clear design system.
- Respect reduced-motion preferences.
