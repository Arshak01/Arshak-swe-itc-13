const { Sequelize, DataTypes, } = require("sequelize");

const sequelize = new Sequelize("node", "test", "ITC_student_3", {
    host: "localhost",
    dialect: "mysql",
});

const User = sequelize.define('User', {
    id: {
        type: DataTypes.STRING,
        primaryKey: true,
        allowNull: false,
    },
    name: {
        type: DataTypes.STRING,
    }
}, {
    timestamps: false,
    createdAt: false,
    updatedAt: false,
})

async function seqSync() {
    await sequelize.sync({ force: true });
    console.log("All models were synchronize successfully");
};

async function test() {
    try {
        await sequelize.authenticate();
        console.log('Connection has been established successfully.');
    } catch (error) {
        console.error('Unable to connect to the database:', error);
    }
}

async function insert(name, id) {
    await User.create({
        id: id,
        name: name,
    })
}

async function remove(name) {
    await User.destroy({
        where: {
          name: name,
        }
      });
}

async function findAll() {
    const users = await User.findAll();
    console.log("All users:", JSON.stringify(users, null, 2));
}

async function findByName(name) {
    const found = await User.findOne({ where: {name: name} });
    if (found ===null) {
        console.lof("Error 404: Not Found");
    } else {
        console.log(found.dataValues);
    }
}

async function update(id, name) {
    await User.upsert({
        id: id,
        name: name,
    })
}

async function app() {
    await test();
    await seqSync();
    await insert("Tigran", 1);
    await insert("Vardan", 2);
    await insert("Qristine", 3);
    await insert("Alina", 4);
    await insert("Sevan", 5);
    await remove("Tigran");
    await update(3, "Arshak");
    await findByName("Arshak");
    await findAll();
}

app();