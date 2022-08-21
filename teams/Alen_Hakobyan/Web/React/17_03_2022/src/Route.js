import { BrowserRouter as Router, Route, Switch } from "react-router-dom";
import UserPage from "./UserPage.js";
import Login from "./Login.js";

function Ro({username,setusername}) {
  return (
    <Router>
      <Switch>
        <Route
          path="/user"
          render={({ history }) => (
            localStorage.getItem("username") ? <UserPage username={localStorage.getItem("username")} history={history} setusername={setusername}/> :
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
