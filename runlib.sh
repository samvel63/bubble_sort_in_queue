#!/bin/bash

if [ -f run ]
	then
	rm run
fi
make lib
gcc main.c -L. lib/libqueue.a -o run
./run