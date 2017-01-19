//Program that uses the Jacobi method to simulate the potential of a conducting sphere in the middle of an electric feild

#include<iostream>  /*Includes all neccessary libraries*/
#include<cmath>
#include<cstdlib>
#include"math.h"
#include"fstream"

using namespace std;

double U[10000][10000];

int main(void){
  double r=0, a=0, d=0 ,V0=0,x=0,y=0, XitMax=0, YitMax=0, TitMax=0, delta=0;
  int i=0,j=0,t=0;

  
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

 if ((2*a)>d){
   cout<<"The plates lie within the sphere. Please fix this"<<endl;
   return 1;
 }
 
 XitMax=(d)/delta;           //The program needs to iterate through all x and y values and carry out the Jacobi method
 YitMax=(d)/delta;           //X and y are the points converted to origin of sphere

 for (i=0;i<=XitMax;i++){     //Iterates through all x and y to set initial boundary conditions
     for(j=0;j<=YitMax; j++){
       
       if(i==0){             //Sets the two plate values; Left plate =V0, Right plate=-V0
	 U[i][j]=V0;
       }
       else if(i==XitMax){
	 U[i][j]=-V0;
       }
       else{
	 U[i][j]=0;         //Sets all other values to 0
	 }
     }
 }


 for (t=0;t<=TitMax; t++){
   for (i=1;i<XitMax;i++){ //i and j start iterating from the side of the box containing cylinder
     for(j=1;j<YitMax; j++){
       
       x=(i-(XitMax/2))*delta;       //Converts i and j to coordinates centered on inner spheres centre.
       y=(j-(YitMax/2))*delta;
       r=sqrt(pow(x,2)+pow(y,2));    //Calculates the radius from the centre of the sphere.
       
        if (a>r){    //If inside the inner circle set to 0 
	 U[i][j]=0;
       }
       else{
	   U[i][j]=(1.0/4.0)*(U[i+1][j]+U[i-1][j]+U[i][j+1]+U[i][j-1]);  //if not use Jacobi method
			   		   		   
       }
     }
   }
 }
   
ofstream file;               //Opens file to write output data to
file.open("Jacobi2.dat");

for(i=0; i<=XitMax;i++){     //Iterates to output all x values
    for(j=0; j<=YitMax; j++){  //Iterates to output all y values

      x=(i-(XitMax/2))*delta;       //Converts i and j to coordinates centered on inner spheres centre.
      y=(j-(YitMax/2))*delta;
      
                            //Outputs x,y and function value at each point
        file<< x << "      "<< y<<"      "<< U[i][j]<< "\n";
    }
    file<<"\n";     //Inserts newline in data file
}

file.close();      //closes file
return 0;
}
