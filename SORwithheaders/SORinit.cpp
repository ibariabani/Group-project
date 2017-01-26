#include "SORinit.h"

/* function to determine the fixed points of the initial matrix and puts the information in U0:
   - returns 1 if (x,y) lies in the +V0 zone
   - returns 2 if (x,y) lies in the -V0 zone
   - returns 0 if (x,y) lies in the V=0 zone
   - returns 3 if (x,y) does not lie in any zone defined by the boundary conditions */
void Initialiser::backMat(){
  double R1 = 1;
  double R2 = 2;
  double R3 = 0.2;
  for (int j=0; j<=J; j++) {
    x = delta*j + xmin;
    for (int l=0; l<=L; l++) {
      y = delta*l + ymin;
      if (0) { //+V0 boundary
	U0(j,l) = 1;
      } else if (fabs(y) >= R2) { //-V0 boundary
	U0(j,l) = 2;
      } else if ((x*x+y*y <= R3*R3) ||
		 ((x-R1)*(x-R1)+y*y <= R3*R3) ||
		 ((x+R1)*(x+R1)+y*y <= R3*R3) ||
		 ((x-2*R1)*(x-2*R1)+y*y <= R3*R3) ||
		 ((x+2*R1)*(x+2*R1)+y*y <= R3*R3)) { //ground boundary
	U0(j,l) = 0;
      } else { //not within a boundary
	U0(j,l) = 3;
      }
    }
  }
}

//returns the initial values for the matrix u depending on the boundary conditions (U0)
double Initialiser::getInit(int j,int l) {
  switch (U0(j,l)) {
  case 0: return 0;
    break;
  case 1: return V0;
    break;
  case 2: return -V0;
    break;
  case 3: return 0;
  }
}
