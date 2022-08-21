import { useNavigate } from "react-router-dom";
import data from "./const/data.js";

function UserProf({email}) {
    const navigate = useNavigate();
	const user = data.find(({ email: dataEmail }) => dataEmail === email);
	return (
		<div className='UserCard'>
			<div className='UserCardTop'>
				<img src={user.img} />
			</div>
			<div className='UserCardBottom'>
				<p>Name</p>
				<h3>{user.name}</h3>
				<p>Email</p>
				<h5><a className='EmailLink' href={`mailto:${user.email}`}>{user.email}</a></h5>
				<p>Age</p>
				<h5>{user.age}</h5>
				<p>Phone number</p>
				<h5>{user.phone}</h5>
			</div>
            <button className="btn"
				onClick={() => {
				navigate(`/`)
				}}>
			Log Out
			</button>
		</div>
        
	);
}
export default UserProf;