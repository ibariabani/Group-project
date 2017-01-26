#!/bin/bash

if [ -e "Analytical2.dat" ]
then
rm Analytical2.dat
fi

if [ -e "GS2.dat" ]
then
rm GS2.dat
fi

if [ -e "Analytical1.dat" ]
then
rm Analytical1.dat
fi

if [ -e "GS1.dat" ]
then
rm GS1.dat
fi

make

./Main


if [ -e "Analytical2.dat" ]
then
gnuplot <<EOF
set terminal postscript color
set output "Problem2.ps"
set size square
set title "Potential of system with grounded cylinder within parallel plates"
set xlabel "x"
set ylabel "y"
set zlabel "z"
set pm3d scansforward
splot "GS2.dat" using 1:2:3 with pm3d title "Gauss-Siedel"
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

set title "Potential in concentric sphere"
set xlabel "x"
set ylabel "y"
set zlabel "z"
set pm3d scansforward
set palette rgbformulae 30,31,32

splot "GS1.dat" using 1:2:3 with pm3d title "Gauss-Siedel"
splot "Analytical1.dat" using 1:2:4 with pm3d title "Analytical"

EOF

ps2pdf14 Problem1.ps
rm -rf Problem1.ps
fi

exit 0
