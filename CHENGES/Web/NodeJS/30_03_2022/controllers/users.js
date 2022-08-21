const { User } = require("../models/index");
const jwt = require('jsonwebtoken');
const argon = require("argon2");


const createUser = async (req, res) => {
  try {
    let hash = await argon.hash(req.body.Password);
    await User.create({
          Name: req.body.Name,
          SurName: req.body.SurName,
          Email:req.body.Email,
          Password:  hash
        })
  } catch (err) {
    res.status(500).send(err);
  }
};

const getUsers = async (req, res) => {
  try {
    const userData = await User.findAll({});
    res.send(userData);
  } catch (err) {
    res.status(500).send(err);
  }
};

const getUser = async (req, res) => {
  try {
    const userData = await User.findOne({
          where: {
            Name: req.params.Name,
          }
    })
    if (await argon.verify(userData.Password, req.params.Password)){
      const token = await jwt.sign({userData},"KEY");
      res.send("TOKEN : "+token);
      console.log("Logged in");
    }else{
      throw error;
    }
  } catch (error) {
    res.status(401).send("Something Wrong")
  }
};

const getUserById = async (req, res) => {
  const userId = parseInt(req.params.id);
  try {
    const userData = await User.findOne({
      where: {
        Id: userId,
      },
    });
    res.send(userData);
  } catch (err) {
    res.status(500).send(err);
  }
};

const deleteUserById = async (req, res) => {
  const userID = parseInt(req.params.id);
  try {
      await User.destroy({
      where: {
        Id: userID,
      },
    });
    res.send("Deleted!");
  } catch (err) {
    res.status(500).send(err);
  }
};

const updateUserById = async (req, res) => {
  const userID = parseInt(req.params.id);
  try {
    await User.update(
      { Name: req.body.Name },
      {
        where: {
          Id: userID,
        },
      }
    );
    res.send("Updated");
  } catch (err) {
    res.status(500).send(err);
  }
};

module.exports = {
  getUser,
  getUsers,
  createUser,
  updateUserById,
  getUserById,
  deleteUserById
};