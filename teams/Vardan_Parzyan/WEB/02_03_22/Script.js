console.log("====================");
console.log("=====First task=====");
console.log("====================");

str = "aaaabbcbda";
var answer = [];

function charCounter(string){
    char = string.split("");
    char.sort();
    let counter = 1;
    for (let i = 0; i < char.length; i++) {
        flag = false;
        if (char[i] == char[i + 1]) {
            counter++;
            flag = true;
        } else {
            if (!flag) {
                answer[char[i]] = counter;
                jump = false;
                counter = 1
            }
            else
                answer[char[i]] = 1;
        }
    }
    return answer;
}
charCounter(str);
console.log(answer);

console.log("====================");
console.log("=====Second task====");
console.log("====================");


function bubbleSort(arr){
    let isSorted = false;
    while(!isSorted){
        isSorted = true;
        for(let i = 0; i < arr.length - 1; i++){
            if(arr[i] > arr[i+1]){
                let temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                isSorted = false;
            }
        }
    }
}

var array = [];
for (i = 0; i < 20; i++) {
    array.push(Math.round(Math.random() * 100));
}
bubbleSort(array);
console.log(array);
