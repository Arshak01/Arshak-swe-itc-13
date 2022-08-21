#!/bin/bash

vocabulary=("car" "sun" "computer" "mouse" "screen" "webcam" "cpu" "ram" "keyboard" "heap")
under=("___" "___" "________" "_____" "______" "______" "___" "___" "________" "____")
unset usedLetters
declare -a usedLetters

wordNum=$(( $RANDOM % 9 + 0 ))
word=${vocabulary[$wordNum]}
guess=${under[$wordNum]}
len=$((${#word}-1))


tries=6
until (( tries == -1 ))
do
    clear
    echo guess the word!
    echo "Your guess: $guess                                          $tries: Your tries"
    if [[ "$guess" != *"_"* ]]
    then
        for i in 1 2 3
        do
            echo YOU WON!!! word = $word
            echo " "
            echo "CONGRATULATIONS, $USER!"
            echo "                      "
            echo "                      "
            echo "                      "
            echo "                      "
            echo "         O            "
            echo "        /|\           "
            echo "    ____/_\_______ ___"
            echo
            sleep 1
            clear
            echo YOU WON!!! word = $word
            echo " "
            echo "CONGRATULATIONS, $USER!"
            echo "                      "
            echo "                      "
            echo "                      "
            echo "        \O/           "
            echo "         |            "
            echo "        / \           "
            echo "    ______________ ___"
            echo
            sleep 1
            if [[ $i != 3 ]]
            then
                clear
            fi
        done

        break
    fi
    case $tries in
    6 )
        echo " "
        echo "Not bad at all, $USER!"
        echo "                      "
        echo "                      "
        echo "        \O/           "
        echo "         |            "
        echo "        / \           "
        echo "    ______________ ___"
        echo ;;

    5 )
        echo " "
        echo "OOPS, $USER!"
        echo "                      "
        echo "                      "
        echo "        \O            "
        echo "         |\       |   "
        echo "        / \       |   "
        echo "    ______________|___"
        echo ;;
    4)
        echo " "
        echo "OH NO, $USER!"
        echo "                      "
        echo "                  |   "
        echo "        \O        |   "
        echo "         |\       |   "
        echo "        / \       |   "
        echo "    ______________|___"
        echo ;;
    3)
        echo " "
        echo "Give your best, $USER!"
        echo "                __    "
        echo "                  |   "
        echo "        \O        |   "
        echo "         |\       |   "
        echo "        / \       |   "
        echo "    ______________|___"
        echo ;;
    2)
        echo " "
        echo "How bad are you, $USER?"
        echo "            ______    "
        echo "                  |   "
        echo "        \O        |   "
        echo "         |\       |   "
        echo "        / \       |   "
        echo "    ______________|___"
        echo ;;
    1)
        echo " "
        echo "The death was never this close"
        echo "Watch out, $USER!"
        echo "         _________    "
        echo "                  |   "
        echo "        \O        |   "
        echo "         |\       |   "
        echo "        / \       |   "
        echo "    ______________|___"
        echo ;;
    0)
        echo 'YOU LOST :-( the word was $word'
        echo " "
        echo "$USER             "
        echo "     RIP__________    "
        echo "         |        |   "
        echo "         O        |   "
        echo "        /|\       |   "
        echo "        / \       |   "
        echo "    ______________|___"
        echo
        break;;
        esac
    read -p "Your guess?  "   letter
    #if [[ " ${usedLetters[*]} " =~ " ${letter} " ]]
    if [[ "${usedLetters[*]}" =~ .*"$letter".* ]]
    then
        echo "OOPS! You already used that letter"
        sleep 1
    else
        usedLetters+=($letter)
        echo "${usedLetters[@]}"
        if [[ "$word" =~ .*"$letter".* ]]
        then
            for i in $(seq 0 $len)
            do
                char=${word:i:1}
                if [ "$letter" == "$char" ]
                then
                    sliceStart=$i+1
                    sliceEnd=$len
                    guess="${guess:0:i}$letter${guess:sliceStart:sliceEnd}"
                fi
            done
        else
            ((tries--))
        fi
    fi
done
