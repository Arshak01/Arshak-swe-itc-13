import React, {
  useState,
  useEffect,
  useCallback,
  useMemo,
  useRef,
} from "react";
import database from "./Data.js";


const useMyCallback = function(depend) {
  return depend
}

function Login({ setusername, history }) {
  const [error, setError] = useState("");
  const [username, setUsername] = useState("");
  const [password, setPass] = useState("");
  const [count, setcount] = useState(0);

  const func = useMyCallback((username) => {console.log("func",username)},[password])
  const func1 = useCallback((username) => {console.log("func1",username)},[password])

  func(password);
  func1(password);


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
            localStorage.setItem('username', username);
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
