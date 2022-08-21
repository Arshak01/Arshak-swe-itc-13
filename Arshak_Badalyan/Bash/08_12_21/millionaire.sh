#!/bin/bash

sum=(250 500 1000 2000 5000 10000 20000 50000 100000 1000000)
questNum=0
starts=1
end=200
currLine=0

table(){
        len=${#sum[@]}
	echo
	echo "---------------"
	echo " LEVEL | MONEY " 
	echo "---------------"
        for (( i=$len-1; i>=0; i-- ));
	do
		if (( $i==$1 ))
 		then
			echo "|$[$i+1] :  ${sum[$i]} * " 
		else
        		echo "|$[$i+1] :  ${sum[$i]} "
 	fi
        done
	echo
}

check(){
	if [[ $1 == $2 ]] 
	then
		questNum=$[$questNum+1]
  		table $questNum
	else
		echo ""
		echo " WRONG ANSWER "
		echo "#### You lose ####"
		exit		
	fi
}


selectAnswer(){
	select item; do
	#if [ 1 -le "$REPLY" ] && [ "$REPLY" -le $# ];
	
	if [[ $item != -z ]]
	then
		echo "Your answer is $item"
		selAnIn=$REPLY
		selAn=$item
		#answer=2
                #check $selAnIn $answer 
		echo $item $selAnIn $selAn
	break;
	else
	echo "Wrong selection: Select any number from 1-$#"
	fi
done
}

readQuestion(){
  	currLine=$[$currLine+1]
	currectAnswer=`sed -n "$currLine"p < $2`	

	sed -n "$starts","$[$starts+4]"p $1
	starts=$[$starts+6]

	echo "Choose your answer 1-4 : "
	read myAnswer
	check $myAnswer $currectAnswer
}

selQuest(){

	if (( $1 == 5 || $1 == 9 ))
	then
		currLine=0
		starts=1
	fi

	if (( $1 <= 4 ))	
	then
		questPath=(`pwd`/low.txt)
		answerPath=(`pwd`/answerLow.txt)
		readQuestion $questPath $answerPath		      
	elif (( $1 > 4 && $1 <= 8 ))
	then
		questPath=(`pwd`/middle.txt)
		answerPath=(`pwd`/answerMiddle.txt)
		readQuestion $questPath $answerPath	       
	elif (( $i > 8 ))
	then
		questPath=(`pwd`/hard.txt)
		answerPath=(`pwd`/answerHard.txt)
		readQuestion $questPath $answerPath
	fi

}

startGame(){
	quest=1
	while (( $quest <= 10 ))
	do
		selQuest $[$questNum + 1]
		quest=$[$quest+1]
	done
}

millionaire(){
echo " **** Welcome MILLIONARIE Game **** "
echo
read -p "If you want to start : yes->1, no->0 : " choose
if (($choose == 1))	
then
	table -1	
	startGame	
else
	echo "Byee"
	exit
fi
}

millionaire

