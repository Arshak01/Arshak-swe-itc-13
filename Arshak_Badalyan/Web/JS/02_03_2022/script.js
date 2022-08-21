/** 1. Write a function to print number of occurrence for each character */

function char_count(text, char) {
    var char_count = 0;
    for (var i = 0; i  < text.length; ++i) {
    if (text.charAt(i ) == char) {
        char_count += 1;
        }
    }
    return char_count;
}

function numOccur(text){
    let array = [];
    for (let i = 0; i < text.length; ++i) {
        let j = i + 1;
        if (text[j] != text[i]) {
            let count = char_count(text, text[i]);
            array.push(`${text[i]}, ${count}`);
        } else {
            ++i;
        }
    }
    return array;
}

let text = "aaaabbcbdar";

console.log("Text : ", text);
console.log("Count : ", numOccur(text));


/** Task: 2 Implement  bubble sort algorithm. */

function bubbleSort(array){
    let swap = true;
    let temp;
    while(swap){
        swap= false;
        for (let i = 0; i < array.length; i++) {
            if(array[i] > array[i+1]){
                temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
                swap = true;
            }
        }
    }
    return array;
}

let array = [9,4,7,2,6,8,1,0,15,78,42,36,25];

console.log("Befor : ",array);
array = bubbleSort(array);
console.log("After : ", array)