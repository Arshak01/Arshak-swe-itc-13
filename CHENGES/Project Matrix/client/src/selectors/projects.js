import { createSelector } from 'reselect';

export const projectSelector = (state) => state.projects;

export const isCreatingSelector = createSelector(
  projectSelector,
  ({ isCreating }) => isCreating,
);

export const projectsSelector = createSelector(projectSelector, ({ items }) =>
  Object.values(items),
);

export const projectsTotalItemsSelector = createSelector(
  projectSelector,
  ({ page, totalItems }) => ({ page, totalItems }),
);

export const projectFormDataSelector = createSelector(
  projectSelector,
  ({ form }) => form.data,
);
