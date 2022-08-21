import React from 'react';
import {
  MdDashboard,
  MdOutlineWork,
  MdPerson,
  MdPlagiarism,
  MdRequestQuote,
  MdTableChart,
} from 'react-icons/md';
import { IoRocketSharp } from 'react-icons/io5';

const { REACT_APP_SERVER_BASE_URL } = process.env;

const SERVER_BASE_PATH = `${REACT_APP_SERVER_BASE_URL}/api/v1`;
const PROJECTS_API = `${SERVER_BASE_PATH}/projects`;
const CHECK_PROJECT_NAME_API = `${PROJECTS_API}/checkProjectName`;
export const META_API = `${SERVER_BASE_PATH}/meta`;
export const EMPLOYEES_API = `${SERVER_BASE_PATH}/employees`;
export const PROJECT_PAGE = '/projects';
export const PROJECT_PROFILE_PAGE = '/projects/:projectName/profile';
export const PROJECT_EDIT_PAGE = '/projects/:projectName/edit';

export const API = {
  CUSTOMERS_API: `${SERVER_BASE_PATH}/customers`,
  PROJECTS_API,
  CONFIDENTIAL_TYPE_API: `${SERVER_BASE_PATH}/confidential_types`, // TODO: camelCase?
  CHECK_PROJECT_NAME_API,
};

export const CONSTANTS = {
  LANGUAGE_WRAPPER: 'LANGUAGE_WRAPPER',
  REQUIRE_CHECK_MESSAGE: 'Please input project name',
  ERROR_MESSAGE: 'There were a problem creating and sending process.',
  CREATE: 'CREATE',
  ADD_NEW: 'Add New',
};

export const LOCALE = {
  EN: { code: 'en', label: 'English' },
  FR: { code: 'fr', label: 'French' },
  AM: { code: 'am', label: 'Armenian' },
};

export const SIDEBAR_ITEMS = [
  { label: 'Dashboard', key: '/', icon: <MdDashboard /> },
  { label: 'Project', key: '/projects', icon: <IoRocketSharp /> },
  {
    label: 'Allocation',
    key: 'sub1',
    children: [
      { label: 'Allocation list', key: '/allocations' },
      { label: 'People in bench', key: '/bench' },
      { label: 'Pairs, learning...', key: '/pairs' },
    ],
    icon: <MdTableChart />,
  },
  {
    label: 'Project need',
    key: 'sub2',
    children: [
      { label: 'Project need list', key: '/projectNeeds' },
      { label: 'Dashboard', key: '/dashboard' },
    ],
    icon: <MdPlagiarism />,
  },
  {
    label: 'Billabilities',
    key: 'sub3',
    children: [
      { label: 'Per unit', key: '/billabilities/units' },
      { label: 'Per project', key: '/billabilities/projects' },
    ],
    icon: <MdRequestQuote />,
  },
  { label: 'Employee', key: '/employees', icon: <MdPerson /> },
  { label: 'Customer', key: '/customers', icon: <MdOutlineWork /> },
];

export const NOT_FOUND_AND_UNDER_CONSTRACT = {
  ERROR: '404',
  HOME: 'Go to Home',
  NOT_FOUND_IMAGE:
    'https://cdn.dribbble.com/users/285475/screenshots/2083086/dribbble_1.gif',
  UNDER_CONSTRACT_IMAGE:
    'http://unblast.com/wp-content/uploads/2021/07/Construction-Illustration.jpg',
};

export const URL_TO = {
  PROFILE_EDIT_BUTTON: {
    urlTo: '/projects/:name/update',
  },
  PROJECT_CREATE_NEW_BUTTON: {
    urlTo: '/projects/create',
  },
  PROJECT_PROFILE_PAGE: {
    urlTo: '/projects/:projectName/profile',
  },
  NOT_FOUND_PAGE: {
    urlTo: '/404',
  },
};

export const ROLES = {
  ACCOUNT_LEAD: 'account lead',
  PROJECT_LEAD: 'team lead',
  PROJECT_MANAGER: 'project manager',
};

export const RANGE_FROMAT = 'll';
