#!/bin/bash
read -p "Factorial of : " n
function fact {
	if (( $1 <=1 ))
	   then
           echo 1
	else
           echo $(( $1 * $(fact $(( $1 - 1 ))) ))
	fi	
	}
fact $n
