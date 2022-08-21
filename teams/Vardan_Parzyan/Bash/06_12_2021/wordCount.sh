#!/bin/bash
read -p "Please enter the text and press ENTER " text
echo "__________________________________________"
read -p "Enter the word which you want to search " word
echo "__________________________________________"
echo $text >|archive
grep --only-matching --ignore-case --regexp="\b$word\b" archive | wc -l
rm archive
