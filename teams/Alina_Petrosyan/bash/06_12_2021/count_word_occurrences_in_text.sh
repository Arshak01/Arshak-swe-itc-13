#! /bin/bash
read -p "Type the word: " word
read -p "Type the text: " text
echo $text > text.txt
grep -o $word text.txt | wc -w
