import React, { useState } from "react";
import { BrowserRouter as Router, Switch, Route } from "react-router-dom";
import "./App.css";

import Login from "./login/login";
import Info from "./info/info";
import NotFound from "./login/login";

const App = () => {
  const [email, setemail] = useState("");

  return (
    <Router>
      <Switch>
        <Route
          exact
          path="/login"
          render={({ history }) => (
            <Login setemail={setemail} history={history} />
          )}
        />
        <Route
          exact
          path="/info"
          render={({ history }) => (
            <Info email={email} setemail={setemail} history={history} />
          )}
        />
      </Switch>
    </Router>
  );
};

export default App;
