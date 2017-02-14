#!/bin/bash
gnuplot <<EOF
set terminal postscript color
set key off
set output "Results.ps"
set palette rgbformulae 30,13,10

set contour base
set cntrparam bspline
set cntrparam levels auto 20
unset surface
set table "cont1.dat"
splot "$1.dat"
unset table

set table "cont2.dat"
splot "$2.dat"
unset table

set table "cont3.dat"
splot "$3.dat"
unset table

set table "cont4.dat"
splot "$4.dat"
unset table

set table "cont5.dat"
splot "$5.dat"
unset table

set xlabel "x"
set ylabel "y"

set title "Potential of system using the $1 method"
plot "$1.dat" with image, "cont1.dat" with lines linetype -1 

set title "Potential of system using the $2 method"
plot "$2.dat" with image, "cont2.dat" with lines linetype -1  

set title "Potential of system using the $3 method"
plot "$3.dat" with image, "cont3.dat" with lines linetype -1

set title "Analytical solution to problem 1"
plot "$4.dat" with image, "cont4.dat" with lines linetype -1  

set title "Analytical solution to problem 2"
plot "$5.dat" with image, "cont5.dat" with lines linetype -1    
EOF

ps2pdf Results.ps
rm -rf Results.ps
rm -rf cont1.dat
rm -rf cont2.dat
rm -rf cont3.dat
rm -rf cont4.dat
rm -rf cont5.dat
rm -rf $2.dat
rm -rf $3.dat
rm -rf $1.dat
rm -rf $4.dat
rm -rf $5.dat
