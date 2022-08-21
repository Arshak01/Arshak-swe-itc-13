#!/bin/bash

echo "Question 1."
question1="In the UK, the abbreviation NHS stands for National what Service?"
rightAnswer="Health"
echo "$question1"

select item in Humanity Health Honour Household; do
  echo "Your answer is ${item}"
  break
done

if [[ ${item} == "Health" ]]; then
  echo "It is the right answer"
else
  echo "The right answer was ${rightAnswer}"
  echo "You have lost..."
  sleep 3
  exit
fi

echo

echo "Question 2."
question2="Which Disney character famously leaves a glass slipper behind at a royal ball?"
rightAnswer="Cinderella"
echo "$question2"

select item in Pocahontas "Sleeping Beauty" Cinderella Elsa; do
  echo "Your answer is ${item}"
  break
done

if [[ ${item} == "Cinderella" ]]; then
  echo "It is the right answer"
else
  echo "The right answer was ${rightAnswer}"
  echo "You have lost..."
  sleep 3
  exit
fi

echo

echo "Question 3."
question3="What name is given to the revolving belt machinery in an airport that delivers checked luggage from the plane to baggage reclaim?"
rightAnswer="Carousel"
echo "$question3"

select item in Hangar Terminal Concourse Carousel; do
  echo "Your answer is ${item}"
  break
done

if [[ ${item} == "Carousel" ]]; then
  echo "It is the right answer"
else
  echo "The right answer was ${rightAnswer}"
  echo "You have lost..."
  sleep 3
  exit
fi

echo

echo "Question 4."
question4="Which of these brands was chiefly associated with the manufacture of household locks?"
rightAnswer="chubb"
echo "$question4"

select item in Phillips Flymo Chubb Ronseal; do
  echo "Your answer is ${item}"
  break
done

if [[ ${item} == "Chubb" ]]; then
  echo "It is the right answer"
else
  echo "The right answer was ${rightAnswer}"
  echo "You have lost..."
  sleep 3
  exit
fi

echo

echo "Question 5."
question5="The hammer and sickle is one of the most recognisable symbols of which political ideology?"
rightAnswer="Communism"
echo "$question5"

select item in Republicanism Communism Conservatism Liberalism; do
  echo "Your answer is ${item}"
  break
done

if [[ ${item} == "Communism" ]]; then
  echo "It is the right answer"
else
  echo "The right answer was ${rightAnswer}"
  echo "You have lost..."
  sleep 3
  exit
fi

echo

echo "Question 6."
question6="Which toys have been marketed with the phrase 'robots in disguise'?"
rightAnswer="Transformers"
echo "$question6"

select item in "Bratz Dolls" "Sylvanian Families" Hatchimals Transformers; do
  echo "Your answer is ${item}"
  break
done

if [[ ${item} == "Transformers" ]]; then
  echo "It is the right answer"
else
  echo "The right answer was ${rightAnswer}"
  echo "You have lost..."
  sleep 3
  exit
fi

echo

echo "Question 7."
question7="What does the word loquacious mean?"
rightAnswer="Chatty"
echo "$question7"

select item in Angry Chatty Beautiful Shy; do
  echo "Your answer is ${item}"
  break
done

if [[ ${item} == "Chatty" ]]; then
  echo "It is the right answer"
else
  echo "The right answer was ${rightAnswer}"
  echo "You have lost..."
  sleep 3
  exit
fi

echo

echo "Question 8."
question8="Obstetrics is a branch of medicine particularly concerned with what?"
rightAnswer="Childbirth"
echo "$question8"

select item in Childbirth "Broken bones" "Heart conditions" "Old age"; do
  echo "Your answer is ${item}"
  break
done

if [[ ${item} == "Childbirth" ]]; then
  echo "It is the right answer"
else
  echo "The right answer was ${rightAnswer}"
  echo "You have lost..."
  sleep 3
  exit
fi

echo

echo "Question 9."
question9="In Doctor Who, what was the signature look of the fourth Doctor, as portrayed by Tom Baker?"
rightAnswer="Wide-brimmed hat and extra long scarf"
echo "$question9"

select item in "Bow-tie, braces and tweed jacket" "Wide-brimmed hat and extra long scarf" "Pinstripe suit and trainers" "Cape, velvet jacket and frilly shirt"; do
  echo "Your answer is ${item}"
  break
done

if [[ ${item} == "Wide-brimmed hat and extra long scarf" ]]; then
  echo "It is the right answer"
else
  echo "The right answer was ${rightAnswer}"
  echo "You have lost..."
  sleep 3
  exit
fi

echo

echo "Question 10."
question10="Which of these religious observances lasts for the shortest period of time during the calendar year?"
rightAnswer="Diwali"
echo "$question10"

select item in Ramadan Diwali Lent Hanukkah; do
  echo "Your answer is ${item}"
  break
done

if [[ ${item} == "Diwali" ]]; then
  echo "It is the right answer"
  echo "You won!!!"
else
  echo "The right answer was ${rightAnswer}"
  echo "You have lost..."
  sleep 3
  exit
fi

echo
