#!/bin/bash
 ps -eo pid,ppid,cmd,%cpu,%mem --sort=-%cpu | head
