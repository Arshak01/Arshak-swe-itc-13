const { User } = require('../models/index');
const {generateToken} = require('../token/token');
const argon = require("argon2");

const resolvers = {
    Query : {
        user : async () => {
            const data = await User.findAll({});
            return data
        },
        async getUserById(root,{id}) {
            const data = await User.findOne({
                where:{
                    id:id
                }
            });
            return data
        }
    },

    Mutation: {
        async createUser(root, {Name,SurName,Email,Password}) {
            return User.create({
                Name,SurName,Email,
                Password: await argon.hash(Password)
            })
        },

        async login (root, { Email, Password})  {
            let token;
            const userData = await User.findOne({
                where: {
                    Email : Email
                }
            })
            if (await argon.verify(userData.Password, Password)){
                token = generateToken({userData});
            }else{
                token = "Invalide user !"
            }
            return {token};
        },

        async updateUser(root, {id, Name, SurName, Email }) {
            await User.update(
                {
                    Name: Name,
                    SurName: SurName,
                    Email: Email,
                },
                {
                    where:{
                        id:id
                    }
                }
            )
            const Info ={
                id:id,
                text:"Updated !"
            }
            return Info;
        },

        async deleteUser(root, {id}) {
            await User.destroy({
                where:{
                    id:id
                }
            })
            const Info ={
                id:id,
                text:"Deleted !"
            }
            return Info;
        },

    },

}

module.exports = {
    resolvers
}

