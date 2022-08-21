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

	2. Create function with recursion to deep copy objects.


## Code source
	https://www.w3schools.com/js/default.asp

## Built With
- JS
- Visual Code

