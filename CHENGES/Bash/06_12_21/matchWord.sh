#!/bin/bash

read -p "Pattern : " pattern
read -p "Text : " text
echo $text > `pwd`/text.txt
grep -o $pattern `pwd`/text.txt | wc -l

