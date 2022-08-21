#!/bin/bash
ps -eo %cpu,pid,comm | sort -nr | head -10
