import PropTypes from 'prop-types';

const CUSTOMER_PROP_TYPES = PropTypes.exact({
  id: PropTypes.intager,
  name: PropTypes.string.isRequired,
  email: PropTypes.string,
  contact_phone: PropTypes.exact({
    phone: PropTypes.string,
    code: PropTypes.intager,
    short: PropTypes.string,
  }),
  address: PropTypes.string,
  about: PropTypes.string,
});

const PROJECT_PROP_TYPES = PropTypes.exact({
  item: PropTypes.exact({
    about: PropTypes.string,
    technology_tools: PropTypes.string,
    budget: PropTypes.string,
    confidential_type: PropTypes.string,
    logo_url: PropTypes.string,
    achievements_report: PropTypes.bool,
    name: PropTypes.string.isRequired,
    country: PropTypes.string,
    agent: PropTypes.string,
    start_date: PropTypes.string.isRequired,
    end_date: PropTypes.string,
    isActive: PropTypes.bool.isRequired,
    is_billable: PropTypes.bool.isRequired,
    accountLead: PropTypes.string.isRequired,
    projectManager: PropTypes.string,
    teamLead: PropTypes.string,
    CUSTOMER: CUSTOMER_PROP_TYPES,
  }),
  index: PropTypes.number,
});

const TAB_PANEL_PROP_TYPES = {
  TAB_PANEL: {
    projectName: PropTypes.string,
    activeTab: PropTypes.string,
  },
};

const TAB_HEADER_PROP_TYPES = {
  title: PropTypes.string,
  label: PropTypes.string,
};

const SIDEBAR_PROP_TYPES = {
  setCollapsed: PropTypes.func,
};

export const PROP_TYPES = {
  TAB_HEADER: TAB_HEADER_PROP_TYPES,
  TAB_PANEL: TAB_PANEL_PROP_TYPES,
  CUSTOMER: CUSTOMER_PROP_TYPES,
  PROJECT: PROJECT_PROP_TYPES,
  SIDEBAR: SIDEBAR_PROP_TYPES,
  PROJECT_LIST: PropTypes.arrayOf(PROJECT_PROP_TYPES).isRequired,
};
