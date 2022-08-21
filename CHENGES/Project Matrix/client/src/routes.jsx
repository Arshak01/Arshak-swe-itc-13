import React from 'react';
import { Route, Routes } from 'react-router-dom';
import ProjectsPage from './containers/Projects';
import ProjectDetailsPage from './containers/ProjectDetails';
import CreateProjectPage from './containers/CreateProject';
import UnderConstract from './components/UnderConstract';
import NotFound from './containers/NotFound';
import ProfileTab from './components/profile/ProfileTab';
import EditProjectForm from './components/profile/EditProjectForm';

function AppRoutes() {
  return (
    <Routes>
      <Route path="/" element={<UnderConstract />} />
      <Route path="/projects" element={<ProjectsPage />} />
      <Route path="/projects/create" element={<CreateProjectPage />} />
      <Route path="/projects/:projectName" element={<ProjectDetailsPage />}>
        <Route path={'overview'} element={<UnderConstract />} />
        <Route path={'profile'} element={<ProfileTab />}></Route>
        <Route path={'need'} element={<UnderConstract />} />
        <Route path={'allocation'} element={<UnderConstract />} />
        <Route path={'teammembers'} element={<UnderConstract />} />
      </Route>
      <Route path="/projects/:projectName/edit" element={<EditProjectForm />} />
      <Route path="/allocations" element={<UnderConstract />} />
      <Route path="/bench" element={<UnderConstract />} />
      <Route path="/pairs" element={<UnderConstract />} />
      <Route path="/projectNeeds" element={<UnderConstract />} />
      <Route path="/dashboard" element={<UnderConstract />} />
      <Route path="/billabilities/units" element={<UnderConstract />} />
      <Route path="/billabilities/projects" element={<UnderConstract />} />
      <Route path="/employees" element={<UnderConstract />} />
      <Route path="/customers" element={<UnderConstract />} />
      <Route path="/404" element={<NotFound />} />
      <Route path="*" element={<NotFound />} />
    </Routes>
  );
}

export default AppRoutes;
