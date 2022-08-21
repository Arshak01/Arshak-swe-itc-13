import React from 'react';
import { useIntl } from 'react-intl';
import { Outlet, useLocation } from 'react-router-dom';
import locale from './projects/locale';
import { StyledLink, StyledTab, StyledTabs } from '../Styled';
import { PROP_TYPES } from '../utils/proptypes';

const PROJECT_TABS = [
  { locale: locale.overview, key: '1', path: 'overview' },
  { locale: locale.profile, key: '2', path: 'profile' },
  { locale: locale.need, key: '3', path: 'need' },
  { locale: locale.allocation, key: '4', path: 'allocation' },
  { locale: locale.teamMembers, key: '5', path: 'teammembers' },
];

const TabPanel = () => {
  const { formatMessage } = useIntl();
  const currentPath = useLocation().pathname.split('/').pop();
  const defaultTab =
    PROJECT_TABS.find((tab) => tab.path === currentPath)?.key || '1';

  return (
    <>
      <StyledTabs defaultActiveKey={defaultTab}>
        {PROJECT_TABS.map(({ locale, key, path }) => (
          <StyledTab
            tab={
              <StyledLink active={defaultTab === key} to={path}>
                {formatMessage(locale)}
              </StyledLink>
            }
            key={key}
          >
            <Outlet />
          </StyledTab>
        ))}
      </StyledTabs>
    </>
  );
};

TabPanel.propTypes = PROP_TYPES.TAB_PANEL;

export default TabPanel;
