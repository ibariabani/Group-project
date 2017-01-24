#include "Analytical1.h"


using namespace std;

void Analytical1(double& a,double& b, double& V0, double& delta)
{

  double x=0, y=0, r=0, i=0, V=0, j=0,Xit=0;

  Xit=(2*b)/delta;
  
  
ofstream file;
file.open("Analytical1.dat");

for(i=0; i<=Xit; i++){
	for(j=0; j<=Xit; j++){
	  
	  x=(i-(Xit/2))*delta;       //Converts i and j to coordinates centered on inner spheres centre.
	  y=(j-(Xit/2))*delta;

	  r = sqrt(pow(x,2) + pow(y,2));

	if( (r>b || r<a)){
		V=0;
	}else{
		V = ((V0/log(b/a))*log(r)) - ((V0*log(a))/(log(b/a)));
	}

	file << x << "    " << y << "    " << r << "    " << V << endl;

}
file<<"\n";

}
file.close();



}

