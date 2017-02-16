#!/bin/bash

g++ -o sortvec sortvec.cpp
chmod 755 ./sortvec
./sortvec $1 $2

gnuplot <<EOF
set terminal postscript color
set key off
set output "plotvec.ps"
set palette rgbformulae 30,13,10

set xlabel "x"
set ylabel "y"
set title "Potential of system using the $1 method"

plot "plotvec.dat" with vectors lc palette lw 2
EOF

gs -o EFields.pdf -sDEVICE=pdfwrite EFields.ps plotvec.ps >&-
pdf2ps EFields.pdf >&-

rm -rf plotvec.ps
rm -rf plotvec.dat
rm -rf $1
