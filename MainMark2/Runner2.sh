#!/bin/bash

make                    # Makes the main program using the makefile
clear
./Main                  #Runs the main function

rm -rf Results.ps
rm -rf Results.pdf
touch Results.ps

for file in ./v* #Plots all the v*.dat files containing the potential information
do
./plotter.sh $file
done

rm -rf Results.ps 

if [[ -e "dJacobi.dat" && -e "dGauss.dat" && -e "dSOR.dat" ]]
then
gnuplot <<EOF
set terminal postscript color
set logscale xy
set output "diffplot.ps"
plot "dJacobi" with lines, "dGS" with lines, "dSOR" with lines

EOF

ps2pdf14 diffplot.ps
rm -rf diffplot.ps
rm dJacobi
rm dGS
rm dSOR
fi

exit 0
