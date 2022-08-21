"use strict"

function countFunc(f) {
    let count = 0;
    while (typeof f() === "function") {
        f = f();
        count++;
    }
    return count;
}

function f1() {
    function f() {
        return "Hello";
    }
    return f;
}

function f2() {
    return f1;
}

function f3() {
    return f2;
}

function BSort(arr) {
    for (let i = 0; i < arr.length - 1; i++) {
        for (let j = 0; j < arr.length - i - 1; j++) {
            if (countFunc(arr[j]) > countFunc(arr[j + 1])) {
                let tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
    return arr;
}
const arr = [f3, f1, f2];
console.log(BSort(arr));