# NodeJS Task
    Created an API for "Users" database that contains an object which contain array from objects that have "id" and "name".

## Usage
    The first you must npm i install body-parser and REST CLIENT extansions.
    After that you should install run the following command in the terminal of current directory.
            `node index.js` or  `npx nodemon index.js`

    The API can handle the following requests.
        * GET /users   -  read all users info from  users.json and send in the response
        * POST /users - create a new user and add it to users.json file
        * PUT /users:id - update an existing user info by id (in users.json file also)
        * DELETE /users:id - delete a user by id (from users.json file also)

## Thanks
    Arshak Badalyan