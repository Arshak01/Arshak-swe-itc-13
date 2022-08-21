#!/bin/bash

read -p "type the text: " text
read -p "type the pattern: " pattern
echo $text >| findingSource

grep --only-matching --ignore-case --regexp="\b$pattern\b" findingSource | wc -l
#\b word boundary
