import { BrowserRouter as Router, Route, Switch } from "react-router-dom";
import UserPage from "./UserPage.js";
import Login from "./Login.js";

function Routes() {
  return (
    <Router>
      <Switch>
        <Route path="/user" component={UserPage} />
        <Route path="/" component={Login} />
      </Switch>
    </Router>
  );
}

export default Routes;
