#!/bin/bash/
ps -eo pid,user,%cpu --sort=-%cpu | head
