#!/bin/bash 



findNumber(){

        compPick=$(shuf -i 1-20 -n 1)
	level=3
        echo " *** Let's start game : try to find my number *** "
	while [ $level -gt 0 ]
	do
	read -p "$level : Entry your number : " num
  		if [ $compPick -eq $num ] 
		then
			echo " ***** Congratulation ***** "
		        bool=1
			break
  		elif [ $num -lt $compPick ]
		then
			echo "It should be greater than the inputting number"
			bool=0
		elif [ $num -gt $compPick ]	
		then
			echo "It should be less than the inputting number"
			bool=0
		fi
	((level--))
	done
	if [ $level == 0 ]
	then
		echo "Game over"
		echo "I keep number $compPick"
	fi

}

findNumber
