import data from "../constants/data";
import React, { useEffect, useState } from "react";
import "./login.css";

const errMessage = {
  email: "Invalid user",
  password: "Invalid password",
};

const Login = ({ setemail, history }) => {
  const [email, setEmail] = useState("");
  const [pass, setPassword] = useState("");
  const [error, setError] = useState("");

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
      const user = data.find((item) => item.password === pass);
      if (user) {
        setemail(user.email);
        history.push("/info");
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
        <button onClick={onSubmit}>Submit</button>
      </div>
    </div>
  );
};

export default Login;
