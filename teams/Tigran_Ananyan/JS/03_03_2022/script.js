f1 = () => console.log("Hello");
f2 = () => f1;
f3 = () => f2;

function counter(foo) {
    let count = 1;
    while (typeof foo() === "function") {
        foo = foo();
        count++;
    }
    return count;
}
let arr = [f3, f1, f2];
var callbackcounter = [];

function callBackCcounter(arr, arr2) {
    for (let i = 0; i < arr.length; i++) {
        arr2[i] = counter(arr[i]);
    }
    return arr2;
}
callBackCcounter(arr, callbackcounter);
console.log(callbackcounter);
callbackcounter.sort();

function arrSorter(arr, arr2) {
    for (let i = 0; i < arr.length - 1; i++) {
        for (let j = 0; j < arr.length - 1; j++) {
            if (counter(arr[j]) > arr2[i]) {
                let tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
    return arr
}
arrSorter(arr, callbackcounter)
console.log(arr);
