
//  Task1 : Deep copy objects
const deepCopy = obj => {
    if (obj === null) return null;
    let copy = Object.assign({}, obj);
    Object.keys(copy).forEach( key => (copy[key] = typeof obj[key] === 'object' ? deepCopy(obj[key]) : obj[key]));
    return copy;
};

const a={ a:{ c:{ e:{ g:[1,2,3,5,6,7]}}}, b:{ d:{ g:{ f:[5,4,1], h:{"key":[146,4,5,6]}}}}}
let dCopy = deepCopy(a)
console.log(dCopy)


//  Task2 : Count function call.
function callbacksDepth(f) {
    let count = 0;
    while (typeof f() === "function") {
        f = f()
        count++
    }
    return count;
}

function f1() {
    function f() {
        return "hello";
    };
    return f;
}

function f2() {
    return f1;
}

function f3() {
    return f2;
}

function funcSort(array) {
    for (let i = 0; i < array.length - 1; i++) {
        for (let j = 0; j < array.length - i - 1; j++) {
            if (callbacksDepth(array[j]) > callbacksDepth(array[j + 1])) {
                let tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
    return array;
}

const functionsArray = [f3, f1, f2];
console.log(functionsArray);
funcSort(functionsArray);
console.log(functionsArray);
