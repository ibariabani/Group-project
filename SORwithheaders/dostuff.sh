#!/bin/bash
g++ -o write "write$1.cpp"
chmod 755 write
./write
g++ -I .. -o SOR SORmain.cpp
chmod 755 SOR
./SOR
