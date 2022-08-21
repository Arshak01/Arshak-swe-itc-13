#! /bin/bash
echo " Max CPU LOAD processes" & ps -eo pid,cmd,%cpu --sort=-%cpu |head -10
