import { createSelector } from 'reselect';

export const customersSelector = (state) => state.customers;

export const customersDataSelector = createSelector(
  customersSelector,
  ({ items }) => items,
);
