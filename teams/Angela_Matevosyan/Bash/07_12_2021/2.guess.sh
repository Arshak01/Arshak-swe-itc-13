#! /bin/bash
maxtries=3
number=$[( $RANDOM % 20 ) +1]
echo "Enter a number between 1 and 20: "

for (( i=1; i <= $maxtries; i++ )); do

    read -p "Attempt $i: " answer

    echo "You guessed $answer"

    if(( $number == $answer )); then
        echo "Well done!"
        break
    fi

    if(( $i >= $maxtries)); then
        echo "You have exceeded $maxtries tries!"
        break

    elif(( $answer < $number )); then
        echo "It should be greater than the inputting number"

    elif(( $answer > $number )); then
        echo "It should be less than the inputting number"
    fi
done
