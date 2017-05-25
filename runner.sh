#! /bin/bash

if [ "$#" -ne 1 ]; then
    echo "Illegal number of parameters"
    exit
fi
	g++ run.cpp
	./a.out $1 < ./input/input
	rm a.out