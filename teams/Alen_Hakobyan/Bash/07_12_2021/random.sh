#! /bin/bash

MAXTRIES=3
VALUE=$[( $RANDOM % 20 ) +1]

for (( i=1 ; i <= $MAXTRIES ; i++ )) ; do

    read -p "Pick a number between 1 and 20  " num

    echo "You guessed $num"

    if [ "$VALUE" -eq "$num" ]
    then
        echo "You win!"
        break
    fi

    if [ $i -ge $MAXTRIES ] 
    then
        echo "You have exceeded $MAXTRIES tries!"
	echo "The number is " $VALUE
        break

    elif [ "$VALUE" -gt "$num" ]
    then
        echo "It should be greater than the inputting number"

    elif [ "$VALUE" -lt "$num" ]
    then
        echo "It should be less than the inputting number"
    fi

done
