import { useState, useEffect } from "react";

const useLocalStorage = (key) => {
  const savedValue = localStorage.getItem(key);
  const [value, setValue] = useState(savedValue);

  useEffect(() => {
    localStorage.setItem(key, value);
  }, [key, value]);

  return [value, setValue];
};

function App1() {
  const [name, setName] = useLocalStorage("username", "Aziz");
  return (
    <input
      value={name}
      onChange={(e) => {
        setName(e.target.value);
      }}
    />
  );
}

export default App1;