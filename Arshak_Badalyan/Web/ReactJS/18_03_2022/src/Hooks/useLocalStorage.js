import { useEffect, useState, useRef } from "react";

const useLocalStorage = (key) => {
  const [value, setValue] = useState(() => {
    localStorage.getItem(key);
  });
  const oldValue = useRef(value);
  useEffect(
    (key) => {
      localStorage.setItem(key, value);
      oldValue.current = value;
    },
    [value, setValue]
  );
};

export default useLocalStorage;
