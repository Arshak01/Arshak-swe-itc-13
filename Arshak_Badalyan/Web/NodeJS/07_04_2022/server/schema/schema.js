const { gql } = require('apollo-server-express');


const typeDefs = gql`
    type User {
        id : Int
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

    type CreateUser {
        Name : String
        SurName : String
        Email : String
        Password : String
    }

    type Login {
        Email : String
        Password : String
    }
    type Token {
        token: String
    }
    type Info {
        id: Int
        text: String
    }

    type Query {
        user : [User]
        getUserById(id: Int!) : UserById
    }

    type Mutation {
        login (
            Email : String
            Password : String
        ):Token

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
        ):Info

        deleteUser(
            id: Int
        ):Info
    }
`

module.exports = {
    typeDefs
}