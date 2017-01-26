#!/bin/bash
g++ -I .. -o SOR SORmain.cpp SORinit.cpp
chmod 755 SOR
./SOR
