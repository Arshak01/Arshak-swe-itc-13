#!/bin/bash


function calculateFactorial {
    if (( $1 <= 1 ))
    then echo 1
    else
        result=$(calculateFactorial $(( $1 - 1 )))
        echo $(( $1 * $(calculateFactorial $(( $1 - 1 ))) ))
    fi
}
calculateFactorial $1  

