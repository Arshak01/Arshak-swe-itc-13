#!/bin/bash
echo "Enter the number"
read num
echo "The factorial of entered number is"
factorial()
{
if (( $1 <= 1 )); then
echo 1
else
element=$(factorial $(( $1 - 1 )))
echo $(( $1 * element ))
    fi
}
factorial num


