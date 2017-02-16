#!/bin/bash

make                    # Makes the main program using the makefile
clear
./Main                  #Runs the main function

rm -rf Results.ps
rm -rf Results.pdf
touch Results.ps
for file in ./v* #Plots all the v* files containing the potential information
do
./plotter.sh $file
done
rm -rf Results.ps 

rm -rf EFields.ps
rm -rf EFields.pdf
touch EFields.ps
for file in ./e* #Plots all the e* files containing the E field information
do
./plotvec.sh $file 200
done
rm -rf EFields.ps


if [[ -e "dJacobi" && -e "dGS" && -e "dSOR" ]]
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
