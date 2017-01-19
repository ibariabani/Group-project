#include "Analytical1.h"


using namespace std;

void Analytical1(double& a,double& b, double& V0)
{

  double x=0, y=0, r=0, i=0, V=0, j=0;


ofstream file;
file.open("Analytical1.dat");

for(i=-100; i<=100; i++){
	
	x = i/100;

	for(j=-100; j<=100; j++){

	y = j/100;

	r = sqrt(pow(x,2) + pow(y,2));

	if( (r<=0.5 && r>=-0.5) || r>1 ){
		V=0;
	}else{
		V = ((V0/log(b/a))*log(r)) - ((V0*log(a))/(log(b/a)));
	}

	file << x << "    " << y << "    " << r << "    " << V << endl;

}
file<<"\n";
file.close();
}




}

