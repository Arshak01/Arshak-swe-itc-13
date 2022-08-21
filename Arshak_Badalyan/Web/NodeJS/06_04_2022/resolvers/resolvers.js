const { User } = require('../models/index');
const bcrypt = require('bcrypt');


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
                Password: await bcrypt.hash(Password, 10)
            })
        },
        async updateUser(root, {id, Name, SurName, Email }) {
            return User.update(
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
        },
        async deleteUser(root, {id}) {
            return User.destroy({
                where:{
                    id:id
                }
            })
        },

    },

}

module.exports = {
    resolvers
}