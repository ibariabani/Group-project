#!/bin/bash

make                    # Makes the main program using the makefile
clear
./Main | tee temp      #Runs the main function
size=$(tail -n 1 temp)
rm -rf temp

./plotter.sh

./plotvec.sh $size

./plotdiff.sh

exit 0
