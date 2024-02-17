#!/bin/bash

if [ -n "$1" ]; then
    command=$1
fi

if [ -n "$2" ]; then
    numClients=$2
fi


if [ "$command" = "add" ]; then
    for i in $(seq 1 $numClients);
    do
        sudo ip addr add 10.0.0.$i/8 brd + dev lo label lo:$i
    done
    sudo ip addr add 10.1.0.1/8 brd + dev lo label lo:srv
elif [ "$command" = "del" ]; then
    for i in $(seq 1 $numClients);
    do
        sudo ip addr del 10.0.0.$i/8 dev lo
    done
    sudo ip addr del 10.1.0.1/8 dev lo
else
    echo "Invalid first argument. Please use 'add' or 'del'."
fi