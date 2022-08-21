#!/bin/bash


VALUE=$[( $RANDOM % 20 ) +1]

for (( i=1 ; i <= 3 ; i++ )) ;
do
    read -p "Guess a number between 1 and 20  " ANS
    if [ "$VALUE" -eq "$ANS" ]
    then
        echo "You win!"
        break
    fi

    if [ $i -ge 3 ]
    then
        echo "You loss"
        break

    elif [ "$VALUE" -gt "$ANS" ]
    then
        echo "It should be greater than the inputting number"
     elif [ "$VALUE" -lt "$ANS" ]
     then
    	    echo "It should be less than the inputting number"
    fi

done
