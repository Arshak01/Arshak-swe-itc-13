// Task 1
const str = "afjhaaaaaaabbbffskxccc";

function foo(str) {
    let obj = {};
    for(let i = 0; i < str.length; ++i) {
        if(obj.hasOwnProperty(str[i])) {
            obj[str[i]] += 1;
        }else {
            obj[str[i]] = 1;
        }   
    }
    return obj
}

console.table(foo(str));

// Task 2

const arr = [13, 3, 21, 50, 1, 26, 10, 8];


function bubble(arr) {
    for(let i = 0; i < arr.length; ++i) {
        for(let i = 0; i < arr.length; ++i) {
            if(arr[i] > arr[i + 1]) {
                [arr[i], arr[i+1]] = [arr[i + 1], arr[i]] ;
            }
        }
    }
    return arr
}

console.log(bubble(arr));

