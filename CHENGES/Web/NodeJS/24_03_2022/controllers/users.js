const userModel = require('../models/users');


const getAllUsers = async (req, res) => {
    let data = await userModel.getAllUsers();
    res.json(data);
};

const getUserById = async (req, res) => {
    const data = await userModel.getUserById(req.params.id);
    res.json(data);
};

const createUser = async (req, res) => {
    await userModel.createUser(req.body);
    res.send(`Added new user ->  id ${req.body.id} : ${req.body.name}`);
};

const updateUser = async (req, res) => {
    await userModel.updateUser(req.params.id, req.body.name);
    res.send(`Update user ->  id ${req.params.id} : ${req.body.name}`);
};

const deleteUser = async (req, res) => {
    await userModel.deleteUser(req.params.id);
    res.json(`Delete user of id : ${req.params.id}`);
};

module.exports = {
    getAllUsers,
    getUserById,
    createUser,
    updateUser,
    deleteUser
}