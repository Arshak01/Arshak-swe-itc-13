import { BrowserRouter as Router, Switch, Route } from "react-router-dom";
import React, { useState } from "react";
import { Context } from "./Context/Context";
import "./App.css";
import Login from "./Login/Login";
import Info from "./Info/Info";

const App = () => {
  const [storageEmail, setStorageEmail] = useState(() =>
    localStorage.getItem("email")
  );

  return (
    <Context.Provider value={[storageEmail, setStorageEmail]}>
      <Router>
        <Switch>
          <Route path="/info" component={Info} />
          <Route path="/" component={Login} />
        </Switch>
      </Router>
    </Context.Provider>
  );
};

export default App;
