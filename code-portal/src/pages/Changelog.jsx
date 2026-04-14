import { useEffect, useState } from 'react'
import { motion, useReducedMotion } from 'framer-motion'
import fallbackUpdates from '../data/changelog'

export default function Changelog() {
  const reduceMotion = useReducedMotion()
  const [entries, setEntries] = useState(fallbackUpdates)
  const [sourceLabel, setSourceLabel] = useState('Local fallback')

  useEffect(() => {
    let ignore = false

    async function loadChangelog() {
      try {
        const githubResponse = await fetch(
          'https://api.github.com/repos/hydralgorithm/CSE_mit_lab/commits?per_page=15',
        )
        if (githubResponse.ok) {
          const commits = await githubResponse.json()
          if (!ignore && Array.isArray(commits)) {
            const mapped = commits.map((commit) => ({
              date: commit?.commit?.author?.date?.slice(0, 10) || '',
              tag: 'Commit',
              title: commit?.commit?.message?.split('\n')[0] || 'Repository update',
              summary: commit?.commit?.message?.split('\n')[0] || 'Repository update',
            }))
            setEntries(mapped)
            setSourceLabel('GitHub commits')
            return
          }
        }

        const response = await fetch('/changelog.json')
        if (response.ok) {
          const payload = await response.json()
          if (!ignore && Array.isArray(payload.entries)) {
            setEntries(payload.entries)
            setSourceLabel('Build-time log')
            return
          }
        }

        throw new Error('Changelog unavailable')
      } catch (error) {
        if (!ignore) {
          setEntries(fallbackUpdates)
          setSourceLabel('Local fallback')
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
        <p className="page-sub">Source: {sourceLabel}</p>
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
