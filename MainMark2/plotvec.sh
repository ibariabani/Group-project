#!/bin/bash

rm -rf EFields.ps
rm -rf EFields.pdf
touch EFields.ps

for file in ./e* #Plots all the e* files containing the E field information
do
    g++ -o sortvec sortvec.cpp
    chmod 755 ./sortvec
    ./sortvec $file $1
    
    gnuplot <<EOF
set terminal postscript color
set key off
set output "plotvec.ps"
set palette rgbformulae 30,13,10

set xlabel "x"
set ylabel "y"
set title "Potential of system using the $file method"

plot "plotvec.dat" with vectors lc palette lw 2
EOF
    
    gs -o EFields.pdf -sDEVICE=pdfwrite EFields.ps plotvec.ps >&-
    pdf2ps EFields.pdf >&-
    
    rm -rf plotvec.ps
    rm -rf plotvec.dat
    rm -rf $file  
done

rm -rf EFields.ps
