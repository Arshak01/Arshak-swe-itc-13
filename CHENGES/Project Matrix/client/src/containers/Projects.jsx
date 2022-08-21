import React from 'react';
import { Space } from 'antd';
import { ProjectLayout } from '../Styled';
import ProjectDashboard from '../components/projects/dashboard/ProjectsDashboard';

const Projects = () => {
  return (
    <ProjectLayout>
      <Space direction="vertical">
        <ProjectDashboard />
      </Space>
    </ProjectLayout>
  );
};

export default Projects;
