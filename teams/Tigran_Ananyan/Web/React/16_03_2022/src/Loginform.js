import React from "react";
import { useState, useEffect } from "react";
import data from "./const/data";
import { useNavigate } from "react-router-dom";

function Login({ setemail }) {
  const navigate = useNavigate();
  const [error, setError] = useState("");
  const [pass, setPass] = useState("");
  const [email, setEmail] = useState("");
  const [count, setCount] = useState(0);
  useEffect(() => {
    if(count > 1){
      console.log(`You have tried ${count} times`)
    };
  });
  return (
    <div className="form-component">
      <h2>SignIn</h2>
      <input
        name="Email"
        value={email}
        onChange={(e) => setEmail(e.target.value)}
      />
      <input
        name="Password"
        type="password"
        value={pass}
        onChange={(e) => setPass(e.target.value)}
      />
      {!!error && <h2>{error}</h2>}
      <button
        className="btn"
        onClick={() => {
          const user = data.find(
            ({ email: dataEmail, password }) =>
              dataEmail === email && password === pass
          );
          if (user) {
            setemail(user.email);
            navigate(`/profile`);
          } else {
            setError("Invalid email or password");
            setCount(count + 1);
          }
        }}
      >
        Login
      </button>
    </div>
    
  );
  
}

export default Login;
