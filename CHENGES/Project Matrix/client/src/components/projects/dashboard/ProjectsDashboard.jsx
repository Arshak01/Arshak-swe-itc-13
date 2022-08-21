import React, { useEffect } from 'react';
import { useDispatch, useSelector } from 'react-redux';
import { useIntl } from 'react-intl';
import PageHeader from '../../PageHeader';
import CarouselLayout from './CarouselLayout';
import TableList from './TableList';
import locale from './locale';
import { projectsSelector } from '../../../selectors/projects';
import { getAllProjects } from '../../../actions/active-projects-actions';
import { PageContainer as Container } from '../../../Styled';

const ProjectsDashboard = () => {
  const { formatMessage } = useIntl();
  const dispatch = useDispatch();
  const projectsList = useSelector(projectsSelector);

  useEffect(() => {
    dispatch(getAllProjects({ pageIndex: 0, pageSize: 100, sortBy: 'id' }));
  }, [dispatch]);

  return (
    <Container>
      <PageHeader
        title={formatMessage(locale.pageHeaderTitle)}
        label={formatMessage(locale.pageHeaderDescriptions)}
      />
      <CarouselLayout projectsList={projectsList} />
      <TableList projectsList={projectsList} />
    </Container>
  );
};

export default ProjectsDashboard;
