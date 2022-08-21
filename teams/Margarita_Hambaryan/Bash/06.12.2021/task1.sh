#! /bin/bash

# getting the name of word
read -p "Input the word, please: " word

# getting the full text
read -p "Input the text, please: " text

echo "The count of word '$word' in this text '$text' is: " 

# giving the count of words in a text
grep --only-matching $word <<< $text | wc -w 

echo $count
