#!/bin/bash

if [ -e "Analytical2.dat" ]
then
rm Analytical2.dat
fi

g++ -o Analytical2 Analytical2.cpp

./Analytical2 <<EOF
1
EOF

gnuplot <<EOF
set terminal postscript color eps
set key off
set output "Analytical2.eps"
set size square
set title "Analytical solution of potential of sphere within parallel plates"
set ylabel "x"
set xlabel "y"
set zlabel "z"
set pm3d map
splot "Analytical2.dat" using 1:2:3 with pm3d
EOF
