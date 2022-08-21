import React, { useEffect } from 'react';
import { useNavigate } from 'react-router-dom';
import { useParams } from 'react-router-dom';
import PageHeader from '../components/PageHeader';
import { PageContainer as Container, ProjectLayout } from '../Styled';
import { checkName } from '../api/projects';
import TabPanel from '../components/TabPanel';
import { URL_TO } from '../utils/constants';

const ProjectDetails = () => {
  const navigate = useNavigate();
  const { projectName, tabName } = useParams();

  useEffect(() => {
    (async () => {
      const { isAvailable } = await checkName(projectName);
      if (!isAvailable) {
        navigate(URL_TO.NOT_FOUND_PAGE);
      }
    })();
  }, [projectName]);

  return (
    <ProjectLayout>
      <Container>
        <PageHeader title={projectName} label={tabName} />
        <TabPanel activeTab={tabName} projectName={projectName} />
      </Container>
    </ProjectLayout>
  );
};

export default ProjectDetails;
