#!/bin/bash

if [ -e "Analytical2.dat" ]
then
rm Analytical2.dat
fi

if [ -e "Jacobi2.dat" ]
then
rm Jacobi2.dat
fi

if [ -e "Analytical1.dat" ]
then
rm Analytical1.dat
fi

if [ -e "Jacobi1.dat" ]
then
rm Jacobi1.dat
fi

make

./Main


if [ -e "Analytical2.dat" ]
then
gnuplot <<EOF
set terminal postscript color eps
set output "Problem2.ps"
set size square
set title "Potential of system with grounded cylinder within parallel plates"
set xlabel "x"
set ylabel "y"
set zlabel "z"
set pm3d scansforward
splot "Jacobi2.dat" using 1:2:3 with pm3d title "Jacobi"
splot "Analytical2.dat" using 1:2:3 with pm3d title "Analytical"
EOF

ps2pdf Problem2.ps
rm -rf Problem2.ps
fi

if [ -e "Analytical1.dat" ]
then
gnuplot <<EOF
set terminal postscript color
set key off
set output "Problem1.ps"
set size square

set title "Jacobi method to find potential"
set xlabel "x"
set ylabel "y"
set zlabel "z"
set pm3d scansforward
set palette rgbformulae 30,31,32

splot "Jacobi1.dat" using 1:2:3 with pm3d title "Jacobi"
splot "Analytical1.dat" using 1:2:4 with pm3d title "Analytical"

EOF

ps2pdf14 Problem1.ps
rm -rf Problem1.ps
fi

exit 0
