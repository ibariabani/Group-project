#ifndef METHODS_H
#define METHODS_H


#include<iostream>  /*Includes all necessary libraries and other header files*/
#include<cmath>
#include<cstdlib>
#include"fstream"
#include<QFile>
#include<QTextStream>
#include<QtGui>
#include<QMainWindow>
#include "mainwindow.h"
#include "ui_mainwindow.h"

class Methods {
public:

static void Jacobi (double a, double b, double c);
static void Gauss (double a, double b, double c);
static void SOR (double a, double b, double c);


static double U[1000][1000];
static double a;
static double b,c;
static bool B[1000][1000];
static double it;
static int Git;
static int n;

  };

#endif // METHODS_H
