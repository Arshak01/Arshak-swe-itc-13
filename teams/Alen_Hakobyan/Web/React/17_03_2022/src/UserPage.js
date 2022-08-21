import database from "./Data.js";
import logo from "./user.png";

function UserPage({ username, history, setusername }) {
  const user = database.find(
    ({ username: dataUsername }) => dataUsername === username
  );
  return (
    <div className="UserCard">
      <div className="UserCardTop">
        <img src={logo} />
      </div>
      <div className="UserCardBottom">
        <h3>Name: {user.name}</h3>
        <h5>
          Email: <a href={`mailto:${user.email}`}>{user.email}</a>
        </h5>
        <h5>Age: {user.age}</h5>
        <h5>Phone number: {user.phone}</h5>
      </div>
      <div>
        <button
          className="btn"
          onClick={() => {
            history.push("/");
            localStorage.removeItem('username');
            setusername("");
          }}
        >
          Log Out
        </button>
      </div>
    </div>
  );
}
export default UserPage;
