import { motion, useReducedMotion } from 'framer-motion'
import { Link } from 'react-router-dom'

const features = [
  {
    title: 'Indexed by semester',
    copy: 'An 8-semester archive (SEM1–SEM8) that grows as each batch is completed.',
  },
  {
    title: 'Built for reference',
    copy: 'Made for juniors and peers to quickly reference real lab work.',
  },
  {
    title: 'Vercel-ready',
    copy: 'Static build with fast incremental indexing for simple deployment.',
  },
]

const steps = [
  {
    title: 'Write code',
    copy: 'Keep every experiment in your repo like normal.',
  },
  {
    title: 'Push to GitHub',
    copy: 'Each push triggers the portal rebuild on Vercel.',
  },
  {
    title: 'Browse instantly',
    copy: 'Open the portal and find exactly what you need.',
  },
]

export default function Landing() {
  const reduceMotion = useReducedMotion()
  const heroVariants = {
    hidden: { opacity: 0, y: reduceMotion ? 0 : 28 },
    show: { opacity: 1, y: 0, transition: { duration: 0.6 } },
  }

  return (
    <div className="landing">
      <section className="landing-hero">
        <motion.div
          className="hero-copy"
          initial="hidden"
          animate="show"
          variants={heroVariants}
        >
          <p className="hero-label">CSE LAB PORTAL</p>
          <h1>A shared CSE lab archive for every semester.</h1>
          <p className="hero-sub">
            MIT CSE ARCHIVE is a public reference hub for students, built to stay organized and fast.
          </p>
          <div className="hero-actions">
            <Link className="btn primary" to="/portal">
              Enter the Portal
            </Link>
            <Link className="btn ghost" to="/changelog">
              View Updates
            </Link>
          </div>
        </motion.div>

        <motion.div
          className="hero-panel"
          initial={{ opacity: 0, y: reduceMotion ? 0 : 32 }}
          animate={{ opacity: 1, y: 0 }}
          transition={{ duration: 0.7, delay: 0.1 }}
        >
          <div className="hero-panel-head">
            <span>Atlas Snapshot</span>
            <span className="hero-pill">SEM1–SEM8</span>
          </div>
          <div className="hero-panel-body">
            <div className="hero-stat">
              <strong>Reference</strong>
              <span>Peer-ready examples</span>
            </div>
            <div className="hero-stat">
              <strong>Focused</strong>
              <span>Portal layout</span>
            </div>
            <div className="hero-stat">
              <strong>Clean</strong>
              <span>Vercel builds</span>
            </div>
          </div>
        </motion.div>
      </section>

      <section className="landing-grid">
        {features.map((feature, index) => (
          <motion.article
            key={feature.title}
            className="feature-card"
            initial={{ opacity: 0, y: reduceMotion ? 0 : 20 }}
            whileInView={{ opacity: 1, y: 0 }}
            viewport={{ once: true, amount: 0.4 }}
            transition={{ duration: 0.45, delay: index * 0.1 }}
          >
            <h3>{feature.title}</h3>
            <p>{feature.copy}</p>
          </motion.article>
        ))}
      </section>

      <section className="landing-steps">
        <div>
          <p className="section-label">Workflow</p>
          <h2>Built for lab consistency.</h2>
        </div>
        <div className="steps-grid">
          {steps.map((step, index) => (
            <motion.div
              key={step.title}
              className="step-card"
              initial={{ opacity: 0, y: reduceMotion ? 0 : 16 }}
              whileInView={{ opacity: 1, y: 0 }}
              viewport={{ once: true, amount: 0.4 }}
              transition={{ duration: 0.4, delay: index * 0.08 }}
            >
              <span className="step-index">0{index + 1}</span>
              <div>
                <h4>{step.title}</h4>
                <p>{step.copy}</p>
              </div>
            </motion.div>
          ))}
        </div>
      </section>

      <section className="landing-credits">
        <div>
          <p className="section-label">Credits</p>
          <h2>Built by hydralgorithm.</h2>
          <p className="page-sub">
            Follow the project and connect with the creator.
          </p>
        </div>
        <div className="credits-links">
          <a
            className="icon-link"
            href="https://github.com/hydralgorithm"
            target="_blank"
            rel="noopener noreferrer"
            aria-label="Hydralgorithm on GitHub"
          >
            <svg viewBox="0 0 24 24" aria-hidden="true" focusable="false">
              <path
                fill="currentColor"
                d="M12 2a10 10 0 0 0-3.16 19.48c.5.1.68-.22.68-.48v-1.7c-2.76.6-3.35-1.33-3.35-1.33-.45-1.15-1.1-1.46-1.1-1.46-.9-.62.07-.61.07-.61 1 .07 1.53 1.05 1.53 1.05.9 1.55 2.36 1.1 2.94.84.09-.66.35-1.1.63-1.35-2.2-.25-4.5-1.1-4.5-4.9 0-1.08.39-1.96 1.03-2.65-.1-.25-.45-1.27.1-2.64 0 0 .84-.27 2.75 1.02a9.6 9.6 0 0 1 5 0c1.9-1.29 2.75-1.02 2.75-1.02.55 1.37.2 2.39.1 2.64.64.69 1.03 1.57 1.03 2.65 0 3.81-2.31 4.64-4.51 4.88.36.31.68.92.68 1.86v2.75c0 .27.18.59.69.48A10 10 0 0 0 12 2z"
              />
            </svg>
            <span>GitHub</span>
          </a>
          <a
            className="icon-link"
            href="https://www.linkedin.com/in/im-abdul-fattah/"
            target="_blank"
            rel="noopener noreferrer"
            aria-label="Abdul Fattah on LinkedIn"
          >
            <svg viewBox="0 0 24 24" aria-hidden="true" focusable="false">
              <path
                fill="currentColor"
                d="M19 3a2 2 0 0 1 2 2v14a2 2 0 0 1-2 2H5a2 2 0 0 1-2-2V5a2 2 0 0 1 2-2h14zm-9 8H7v7h3v-7zm-1.5-1.7a1.5 1.5 0 1 0 0-3 1.5 1.5 0 0 0 0 3zM18 18v-4.2c0-2.24-1.2-3.3-2.8-3.3-1.3 0-1.88.72-2.2 1.22V11h-2.8v7H13v-3.9c0-1.02.2-2 1.46-2 1.24 0 1.26 1.16 1.26 2.06V18H18z"
              />
            </svg>
            <span>LinkedIn</span>
          </a>
        </div>
      </section>
    </div>
  )
}
