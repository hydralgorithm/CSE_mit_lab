import { NavLink, Outlet } from 'react-router-dom'

function NavItem({ to, children }) {
  return (
    <NavLink
      to={to}
      className={({ isActive }) => `nav-link${isActive ? ' active' : ''}`}
    >
      {children}
    </NavLink>
  )
}

export default function AppLayout() {
  return (
    <div className="site-shell">
      <header className="site-header">
        <div className="brand">
          <img className="brand-mark" src="/mitarchive.png" alt="MitArchive logo" />
          <div>
            <strong>MIT CSE ARCHIVE</strong>
            <span>Code atlas for lab work</span>
          </div>
        </div>
        <nav className="site-nav">
          <NavItem to="/">Home</NavItem>
          <NavItem to="/portal">Portal</NavItem>
          <NavItem to="/changelog">Changelog</NavItem>
        </nav>
      </header>

      <main className="site-main">
        <Outlet />
      </main>

      <footer className="site-footer">
        <span>MIT CSE ARCHIVE — built for fast lab lookup.</span>
        <span className="footer-meta">Updated via GitHub pushes.</span>
      </footer>
    </div>
  )
}
