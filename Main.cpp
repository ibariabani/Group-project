#include<iostream>  /*Includes all neccessary libraries*/
#include<cmath>
#include<cstdlib>
#include"math.h"
#include"fstream"
#include"Analytical1.h"
#include"Jacobi1.h"

 double a=0,b=0,V0=0,delta=0,TitMax=0;
using namespace std; 

int main(){
  cout<<"This program runs a Jacobi simulation of the potential in a concentric sphere and compares it to the analytical."<<endl;
cout<< "Please enter the radius of the inner sphere"<<endl;
cin>>a;
cout<< "Please enter the radius of the outer sphere"<<endl;
cin>>b;
cout<< "Please enter the potential at the outer sphere"<<endl;
cin>>V0;
cout<<"Please enter the step size"<<endl;
cin>>delta;
cout<<"How many times do you want the simulation to iterate"<<endl;
cin>>TitMax;

 Jacobi1( a,b,V0,delta,TitMax);
 Analytical1( a,b,V0);

 return 0;
}
 
