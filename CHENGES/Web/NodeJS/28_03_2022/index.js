const { Sequelize, DataTypes } = require('sequelize');

const db_name = 'myDB';
const db_username = 'user';
const db_password = 'pass';

const sequelize = new Sequelize(db_name, db_username, db_password, {
    host: 'localhost',
    dialect: 'mysql'
});


const User = sequelize.define("User", {

    id:{
        type:DataTypes.INTEGER,
        autoIncrement: true,
        primaryKey: true,
        allowNull: false,
        unique:true
    },

    firstName: {
        type: DataTypes.STRING,
        allowNull:false
    },
    lastName:{
        type: DataTypes.STRING,
        allowNull:false
    }
}, {
    tableName: "User",
    createdAt: false,
    updatedAt: false
})

async function addUser(firstName, lastName) {
    await User.create({ firstName: firstName, lastName: lastName });
    console.log('User added');
}

async function deleteUserById(id) {
    const user = await User.findOne({
        where: {
            id:id
        }
    });
    if (user === null) {
        console.log('Not found!');
    } else {
        await user.destroy();
        console.log("Deleted by Id");
    }
}

async function deleteUserByName(firstName) {
    const user = await User.findOne({
        where: {
            firstName: firstName
        }
    });
    if (user === null) {
        console.log('Not found!');
    } else {
        await user.destroy();
        console.log("Deleted by name");
    }
}

async function updateUser(id, firstName, lastName){
    try{
        const user = await User.findOne({
            where: {
              id: id,
            },
        });
        if (user !== null) {
            await user.update({
                firstName: firstName,
                lastName: lastName
            });
            console.log("Changed data");
        } else {
            console.log("Not found!");
        }
    }catch(e){
        console.log("Error : ", e)
    }
}

async function showUsers() {
    await sequelize.sync({});
    console.log("All models were synchronized successfully.");
    console.log(await User.findAll({}))
}

async function save () {
    await sequelize.sync();
}

async function authentication() {
    try {
        await sequelize.authenticate();
        console.log('Connection has been established successfully.');
    } catch (error) {
        console.error('Unable to connect to the database:', error);
    }
}

addUser("Arman", "Mnacakanyan");
addUser("Emma", "Sardaryan");
addUser("Tigran", "Vopyan");
addUser("Varujan", "Amirxanyan");

showUsers()

deleteUserByName("Emma")
deleteUserById(3)
deleteAllUser()

updateUser(4, "Kima", "Aslanyan");
showUsers()

save()
authentication()
