#!/bin/bash/
#numbers=(1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20)
secret=$((RANDOM%20))

read -p "Let's play Guessing number!!
Now I've a number in my mind and it's between 1 and 20.
Try to guess by 3 attepmts!!
Enter your number: " answer

for ((i=1; i<3; i++))
do

if (($answer == $secret))
then echo "WOW $answer was my number! You won!!"
elif (($answer < $secret))
then echo "It's greater than $answer"
else (($answer > $secret))
	echo "It's less than $answer"
fi

read -p "Try again! " answer

done
echo "You lost! My number was $secret"
