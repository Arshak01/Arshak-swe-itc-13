#!/bin/bash

arr=("beauty" "language" "beyond" "changing" "corner" "couple" "energy" "handle" "person" "safety" "spirit" "learning" "meaning" "winner" "theory" "expand")

word=${arr[ $RANDOM % ${#arr[@]} ]}

attempts=0

while(( $attempts <= 5 ))
do
    read -p "type a character: " character
    if [[ $word =~ $character && ${#character} == 1 ]]
        then
            echo "The word was '$word'. you won, you are free!"
            break
    fi
    (( attempts+=1 ))
done

if (( $attempts > 5 ))
then echo "The word was '$word'. you lost, hang up!"
fi