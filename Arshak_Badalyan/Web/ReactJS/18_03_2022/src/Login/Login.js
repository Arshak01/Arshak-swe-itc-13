import React, { useEffect, useState, useRef, useContext } from "react";
import { useHistory } from "react-router-dom";
import { Context } from "../Context/Context";
import { useLocalStorage } from "../Hooks/useLocalStorage";
import data from "../Constants/data";
import "./Login.css";

const errMessage = {
  email: "Invalid user",
  password: "Invalid password",
};

const Login = () => {
  const [email, setEmail] = useState("");
  const [pass, setPassword] = useState("");
  const [error, setError] = useState("");
  const history = useHistory();
  const [storageEmail, setStorageEmail] = useContext(Context);
  // const [useStorage, setUseStorage] = useLocalStorage('email');

  if (storageEmail) {
    history.push("/info");
  }

  useEffect(() => {
    if (!email) {
    } else if (email.length < 4) {
      setError("Email length short than 4 letters");
    } else if (email.length > 20) {
      setError("Email length long than 10 letters");
    } else {
      setError("");
    }
  }, [email]);

  const onSubmit = () => {
    const user = data.find((item) => item.email === email);
    if (user) {
      if (user.password === pass) {
        // setUseStorage(user.email);
        setStorageEmail(user.email);
        localStorage.setItem("email", user.email);
      } else {
        setError(errMessage.password);
      }
    } else {
      setError(errMessage.email);
    }
  };

  return (
    <div className="flex-container">
      <div className="container flex-container">
        <img
          src="https://cdn.dribbble.com/users/4504621/screenshots/15073881/media/2b9334b41f700d68fb02bac81484a374.jpg?compress=1&resize=400x300&vertical=top"
          alt="images"
        />
        <input
          name="login"
          type="login"
          value={email}
          placeholder="Login"
          onChange={(e) => {
            setEmail(e.target.value);
          }}
          required
        ></input>
        <input
          name="password"
          type="password"
          value={pass}
          placeholder="Password"
          onChange={(e) => {
            setPassword(e.target.value);
          }}
          required
        ></input>
        <label>{error}</label>
        <button className="btnClick" onClick={() => onSubmit([])}>
          Submit
        </button>
      </div>
    </div>
  );
};

export default Login;
