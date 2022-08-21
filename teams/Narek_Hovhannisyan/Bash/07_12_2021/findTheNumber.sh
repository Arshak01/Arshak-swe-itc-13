#!/bin/bash

number=$(( $RANDOM % 20 + 1 ))

read -p "type the first number: " first

if (( $first == $number ))
then
    echo "You've found. The number was $number"
    sleep 2
    exit 1
else if (( $first > $number ))
then echo "It should be less than the inputting number"
else echo "It should be greater than the inputting number"
fi
fi

read -p "type the second number: " second 

if (( $second == $number ))
then 
    echo "You've found. The number was $number"
    sleep 2
    exit 1
else if (( $second > $number ))
then echo "It should be less than the inputting number"
else echo "It should be greater than the inputting number"
fi
fi

read -p "type the third number: " third

if (( $third == $number ))
then 
    echo "You've found. The number was $number"
    sleep 2
    exit 1
else if (( $third > $number ))
then echo "It should be less than the inputting number"
else echo "It should be greater than the inputting number"
fi
fi
