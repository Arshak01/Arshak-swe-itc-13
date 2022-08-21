let promise1 = fetch('https://raw.githubusercontent.com/SevanIM/SevansRepo/main/Homework/Users').then(res => res.json());
let promise2 = fetch('https://raw.githubusercontent.com/SevanIM/SevansRepo/main/Homework/Investments').then(res => res.json());

let arr1 = [];
let arr2 = [];

let promises = Promise.all([promise1,promise2]).then((res) => {
    arr1 = res[0].users;
    arr2 = res[1].investments;
    arr1.push(res[0]['users'][a]);
    arr2.push(res[1]['investments'][a]);
   
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
