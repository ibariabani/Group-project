#ifndef BCONDS_H
#define BCONDS_H

#include<iostream>  /*Includes all necessary libraries and other header files*/
#include<cmath>
#include<cstdlib>
#include"fstream"

class Bconds{
public:
static void Problem0(int GridSize);
static void Problem1(int GridSize);
static void Problem2_2(int GridSize);
static void ud(int GridSize);

static double U[1000][1000];
static bool B[1000][1000];
static int rval,gval,bval, GridSize;
static double UV, delta, Dimen, V0;

};

#endif // BCONDS_H
