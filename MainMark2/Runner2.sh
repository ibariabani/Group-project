#!/bin/bash

if [ -e "GS.dat" ]     #The next few lines removes any old data file to stop any overwriting etc
then
rm GS.dat
fi

if [ -e "Jacobi.dat" ]
then
rm Jacobi.dat
fi

if [ -e "SOR.dat" ]
then
rm SOR.dat
fi

if [ -e "GS1.dat" ]
then
rm GS1.dat
rm Analytical1.dat
fi

if [ -e "GS2.dat" ]
then
rm GS2.dat
rm Analytical2.dat
fi



make                    # Makes the main program using the makefile

./Main                  #Runs the main function

if [ -e "GS1.dat" ]     #If this data file exists then the user has run the 1st example, gnuplots appropriate data
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

splot "GS1.dat" using 1:2:3 with pm3d title "Gauss-Siedel solution"
splot "Analytical1.dat" using 1:2:4 with pm3d title "Analytical solution"

EOF

ps2pdf14 Problem1.ps      #converts to pdf
rm -rf Problem1.ps        #removes ps file
rm GS1.dat                #removes data files
rm Analytical1.dat
fi

if [ -e "GS2.dat" ]  #If this data file exists then the user has run the 2nd example, gnuplots appropriate data
then
gnuplot <<EOF
set terminal postscript color
set key off
set output "Problem2.ps"
set size square

set title "Potential between two parrallel plates with a sphere at the centre"
set xlabel "x"
set ylabel "y"
set zlabel "z"
set pm3d scansforward
set palette rgbformulae 30,31,32

splot "GS2.dat" using 1:2:3 with pm3d title "Gauss-Siedel solution"
splot "Analytical2.dat" using 1:2:3 with pm3d title "Analytical solution"

EOF

ps2pdf14 Problem2.ps         #Converts ps file to pdf
rm -rf Problem2.ps           #Removes data files an ps file
rm GS2.dat
rm Analytical2.dat
fi

if [ -e "GS.dat" ]         #After the Main function has run, if the Gauss data file exists then plot it
then                       #The next few lines are all GNUPLOT commands to give a graph
./plotter.sh GS
fi

if [ -e "Jacobi.dat" ]             #If the Jacobi data file exists then then these lines plot it using gnuplot
then                               #The following are all gnuplot commands 
./plotter.sh Jacobi
fi


if [ -e "SOR.dat" ]             #If the Jacobi data file exists then then these lines plot it using gnuplot
then                               #The following are all gnuplot commands 
./plotter.sh SOR
fi


if [[ -e "Jacobidiff.dat" && -e "Gaussdiff.dat" && -e "SORdiff.dat" ]]
then
gnuplot <<EOF
set terminal postscript color
set logscale xy
set output "diffplot.ps"
plot "Jacobidiff.dat" with lines, "Gaussdiff.dat" with lines, "SORdiff.dat" with lines

EOF

ps2pdf14 diffplot.ps
rm -rf diffplot.ps
rm Jacobidiff.dat
rm Gaussdiff.dat
rm SORdiff.dat
fi

exit 0
