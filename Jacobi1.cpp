//Program that uses the Jacobi method to simulate the potential feild in a concentric sphere
#include"Jacobi1.h"
using namespace std;

double U[10000][10000];

void Jacobi1(double& a,double& b,double& V0,double& delta,double& TitMax){
  double r=0,x=0,y=0, XitMax=0, YitMax=0;
  int i=0,j=0,t=0;


 XitMax=(2*b)/delta;
 YitMax=(2*b)/delta;

for (i=0;i<=XitMax;i++){
     for(j=0;j<=YitMax; j++){
       
       x=(i-(XitMax/2))*delta;       //Converts i and j to coordinates centered on inner spheres centre.
       y=(j-(YitMax/2))*delta;
       r=sqrt(pow(x,2)+pow(y,2));
       
       if (r<(b+0.01) && r>(b-0.01)){  //If point is outside outer circle set to v0
         U[i][j]=V0;
         }
       else{
	 U[i][j]=0;
	 }
     }
 }


 for (t=0;t<=TitMax; t++){
   for (i=1;i<=XitMax;i++){ //i and j start iterating from the side of the box containing cylinder
     for(j=1;j<=YitMax; j++){
       
       x=(i-(XitMax/2))*delta;       //Converts i and j to coordinates centered on inner spheres centre.
       y=(j-(YitMax/2))*delta;
       r=sqrt(pow(x,2)+pow(y,2)); //Converts i and j to coordinates centered on inner spheres centre.
       
       if (r<(b+0.01) && r>(b-0.01)){  //If point lies on outer sphere. Given finite width so points land on.
         U[i][j]=V0;
       }
	else if (a>r){    //If inside the inner circle set to 0 
	 U[i][j]=0;
       }
	else if (r>b){    // If outside the outer circle set to 0
	 U[i][j]=0;
       }
       else{
	   U[i][j]=(1.0/4.0)*(U[i+1][j]+U[i-1][j]+U[i][j+1]+U[i][j-1]);  //if not use Jacobi method
			   		   
			   
       }
     }
   }
 }
   
ofstream file;               //Opens file to write output data to
file.open("Jacobi1.dat");

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

}
