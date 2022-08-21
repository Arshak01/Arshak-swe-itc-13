import React, { useState } from "react";
import Ro from "./route.js";
import "./App.css";

function App() {
	const [username, setusername] = useState("");
  return (
    <div className="App">
      <Ro username={username} setusername={setusername} />
    </div>
  );
}

export default App;
