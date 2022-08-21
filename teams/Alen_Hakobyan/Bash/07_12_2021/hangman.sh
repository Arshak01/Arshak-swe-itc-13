#!/bin/bash

function wrong1 {
    echo
    echo "        O             "
    echo
    echo
    echo
    echo
    echo
    echo
}
function wrong2 {
    echo
    echo "         O            "
    echo "         |            "
    echo
    echo
    echo
    echo
    echo
}
function wrong3 {
    echo
    echo "         O            "
    echo "         |\           "
    echo
    echo
    echo
    echo
    echo
}
function wrong4 {
    echo
    echo "         O            "
    echo "        /|\           "
    echo
    echo
    echo
    echo
    echo
}
function wrong5 {
    echo
    echo "         O            "
    echo "        /|\           "
    echo "        /             "
    echo
    echo
    echo
    echo
}
function wrong6 {
    echo
    echo "         __________   "
    echo "         |        |   "
    echo "         O        |   "
    echo "        /|\       |   "
    echo "        / \       |   "
    echo "    ______________|___"
    echo
}

function correct {
    echo
    echo "          O            "
    echo "         \|\           "
    echo "          /\           "
    echo
    echo
    echo
    echo
}






words=("twiter" "facebook" "myspace" "youtube" "amazon" "instagram" "zona" "telegram" "google" "linux")

#words[1]="twitter"
#words[2]="facebook"
#words[3]="myspace"
#words[4]="youtube"
#words[5]="amazon"
random_nr=6
correct_letters[1]=""
mistake_letters[1]=""
imploded_letters[1]=""
geuss_counter=1
correct_counter=0
mistakes=0
place=1

# setters
set_word() {
    until [[ $random_nr -lt 6 ]] && [[ $random_nr -gt 0 ]]; do 
        random_nr=${RANDOM};
        word=${words[$random_nr]}
    done
}

set_word_length() {
    word_length_incl_zero=${#word}
    word_length=$((word_length_incl_zero+1))
}

# views
display_result() {
    for i in $(seq 1 $word_length); do
        if [[ $i -ne $word_length ]]; then
            position=$((i-1))
            if [[ ${word:position:1} == $user_input ]]; then
                correct_counter=$((correct_counter+1))
                correct_letters[$correct_counter]=$user_input

                continue_game
            fi
        fi
    done

    echo "sorry you're wrong"

    mistakes=$((mistakes+1))
    mistake_letters[$mistakes]=$user_input
}

display_welcome_message() {
   
    echo
    echo "Hello, so happy to see you playing hangman game"
    echo "Basicly you need to guess every letter of the word below"
    echo "Before things go badly with the guy on the left"
    echo
}

display_dashes() {
    letters_not_guessed=0
    for i in $(seq 1 $word_length); do
        if [[ $i -ne $word_length ]]; then
            position=$((i-1))
            check_if_already_guessed
            if [[ $found -eq 1 ]]; then
                echo -n ${word:position:1}
            else
                letters_not_guessed=$((letters_not_guessed+1))
                echo -n "-"
            fi
        fi
    done
    echo
    echo
}

check_if_already_guessed() {
    found=0
    for i in "${correct_letters[@]}"
    do
        if [ "$i" == "${word:position:1}" ] ; then
            found=1
        fi
    done
}

display_asking_for_a_letter() {
    if [[ $letters_not_guessed == 0 ]]; then
        echo "you've won"
	correct
        exit
    fi
    read -sn 1 user_input
    echo
}

display_mistakes() {
    if [[ $mistakes -lt 6 ]]; then
    	    for i in $(seq 1 ${#mistake_letters[@]}); do
            if [[ $mistakes -eq 1 ]]; then
	     	more_mistakes_than_one=""
            else
                more_mistakes_than_one="s"
            fi

            if [[ $i -eq 1 ]]; then	    
                echo -n "wrong ($mistakes) letter$more_mistakes_than_one: "
                echo -n ${mistake_letters[$i]}
            else
                echo -n ", ${mistake_letters[$i]}"
            fi
        done
        echo
    else
        end_game
    fi
}

display_correct_letters() {
    if [[ $mistakes -lt 6 ]] && [[ $correct_counter -lt $word_length ]]; then
        for i in $(seq 1 ${#correct_letters[@]}); do
            if [[ $correct_counter -eq 1 ]]; then
                more_correct_than_one=""
            else
                more_correct__than_one="s"
            fi

            if [[ $i -eq 1 ]]; then
                echo -n "right ($correct_counter) letter$more_correct_than_one: "
                echo -n ${correct_letters[$i]}
            else
                echo -n ", ${correct_letters[$i]}"
            fi
        done
        echo
        echo
    else
        end_game
    fi
}

continue_game() {
    display_mistakes
    display_correct_letters
    geuss_counter=$((geuss_counter+1))
    main
}

end_game() {
    echo "sorry you've lost"
    	wrong1
	wrong2 
	wrong3 
	wrong4 
	wrong5 
	wrong6 
	wrong7
    exit
}

get_first_time_guess() {
    first_time_guess=1

    for letter in "${correct_letters[@]}"
    do
        if [ "$letter" == "$user_input" ] ; then
            first_time_guess=0
        fi
    done

    for letter in "${mistake_letters[@]}"
    do
        if [ "$letter" == "$user_input" ] ; then
            first_time_guess=0
        fi
    done
}

main() {
    #visuals
    display_dashes
    display_asking_for_a_letter

    #if this letter is already guessed the user
    #shouldnt be penalized for it
    get_first_time_guess
    if [[ $first_time_guess -eq 1 ]]; then
        display_result
    fi

    continue_game
}

set_word
set_word_length
display_welcome_message
main
