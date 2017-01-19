#!/bin/bash
#The following lines plot the data generated using gnuplot
rm -rf Jacobi2.dat
rm -rf Jacobi2.pdf
g++ -o Jacobi2 Jacobi2.cpp
./Jacobi2
gnuplot <<EOF
set terminal postscript color
set key off
set output "Jacobi2.ps"
set size square

set title "Jacobi method to find potential of sphere within parallel plates"
set ylabel "x"
set xlabel "y"
set zlabel "z"
set pm3d map
set palette rgbformulae 20,21,32

splot "Jacobi2.dat" using 1:2:3 with pm3d title "Jacobi"

EOF

ps2pdf14 Jacobi2.ps
rm -rf Jacobi2.ps
exit 0 
