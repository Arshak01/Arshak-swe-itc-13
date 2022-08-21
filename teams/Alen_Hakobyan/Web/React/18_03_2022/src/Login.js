import React, { useState, useRef, useContext } from "react";
import { useHistory, Redirect } from "react-router-dom";
import UsersContext from "./Context";
import database from "./Data";

function useMyEffect(cb, dependencis) {
  const prevDep = useRef(dependencis);
  const prevRes = useRef(cb);
  if (dependencis.some((value, index) => prevDep.current[index] !== value)) {
    prevDep.current = dependencis;
    prevRes.current();
    prevRes.current = cb();
  }
}

function useMyCallback(cb, dependencis) {
  const prevDep = useRef(dependencis);
  const prevRes = useRef(cb);
  if (dependencis.some((value, index) => prevDep.current[index] !== value)) {
    prevDep.current = dependencis;
    prevRes.current = cb;
  }
  return prevDep.current;
}

const useMyMemo = (cb, dependencis) => {
  const prevDep = useRef(dependencis);
  const prevRes = useRef(null);
  if (prevRes.current == null) {
    prevRes.current = cb();
  }
  if (dependencis.some((value, index) => prevDep.current[index] !== value)) {
    prevRes.current = cb();
    prevDep.current = dependencis;
  }
  return prevRes.current;
};

function click({ username, setusername, password, setError, history }) {
  const user = database.find(
    ({ username: dataUsername, pass }) =>
      dataUsername === username && pass === password
  );
  if (user) {
    setusername(user.username);
    localStorage.setItem("username", username);
    localStorage.setItem("Flag", true);
    history.push("/user");
  } else {
    setError("Invalid user or password");
  }
}

function Login() {
  const history = useHistory();
  const { setusername } = useContext(UsersContext);
  const [error, setError] = useState("");
  const [username, setUsername] = useState("");
  const [password, setPass] = useState("");

  return !localStorage.getItem("Flag") ? (
    <div className="form-component">
      <h2>Signin</h2>
      <input
        name="Username"
        value={username}
        onChange={(e) => setUsername(e.target.value)}
      />
      <input
        name="Password"
        type="password"
        value={password}
        onChange={(e) => setPass(e.target.value)}
      />
      {!!error && <h2>{error}</h2>}
      <button
        className="btn"
        onClick={() => {
          click({ username, setusername, password, setError, history });
        }}
      >
        Login
      </button>
    </div>
  ) : (
    <Redirect to={{ pathname: "/user" }} />
  );
}

export default Login;
