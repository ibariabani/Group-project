#include "Problem1.h"

using namespace std;
float U1[10000][10000];

int Problem1(){
  double a=0,b=0,V0=0,delta=0,ErrTol=0, x=0, y=0, r=0, V=0,Xit=0,Pre=0, Post=0,Err=0, ErrTotal=1, it=0, InitErr=0, dist=0, percent=0;
int i=0,j=0,t=0;
 
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

Xit=(2*b)/delta;    
ofstream file;
file.open("Analytical1.dat");

for(i=0; i<=Xit; i++){
	for(j=0; j<=Xit; j++){
	  x=(i-(Xit/2))*delta;       //Converts i and j to coordinates centered on inner spheres centre.
	  y=(j-(Xit/2))*delta;
	  r = sqrt(pow(x,2) + pow(y,2));

	  if( (r>b || r<a)){
		V=0;
	  }
	  else{
		V = ((V0/log(b/a))*log(r)) - ((V0*log(a))/(log(b/a)));
	  }

	file << x << "    " << y << "    " << r << "    " << V << endl;
      }
   file<<"\n";
}
file.close();

 
for (i=0;i<=Xit;i++){
     for(j=0;j<=Xit; j++){
       
       x=(i-(Xit/2))*delta;       //Converts i and j to coordinates centered on inner spheres centre.
       y=(j-(Xit/2))*delta;
       r=sqrt(pow(x,2)+pow(y,2));
       
       if (r<(b+delta) && r>(b-delta)){  //If point is outside outer circle set to v0
         U1[i][j]=V0;
         }
       else{
	 U1[i][j]=0;
	 }
     }
 }

 while (ErrTotal>ErrTol){
 ErrTotal=0;
   for (i=0;i<=Xit;i++){ //i and j start iterating from the side of the box containing cylinder
     for(j=0;j<=Xit; j++){
       
       x=(i-(Xit/2))*delta;       //Converts i and j to coordinates centered on inner spheres centre.
       y=(j-(Xit/2))*delta;
       r=sqrt(pow(x,2)+pow(y,2)); //Converts i and j to coordinates centered on inner spheres centre.
       
       if (r<(b+delta) && r>(b-delta)){  //If point lies on outer sphere. Given finite width so points land on.
         U1[i][j]=V0;
       }
	else if (a>r){    //If inside the inner circle set to 0 
	 U1[i][j]=0;
       }
	else if (r>b){    // If outside the outer circle set to 0
	 U1[i][j]=0;
       }
       
       else{
	  Pre=U1[i][j];
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
   it++;
   if (it==1){
     InitErr=abs(ErrTotal-ErrTol);
     }
   dist=abs(ErrTotal-ErrTol);
   percent=((InitErr-dist)/InitErr)*100;
   cout<<"The Gauss-Siedell is "<<percent<<"% of the way to your desired accuracy"<<endl;
 }
 
 cout<< "Gauss Siedell took "<<it<<" iterations to converge"<< endl;
 
file.open("GS1.dat");

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
 
