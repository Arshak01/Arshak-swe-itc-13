#!/bin/bash

function factorial()
{
    local n=$1
    if (( $n < 2 ))
    then
        echo 1
    else
        echo $((n*$(factorial $n-1)))
    fi
}

read -p "Enter a number = " num
echo "Factorial of $num = $(factorial $num)"
