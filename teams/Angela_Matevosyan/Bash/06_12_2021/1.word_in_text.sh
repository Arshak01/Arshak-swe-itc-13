#!/bin/bash
echo "Enter your text: "
read text
echo "Enter the word: "
read word
grep --only-matching $word <<< $text | wc -w
