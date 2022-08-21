#! /bin/bash
ps -eo uid,pid,%cpu,cmd | sort -rk 3 | head
