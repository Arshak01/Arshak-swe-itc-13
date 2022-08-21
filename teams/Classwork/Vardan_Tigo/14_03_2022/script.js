const axios = require('axios');


let promise1 = axios.get('https://raw.githubusercontent.com/SevanIM/SevansRepo/main/Homework/Users').then(res => res.data);
let promise2 = axios.get('https://raw.githubusercontent.com/SevanIM/SevansRepo/main/Homework/Investments').then(res => res.data);

let arr1 = [];
let arr2 = [];

let promises = Promise.all([promise1,promise2]).then((res) => {
    arr1 = res[0].users;
    arr2 = res[1].investments;
    let merged = [];
    for(let i=0; i<arr1.length; i++) {
        merged.push({
        ...arr1[i],
        ...(arr2.find((itmInner) => itmInner.id === arr1[i].id))}
    );
    }
    let newArr1 = [];
    let newArr2 = [];
    merged.reduce((item, index) => newArr1.push(index.name + ' ' + index.surname), "");
    merged.sort((a,b) => b.investment - a.investment).filter((item, index) => index < 5).reduce((item, index) => newArr2.push(index.name), "");
    console.log(newArr1);
    console.log(newArr2);
});