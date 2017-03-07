#include <iostream>
#include <fstream>
#include <cmath>

/* function to determine the fixed points of the initial matrix and puts the information in U0:
   - returns 1 if (x,y) lies in the +V0 zone
   - returns 2 if (x,y) lies in the -V0 zone
   - returns 0 if (x,y) lies in the V=0 zone
   - returns 3 if (x,y) does not lie in any zone defined by the boundary conditions */

using namespace std;

int main(){
  double R1 = 1;
  double R2 = 1.5;
  double R3 = 0.15;
  double J = 300;
  double L = J;
  double xmin = -3;
  double delta = -2*xmin/J;
  double ymin = -delta*L/2;
  double x,y;

  ofstream params("param");
  params << J << endl;
  params << xmin << endl;
  params << delta << endl;
  params << ymin;
  params.close();

  ofstream iFile("bound.mat");

  for (int l=0; l<=L; l++) {
    y = delta*l + ymin;
    for (int j=0; j<=J; j++) {
      x = delta*j + xmin;
      if (0) { //+V0 boundary
	iFile << "1";
      } else if (fabs(y) >= R2) { //-V0 boundary
        iFile << "2";
      } else if ((x*x+y*y <= R3*R3) ||
		 ((x-R1)*(x-R1)+y*y <= R3*R3) ||
		 ((x+R1)*(x+R1)+y*y <= R3*R3) ||
		 ((x-2*R1)*(x-2*R1)+y*y <= R3*R3) ||
		 ((x+2*R1)*(x+2*R1)+y*y <= R3*R3)) { //ground boundary
	iFile << "0";
      } else { //not within a boundary
	iFile << "3";
      }
      if (j != J) iFile << "\t";
    }
    iFile << endl;
  }
}
