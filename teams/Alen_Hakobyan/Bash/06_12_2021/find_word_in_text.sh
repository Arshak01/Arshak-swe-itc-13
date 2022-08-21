#! /bin/bash

echo "Please write a text"
read a
echo "Please write a word"
read b
echo $a > c.txt
grep -o $b c.txt | wc -w
