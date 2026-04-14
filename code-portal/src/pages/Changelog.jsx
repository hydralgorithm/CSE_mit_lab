import { useEffect, useState } from 'react'
import { motion, useReducedMotion } from 'framer-motion'
import fallbackUpdates from '../data/changelog'

export default function Changelog() {
  const reduceMotion = useReducedMotion()
  const [entries, setEntries] = useState(fallbackUpdates)

  useEffect(() => {
    let ignore = false

    async function loadChangelog() {
      try {
        const response = await fetch('/changelog.json')
        if (!response.ok) {
          throw new Error('Changelog unavailable')
        }
        const payload = await response.json()
        if (!ignore && Array.isArray(payload.entries)) {
          setEntries(payload.entries)
        }
      } catch (error) {
        if (!ignore) {
          setEntries(fallbackUpdates)
        }
      }
    }

    loadChangelog()

    return () => {
      ignore = true
    }
  }, [])

  return (
    <div className="page">
      <header className="page-head">
        <p className="section-label">Updates</p>
        <h1>Changelog</h1>
        <p className="page-sub">Track portal improvements and indexing upgrades.</p>
      </header>

      <section className="changelog-grid">
        {entries.map((entry, index) => (
          <motion.article
            key={`${entry.title}-${entry.date}`}
            className="changelog-card"
            initial={{ opacity: 0, y: reduceMotion ? 0 : 18 }}
            whileInView={{ opacity: 1, y: 0 }}
            viewport={{ once: true, amount: 0.3 }}
            transition={{ duration: 0.4, delay: index * 0.05 }}
          >
            <div className="changelog-meta">
              <span>{entry.date}</span>
              <span className="changelog-tag">{entry.tag}</span>
            </div>
            <h3>{entry.title}</h3>
            <p>{entry.summary}</p>
          </motion.article>
        ))}
      </section>
    </div>
  )
}
