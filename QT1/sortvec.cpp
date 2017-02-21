#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

//plots a vector field using a file e.dat

//returns average magnitude

void vecsort(char* name, int size) {

  double x,y,ex,ey,mag,exn,eyn;

  ifstream eFile(name);
  ofstream eSort("plotvec.dat");

  while (eFile) {
    eFile >> x;
    eFile >> y;
    eFile >> ex;
    eFile >> ey;

    mag = 0;
    exn = 0;
    eyn = 0;
  
    if ((ex) || (ey)) { 

      mag = sqrt(ex*ex + ey*ey);
      
      exn = ex/mag;
      eyn = ey/mag;
    }

    if ( !(((int)(size*x))%(size/10)) && !(((int)(size*y))%(size/10)) )
      eSort << x << "\t" << y << "\t" << exn/10 << "\t" << eyn/10 << "\t" << mag << endl;

  }

  eFile.close();
  eSort.close();


}
