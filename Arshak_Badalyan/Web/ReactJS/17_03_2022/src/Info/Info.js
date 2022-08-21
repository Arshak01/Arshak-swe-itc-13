import React from "react";
import data from "../Constants/data";
import "./Info.css";

const Info = ({ email, setemail, history }) => {
  const user = data.find(({ email: dataEmail }) => email === dataEmail);

  const logout = () => {
    localStorage.removeItem("email");
    localStorage.removeItem("password");
    setemail("");
    history.push("/Login");
  };

  return (
    <>
      <div className="container-info flex-container-info">
        <div>
          <img className="avatar" />
        </div>
        {Object.entries(user).map(([key, value]) => (
          <h1 key={key}>
            {key}: {value}
          </h1>
        ))}
        <button onClick={logout}>logout</button>
      </div>
    </>
  );
};

export default Info;
