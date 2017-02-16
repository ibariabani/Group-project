#!/bin/bash

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
