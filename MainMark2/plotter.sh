#!/bin/bash

gnuplot <<EOF
set terminal postscript color
set key off
set output "$1.ps"
set palette rgbformulae 30,13,10

set contour base
set cntrparam bspline
set cntrparam levels auto 20
unset surface
set table "cont.dat"
splot "$1.dat"
unset table

set title "Potential of system using the $1 method"
set xlabel "x"
set ylabel "y"
plot "$1.dat" with image, "cont.dat" with lines linetype -1
EOF

ps2pdf $1.ps
rm -rf $1.ps
rm -rf cont.dat
rm -rf $1.dat
