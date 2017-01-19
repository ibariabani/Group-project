#include <iostream>
#include <cmath>
#include <fstream>


using namespace std;

int main()
{

double a=0.5, b=1, V, x, y, r, V_0, i, j;


cout << "Enter the initial potential, V_0" << endl;
cin >> V_0;

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
		V = ((V_0/log(b/a))*log(r)) - ((V_0*log(a))/(log(b/a)));
	}

	file << x << "    " << y << "    " << r << "    " << V << endl;

}
file<<"\n";

}
//cout << pot << endl;


return 0;
}

