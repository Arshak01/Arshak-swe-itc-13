#!/bin/bash

echo "Removing all temporary files from desktop"

# version 1
	find ~/Desktop -type f -name "*.temp"  -exec rm -f {} \;
# version 2
	find ~/Desktop -type f \( -iname "*.temp" \) -delete

echo "Already remove .temp files from desktop"
