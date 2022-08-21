#! /bin/bash

guess=-1
typeset -i num=0

echo -e "Hii. Hope you are doing well. Today I created a game.\nYou can play it. The main rule is that you are going to guess my memorised number.\nAlso, you have only 3 chanches. Good luck to you! Guess a number between 1 and 20.\n"

### Generate random number
(( answer = RANDOM % 20 + 1 ))

### Play game
count=0
while [[ $guess -ne $answer && $count -lt 3 ]]; do

	read -p "Enter guess $num: " guess
	if [[ $guess -lt $answer ]] 
	then
		echo "It should be greater than the inputting number."
		count=$((count+1))
	elif [[ $guess -gt $answer ]]
	then 
		echo "It should be less than the inputting number."
		count=$((count+1))
	fi
done

if (( $answer==$guess ))
then 
		echo "Perfect! You won! Congrats:)"
else
		echo "You lost. But don't worry! Try again!"
fi
