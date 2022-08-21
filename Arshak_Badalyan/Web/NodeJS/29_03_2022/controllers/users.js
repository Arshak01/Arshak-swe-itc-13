const { User } = require("../models/index");

const createUser = async (req, res) => {
  try {
    const userData = await User.create(req.body);
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
  getUsers,
  createUser,
  deleteUserById,
  updateUserById,
  getUserById
};
