#!/bin/bash

factorial () 
{
x=$1
if (( x <= 2 ))
    then
        echo $x
    else
        f=$((x-1))
        
f=$(factorial $f)
f=$(($f*$x))
echo $f
fi
}

   
read -p "Enter a number: " num
if (( num == 0 ))
then   
	echo 1
else
factorial $num
fi
