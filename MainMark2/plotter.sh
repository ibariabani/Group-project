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
splot "$1"
unset table

set xlabel "x"
set ylabel "y"

set title "Potential of system using the $1 method"
plot "$1" with image, "cont.dat" with lines linetype -1 
  
EOF

gs -o Results.pdf -sDEVICE=pdfwrite Results.ps $1.ps >&-
pdf2ps Results.pdf >&-
rm -rf $1.ps
rm -rf cont.dat
rm -rf $1
