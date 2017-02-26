#!/bin/bash

gnuplot <<EOF
set terminal pngcairo size 1024,768
set key off
set output "$1.png"
set palette rgbformulae 30,13,10
set xlabel "x"
set ylabel "y"
set title "Electric field of system using the $1 method"
plot "plotvec.dat" with vectors lc palette lw 2
EOF
     
   
rm -rf plotvec.dat
rm -rf $1  
