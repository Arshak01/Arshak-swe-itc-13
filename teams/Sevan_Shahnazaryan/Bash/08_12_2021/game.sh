#!/bin/bash

want=1


while (( $want == 1 ))
do
	easy=(1 8 15 22 29 36 43 50 57 64)
	medium=(71 78 85 92 99 106 113 120 127 134)
	hard=(141 148 155 162 169 176 183 190 197 204)
	quo=1
	money=250
	win=1


	while (( $money < 256000 && $win == 1))
	do



        #EASY LEVEL
        question=0
		while (( $money < 4000 && $win == 1 ))
		do
			line=0

			while (( $line == 0 ))
			do
				randomQuo=$(( $RANDOM % 9 + 0 ))
				line=${easy[$randomQuo]}
			done

			easy[$randomQuo]=0
			firstLine=`sed -n "${line}p" < questions.txt`
			((line++))
			correctAnswer=${firstLine:4:5}
			question=`sed -n "${line} p" < questions.txt`
			((line++))
			A=`sed -n "${line}p" < questions.txt`
			((line++))
			B=`sed -n "${line}p" < questions.txt`
			((line++))
			C=`sed -n "${line}p" < questions.txt`
			((line++))
			D=`sed -n "${line}p" < questions.txt`
			clear
			echo "LEVEL $quo:           		                             $money$ :MONEY"
			echo "Difficulty: Easy"
			printf "\n"
			echo $question

			select item in "${A[@]}" "${B[@]}" "${C[@]}" "${D[@]}"
			do
				printf "\n"
				if (( $REPLY == $correctAnswer ))
				then
					((money=money*2))
					echo "CONGRATULATIONS!"
					sleep 1
					echo "You've won $ $money"
					sleep 2
					((quo++))
					break
				else
					echo "You lost with $ $money"
					sleep 2
					win=0
					break
				fi
			done
		done



        #MEDIUM LEVEL
        question=0
        while (( $money < 64000 && $win == 1 ))
        do
            line=0
            echo win = $win

            while (( $line == 0 ))
            do
                randomQuo=$(( $RANDOM % 9 + 0 ))
                line=${medium[$randomQuo]}
            done

            medium[$randomQuo]=0
            firstLine=`sed -n "${line}p" < questions.txt`
            ((line++))
            correctAnswer=${firstLine:4:5}
            question=`sed -n "${line} p" < questions.txt`
            ((line++))
            A=`sed -n "${line}p" < questions.txt`
            ((line++))
            B=`sed -n "${line}p" < questions.txt`
            ((line++))
            C=`sed -n "${line}p" < questions.txt`
            ((line++))
            D=`sed -n "${line}p" < questions.txt`
            clear
            echo "LEVEL $quo:                                                $money$ :MONEY"
            echo "Difficulty: Medium"
            printf "\n"
            echo $question

            select item in "${A[@]}" "${B[@]}" "${C[@]}" "${D[@]}"
            do
                printf "\n"
                if (( $REPLY == $correctAnswer ))
                then
                    ((money=money*2))
                    echo "CONGRATULATIONS!"
                    sleep 1
                    echo "You've won $ $money"
                    sleep 2
                    ((quo++))
                    break
                else
                    echo "You lost with $ $money"
                    sleep 2
                    win=0
                    break
                fi
            done
        done



		#HARD LEVEL
		question=0
        while (( $money < 256000 && $win == 1 ))
        do
            line=0
            echo win = $win

            while (( $line == 0 ))
            do
                randomQuo=$(( $RANDOM % 9 + 0 ))
                line=${hard[$randomQuo]}
            done

            hard[$randomQuo]=0
            firstLine=`sed -n "${line}p" < questions.txt`
            ((line++))
            correctAnswer=${firstLine:4:5}
            question=`sed -n "${line} p" < questions.txt`
            ((line++))
            A=`sed -n "${line}p" < questions.txt`
            ((line++))
            B=`sed -n "${line}p" < questions.txt`
            ((line++))
            C=`sed -n "${line}p" < questions.txt`
            ((line++))
            D=`sed -n "${line}p" < questions.txt`
            clear
            echo "LEVEL $quo:                                                $money$ :MONEY"
            echo "Difficulty: Hard"
            printf "\n"
            echo $question

            select item in "${A[@]}" "${B[@]}" "${C[@]}" "${D[@]}"
            do
                printf "\n"
                if (( $REPLY == $correctAnswer ))
                then
                    ((money=money*2))
                    echo "CONGRATULATIONS!"
                    sleep 1
                    echo "You've won $ $money"
                    sleep 2
                    ((quo++))
                    break
                else
                    echo "You lost with $ $money"
                    sleep 2
                    win=0
                    break
                fi
            done
        done
	done



	#WIN
	if (( $money == 256000 ))
    then
    	echo !!!YOU WON $ 256000 PLUS BONUS PRIZE!!!
		sleep 1
        echo ONE MILLION DOLLARS!
		sleep 1
	fi



	#PLAY AGAIN
	echo "Would you like to play again? "
	    select item in Yes No
        do
        	if (( $REPLY == 2 ))
        	then
            	want=0
        		break
        	else
            	want=1
            	break
        	fi
        done
done
