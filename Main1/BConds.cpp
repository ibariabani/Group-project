#include"BConds.h"

using namespace std;

float delta, GS;


int BConds(){

  //This is an arbritrary example ---------------------------------------
  
  double a=0, V0=0,d=0,ErrTol=0, x=0,y=0,r=0;
  int i=0,j=0,ItMax=0;

  cout<<"Please enter the grid size you wish to use"<<endl;
  cin>>GS;
  cout<< "Please enter the radius of the sphere"<<endl;
  cin>>a;
  cout<< "Please enter the absolute value of the potential at the plates"<<endl;
  cin>>V0;
  cout<< "Please enter the seperation of the plates. This must be larger than the diameter of the sphere"<<endl;
  cin>>d;
  cout<<"Please enter the step size for the Numerical methods to use"<<endl;
  cin>>delta;

  
  if ((2*a)>d)
    {
      cout<<"The plates lie within the sphere. Please fix this"<<endl;
      return 2;
    }

   ItMax=GS/delta;           //The program needs to iterate through all x and y values and carry out the Jacobi metho
                              //X and y are the points converted to origin of sphere

 for (i=0;i<=ItMax;i++){     //Iterates through all x and y to set initial boundary conditions
     for(j=0;j<=ItMax; j++){

       x=(i-(ItMax/2))*delta;       //Converts i and j to coordinates centered on inner spheres centre.
       y=(j-(ItMax/2))*delta;
       r=sqrt(pow(x,2)+pow(y,2));    //Calculates the radius from the centre of the sphere.
       
       if(i==0){             //Sets the two plate values; Left plate =V0, Right plate=-V0
	 Ug[i][j]=V0;
	 Uj[i][j]=V0;
	 B[i][j]=true;
       }
       else if(i==ItMax){
	 Ug[i][j]=-V0;
	 Uj[i][j]=-V0;
	 B[i][j]=true;
       }
       else if(a>r){
	 Ug[i][j]=0;     //Sets all other values to 0
	 Uj[i][j]=0;
	 B[i][j]=true;
	 }
       else{
	 Ug[i][j]=0;
	 Uj[i][j]=0;
	 B[i][j]=false;
       }
     }
 }


 return 0;
}
