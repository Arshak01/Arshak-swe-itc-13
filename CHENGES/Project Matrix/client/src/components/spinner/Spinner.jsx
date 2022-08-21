import React from 'react';
import PropTypes from 'prop-types';

import { SpinnerCircle } from './SpinnerStyled';

export function getModifier({ small, large }) {
  // This modifier is responsible for setting the width and height of each arm as well as the
  // positioning of them away from the axis. They were carefully selected via trial and error to
  // create the correct icon.
  if (small) return 0.422;
  if (large) return 1;

  return 0.615;
}

export function getLoadingAnimationElements() {
  const divs = [];
  for (let i = 0; i < 12; i += 1) {
    divs.push(<div key={`empty-div-${i}`} />);
  }
  return divs;
}

// eslint-disable-next-line react/display-name
const Spinner = React.memo(({ small, large, color, style }) => (
  <SpinnerCircle
    modifier={getModifier({ small, large })}
    color={color}
    style={style}
  >
    {getLoadingAnimationElements()}
  </SpinnerCircle>
));

Spinner.propTypes = {
  small: PropTypes.bool,
  large: PropTypes.bool,
  color: PropTypes.string,
  style: PropTypes.shape(),
};

Spinner.defaultProps = {
  small: false,
  large: false,
  color: 'black',
  style: {},
};

export default Spinner;
