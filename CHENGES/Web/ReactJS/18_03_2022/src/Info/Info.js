import { useHistory } from "react-router-dom";
import React, { useContext } from "react";
import data from "../Constants/data";
import { Context } from "../Context/Context";

import "./Info.css";

const Info = () => {
  const [storageEmail, setStorageEmail] = useContext(Context);
  const user = data.find(({ email: dataEmail }) => storageEmail === dataEmail);

  let history = useHistory();

  if (!localStorage.getItem("email")) {
    history.push("/login");
  }

  const logout = () => {
    localStorage.removeItem("email");
    setStorageEmail("");
    history.push("/Login");
  };

  return (
    <>
      <div className="container-info flex-container-info">
        <div>
          <img
            src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTE_RuKIRtvySdfJHwKHzHXwiO7bHojnHqTSg&usqp=CAU"
            className="avatar"
            alt="avatar"
          />
        </div>
        {user &&
          Object.entries(user).map(([key, value]) => (
            <h1 key={key}>
              {key}:{value}
            </h1>
          ))}
        <button onClick={logout}>logout</button>
      </div>
    </>
  );
};

export default Info;
