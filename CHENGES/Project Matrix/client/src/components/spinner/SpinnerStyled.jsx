import styled from 'styled-components';

// css found at: https://loading.io/css/
export const SpinnerCircle = styled.div`
  display: inline-block;
  position: relative;
  width: calc(64px * ${({ modifier }) => modifier});
  height: calc(64px * ${({ modifier }) => modifier});
  & div {
    transform-origin: calc(32px * ${({ modifier }) => modifier})
      calc(32px * ${({ modifier }) => modifier});
    animation: lds-spinner 1.2s linear infinite;
  }
  & div:after {
    content: ' ';
    display: block;
    position: absolute;
    top: calc(3px * ${({ modifier }) => modifier});
    left: calc(29px * ${({ modifier }) => modifier});
    width: calc(5px * ${({ modifier }) => modifier});
    height: calc(14px * ${({ modifier }) => modifier});
    border-radius: 20%;
    background: ${({ color }) => color};
  }
  & div:nth-child(1) {
    transform: rotate(0deg);
    animation-delay: -1.1s;
  }
  & div:nth-child(2) {
    transform: rotate(30deg);
    animation-delay: -1s;
  }
  & div:nth-child(3) {
    transform: rotate(60deg);
    animation-delay: -0.9s;
  }
  & div:nth-child(4) {
    transform: rotate(90deg);
    animation-delay: -0.8s;
  }
  & div:nth-child(5) {
    transform: rotate(120deg);
    animation-delay: -0.7s;
  }
  & div:nth-child(6) {
    transform: rotate(150deg);
    animation-delay: -0.6s;
  }
  & div:nth-child(7) {
    transform: rotate(180deg);
    animation-delay: -0.5s;
  }
  & div:nth-child(8) {
    transform: rotate(210deg);
    animation-delay: -0.4s;
  }
  & div:nth-child(9) {
    transform: rotate(240deg);
    animation-delay: -0.3s;
  }
  & div:nth-child(10) {
    transform: rotate(270deg);
    animation-delay: -0.2s;
  }
  & div:nth-child(11) {
    transform: rotate(300deg);
    animation-delay: -0.1s;
  }
  & div:nth-child(12) {
    transform: rotate(330deg);
    animation-delay: 0s;
  }
  @keyframes lds-spinner {
    0% {
      opacity: 1;
    }
    100% {
      opacity: 0;
    }
  }
`;

export const GroupsSpinnerContainer = styled.div`
  display: flex;
  justify-content: center;
  margin: 100px auto;

  ${({ shouldHideMarginBottom }) =>
    shouldHideMarginBottom && 'margin-bottom: 0;'}
`;

export const SpinnerContainer = styled.div`
  position: absolute;
`;
