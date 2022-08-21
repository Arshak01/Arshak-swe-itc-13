const dbPath = "./data/users.json";
const fs = require('fs');

const getAllUsers = async () => {
    fs.promises.readFile(dbPath, "utf8")
    .then(( data ) => {
         const jsonData = JSON.parse(data);
         return jsonData;
     })
    .catch((error) => {
        console.log(error);
    });
}

const  getUserById = async (id) => {
    return fs.promises.readFile(dbPath, "utf8")
        .then(( data ) => {
            const jsonData = JSON.parse(data);
            const item = jsonData.users.find((item) => item.id  == id);
            return item;
        })
        .catch((error) => {
            console.log(error);
        });
}

const  createUser = async (body) => {
    fs.promises.readFile(dbPath, "utf8")
        .then(data => {
            const jsonData = JSON.parse(data);
            let item = {};
            item.id = body.id;
            item.name = body.name;
            const finalResult = jsonData.users;
            finalResult.push(item);
            let newMyObject = {"users" : finalResult};
            fs.promises.writeFile(dbPath,JSON.stringify(newMyObject));
            return newMyObject;
        })
        .catch((error) => {
            console.log(error);
        });
}

const  updateUser = async (id, name) => {
    fs.promises.readFile(dbPath, "utf8")
        .then((data) => {
            let myObject = JSON.parse(data);
            myObject.users.find((item) => item.id  == id).name = name;
            fs.promises.writeFile(dbPath,JSON.stringify(myObject));
        })
        .catch((error) => {
            console.log(error);
        });
}

const  deleteUser = async (id) => {
    fs.promises.readFile(dbPath, "utf8")
        .then( ( data ) => {
            let myObject = JSON.parse(data);
            const item = myObject.users.filter((item) => item.id != id);
            let newMyObject = {"users" : item};
            fs.promises.writeFile(dbPath,JSON.stringify(newMyObject));
            return myObject;
        })
        .catch((error) => {
            console.log(error);
        });
}

module.exports = {
    getAllUsers,
    getUserById,
    createUser,
    updateUser,
    deleteUser
}