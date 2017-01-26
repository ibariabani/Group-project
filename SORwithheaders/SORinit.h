#ifndef INIT_H
#define INIT_H

#include <iostream>
#include <cmath>
#include <fstream>
#include <Eigen/Dense> //makes matrix stuff easier

//class to initialise matrix U0 defining the boundary conditions
class Initialiser
{
public:
  static const int J = 300;
  static const int L = 300;
  static const double V0 = 10; //max voltage
  static const double xmin = -5;
  double delta = -2*xmin/J;
  double ymin = -delta*L/2;
  double x,y;

  Eigen::MatrixXi U0 = Eigen::MatrixXi::Zero(J+1,L+1); //define matrix U0 containing boundary conditions

  void backMat();
  double getInit(int j, int l);
  double getX(int j) { return delta*j + xmin; }//access value of x
  double getY(int l) { return delta*l + ymin; }//access value of y
};

#endif
