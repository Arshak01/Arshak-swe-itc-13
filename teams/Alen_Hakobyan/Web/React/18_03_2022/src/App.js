import React, { useState } from "react";
import Routes from "./Route";
import UsersContext from "./Context";
import useLocalStorage from "./localStorage";
import "./App.css";

function App() {
  const name = useLocalStorage("username");
  const [username, setusername] = useState(name);
  return (
    <div className="App">
      <UsersContext.Provider value={{ username, setusername }}>
        <Routes />
      </UsersContext.Provider>
    </div>
  );
}

export default App;
