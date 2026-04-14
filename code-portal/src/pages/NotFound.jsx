import { Link } from 'react-router-dom'

export default function NotFound() {
  return (
    <div className="page not-found">
      <p className="section-label">404</p>
      <h1>Route not found</h1>
      <p className="page-sub">
        The archive is wide, but this address isn’t mapped. Jump back to the portal.
      </p>
      <Link className="btn primary" to="/portal">
        Back to Portal
      </Link>
    </div>
  )
}
