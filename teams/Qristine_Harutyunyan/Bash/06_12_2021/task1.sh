#!/bin/bash
read -p "text: " text
read -p "word from text: " word

echo $text |  grep -o -i $word | wc - 1
