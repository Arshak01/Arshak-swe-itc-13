#!/bin/bash
RANDOMa=($(shuf -i 1-10  ))
d=1000
for i in {1..10}
do
	if [[ $i -le 4 ]] 
	then
		echo "Low Level"
		questionfile="./lowq.txt"
		answerfile="./lowa.txt"
		rightanswerfile="./lowra.txt"
	elif [[ $i -gt 4 && $i -le 8 ]]
	then
		echo "Medium Level"
		questionfile="./mediumq.txt"
		answerfile="./mediuma.txt"
		rightanswerfile="./mediumra.txt"
	else
                echo "Hard Level"
		questionfile="./hardq.txt"
		answerfile="./harda.txt"
		rightanswerfile="./hardra.txt"
	fi
		question=$(sed -n "${RANDOMa[$i-1]} p" $questionfile)
                echo "Question number $i:" $question
                answers=$(sed -n "${RANDOMa[$i-1]} p" $answerfile)
                rightanswers=$(sed -n "${RANDOMa[$i-1]} p" $rightanswerfile)
	select answer in $answers
	do
	if [ "$rightanswers" == "$answer" ]
	then
		echo "This is right answer you are win" $((d*i))$
	else
		echo "Sorry but it is wrong answer, you lose!!!"
		exit
	fi
	break
	done
done
