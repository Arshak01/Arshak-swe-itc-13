#!/bin/bash

printf "%s" "%CPU    PID  USER        PPID CMD			   %MEM"
printf "\n"
ps -eo %cpu,pid,user,ppid,cmd,%mem,| sort -nr | head -11
