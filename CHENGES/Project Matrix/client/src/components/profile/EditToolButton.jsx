import React from 'react';
import { useNavigate, useParams } from 'react-router-dom';
import { Button } from 'antd';
import { MdEdit } from 'react-icons/md';
import { EditTooltip, EditTooltipWrapper } from '../../Styled';
import { useIntl } from 'react-intl';
import { PROJECT_EDIT_PAGE } from '../../utils/constants';
import locale from './locale';

const EditToolButton = () => {
  const navigate = useNavigate();
  const { formatMessage } = useIntl();
  const params = useParams();

  const onClick = () => {
    navigate(
      PROJECT_EDIT_PAGE.replace(':projectName', params.projectName),
      {
        replace: false,
      },
      {
        state: { backgroundLocation: location },
      },
    );
  };

  return (
    <EditTooltipWrapper>
      <EditTooltip title={formatMessage(locale.editButton)}>
        <Button shape="circle" icon={<MdEdit />} onClick={onClick} />
      </EditTooltip>
    </EditTooltipWrapper>
  );
};

export default EditToolButton;
