#ifndef METHODS_H
#define METHODS_H


#include<iostream>  /*Includes all necessary libraries and other header files*/
#include<cmath>
#include<cstdlib>
#include"fstream"


class Methods {
public:

static void Jacobi (double a, double b, double c);
static void Gauss (double a, double b, double c);
static void SOR (double a, double b, double c);

static double U[1000][1000];
static double a;
static double b,c;
static bool B[1000][1000];



  };

#endif // METHODS_H
