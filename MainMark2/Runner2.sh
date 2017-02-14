#!/bin/bash

make                    # Makes the main program using the makefile
clear
./Main                  #Runs the main function

rm -rf Results.ps
rm -rf Results.pdf
touch Results.ps

if [ -e "GS.dat" ]         #After the Main function has run, if the Gauss data file exists then plot it
then                       #The next few lines are all GNUPLOT commands to give a graph
./plotter.sh GS Analytical2
fi

if [ -e "Jacobi.dat" ]
then
./plotter.sh Jacobi
fi

if [ -e "SOR.dat" ]
then
./plotter.sh SOR
fi

if [ -e "Analytical1.dat" ]
then
./plotter.sh Analytical1
fi

if [ -e "Analytical2.dat" ]
then
./plotter.sh Analytical2
fi

rm -rf Results.ps 

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
