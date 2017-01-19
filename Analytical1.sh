#!/bin/bash

gnuplot<<EOF

set terminal postscript color
set view map

set title “Analytical Solution of two Concentric Cylinders”
set xlabel 'x'
set ylabel 'y'
set size square 1,1

set pm3d map
splot "Analytical1.dat" using 1:2:4 with pm3d
set output "analytical.ps"
replot
save "analytical.plt"
quit

EOF

ps2pdf14 analytical.ps
