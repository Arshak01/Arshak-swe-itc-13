#! /bin/bash

ps --sort -%cpu -eo %cpu | head -n 11
