#!/bin/bash


gameOver(){
    echo
    echo "         __________   "
    echo "         |        |   "
    echo "         O        |   "
    echo "        /|\       |   "
    echo "        / \       |   "
    echo "    ______________|___"
    echo
}

congratulation(){
	echo "--------------------------------------------------------"
    	echo " #     #    #    #     #  #####  #     #    #    #     #"
    	echo " #     #   # #   ##    # #     # ##   ##   # #   ##    #"
    	echo " #     #  #   #  # #   # #       # # # #  #   #  # #   #"
    	echo " ####### #     # #  #  # #  #### #  #  # #     # #  #  #"
    	echo " #     # ####### #   # # #     # #     # ####### #   # #"
    	echo " #     # #     # #    ## #     # #     # #     # #    ##"
    	echo " #     # #     # #     #  #####  #     # #     # #     #"
	echo "--------------------------------------------------------"
}


nameArray=("dataframe" "limit" "interface" "goal" "funny" "level" "tool" "merge" "gitignore" "soft")

 
random_nr=6
correctLetters[1]=""
mistakeLetters[1]=""
implodedLetters[1]=""
geussCounter=1
correctCounter=0
mistakes=0
place=1

chooseWord() {
    until [[ $random_nr -lt 6 ]] && [[ $random_nr -gt 0 ]]; do 
        random_nr=${RANDOM};
        word=${nameArray[$random_nr]}
    done
}

chooseWordLength() {
    wordLengthZero=${#word}
    wordLength=$((wordLengthZero+1))
}


result() {
    for i in $(seq 1 $wordLength); do
        if [[ $i -ne $wordLength ]]; then
            position=$((i-1))
            if [[ ${word:position:1} == $userInput ]]; then
                correctCounter=$((correctCounter+1))
                correctLetters[$correctCounter]=$userInput

                continueGame
            fi
        fi
    done

    echo "sorry you're wrong"

    mistakes=$((mistakes+1))
    mistakeLetters[$mistakes]=$userInput
}

displayMmessage() {
  echo " *** Let's find word *** "
}

showEmptyChar() {
    notGuessed=0
    for i in $(seq 1 $wordLength); do
        if [[ $i -ne $wordLength ]]; then
            position=$((i-1))
            alreadyGuessed
            if [[ $found -eq 1 ]]; then
                echo -n ${word:position:1}
            else
                notGuessed=$((notGuessed+1))
                echo -n "-"
            fi
        fi
    done
    echo
    echo
}

alreadyGuessed() {
    found=0
    for i in "${correctLetters[@]}"
    do
        if [ "$i" == "${word:position:1}" ] ; then
            found=1
        fi
    done
}

displayAskLetter() {
    if [[ $notGuessed == 0 ]]; then
        echo "***************   YOU WON   **************"
		congratulation
        exit
    fi
    read -sn 1 userInput
    echo
}

showMistakes() {
    if [[ $mistakes -lt 7 ]]; then
        for i in $(seq 1 ${#mistakeLetters[@]}); do
            if [[ $mistakes -eq 1 ]]; then
                MMistakes=""
            else
                MMistakes="s"
            fi

            if [[ $i -eq 1 ]]; then
                echo -n "wrong ($mistakes) "
				echo -n "letter$MMistakes: "
                echo -n ${mistakeLetters[$i]}
            else
                echo -n ", ${mistakeLetters[$i]}"
            fi
        done
        echo
    else
        endGame
    fi
}

display_correctLetters() {
    if [[ $mistakes -lt 7 ]] && [[ $correctCounter -lt $wordLength ]]; then
        for i in $(seq 1 ${#correctLetters[@]}); do
            if [[ $correctCounter -eq 1 ]]; then
                more_correct_than_one=""
            else
                more_correct__than_one="s"
            fi

            if [[ $i -eq 1 ]]; then
                echo -n "right ($correctCounter) letter$more_correct_than_one: "
                echo -n ${correctLetters[$i]}
            else
                echo -n ", ${correctLetters[$i]}"
            fi
        done
        echo
        echo
    else
        endGame
    fi
}

continueGame() {
    showMistakes
    display_correctLetters
    geussCounter=$((geussCounter+1))
    hangMan
}

endGame() {
    echo "sorry you've lost"
	gameOver
    exit
}

getFGuess() {
    fGuess=1

    for letter in "${correctLetters[@]}"
    do
        if [ "$letter" == "$userInput" ] ; then
            fGuess=0
        fi
    done

    for letter in "${mistakeLetters[@]}"
    do
        if [ "$letter" == "$userInput" ] ; then
            fGuess=0
        fi
    done
}

hangMan() {
  
    showEmptyChar
    displayAskLetter
 
    getFGuess
    if [[ $fGuess -eq 1 ]]; then
        result
    fi

    continueGame
}

chooseWord
chooseWordLength
displayMmessage
hangMan