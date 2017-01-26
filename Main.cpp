#include<iostream>  /*Includes all neccessary libraries*/
#include<cmath>
#include<cstdlib>
#include<fstream>
#include"Analytical2.h"
#include"GS2.h"
#include"Analytical1.h"
#include"GS1.h"


using namespace std;

double a = 0, b=0, V0 = 0, d = 0, delta = 0, TitMax = 0;
int Index=0;


int Problem2(){
  cout<<"This program runs a Jacobi simulation of the potential between two plates of opposing potentials V0 and -V0"<<endl;
  cout<<"with a conducting sphere at V=0 in the middle."<<endl;
  
  cout<< "Please enter the radius of the sphere"<<endl;
  cin>>a;
  cout<< "Please enter the absolute value of the potential at the plates"<<endl;
  cin>>V0;
  cout<< "Please enter the seperation of the plates. This must be larger than the diameter of the sphere"<<endl;
  cin>>d;
  cout<<"Please enter the step size for the Jacobi method to use"<<endl;
  cin>>delta;
  cout<<"How many times do you want the simulation to iterate"<<endl;
  cin>>TitMax;

  if ((2*a)>d)
    {
      cout<<"The plates lie within the sphere. Please fix this"<<endl;
      return 2;
    }

  GS2(a,V0,d,delta,TitMax);
  Analytical2(a,V0,d,delta);

  return 0;
}

int Problem1(){
  cout<<"This program runs a Jacobi and Gauss-Siedel simulation of the potential in a concentric sphere and compares it to the analytical."<<endl;
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

 GS1(a,b,V0,delta,TitMax);
 Analytical1(a,b,V0,delta);

 return 0;
}
 

int main(){
  cout<<"Please type 1 for problem 1, and 2 for problem 2"<<endl;
cin>>Index;

if (Index != 1 && Index != 2){
  cerr<<"This is not one of the options"<<endl;
  return 1;
 }

if (Index ==1){
  Problem1();
 }

if (Index ==2){
  Problem2();
 }

return 0;
 
 }
