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
  double xmin,ymin,delta;
  int n=0,j,l;
  double magav = MagAv(name);
  int interval = (int) size/60; //check if not work, 60 is the number of arrows in both directions, change for more or less arrows


  ifstream eFile(name);
  ofstream eSort("plotvec.dat");

  while (eFile) {
    eFile >> x;
    eFile >> y;
    eFile >> ex;
    eFile >> ey;
    
    if (!n) {
      xmin = x;
      ymin = y;
      delta = -2.*xmin/size; //check if not work
      n++;
    }
    
    j = floor( (x-xmin)/delta + 0.5 ); //check if not work
    l = floor( (y-ymin)/delta + 0.5 ); //check if not work

    mag = 0;
    exn = 0;
    eyn = 0;
  
    if ((ex) || (ey)) { 

      mag = sqrt(ex*ex + ey*ey);
      
      exn = ex/mag/15; //15 is to make the arrows smaller, change if they are too big or too small
      eyn = ey/mag/15; //15 is to make the arrows smaller, change if they are too big or too small
    }

    if (mag >= magav/10) {
      if ( !(j % interval) && !(l % interval) ) //check if not work
        eSort << x << "\t" << y << "\t" << exn << "\t" << eyn << "\t" << mag << endl;

    }
  }

  eFile.close();
  eSort.close();


}
