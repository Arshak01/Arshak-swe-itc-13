const arr = [
    { name: "Name2", age: 42, investment: 353  },
    { name: "Name1", age: 41, investment: 12  },
    { name: "Name7", age: 47, investment: 4654  },
    { name: "Name9", age: 49, investment: 456  },
    { name: "Name3", age: 43, investment: 4566  },
    { name: "Name5", age: 45, investment: 4576  },
    { name: "Name6", age: 46, investment: 78  },
    { name: "Name8", age: 48, investment: 436546  },
    { name: "Name10", age: 410, investment: 123  },
    { name: "Name4", age: 44, investment: 3676  },
]
let newArr = [];
arr.sort((a,b) => b.investment - a.investment).filter((item, index) => index < 5).reduce((item, index) => newArr.push(index.name), "");
console.log(newArr);