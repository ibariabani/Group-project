#!/bin/bash

make                    # Makes the main program using the makefile
clear
./Main                  #Runs the main function


if [ -e "GS.dat" ]         #After the Main function has run, if the Gauss data file exists then plot it
then                       #The next few lines are all GNUPLOT commands to give a graph
./plotter.sh Jacobi GS SOR Analytical1 Analytical2
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
