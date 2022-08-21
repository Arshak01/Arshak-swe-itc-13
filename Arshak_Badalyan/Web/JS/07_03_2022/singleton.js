
class Singleton {
    constructor() {
      if (!Singleton.instance) {
          return  Singleton.instance = this;
        }
        return Singleton.instance;
    }
}

var obj1 = new Singleton()
var obj2 = new Singleton()
var obj3 = new Singleton()
console.log(obj1 === obj2)
console.log(obj1 === obj3)
console.log(obj2 === obj3)