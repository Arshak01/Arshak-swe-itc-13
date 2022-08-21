alert("Task 1");
function swap(arr, num1, num2) {
  let temp = arr[num1];
  arr[num1] = arr[num2];
  arr[num2] = temp;
}
function bubbleSort( arr) {
  let i, j;
  for (i = 0; i < arr.length-1; ++i) {
    for (j = 0; j < arr.length-i-1; ++j) {
      if (arr[j] > arr[j+1]) {
        swap(arr,j,j+1);
      }
    }
  }
}
let arr = [15,6,85,5,9,20];
alert(`Befor bubble sort arr is ${arr}`);
bubbleSort(arr);
alert(`After bubble sort arr is ${arr}`);

alert("Task 2");
function countString(str, letter) {
  let count = 0;
  for(let i = 0; i < str.length; ++i) {
    if (str.charAt(i) == letter) {
      count += 1;
    }
  }
  return count;
}
let string = prompt('Enter a string: ');
for (let i = 0; i < string.length; ++i) {
  let j = i + 1;
  if (string[j] != string[i]) {
    let result = countString(string, string[i]);
    alert(`${result} - ${string[i]}`);
  }
  else {
    ++i;
  }
}