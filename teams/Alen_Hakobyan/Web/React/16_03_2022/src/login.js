import React, {
  useState,
  useEffect,
  useCallback,
  useMemo,
  useRef,
} from "react";
import database from "./data.js";

function Login({ setusername, history }) {
  const [error, setError] = useState("");
  const [username, setUsername] = useState("");
  const [password, setPass] = useState("");
  const [count, setcount] = useState(0);

  useEffect(() => {
    setcount(() => count);
  }, [count]);

  return (
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
          const user = database.find(
            ({ username: dataUsername, pass }) =>
              dataUsername === username && pass === password
          );
          if (user) {
            setusername(user.username);
            history.push("/user");
          } else {
            setError("Invalid user or password");
			      setcount((c) => c + 1)
          }
        }}
      >
        Login
      </button>
      <p>Wrong Login Count {count}</p>
    </div>
  );
}

export default Login;
