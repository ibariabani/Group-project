#include <iostream>
#include <cmath>
#include <fstream>

//this program solves Poissons equation using the SOR scheme (kinda)

using namespace std;

/*function to determine the boundary conditions for a given point:
  - returns 1 if (x,y) lies in the +V0 zone
  - returns 2 if (x,y) lies in the -V0 zone
  - returns 0 if (x,y) lies in the V=0 zone
  - returns 3 if (x,y) does not lie in any zone defined by the boundary conditions  
 */
int bound(double x, double y, double d) {
  double R1 = 1;
  double R2 = 3;
  double r = sqrt(x*x+y*y); //distance of (x,y) to the origin

  //boundary conditions are currently set for our numerical problem
  if (0) { //+V0 boundary
    return 1;
  } else if (fabs(y) >= R2) { //-V0 boundary
    return 2;
  } else if ((y == 0) && (((x >= -d) && (x <= d)) || ((x >= R1-d) && (x <= R1+d)) || ((x >= -R1-d) && (x <= -R1+d)) || ((x >= 2*R1-d) && (x <= 2*R1+d)) || ((x >= -2*R1-d) && (x <= -2*R1+d)))) { //ground boundary
    return 0;
  } else { //not within a boundary
    return 3;
  }
}

int main() {

  //define a bunch of constants
  int J=200,L=150; //size of array
  double resid,r,x,y;
  double a,b,c,d,e; //equation coefficients

  //rho Jacobi, it's an important parameter of the SOR (and what makes it actually work better than other methods) but a pain to calculate, so I set a random value
  //for the numerical problem we have to solve, 0.98 seems to be very good
  double r_jac=0.98;
  
  //matrices used for the potential and charge density
  double u[J+1][L+1];

  double reduct = 1e-4; //error tolerance of the method: stops the program when accurate enough
  cout << "error reduction: " << reduct << endl;
  double error, error0;

  double MAXITS=10000; //maximal number of iterations

  double xmax=4; //size of array in x direction
  double delta = 2*xmax/J; //delta calculated
  double ymax = delta*L/2; //ymax calculated using delta since different deltas for x and y are currently not supported
  cout << "delta = " << delta << endl;
  cout << "xmax = " << xmax << endl;
  cout << "ymax = " << ymax << endl;
  double xmin = -xmax;
  double ymin = -ymax;

  //PDE coefficients, these change for a different PDE problem and are currently set to solve Poisson's equation, need not to be changed if we keep the program to only solve potential problems
  a = 1;
  b = 1;
  c = 1;
  d = 1;
  e = -4;

  //initialise the array with the specified boundary values and 0 elsewhere, using the "bound" function above to determine where a point lies in the problem (should probably be merged with "bound" function later on)
  double V0 = 10; //potential magnitude at boundaries
  for (int j=0; j<=J; j++) {
    x = delta*j + xmin;
    for (int l=0; l<=L; l++) {
      y = delta*l + ymin;
      switch(bound(x,y,delta)) { //different things happen depending on where (x,y) is
      case 1 : u[j][l] = V0;
	break;
      case 0 : u[j][l] = 0;
	break;
      case 2 : u[j][l] = -V0;
	break;
      case 3 : u[j][l] = 0;
	break;
      }
    }
  }

  double omega; //important parameter of the SOR method
  
  //performs the SOR computation
  for (int n=1; n<=MAXITS; n++) { //number of total iterations
    error=0;
    for (int OE=0; OE<=1; OE++) { //divides each iterations in two half-steps, one with odd points, the other with even point (cf: Numerical recipes p892 for info)

      //calculate omega, changes with each half-step
      if (n == 1) {
	if (OE == 0) {
	  omega = 1; //first iteration
	} else {
	  omega = 1/(1-r_jac*r_jac/2); //1.5th iteration
	}
      } else {
	omega = 1/(1-r_jac*r_jac*omega/4); //other iterations, uses r_jac which is not properly defined yet
      }

      for (int j=1+OE; j<J; j+=2) {
	x = delta*j + xmin;
	for (int l=1; l<L; l++) {
	  y = delta*l + ymin;
	  r = sqrt(x*x+y*y);
	  if (bound(x,y,delta) == 3) { //if point is outwith any defined boundary zone
	    resid = a*u[j+1][l] + b*u[j-1][l] + c*u[j][l+1] + d*u[j][l-1] + e*u[j][l]; //residual, comes from some equations somewhere, used for SOR method and error calculation
	    u[j][l] -= omega*resid/e; //calculates the updated u(j,l) using omega and resid
	    error += fabs(resid); //error calculation
	  }
	}
      }	
    }
    if (n == 1)
      error0 = error;
    if (error < error0*reduct) {
      cout << "iterations: " << n << endl;
      n = MAXITS+1;
    }
  }

  //output the result to a file called "u.dat"
  ofstream data("u.dat");
  for (int j=0; j<J; j++) {
    x = delta*j + xmin;
    for (int l=0; l<L; l++) {
      y = delta*l + ymin;
      data << x << "\t" << y << "\t" << u[j][l] << "\n";
    }
  }

  return 0;
}
