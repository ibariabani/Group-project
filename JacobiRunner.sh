#!/bin/bash
#The following lines plot the data generated using gnuplot
rm -rf Jacobi1.dat
rm -rf Jacobi1.pdf
g++ -o Jacobi Jacobi.cpp
./Jacobi
gnuplot <<EOF
set terminal postscript color
set key off
set output "Jacobi1.ps"
set size square

set title "Jacobi method to find potential"
set ylabel "x"
set xlabel "y"
set zlabel "z"
set pm3d map
set palette rgbformulae 30,31,32

splot "Jacobi1.dat" using 1:2:3 with pm3d title "Jacobi"

EOF

ps2pdf14 Jacobi1.ps
rm -rf Jacobi1.ps
exit 0 




