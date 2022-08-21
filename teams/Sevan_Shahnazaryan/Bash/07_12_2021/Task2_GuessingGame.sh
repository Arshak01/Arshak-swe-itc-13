#!/bin/bash

randomNum=$(( $RANDOM % 20 + 1))

for((i=0; i<4; i++))
do
    if (( $i == 3 ))
    then
        echo OOPS Too much tries. Try next time
        break;
    fi
    read num
    if (( $num ==  $randomNum ))
    then
        echo You guessed it!
        break
    elif (( $num < $randomNum ))
    then
        echo It should be greater than the inputting number
    else #(( $num > $randomNum))
        echo It should be less than the inputting number
    fi
done
