#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>
#include <sstream>

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

int main(int argc, char *argv[]) {

  std::stringstream convert(argv[2]);
  double size;
  convert >> size;

  double x,y,ex,ey,mag,exn,eyn,k;

  double MagAv(char* name);
  double magav = MagAv(argv[1]);

  srand(time(0));

  ifstream eFile(argv[1]);
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

    k = 4.0 * random() / RAND_MAX / fabs(mag-magav) * pow(size/100,2);

    if (!(floor(k))) eSort << x << "\t" << y << "\t" << exn/magav << "\t" << eyn/magav << "\t" << mag << endl;

  }

  eFile.close();
  eSort.close();

  return 0;
}

