#include <iostream>
#include <cmath>
#include <fstream>
#include <Eigen/Dense> //makes matrix stuff easier
#include "SORinit.h"

//this program solves Poissons equation using the SOR scheme (kinda)

//put functions everywhere + take file as input for U0

using namespace std;

int main() {

  //define a bunch of constants
  double resid,r,x,y,Ex,Ey;
  int a,b,c,d,e; //equation coefficients
  double omega; //important parameter of the SOR method

  double reduct = 1e-2; //error tolerance of the method: stops the program when accurate enough
  cout << "error reduction: " << reduct << endl;
  double error, error0=0;

  double MAXITS=10000; //maximal number of iterations

  //PDE coefficients, these change for a different PDE problem and are currently set to solve Poisson's equation, need not to be changed if we keep the program to only solve potential problems
  a = 1;
  b = 1;
  c = 1;
  d = 1;
  e = -4;
  
  //initialise matrix u using the Initialiser class and U0
  Initialiser volt;
  volt.backMat();
  Eigen::MatrixXd u(volt.J+1,volt.L+1);
  for (int j=0; j<=volt.J; j++) {
    for (int l=0; l<=volt.L; l++) {
      u(j,l) = volt.getInit(j,l);
    }
  }
  cout << "delta: " << volt.delta << endl;

 /* Rho Jacobi, it's an important parameter of the SOR (and what makes it actually work better than other methods) but a pain to calculate, so I set a random value
     For the numerical problem we have to solve, 0.98 seems to be very good */
  double r_jac=cos(3.14159265359/(volt.L+1));
  cout << "rho jacobi: " << r_jac << endl;
  
  //performs the SOR computation
  for (int n=1; n<=MAXITS; n++) { //number of total iterations
    error=0;
    for (int OE=1; OE>=0; OE--) { //divides each iterations in two half-steps, one with odd points, the other with even point (cf: Numerical recipes p892 for info)

      //calculate omega, changes with each half-step
      if (n == 1) {
	if (OE == 1) {
	  omega = 1; //first iteration
	} else {
	  omega = 1/(1-r_jac*r_jac/2); //1.5th iteration
	}
      } else {
	omega = 1/(1-r_jac*r_jac*omega/4); //other iterations, uses r_jac which is not properly defined yet
      }

      for (int j=OE; j<=volt.J; j+=2) {
	for (int l=0; l<=volt.L; l++) {
	  if (volt.U0(j,l) == 3) { //if point is outwith any defined boundary zone
	    
	    //boundary cases changed to avoid having unintended fixed boundaries, simulate infinite boundaries
	    //residual comes from some equations somewhere, used for SOR method and error calculation
	    resid = e*u(j,l);
	    if (j == volt.J) resid += a*u(j,l);
	    else resid += a*u(j+1,l);
	    if (j == 0) resid += b*u(j,l);
	    else resid += b*u(j-1,l);
	    if (l == volt.L) resid += c*u(j,l);
	    else resid += c*u(j,l+1);
	    if (l == 0) resid += d*u(j,l);
	    else resid += d*u(j,l-1);

	    u(j,l) -= omega*resid/e; //calculates the updated u(j,l) using omega and resid
	    error += fabs(resid); //error calculation
	  }
	}
      }	
    }
    if (n == 1) error0=error;
    if (error < error0*reduct) {
      cout << "iterations: " << n << endl;
      n = MAXITS+1;
    }
  }

  //output the result to a file called "u.dat"
  ofstream Vfile("u.dat");
  for (int j=0; j<volt.J; j++) {
    x = volt.getX(j);
    for (int l=0; l<volt.L; l++) {
      y = volt.getY(l);
      Vfile << x << "\t" << y << "\t" << u(j,l) << "\n";
    }
  }
  Vfile.close();

  //calculates the electric field from the potential field and ouputs the result to a file
  ofstream Efile("e.dat");
   for(int j=0; j<=volt.J; j++) {
     x = volt.getX(j);
     for(int l=0; l<=volt.L; l++) {
       y = volt.getY(l);
       if (j == 0) {
	 Ex = (u(j,l) - u(j+1,l)) / (volt.delta);
       } else if (j == volt.J) {
	 Ex = (u(j-1,l) - u(j,l)) / (volt.delta);
       } else {
	 Ex = (u(j-1,l) - u(j+1,l)) / (2*volt.delta);
       }
       if (l == 0) {
	 Ey = (u(j,l) - u(j,l+1)) / (volt.delta);
       } else if (l == volt.L) {
	 Ey = (u(j,l-1) - u(j,l)) / (volt.delta);
       } else {
	 Ey = (u(j,l-1) - u(j,l+1)) / (2*volt.delta);
       }
       Efile << x << "\t" << y << "\t" << Ex << "\t" << Ey << "\n";
     }
   }
   Efile.close();

  return 0;
}
