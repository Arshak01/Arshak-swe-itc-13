#!/bin/bash

read -p "Entry number : " num

factorial(){
    if (( $1 == 1 ))
    then
        echo 1
    else
        echo $(( $1 * $(factorial $(( $1 - 1 )))))
    fi
}
factorial $num
