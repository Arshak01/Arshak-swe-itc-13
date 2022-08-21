const { gql } = require('apollo-server-express');


const typeDefs = gql`
    type User {
        Name : String
        SurName : String
        Email : String
        Password : String
    }

    type UserById {
        id: Int
        Name : String
        SurName : String
        Email : String
        Password : String
    }

    type Query {
        user : [User]
        getUserById(id: Int!) : UserById
    }

    type CreateUser {
        Name : String
        SurName : String
        Email : String
        Password : String
    }
    type UpdateUser {
        id: Int
        Name : String
        SurName : String
        Email : String
    }
    type DeleteUser {
        id: Int
        Name : String
        SurName : String
        Email : String
        Password : String
    }

    type Mutation {
        createUser (
            Name : String
            SurName : String
            Email : String
            Password : String
        ) : CreateUser

        updateUser(
            id: Int
            Name : String
            SurName : String
            Email : String
        ):UpdateUser

        deleteUser(
            id: Int
        ):DeleteUser
    }

`

module.exports = {
    typeDefs
}