import { Routes, Route } from 'react-router-dom'
import AppLayout from './layout/AppLayout'
import Landing from './pages/Landing'
import Portal from './pages/Portal'
import Changelog from './pages/Changelog'
import NotFound from './pages/NotFound'
import './App.css'

function App() {
  return (
    <Routes>
      <Route element={<AppLayout />}>
        <Route index element={<Landing />} />
        <Route path="portal" element={<Portal />} />
        <Route path="changelog" element={<Changelog />} />
        <Route path="*" element={<NotFound />} />
      </Route>
    </Routes>
  )
}

export default App


