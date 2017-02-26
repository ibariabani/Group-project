#ifndef BCONDS_H
#define BCONDS_H

#include<iostream>  /*Includes all necessary libraries and other header files*/
#include<cmath>
#include<cstdlib>
#include"fstream"

class Bconds{
public:
static void Problem1 (double a, double b);
static void Problem2(double a, double b);
static void ud(double a, double b);
static double U[1000][1000];
static double a,b;
static bool B[1000][1000];
static int rval,gval,bval;
static double UV;

};

#endif // BCONDS_H
