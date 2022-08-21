#!/bin/bash
read -p "Word:" word 
read -p "Text:" text
echo "$text" | grep -o -w  $word | wc -w
