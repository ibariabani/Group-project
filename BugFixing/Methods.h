#ifndef METHODS_H
#define METHODS_H


#include<iostream>  /*Includes all necessary libraries and other header files*/
#include<cmath>
#include<cstdlib>
#include"fstream"


class Methods {
public:

static void Jacobi (int GridSize, double c);
static void Gauss (int GridSize, double c);
static void SOR (int GridSize, double c);


static double U[1000][1000];
static double c;
static double delta;
static int GridSize;
static bool B[1000][1000];


  };

#endif // METHODS_H
