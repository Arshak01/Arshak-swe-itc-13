import { render } from "@testing-library/react";
import React from "react";
import data from "../constants/data";
import "./info.css";

const Info = ({ email, setemail, history }) => {
  const user = data.find(({ email: dataEmail }) => email === dataEmail);

  const logout = () => {
    setemail("");
    history.push("/login");
  };

  if (!user) {
    return <></>;
  }

  return (
    <>
      <div className="container-info flex-container-info">
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
