//Program that uses the Jacobi method to simulate the potential of a conducting sphere in the middle of an electric feild

#include "GS2.h"

using namespace std;
double U2[10000][10000];
void GS2(double& a, double& V0, double &d, double& delta, double& TitMax)
{
  double r = 0, x = 0, y = 0, XitMax=0, YitMax=0;
  int i=0,j=0,t=0;
  

 XitMax=(d)/delta;           //The program needs to iterate through all x and y values and carry out the Jacobi method
 YitMax=(d)/delta;           //X and y are the points converted to origin of sphere

 for (i=0;i<=XitMax;i++){     //Iterates through all x and y to set initial boundary conditions
     for(j=0;j<=YitMax; j++){
       
       if(i==0){             //Sets the two plate values; Left plate =V0, Right plate=-V0
	 U2[i][j]=V0;
       }
       else if(i==XitMax){
	 U2[i][j]=-V0;
       }
       else{
	 U2[i][j]=0;         //Sets all other values to 0
	 }
     }
 }


 for (t=0;t<=TitMax; t++){
   for (i=1;i<XitMax;i++){ //i and j start iterating from the side of the box containing cylinder
     for(j=0;j<=YitMax; j++){
       
       x=(i-(XitMax/2))*delta;       //Converts i and j to coordinates centered on inner spheres centre.
       y=(j-(YitMax/2))*delta;
       r=sqrt(pow(x,2)+pow(y,2));    //Calculates the radius from the centre of the sphere.
       
        if (a>r){    //If inside the inner circle set to 0 
	 U2[i][j]=0;
       }
	
	else if (j==0){
	  U2[i][j]=(1.0/4.0)*(U2[i+1][j]+U2[i-1][j]+U2[i][j+1]+U2[i][j]);
	}

       	else if (j==YitMax){
	  U2[i][j]=(1.0/4.0)*(U2[i+1][j]+U2[i-1][j]+U2[i][j]+U2[i][j-1]);
	}
       else{
	   U2[i][j]=(1.0/4.0)*(U2[i+1][j]+U2[i-1][j]+U2[i][j+1]+U2[i][j-1]);  //if not use Jacobi method
			   		   		   
       }
     }
   }
 }
   
ofstream file;               //Opens file to write output data to
file.open("GS2.dat");

for(i=0; i<=XitMax;i++){     //Iterates to output all x values
    for(j=0; j<=YitMax; j++){  //Iterates to output all y values

      x=(i-(XitMax/2))*delta;       //Converts i and j to coordinates centered on inner spheres centre.
      y=(j-(YitMax/2))*delta;
      
                            //Outputs x,y and function value at each point
        file<< x << "      "<< y<<"      "<< U2[i][j]<< "\n";
    }
    file<<"\n";     //Inserts newline in data file
}

file.close();      //closes file

}
