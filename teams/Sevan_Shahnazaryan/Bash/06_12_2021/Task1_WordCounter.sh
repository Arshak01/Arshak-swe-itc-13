#!/bin/bash

read -p "Enter a text: " text
read -p "Enter a word: " word

echo $text | grep -o "\<$word\>" | wc -l
