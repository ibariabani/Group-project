
#include "Analytical2.h"


using namespace std;

void Analytical2(double& a, double& V0, double& d, double& delta){

double x=0, y=0, r=0, i=0, V=0, j=0,Xit=0;
Xit=(d/delta);

 
ofstream file;
file.open("Analytical2.dat");

for(i=0; i<=Xit; i++){
	for(j=0; j<=Xit; j++){
	  
	  x=(i-(Xit/2))*delta;       //Converts i and j to coordinates centered on inner spheres centre.
	  y=(j-(Xit/2))*delta;
	  r = sqrt(pow(x,2) + pow(y,2));

	  if(a>r){
		V=0;
	  }
	  /*
	  else if(i==0){
	    V=V0;
	  }
	  
	  else if(i==Xit){
	    V=(-V0);
	  }
	  */
	  else{
	    V = -(V0)*(2*x/d)*(1 - (pow(a,3)/pow(r,3))); 
	  }
	 

	file << x << "    " << y << "    " << V << endl;

}
file<<"\n";

}
file.close();



}


