import { createSelector } from 'reselect';

const employeesSelector = (state) => state.employees;

export const accountLeadsSelector = createSelector(
  employeesSelector,
  ({ account_lead }) => Object.values(account_lead) || [],
);

export const projectManagersSelector = createSelector(
  employeesSelector,
  ({ project_manager }) => Object.values(project_manager) || [],
);

export const teamLeadsSelector = createSelector(
  employeesSelector,
  ({ team_lead }) => Object.values(team_lead) || [],
);
