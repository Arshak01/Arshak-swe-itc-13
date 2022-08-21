#! /bin/bash
echo "Welcome to our game"
echo "---GUESS NUMBER--- "
echo "Let's start to play"
echo "You have 4 attempts"
random=$(( RANDOM % 21 ))
for ((i=0;i<4;i++)){
echo "Please enter the number"
read num
if (($num==$random));
then
	echo "Ammazing... You won"
break
elif (($num>$random))
then
	echo "Wrong"
	echo "The hidden number is less than the entered one"
elif (($num<$random))
then
	echo "Wrong"
	echo "The hidden number is greater than the entered one"
fi
echo ""
echo "Attempt left #$((3-$i))"
}

echo "The hidden number was " $random
