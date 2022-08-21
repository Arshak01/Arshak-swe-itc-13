import { BrowserRouter as Router, Route, Switch } from "react-router-dom";
import UserPage from "./userPage.js";
import Login from "./login.js";

function Ro({username,setusername}) {
  return (
    <Router>
      <Switch>
        <Route
          path="/user"
          render={({ history }) => (
            <UserPage username={username} history={history} setusername={setusername}/>
          )}
        />
        <Route
          path="/"
          render={({ history }) => (
            <Login setusername={setusername} history={history} />
          )}
        />
      </Switch>
    </Router>
  );
}

export default Ro;
