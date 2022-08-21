#!/bin/bash
lock="Desktop/*.temp"
if [ -f "$lock" ];
then
rm $lock;
fi
