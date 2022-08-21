## Project-name
	JS tasks

## Project-description
	1. Create an array of functions, each of those functions can return a function (multiple level). Create a sort function which will take that array and will sort based on the number of calls required for a function to reach the last value.
        Example
        f1 = _ => "hello"
        // f1() ➞ "hello"   // called only 1 time to reach value "hello"

        f2 =  =>  => "hello"
        // f2()() ➞ "hello"   // we will call 2 times to reach value "hello"

        f3 =  =>  => _ => "hello"
        // f3()()() ➞ "hello" // we will call 3 times to reach value "hello"

        funcSort([f2, f3, f1]) ➞ [f1, f2, f3]
        // [f2, f3, f1] ➞ [2, 3, 1] ➞ [1, 2, 3] ➞ [f1, f2, f3]

        funcSort([f1, f2, f3]) ➞ [f1, f2, f3]
        // [f1, f2, f3] ➞ [1, 2, 3] ➞ [1, 2, 3] ➞ [f1, f2, f3]

        2. Create recursion function to deep copy of objects.


## Code source
	https://www.w3schools.com/jsref/jsref_map.asp
	https://www.w3schools.com/js/default.asp
        https://www.javascripttutorial.net/


## Description
For running project,go to folder and write on terminal `node filename.js`. Afther that show result. If there is not node on you computer, you must install it.


## Contents
Thanks for reading :)
