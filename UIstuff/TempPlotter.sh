#!/bin/bash

#rm -rf Results.ps
#rm -rf Results.pdf
#touch Results.ps
for file in "$@"; do
rm -rf $file.png
    gnuplot <<EOF
set terminal png  
set key off
set output "$file.png"
set palette rgbformulae 30,13,10
set contour base
set cntrparam bspline
set cntrparam levels auto 20
unset surface
set table "cont.dat"
splot "$file"
unset table
set xlabel "x"
set ylabel "y"
set title "Potential of system using the $file method"
plot  "$file" with image, "cont.dat" with lines linetype -1 
  
EOF
    
    rm -rf cont.dat
    #rm -rf $file
done
rm -rf Results.ps
