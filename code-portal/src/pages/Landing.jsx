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
    </div>
  )
}
