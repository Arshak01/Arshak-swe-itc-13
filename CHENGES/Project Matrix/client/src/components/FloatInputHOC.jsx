import React, { useState } from 'react';
import {
  StyledErrorWrapper,
  StyledFloatLabel,
  StyledInputFieldDiv,
  StyledRequireMark,
} from './FloatInputHOCStyled';
import PropTypes from 'prop-types';

function FloatInputHOC(Input) {
  const Component = ({
    label,
    placeholder,
    required,
    onBlur,
    errorMessage,
    lightLabel,
    ...inputProps
  }) => {
    const [focus, setFocus] = useState(false);
    const { value } = inputProps;
    const isOccupied = focus || value || typeof value === 'boolean';
    return (
      <StyledInputFieldDiv
        onBlur={() => {
          setFocus(false);
          if (onBlur && value) onBlur(value);
        }}
        onFocus={() => setFocus(true)}
        isError={errorMessage}
      >
        <Input {...inputProps} onBlur={onBlur} focus={focus} placeholder="" />
        <StyledFloatLabel isOccupied={isOccupied} lightLabel={lightLabel}>
          {!placeholder && isOccupied ? label : placeholder}{' '}
          {required && <StyledRequireMark>*</StyledRequireMark>}
        </StyledFloatLabel>
        {errorMessage && (
          <StyledErrorWrapper>{errorMessage}</StyledErrorWrapper>
        )}
      </StyledInputFieldDiv>
    );
  };
  Component.propTypes = {
    label: PropTypes.string,
    placeholder: PropTypes.string,
    errorMessage: PropTypes.string,
    required: PropTypes.bool,
    onBlur: PropTypes.func,
    lightLabel: PropTypes.bool,
  };
  return Component;
}

export default FloatInputHOC;
