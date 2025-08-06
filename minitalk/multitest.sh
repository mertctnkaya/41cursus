#!/bin/bash

# This script is used to test multi client communication with server in the minitalk project.
PID=$(ps -e | grep server_bonus | awk '{print $4}')

./client_bonus $PID "Client1 Message 😁"
./client_bonus $PID "Client2 Message 😁"
./client_bonus $PID "Client3 Message 😁"
./client_bonus $PID "Client4 Message 😁"

wait
