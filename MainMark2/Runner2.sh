#!/bin/bash

make                    # Makes the main program using the makefile
clear
./Main | tee temp      #Runs the main function
size=$(tail -n 1 temp)
rm -rf temp

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
./plotvec.sh $file $size
done
rm -rf EFields.ps


#if [[ -e "dJacobi" && -e "dGS" && -e "dSOR" ]]
#then
echo -n "\
set terminal postscript color
set logscale xy
set output \"plotdiff.ps\"
plot " > plotdiff.plt

c=0

for file in d*
do
echo -n "\"$file\" with lines, " >> plotdiff.plt
c=1
done

if [ $c -eq 1 ]; then
gnuplot plotdiff.plt
ps2pdf14 plotdiff.ps
rm -rf plotdiff.ps
fi

rm -rf plotdiff.plt
rm -rf d*

exit 0
