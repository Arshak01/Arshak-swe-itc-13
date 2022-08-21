#!/bin/bash/
read -p "Enter a Number: " number

functionFactorial () 
{
	factorial=1

for((i=1; i<=$number; i++))
	do
		factorial=$(($factorial*$i))
	done
		echo $factorial
	}
functionFactorial

