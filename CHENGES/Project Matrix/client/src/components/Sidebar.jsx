import React from 'react';
import { useNavigate } from 'react-router-dom';
import { Menu } from 'antd';
import { StyledSidebar } from '../Styled';
import { SIDEBAR_ITEMS } from '../utils/constants';
import { PROP_TYPES } from '../utils/proptypes';

const Sidebar = ({ setCollapsed }) => {
  const navigate = useNavigate();
  const onClick = (e) => navigate(e.key);

  return (
    <StyledSidebar collapsible defaultCollapsed onCollapse={setCollapsed}>
      <Menu mode="inline" items={SIDEBAR_ITEMS} onClick={onClick} />
    </StyledSidebar>
  );
};

Sidebar.propTypes = PROP_TYPES.SIDEBAR;

export default Sidebar;
