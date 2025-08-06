#!/bin/bash
PID="193264"

./client_bonus $PID "Client1 Message" &&
./client_bonus $PID "Client2 Message" &&
./client_bonus $PID "Client3 Message" &&
wait
