#!/bin/bash

# get the maximum value of a process ID
max_pid=$(cat /proc/sys/kernel/pid_max)

# print the maximum value of a process ID
echo "The maximum value of a process ID is $max_pid"