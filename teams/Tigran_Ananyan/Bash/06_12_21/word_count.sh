#!/bin/bash
read -p "word=" a
read -p "text=" b
grep -o $a <<<"$b" | wc -w
