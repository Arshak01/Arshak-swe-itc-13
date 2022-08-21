#!/bin/bash
clear
money=2000
while IFS="#" read -r question choices answer
do
 echo
 echo $question
 echo
 echo
 echo $choices
 echo
 echo
 echo "If you answer correctly you win $money$"
 read player_answer </dev/tty
 if (( $player_answer == $answer ))
 then
     echo "Congradilations you win $money$"
      money=$((money*2))

 else
     break
 fi
 clear
done <questions.txt

if (( $money >= 1000000 ))
then
    echo
    echo "You are a genius"
    figlet YOURE  A  MILLIONAIRE
    echo
    echo
else
    echo
    echo
    figlet YOU  LOOSE
    echo
    echo
    read -r -p "Play again? [y/N] " response
case "$response" in
    [yY][eE][sS]|[yY])
        source millionaire.sh
        ;;
    *)
        ;;
esac

fi
