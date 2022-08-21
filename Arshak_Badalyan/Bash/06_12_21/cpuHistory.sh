#!/bin/bash

echo " Find the highest 10  processing " 
# Only work Linux -> echo "$( ps -Ao user,uid,comm,pid,pcpu,tty --sort=-pcpu | head -n 10)"
ps -A | head -n 10
echo "--------------------------"
ps -aux | less  | head -n 10



