#!/bin/bash

lock="~/Desktope/*.txt"
if [ -f "$lock" ];
then
	rm $lock;
fi
