#include "Problem1.h"              //Includes the problems header file

using namespace std;
float U1[10000][10000];           //Declares this large array outside the stack to avoid memory problems

int Problem1(){
double a=0,b=0,V0=0,delta=0,ErrTol=0, x=0, y=0, r=0, V=0,Xit=0,Pre=0, Post=0,Err=0, ErrTotal=1, it=0, InitErr=0, dist=0, percent=0;
 int i=0,j=0,t=0;                  //This is all just declaring neccessary variables

                                  //Takes the required user input for this problem
cout<<"This program runs a Gauss-Siedel simulation of the potential in a concentric sphere and compares it to the analytical."<<endl;
cout<< "Please enter the radius of the inner sphere"<<endl;
cin>>a;
cout<< "Please enter the radius of the outer sphere"<<endl;
cin>>b;
cout<< "Please enter the potential at the outer sphere"<<endl;
cin>>V0;
cout<<"Please enter the step size"<<endl;
cin>>delta;
cout<<"What error tolerance would you like?"<<endl;
cin>>ErrTol;

 Xit=((2*b)+delta)/delta;               //Calculates the maximimum number of iterations req
 
 ofstream file;                         //Opens a file to write the analytical solution data to
file.open("Analytical1.dat");

 for(i=0; i<=Xit; i++){                //Loops through the entire grid
	for(j=0; j<=Xit; j++){
	  x=(i-(Xit/2))*delta;       //Converts i and j to coordinates centered on inner spheres centre.
	  y=(j-(Xit/2))*delta;
	  r = sqrt(pow(x,2) + pow(y,2));    //Calculates the radius of each point 

	  if( (r>b || r<a)){          //If the point lies outwith the larger sphere, or within the inner sphere, set=0
		V=0;
	  }
	  else{                       //Otherwise use the derived analytical solution
		V = ((V0/log(b/a))*log(r)) - ((V0*log(a))/(log(b/a)));
	  }

	  file << x << "    " << y << "    " << r << "    " << V << endl;    //Outputs data to the file
      }
   file<<"\n";
}
 file.close();                                  //Closes file

 //This next bit of code is the numerical approximation using the Gauss Siedell Method
 //Begins by setiing the values of the array to the boundaries defined by the problem
 
 for (i=0;i<=Xit;i++){              //This loops throught the whole grid
     for(j=0;j<=Xit; j++){
       
       x=(i-(Xit/2))*delta;       //Converts i and j to coordinates centered on inner spheres centre.
       y=(j-(Xit/2))*delta;
       r=sqrt(pow(x,2)+pow(y,2));
       
       if (r<(b+delta) && r>(b-delta)){  //If point is on, or close to on, the outer circle, define as V0
         U1[i][j]=V0;                    //Slight inaccuray due to the inexact nature of the x and y coordinate conversion
         }
       else{
	 U1[i][j]=0;                 // Otherwise set the value to zero for the Gauss to work on
	 }
     }
 }

 while (ErrTotal>ErrTol){        //iterate while the cumalative error for each whole grid iteration is above the tolerance 
 ErrTotal=0;
   for (i=0;i<=Xit;i++){          //i and j start iterating from the side of the box containing cylinder
     for(j=0;j<=Xit; j++){
       
       x=(i-(Xit/2))*delta;       //Converts i and j to coordinates centered on inner spheres centre.
       y=(j-(Xit/2))*delta;
       r=sqrt(pow(x,2)+pow(y,2)); //Finds the radius of each point
       
       if (r<(b+delta) && r>(b-delta)){  //If point lies on outer sphere set = V0. Given finite width so points land on.
         U1[i][j]=V0;
       }
	else if (a>r){    //If inside the inner circle set to 0 
	 U1[i][j]=0;
       }
	else if (r>b){    // If outside the outer circle set to 0
	 U1[i][j]=0;
       }
       
	else{                        //Otherwise use the Gauss Siedell method
	  Pre=U1[i][j];              //Takes the value before Gauss for use in error calc
	    if (j==0){              //Uses altered formuala if at J=0 boundary
	  U1[i][j]=(1.0/4.0)*(U1[i+1][j]+U1[i-1][j]+U1[i][j+1]+U1[i][j]);
	  }

	 else if (j==Xit){    //Uses altered formula if at j=MAX boundary
	  U1[i][j]=(1.0/4.0)*(U1[i+1][j]+U1[i-1][j]+U1[i][j]+U1[i][j-1]);
	  }
	   
	 else if (i==0){       //Uses altered formula if at i=0 boundary
	  U1[i][j]=(1.0/4.0)*(U1[i+1][j]+U1[i][j]+U1[i][j+1]+U1[i][j-1]);
	  }

	 else if (i==Xit){     //Uses altered formula if at i=MAX boundary
	  U1[i][j]=(1.0/4.0)*(U1[i][j]+U1[i-1][j]+U1[i][j+1]+U1[i][j-1]);
	  }
	 else{
	   U1[i][j]=(1.0/4.0)*(U1[i+1][j]+U1[i-1][j]+U1[i][j+1]+U1[i][j-1]);  //if not at boundary use normal Gauss method		     
           }
      
      	 Post=U1[i][j];          //Takes value after the operation is carried out
	 Err=abs(Pre-Post);     // Finds the error value of each point in the grid
	 ErrTotal=ErrTotal+Err; //finds a cumaltive error for the whole grid for each iterationPost=U1[i][j];
       }
     }
   }
   it++;                           //Increase it counter by 1
   if (it==1){                     //If on 1st iteration define error as initial error
     InitErr=abs(ErrTotal-ErrTol);
     }
   dist=abs(ErrTotal-ErrTol);              // displays How far from the requested tolerance each iteration is
   percent=((InitErr-dist)/InitErr)*100;   //Finds the % of the way to  the requested toleranceeach iteration is
   cout<<"The Gauss-Siedell is "<<percent<<"% of the way to your desired accuracy"<<endl;      //Output this
 }
 
 cout<< "Gauss Siedell took "<<it<<" iterations to converge"<< endl;      //Outputs how many iterations the Gauss took
 
 file.open("GS1.dat");             //open data file to write to

for(i=0; i<=Xit;i++){     //Iterates to output all x values
    for(j=0; j<=Xit; j++){  //Iterates to output all y values

      x=(i-(Xit/2))*delta;       //Converts i and j to coordinates centered on inner spheres centre.
      y=(j-(Xit/2))*delta;
      
                            //Outputs x,y and function value at each point
        file<< x << "      "<< y<<"      "<< U1[i][j]<< "\n";
    }
    file<<"\n";     //Inserts newline in data file
 }

file.close();      //closes file


 

 return 0;
}
 
