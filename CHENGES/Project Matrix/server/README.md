## PSQL DB creation and connection

To create PSQL DB and connect to our server run following commands from new terminal
Enter to psql shell
Create psql user named psqluser22 and database with all premissions named projectmatrixdb

```
  create user psqluser22 with encrypted password 'qUaVxYjG$Iea';
  create database projectmatrixdb;
  grant all privileges on database projectmatrixdb to psqluser22;
  \c projectmatrixdb psqluser22;
```

Open new terminal on "server" directory and install all needed modules

```
  npm install
```

Run server

```
  npm run nodemon
```

## Swagger

To generate swagger API documentation run command belaw from root directory

```
npm run docs
```

## Eslintrc

To run ESLint on project run command belaw from root directory

Check prettier format

```
    npm run format:check
```

Write prettier format

```
    npm run format:write
```

Show list of errors and wornings

```
    npm run lint:check
```

Auto fixed command

```
    npm run lint:fix
```

## Built With

- PSQL
- NodeJS
- Sequelize
- Express

## Thank you for your attention!
