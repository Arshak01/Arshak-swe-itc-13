import React, { useState } from "react";
import Login from "./Loginform.js";
import UserProf from "./UserProf.js";
import { BrowserRouter, Routes, Route } from "react-router-dom";
import "./App.css";

function App() {
  const [email, setemail] = useState("");
  return (
    <div className="App">
    <BrowserRouter>
      <Routes>
        <Route path="/" element={<Login setemail={setemail} />}/>
        <Route path="/profile" element={<UserProf email={email}/>}/>
      </Routes>
    </BrowserRouter>
    </div>
  );
}

export default App;
