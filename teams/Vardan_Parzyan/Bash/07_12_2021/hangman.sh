echo    " #     #    #    #     #  #####  #     #    #    #     #"
echo    " #     #   # #   ##    # #     # ##   ##   # #   ##    #"
echo    " #     #  #   #  # #   # #       # # # #  #   #  # #   #"
echo    " ####### #     # #  #  # #  #### #  #  # #     # #  #  #"
echo    " #     # ####### #   # # #     # #     # ####### #   # #"
echo    " #     # #     # #    ## #     # #     # #     # #    ##"
echo    " #     # #     # #     #  #####  #     # #     # #     #"
    
    
    
arr=( apple horse pencil shark tiger ring )
word=${arr[ $RANDOM % ${#arr[@]}]}
count=0
array=( `echo $word | grep -o . ` )
echo ${array[@]}

echo "Enter the character you want"
while(( $count <= 5 ))
do
	
read char
if [[ " ${array[@]} " =~ " ${char} " ]] 
	then
charArray+=$char
character=$charArray
character=( `echo $charArray | grep -o . ` )
(( count+=1 ))
echo "Correct character"
echo  ${charArray[@]}
echo "Enter the next one ;)"
	
	elif [[ "${array[@]}" != " ${char} " ]]
then 
echo "Wrong character!"
(( count+=1 ))
echo  ${charArray[@]}



elif [[ ${array[!]}  ==  ${character[!]}  ]];
	then 
echo "You WIN. Now you're free bird. You can fly away"
break
fi
 
done

if (( $count > 5 ))
then
echo "You lose, the word was '$word'"
echo
echo "$USER             "
    echo "     RIP__________    "
    echo "         |        |   "
    echo "         O        |   "
    echo "        /|\       |   "
    echo "        / \       |   "
    echo "    ______________|___"
    echo
fi
echo  ${character[@]}
echo  ${array[@]}
