#! /bin/bash

arr=("apple" "banana" "apricot" "cherry" "orange" "peach" "pear" "strawberry" "pineapple" "mango")
random=${arr[$(( $RANDOM % 9 + 0 ))]}
word=()
for ((i=0; i<${#random}; i++))
do
	word[$i]="-"
done
turns=6
a="false"
echo $random ${#random}
echo "Guess the fruit."
echo "You have $turns chances to make a mistake."
echo "If you don't guess, the man will be hanged."
letters=()

while (( $turns > 0 ))
do
	word_str=""
	for (( i=0; i<${#word[@]}; i++ ))
	do
		word_str+=${word[$i]}
	done
	echo $word_str
	read -p "Enter the letter: " letter
	if [[ ${letters[*]} =~ ${letter} ]]
	then
		echo "The letter is repeated. Try again."
		continue
	else
		letters[${#letters[@]}]=$letter
	fi
	k="false"
	x="false"
	for (( i=0; i<${#random}; i++ ))
	do
		if [[ ${random:$i:1} == $letter ]]
		then
			word[$i]=$letter
			k="true"
		fi
		if [[ ${word[$i]} == "-" ]]
		then
			x="true"
		fi
	done
	if [[ $x == "false" ]]
	then
		a="true"
		echo "Comgratulations!!!"
		echo "You win. You saved the man."
		echo "\o/"
                echo " |"
                echo "/ \ "
		break
	fi
	if [[ $k == "false" ]]
	then
		turns=$((turns-1))
		echo "The word doesn't contain the letter '$letter'."
		if [[ $turns == 5 ]]
		then
			echo " o "
		elif [[ $turns == 4 ]]
		then
			echo " o "
                	echo " | "
		elif [[ $turns == 3 ]]
		then
			echo " o "
                	echo "/|"
		elif [[ $turns == 2 ]]
		then
			echo " o "
			echo "/|\ "
		elif [[ $turns == 1 ]]
		then
			echo " o "
        	        echo "/|\ "
	                echo "/"
		else
			echo " o "
        	        echo "/|\ "
	                echo "/ \ "
		fi
		echo "You have $turns chances to make a mistake."
	fi
done
if [[ $a == "false" ]]
then
	echo "You lost. Hange the man!!!"
	echo "_______"
	echo " |    |"
	echo " o    |"
	echo "/|\   |"
	echo "/ \   |"
fi
