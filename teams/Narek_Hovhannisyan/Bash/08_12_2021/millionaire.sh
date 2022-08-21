#!/bin/bash

clear
echo
echo "The game is starting. There are 10 questinos and every question has 4 options. Your task is to chose the right answer"
echo

questionNumber=1

questionsForLowLevel=($(shuf -i 1-6 -n 4))

for ((i = 0; i < ${#questionsForLowLevel[@]}; i++)); do
  currentQuestionNumber="${questionsForLowLevel[$i]}"
  currentQuestion=$(cat $currentQuestionNumber | head -n 1 | tail -1)
  currentAnswersString=$(cat $currentQuestionNumber | head -n 2 | tail -1)
  currentRightAnswer=$(cat $currentQuestionNumber | head -n 3 | tail -1)
  IFS=': ' read -r -a currentAnswersArray <<<"$currentAnswersString"

  echo "Question $questionNumber."
  ((questionNumber++))
  echo "$currentQuestion"
  echo

  select answer in "${currentAnswersArray[@]}"; do
    echo "$answer"
    break
  done

  if [[ $answer != "$currentRightAnswer" ]]; then
    echo "Fail. The right answer was '$currentRightAnswer'"
    echo "You can play again, or exit"

    echo
    select choise in Exit PlayAgain; do
      if [[ $choise == "Exit" ]]; then
        exit
      else
        source $0
      fi
      break
    done

    break
  fi

  echo "---------------------------***---------------------------"

done

questionsForMidLevel=($(shuf -i 7-12 -n 4))

for ((i = 0; i < ${#questionsForMidLevel[@]}; i++)); do
  currentQuestionNumber="${questionsForMidLevel[$i]}"
  currentQuestion=$(cat $currentQuestionNumber | head -n 1 | tail -1)
  currentAnswersString=$(cat $currentQuestionNumber | head -n 2 | tail -1)
  currentRightAnswer=$(cat $currentQuestionNumber | head -n 3 | tail -1)
  IFS=': ' read -r -a currentAnswersArray <<<"$currentAnswersString"

  echo "Question $questionNumber."
  ((questionNumber++))
  echo "$currentQuestion"

  echo

  select answer in "${currentAnswersArray[@]}"; do
    echo "$answer"
    break
  done

  if [[ $answer != "$currentRightAnswer" ]]; then
    echo "Fail. The right answer was '$currentRightAnswer'"
    echo "You can play again, or exit"

    echo
    select choise in Exit PlayAgain; do
      if [[ $choise == "Exit" ]]; then
        exit
      else
        source $0
      fi
      break
    done

    break
  fi

  echo "---------------------------***---------------------------"

done

questionsForHighLevel=($(shuf -i 13-15 -n 2))

for ((i = 0; i < ${#questionsForHighLevel[@]}; i++)); do
  currentQuestionNumber="${questionsForHighLevel[$i]}"
  currentQuestion=$(cat $currentQuestionNumber | head -n 1 | tail -1)
  currentAnswersString=$(cat $currentQuestionNumber | head -n 2 | tail -1)
  currentRightAnswer=$(cat $currentQuestionNumber | head -n 3 | tail -1)
  IFS=': ' read -r -a currentAnswersArray <<<"$currentAnswersString"

  echo "Question $questionNumber."
  ((questionNumber++))
  echo "$currentQuestion"

  echo "$currentRightAnswer"

  echo

  select answer in "${currentAnswersArray[@]}"; do
    echo "$answer"
    break
  done

  if [[ $answer != "$currentRightAnswer" ]]; then
    echo "Fail. The right answer was '$currentRightAnswer'"
    echo "You can play again, or exit"

    echo
    select choise in Exit PlayAgain; do
      if [[ $choise == "Exit" ]]; then
        exit
      else
        source $0
      fi
      break
    done

    break
  fi

  echo "Congratulations you have won the game!!!"

  echo "---------------------------***---------------------------"

done
