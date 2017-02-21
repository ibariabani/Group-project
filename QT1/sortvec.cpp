#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

//plots a vector field using a file e.dat

//returns average magnitude
double MagAv(char* name){
  ifstream file(name);

  double temp,ex,ey,magav=0;
  int m = 1;

  while (file) {
    file >> temp;
    file >> temp;
    file >> ex;
    file >> ey;

    if ((ex) || (ey)) {
      magav += sqrt(ex*ex + ey*ey);
      m++;
    }
  }

  magav /= m;

  file.close();

  return magav;
}

void vecsort(char* name, int size) {

  double x,y,ex,ey,mag,exn,eyn;

  double magav = MagAv(name);

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
      
      exn = ex/mag/15;
      eyn = ey/mag/15;
    }
    if (mag >= magav/10) {
      if ( !(((int)(size*x))%(size/10)) && !(((int)(size*y))%(size/10)) )
        eSort << x << "\t" << y << "\t" << exn << "\t" << eyn << "\t" << mag << endl;

    }
  }

  eFile.close();
  eSort.close();


}
