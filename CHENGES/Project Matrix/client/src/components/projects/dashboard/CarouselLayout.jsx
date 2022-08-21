import React from 'react';
import { useIntl } from 'react-intl';
import { Col, Row } from 'antd';
import Carousel from 'react-multi-carousel';
import 'react-multi-carousel/lib/styles.css';
import CarouselItemComponent from './CarouselItemComponent';
import {
  BsPlusIcon,
  CreateButtonText,
  SlideLayoutButton,
  SlideLayoutComponent,
} from '../../../Styled';
import locale from './locale';
import { useNavigate } from 'react-router-dom';
import { URL_TO } from '../../../utils/constants';
import { PROP_TYPES } from '../../../utils/proptypes';

const CarouselLayout = ({ projectsList }) => {
  const { formatMessage } = useIntl();
  const navigate = useNavigate();

  const onClick = () => {
    navigate(URL_TO.PROJECT_CREATE_NEW_BUTTON.urlTo);
  };

  return (
    <SlideLayoutComponent>
      <Row gutter={[12]}>
        <Col span={20}>
          <Carousel
            showDots={true}
            responsive={{
              superLargeDesktop: {
                breakpoint: { max: 4000, min: 3000 },
                items: 10,
                slidesToSlide: 10,
              },
              desktop: {
                breakpoint: {
                  max: 3000,
                  min: 1024,
                },
                items: 3.5,
                slidesToSlide: 3,
              },
              mobile: {
                breakpoint: {
                  max: 464,
                  min: 0,
                },
                items: 1,
                slidesToSlide: 1,
              },
              tablet: {
                breakpoint: {
                  max: 1024,
                  min: 464,
                },
                items: 2,
                slidesToSlide: 2,
              },
            }}
          >
            {projectsList.map((project, index) => {
              return (
                <CarouselItemComponent
                  item={project}
                  index={index}
                  key={project.name}
                />
              );
            })}
          </Carousel>
        </Col>
        <Col span={4}>
          <SlideLayoutButton onClick={onClick}>
            <BsPlusIcon />
            <CreateButtonText>
              {formatMessage(locale.SlideLayoutButton)}
            </CreateButtonText>
          </SlideLayoutButton>
        </Col>
      </Row>
    </SlideLayoutComponent>
  );
};

CarouselLayout.propTypes = PROP_TYPES.PROJECT_LIST;

export default CarouselLayout;
