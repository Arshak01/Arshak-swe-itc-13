#!/bin/bash

ps -eo user,pid,pcpu --sort=-pcpu | head -n 11
