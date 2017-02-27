#!/bin/bash

rm -rf $1.png

gnuplot <<EOF
set terminal png  
set key off
set output "$1.png"
set palette rgbformulae 30,13,10
set contour base
set cntrparam bspline
set cntrparam levels auto 20
unset surface
set table "cont.dat"
splot "$1"
unset table
set xlabel "x"
set ylabel "y"
set title "Potential of system using the ${1:1} method"
plot  "$1" with image, "cont.dat" with lines linetype -1
  
EOF
    
rm -rf cont.dat
rm -rf $1
