import React from 'react';
import { useNavigate } from 'react-router-dom';
import { useIntl } from 'react-intl';
import {
  AccountLeadIcon,
  AgentIcon,
  BillableIcon,
  BsCheckCircleFillIcon,
  CarouselDiscription,
  CarouselHeaderContent,
  CarouselHeaderTitle,
  CarouselItem,
  CarouselItemBody,
  CarouselItemHeader,
  CustomerIcon,
  ProjectManagerIcon,
  TeamLeadIcon,
} from '../../../Styled';
import locale from './locale';
import { PROP_TYPES } from '../../../utils/proptypes';

const CarouselItemComponent = ({ item, index }) => {
  const {
    name,
    country,
    customer,
    isActive,
    is_billable: isBillable,
    agent,
    accountLead,
    projectManager,
    teamLead,
  } = item;
  const { formatMessage } = useIntl();
  const navigate = useNavigate();

  const onClick = () => {
    navigate(`/projects/${name.toLowerCase().trim()}/profile`);
  };

  return (
    <CarouselItem hoverable onClick={onClick}>
      <CarouselItemHeader backgroundColor={index % 3}>
        <div>
          <CarouselHeaderTitle>
            <strong>
              {name} {country && <>/</>}
            </strong>
            <br />
            <strong>{country?.name || <br />}</strong>
          </CarouselHeaderTitle>
          <CarouselHeaderContent>
            <BsCheckCircleFillIcon />
            {isActive
              ? formatMessage(locale.carouselHeaderOpen)
              : formatMessage(locale.carouselHeaderClose)}
          </CarouselHeaderContent>
          <CarouselHeaderContent>
            <BillableIcon />
            {isBillable
              ? formatMessage(locale.carouselHeaderBillable)
              : formatMessage(locale.carouselHeaderPresales)}
          </CarouselHeaderContent>
        </div>
      </CarouselItemHeader>
      <CarouselItemBody>
        <CarouselDiscription>
          <CustomerIcon />
          {customer?.name}
        </CarouselDiscription>
        <CarouselDiscription>
          <AccountLeadIcon />
          {accountLead}
        </CarouselDiscription>

        {agent && (
          <CarouselDiscription>
            <AgentIcon />
            {agent?.name}
          </CarouselDiscription>
        )}
        {projectManager && (
          <CarouselDiscription>
            <ProjectManagerIcon />
            {projectManager}
          </CarouselDiscription>
        )}
        {teamLead && (
          <CarouselDiscription>
            <TeamLeadIcon />
            {teamLead}
          </CarouselDiscription>
        )}
      </CarouselItemBody>
    </CarouselItem>
  );
};
CarouselItemComponent.propTypes = PROP_TYPES.PROJECT_LIST;

export default CarouselItemComponent;
