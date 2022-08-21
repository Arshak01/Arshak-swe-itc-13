const request = require('supertest')
const app = require('../index')


describe('GET USERS', () => {
    it('should get all users', async () => {
        const res = await request(app)
            .get('/users')
            expect(res.statusCode).toEqual(200)

    })
})
describe('CREATE USER', () => {
    it('should create new user', async () => {
        const res = await request(app)
            .post('/users/')
            .send({
                "Name": "Armen",
                "SurName": "Hakobyan",
                "Email": "a@gmail.com",
                "Password": "Password"
            })
        expect(res.statusCode).toEqual(200)

    })
})

describe('UPDATE USER', () => {
    it('should UPDATE existing user', async () => {
        const res = await request(app)
            .put('/users/1')
            .send({
                "Name": "Harut"
            })
        expect(res.statusCode).toEqual(200)
    })
})

describe('FIND USER', () => {
    it('should DELETE existing user', async () => {
        const res = await request(app)
            .get('/users/login/Harut/user1')
        expect(res.statusCode).toEqual(200)
        expect(res.body).toEqual(
            [{
                "Name": "Harut",
                "SurName": "Hakobyan",
                "Email": "a@gmail.com",
                "Password": "Password"
            }]
        )
    })
}) 

describe('DELETE USER', () => {
    it('should DELETE existing user', async () => {
        const res = await request(app)
            .put('/users/1')
        expect(res.statusCode).toEqual(200)
    })
})


