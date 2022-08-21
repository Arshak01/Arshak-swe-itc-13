class Singleton {
    constructor() {
        if (!Singleton.instance){
            Singleton.instance = this;
        }
        return Singleton.instance;
    }
}
let obj1 = new Singleton();
let obj2 = new Singleton();
let obj3 = new Singleton();
let obj4 = new Singleton();


console.log(obj1 === obj2);
console.log(obj2 === obj3);
console.log(obj3 === obj4);
console.log(obj1);
console.log(obj2);