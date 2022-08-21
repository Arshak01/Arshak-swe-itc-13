#!/bin/bash/

allQuestions=()

shuf -n 4 simpleQuestions.txt > mainQuestions.txt
shuf -n 4 mediumQuestions.txt >> mainQuestions.txt
shuf -n 2 hardQuestions.txt >> mainQuestions.txt

numberOFlines=`cat mainQuestions.txt | sed '/^\s*$/d' | wc -l`
while (($mumberOFlines != 10))
do
	if (($numberOFlines != 10))
	then
	shuf -n 4 simpleQuestions.txt > mainQuestions.txt
	shuf -n 4 mediumQuestions.txt >> mainQuestions.txt
	shuf -n 2 hardQuestions.txt >> mainQuestions.txt
	else break
	fi
done

echo "Who Wants to BE a Millionaire"
echo "You're WELCOME to one of the most popular game of the world!"
read -p "What's your name? : " name
echo "Hello $name. Let's start the SHOW!!"
echo
echo "---------START---------"
echo
while IFS='#' read -r question choices answer
do 
	echo
        echo $question
	echo 
   	echo $choices	
	echo "Your answer:"
	read playeranswer  </dev/tty
if [ "$playeranswer" == "$answer" ]; 
 	then 
		echo "That is the right answer!!!"
	else 
	    echo "You lost!" && break
fi

done <mainQuestions.txt
	
	
