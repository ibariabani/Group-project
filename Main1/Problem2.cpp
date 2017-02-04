#include "Problem2.h"

using namespace std;
float U2[10000][10000];

int Problem2(){
  double a=0,V0=0,Delta=0,ErrTol=0, x=0,d=0, y=0, r=0, V=0,Xit=0,Pre=0, Post=0,Err=0, ErrTotal=1, it=0;
int i=0,j=0,t=0;
 
 cout<<"This program runs a Gauss-Siedell simulations of the potential between two plates of opposing potentials V0 and -V0"<<endl;
 cout<<"with a conducting sphere at V=0 in the middle."<<endl;
  cout<< "Please enter the radius of the sphere"<<endl;
  cin>>a;
  cout<< "Please enter the absolute value of the potential at the plates"<<endl;
  cin>>V0;
  cout<< "Please enter the seperation of the plates. This must be larger than the diameter of the sphere"<<endl;
  cin>>d;
  cout<<"Please enter the step size for the Numerical methods to use"<<endl;
  cin>>Delta;
 cout<<"What error tolerance would you like?"<<endl;
 cin>>ErrTol; 

  if ((2*a)>d) {
      cout<<"The plates lie within the sphere. Please fix this"<<endl;
      return 2;
  }

Xit=(d)/Delta;    
  

 ofstream file;
 file.open("Analytical2.dat");

 for(i=0; i<=Xit; i++){
   for(j=0; j<=Xit; j++){
	  
     x=(i-(Xit/2))*Delta;       //Converts i and j to coordinates centered on inner spheres centre.
     y=(j-(Xit/2))*Delta;
     r = sqrt(pow(x,2) + pow(y,2));
    
     if(a>r){
       V=0;
     }  
     else{
       V = -(V0)*(2*x/d)*(1 - (pow(a,3)/pow(r,3))); 
     }
     file << x << "    " << y << "    " << V << endl;
   }
   file<<"\n";
 }
file.close();

 
 for (i=0;i<=Xit;i++){     //Iterates through all x and y to set initial boundary conditions
   for(j=0;j<=Xit; j++){
       
     if(i==0){             //Sets the two plate values; Left plate =V0, Right plate=-V0
       U2[i][j]=V0;
     }
     else if(i==Xit){
       U2[i][j]=-V0;
     }
     else{
       U2[i][j]=0;         //Sets all other values to 0
     }
   }
 }


 while (ErrTotal>ErrTol){
 ErrTotal=0;
   for (i=1;i<Xit;i++){               //i and j start iterating from the side of the box containing cylinder
      x=(i-(Xit/2))*Delta;               //Converts i and j to coordinates centered on inner spheres centre.
      for(j=0;j<=Xit; j++){
                                   //Converts i and j to coordinates centered on inner spheres centre.
       y=(j-(Xit/2))*Delta;
       r=sqrt(pow(x,2)+pow(y,2));        //Calculates the radius from the centre of the sphere.
      

       if (a>r){                     //If inside the inner circle set to 0 
	 U2[i][j]=0;
       }
       else{
       Pre=U2[i][j];                    //Takes the value of the array point before the operation  

       if (j==0){              //Uses altered formuala if at J=0 boundary
	 U2[i][j]=(1.0/4.0)*(U2[i+1][j]+U2[i-1][j]+U2[i][j+1]+U2[i][j]);
       }

       else if (j==Xit){    //Uses altered formula if at j=MAX boundary
	 U2[i][j]=(1.0/4.0)*(U2[i+1][j]+U2[i-1][j]+U2[i][j]+U2[i][j-1]);
       }
	   
       else if (i==0){       //Uses altered formula if at i=0 boundary
	 U2[i][j]=(1.0/4.0)*(U2[i+1][j]+U2[i][j]+U2[i][j+1]+U2[i][j-1]);
       }

       else if (i==Xit){     //Uses altered formula if at i=MAX boundary
	 U2[i][j]=(1.0/4.0)*(U2[i][j]+U2[i-1][j]+U2[i][j+1]+U2[i][j-1]);
       }
       else{
	 U2[i][j]=(1.0/4.0)*(U2[i+1][j]+U2[i-1][j]+U2[i][j+1]+U2[i][j-1]);  //if not at boundary use normal Gauss method		     
       }
	 
       Post=U2[i][j];          //Takes value after the operation is carried out
       Err=abs(Pre-Post);     // Finds the error value of each point in the grid
       ErrTotal=ErrTotal+Err; //finds a cumaltive error for the whole grid for each iteration		   		   		   
       }
     }
   }
   cout<<ErrTotal<<endl;
   it++;
 }

 cout<<"The Gauss Siedell took "<<it<<" iterations to converge to desired accuracy"<<endl;
 

file.open("GS2.dat");

for(i=0; i<=Xit;i++){     //Iterates to output all x values
    for(j=0; j<=Xit; j++){  //Iterates to output all y values

      x=(i-(Xit/2))*Delta;       //Converts i and j to coordinates centered on inner spheres centre.
      y=(j-(Xit/2))*Delta;
      
                            //Outputs x,y and function value at each point
        file<< x << "      "<< y<<"      "<< U2[i][j]<< "\n";
    }
    file<<"\n";     //Inserts newline in data file
}

file.close();      //closes file


 return 0;
}
 

