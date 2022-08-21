#!/bin/bash
echo "Lets play the game"
echo "Guess the number from 1 to 20 in three tries"
echo "Let's go"
answer=$(( $RANDOM % 20 + 1 ))
tries=0
while (( answer != num && tries != 3 )); do
    read -p "Enter guess number:" num
    if (( num < answer ))
    then
        echo "$num is less than the number"
        tries=$((tries+1))
    elif (( num > answer ))
    then
        echo "$num is greater than the number"
        tries=$((tries+1))
    fi
done
if (( answer == num ))
then
    echo -e "Correct,congradilations, You win"
else
    echo -e "Tries out, try again"
fi
