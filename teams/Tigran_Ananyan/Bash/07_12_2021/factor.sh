#!/bin/bash
echo "Enter the num"
read x
function factor {
    if (( $1 <= 1 ))
    then
        echo 1
    else
        prev=$(factor $(( $1 - 1))
    )
        echo $(( $1 * prev ))
    fi
}

factor $x
