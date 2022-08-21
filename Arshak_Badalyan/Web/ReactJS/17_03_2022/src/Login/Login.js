import React, { useEffect, useState, useRef } from "react";
import data from "../Constants/data";
import "./Login.css";

const errMessage = {
  email: "Invalid user",
  password: "Invalid password",
};

// const useLocalStorage = (key) => {
//   const [value, setValue] = useState(() => {localStorage.getItem(key)})
//   const oldValue = useRef(value);
//   console.log('value = ',value)
//   console.log('oldValue = ',oldValue)
//   if (value && (value !== oldValue))
//     localStorage.setItem(key,value);
//     oldValue.current = value;
//   return ([value, setValue])
// }

const Login = ({ setemail, history }) => {
  const [email, setEmail] = useState("");
  const [pass, setPassword] = useState("");
  const [error, setError] = useState("");
  // const [emailStorage, setEmailStorage] = useLocalStorage('email');

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
        setemail(user.email);
        // setEmailStorage(user.email)
        localStorage.setItem("email", user.email);
        localStorage.setItem("password", user.password);
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
        <img />
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
        <button className="btnClick" onClick={onSubmit}>
          Submit
        </button>
      </div>
    </div>
  );
};

export default Login;
