import React from 'react';
import { Descriptions } from 'antd';
import { PageHeaderComponent } from '../Styled';
import { PROP_TYPES } from '../utils/proptypes';

const PageHeader = ({ title, label }) => {
  return (
    <PageHeaderComponent title={title}>
      <Descriptions size="small" column={3}>
        <Descriptions.Item label={label} />
      </Descriptions>
    </PageHeaderComponent>
  );
};

PageHeader.propTypes = PROP_TYPES.TAB_HEADER;

export default PageHeader;
