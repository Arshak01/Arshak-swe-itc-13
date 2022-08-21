import { BrowserRouter as Router, Switch, Route } from "react-router-dom";
import React, { useState } from "react";
import "./App.css";

import Login from "./Login/Login";
import Info from "./Info/Info";

const UserContext = React.createContext("User");

const App = () => {
  const [email, setemail] = useState("");

  return (
    <UserContext.Provider value={"asss"}>
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
            render={({ history }) =>
              localStorage.getItem("email") ? (
                <Info
                  email={localStorage.getItem("email")}
                  setemail={setemail}
                  history={history}
                />
              ) : (
                <Info email={email} setemail={setemail} history={history} />
              )
            }
          />
          <Route
            exact
            path="/"
            render={({ history }) => (
              <Login setemail={setemail} history={history} />
            )}
          />
        </Switch>
      </Router>
    </UserContext.Provider>
  );
};

export default App;
