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
/*
  #swagger.tags = ['Users']
  #swagger.summary = 'Creat user '
  #swagger.description = 'Input user` name,surname,email,password and creat user, token wich response back'
  #swagger.operationId = 'createUser'
  #swagger.requestBody = {
      content: {
        "application/json": {
          schema: {
            $ref: "#/components/CreateUser"
          }
        }
      }
    }
*/
  try {
    const passHash = bcrypt.hashSync(req.body.Password,10);
    console.log(passHash)
    const userData = await User.create({
      Name :req.body.Name,
      SurName : req.body.SurName,
      Email : req.body.Email,
      Password : passHash
    });
// #swagger.responses[200] = 'Creat user'
  res.send(userData);
  } catch (err) {
// #swagger.responses[500] = 'server not found'
  res.status(500).send(err);
}
};

const getUsers = async (req, res) => {
/*
  #swagger.tags = ['Users']
  #swagger.summary = 'Get users '
  #swagger.description = 'Get all users'
  #swagger.parameters = 'userData'
  #swagger.operationId = 'getUsers'
  #swagger.security = [{
      "bearerAuth": []
    }]
  
*/
  try {
    const userData = await User.findAll({});
// #swagger.responses[200] = 'get all users'
  res.send(userData);
} catch (err) {
// #swagger.responses[500] = 'server not found'
  res.status(500).send(err);
}
};

const getUserById = async (req, res) => {
/*
  #swagger.tags = ['Users']
  #swagger.summary = 'Get user by id '
  #swagger.description = 'Input id of user and get user data'
  #swagger.operationId = 'getUserById'
  #swagger.parameters['id'] = {
      name:"id",
      in: "path"
  }
*/
  const userId = parseInt(req.params.id);
  try {
    const userData = await User.findOne({
      where: {
        Id: userId,
      },
    });
  // #swagger.responses[200] = {description: "get user"}
    res.send(userData);

  } catch (err) {
  // #swagger.responses[500] = {description:"server not found"}
    res.status(500).send(err);
  }
};

const deleteUserById = async (req, res) => {
/*
  #swagger.tags = ['Users']
  #swagger.summary = 'Delete user by id '
  #swagger.description = 'Find user by id and delete that user.'
  #swagger.operationId = 'deleteUserById'
  #swagger.parameters['id'] = {
      name:"id",
      in: "path"
    }
*/
  const userID = parseInt(req.params.id);
  try {
    await User.destroy({
      where: {
        Id: userID,
      },
    });
// #swagger.responses[200] = {description: "Deleted"}
  res.send("Deleted!");
  } catch (err) {
//  #swagger.responses[500] = {description:"server not found"}
  res.status(500).send(err);
  }
};

const updateUserById = async (req, res) => {
/*
  #swagger.tags = ['Users']
  #swagger.summary = 'Update user by id '
  #swagger.description = 'Find user by id and update user.'
  #swagger.operationId = 'updateUserById' 
  #swagger.parameters['id'] = {
    name:"id",
    in: "path"
  }
  #swagger.requestBody = {
    content: {
      "application/json": {
        schema: {
          $ref: "#/components/UpdateUser"
        }
      }
    }
  }
*/
  const userID = parseInt(req.params.id);
  try {
    await User.update({
        Name: req.body.Name,
        SurName : req.body.SurName,
        Email : req.body.Email},
      {
        where: {
          Id: userID,
        },
      }
    );
// #swagger.responses[200] = { description:"updated"}
  res.send("Updated");
  } catch (err) {
// #swagger.responses[500] = {description:"server not found"}
  res.status(500).send(err);
  }
};

const login = async (req, res) => {
/*
  #swagger.tags = ['Users']
  #swagger.summary = 'Login '
  #swagger.description = 'Login page.'
  #swagger.operationId = 'login'
  #swagger.requestBody = {
      content: {
        "application/json": {
          schema: {
            $ref: "#/components/Login"
          }
        }
      }
  }
*/
  const userName = req.body.Name;
  try {
    const userData = await User.findOne({
      where: {
        Name: userName,
      },
    });
    if(bcrypt.compareSync(req.body.Password, userData.Password)){
      const data = {userData};
      delete data.Password;
      const token = generateToken(data);
      console.log("The Token has already created")
// #swagger.responses[200] = {description:"Genereted token"} 
    res.send(token);
  }else {
// #swagger.responses[401] = {description:'User not found'}
    res.send("Wrong Password");
    }
  } catch (err) {
// #swagger.responses[500] = {description: "server not found"}
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
