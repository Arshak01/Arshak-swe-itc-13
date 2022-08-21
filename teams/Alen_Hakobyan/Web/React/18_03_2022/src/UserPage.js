import React, { useContext } from "react";
import { useHistory, Redirect } from "react-router-dom";
import UsersContext from "./Context";
import database from "./Data";
import logo from "./user.png";
import useLocalStorage from "./localStorage";

function UserPage() {
  const history = useHistory();
  const [name] = useLocalStorage("username");
  const { setusername } = useContext(UsersContext);
  const user = database.find((user) => user.username === name);

  return name && user ? (
    <div className="UserCard">
      <div className="UserCardTop">
        <img src={logo} />
      </div>
      <div className="UserCardBottom">
        <h3>Name: {user.name}</h3>
        <h5>
          Email: <a href={`mailto:${user.email}`}>{user.email}</a>
        </h5>
        <h5>Age: {user.age}</h5>
        <h5>Phone number: {user.phone}</h5>
      </div>
      <div>
        <button
          className="btn"
          onClick={() => {
            localStorage.removeItem("username");
            localStorage.removeItem("Flag");
            history.push("/");
            setusername("");
          }}
        >
          Log Out
        </button>
      </div>
    </div>
  ) : (
    <Redirect to={{ pathname: "/" }} />
  );
}

export default UserPage;
