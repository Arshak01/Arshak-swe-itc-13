#! /bin/bash

random=$(( $RANDOM % 20 + 1 ))
for ((i=3; i>=1; i--))
do
	echo "You have $i turns to guess the number in range 1-20."
	read -p "Enter the number: " number
	if (( $number > $random )); then
		echo "It should be less than the inputting number."
	elif (( $number < $random)); then
		echo "It should be greater than the inputting number."
	else
		echo "Congratulations! You guess the number."
		break
	fi
	if (($i == 1)); then
		echo "You loose. The number was $random."
	fi
done
