"use strict";

function isObject(obj) {
    return obj.constructor.name === "Object";
}

function clone(obj) {
    if (!isObject(obj)) {
        return obj;
    }
    let tmp = {}
    for (let key of Object.keys(obj)) {
        tmp[key] = clone(obj[key]);
    }
    return tmp;
}

let user = {
    name: "User1",
    age: {
        year: 2000,
    },
    access: {
        root: true
    }
};

let userClone = clone(user)
userClone.name = "User2"
userClone.age.year = 1999;
userClone.access.root = false;
console.table(userClone === user);
console.table(userClone.name === user.name);
console.table(userClone.age === user.age);
console.table(userClone.access === user.access);
console.table(user);
console.table(userClone);