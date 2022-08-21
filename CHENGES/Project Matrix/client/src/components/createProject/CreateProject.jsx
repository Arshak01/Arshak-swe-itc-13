import React, { useEffect } from 'react';
import { useDispatch } from 'react-redux';

import {
  getAccountLeads,
  getProjectManagers,
  getTeamLeads,
} from '../../actions/employees-actions';
import { CreateProjectForm } from './CreateProject.form';

const CreateProject = () => {
  const dispatch = useDispatch();

  const handleSuccess = () => {};

  const handleFail = () => {};

  useEffect(() => {
    dispatch(getAccountLeads());
    dispatch(getTeamLeads());
    dispatch(getProjectManagers());
  }, [dispatch]);

  return (
    <div>
      <CreateProjectForm onSuccess={handleSuccess} onFail={handleFail} />
    </div>
  );
};

export default CreateProject;
