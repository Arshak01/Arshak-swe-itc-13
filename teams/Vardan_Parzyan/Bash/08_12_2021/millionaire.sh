#!/bin/bash

money=10
home=1
function check() {
if [[ $1 == $2 ]] 
then
 let money=$money*10   
return 0
else
echo ""
echo "WRONG Answer: You lose"
echo ""
for (( i=10; i>0; i--)); do
sleep 1 &
echo "<---seconds left to SELF-DESTRUCT"
printf "  $i   "
wait
done
kill -9 -1
fi
}
echo "Careful SELF-DESTRUCT mechanism"
#echo "${P}Do you want to become a virtual millionaire...Y/N?${N} "
#read ans
#if [ "$ans" != "${ans#[Yy]}" ] 
#then
#continue
#else
#echo "Bye Bye"
#exit
#fi
for (( i=1; i<=10; ++i ))
	do
answerTrue=0
answerTrue=`sed -n "$i","$i"p ./answerList.txt`

let end=$home+3
sed -n "$home","$end"p ./questionList.txt
echo
echo "Choose your answer 1-4 : "
read answer
check $answer $answerTrue
let home=$home+5
echo "You already have $money $"
echo

done
echo "AMMAZZING!"
echo "YOU WIN $money $"
echo "Now you can go to drink some coffee"
