const bcrypt = require('bcrypt');
const { User } = require("../models/index");
const { generateToken } = require("./token");


const auth = async (req, res, next) => {
  try {
      const { authorization } = req.headers;
      if (!authorization) return next("unauthorized");
      const token = authorization.split(" ")[1];
      if (!token) return next("Your token is not valid");
      const user = await (token => {jwt.verify(token, "JWT_ACCESS_TOKEN_SECRET")});
      if (!user) return next("You are not authorized");
      req.user = user;
      next()
  } catch (error) {
      res.status(401)
      res.send("Something went wrong")
  }
};

const createUser = async (req, res) => {
  try {
    const passHash = bcrypt.hashSync(req.body.Password,10);
    console.log(passHash)
    const userData = await User.create({
      Name : req.body.Name,
      SurName : req.body.SurName,
      Email : req.body.Email,
      Password : passHash
    });
    res.send(userData);
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
      { Name: req.body.Name,
        SurName : req.body.SurName,
        Email : req.body.Email},
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

const login = async (req, res) => {
  const userName = req.params.Name;
  try {
    const userData = await User.findOne({
      where: {
        Name: userName,
      },
    });
    if(bcrypt.compareSync(req.params.Password, userData.Password)){
      const data = {userData};
      delete data.Password;
      const token = generateToken(data);
      console.log("The Token has already created")
      res.send(token);
    }else {
      console.log("Wrong Password")
    }
  } catch (err) {
    res.status(500).send(err);
  }
};


module.exports = {
  getUsers,
  createUser,
  login,
  auth,
  deleteUserById,
  updateUserById,
  getUserById
};
