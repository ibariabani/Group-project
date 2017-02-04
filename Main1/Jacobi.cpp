#include"Jacobi.h"

/*This program takes an array from the boundary conditions program, and runs the Jacobi method on it*/

using namespace std;

float UNew[10000][10000];       //Declare large array outside stack

void Jacobi(){
  
 double x=0,y=0, ItMax=0, Pre=0, Post=0,Err=0, it=0, ErrTol=0, ErrTotal=1, ArraySize=0;     //Declares all neccesary variables
 int i=0,j=0,m=0,n=0;


  cout<<"What error tolerance would you like the Jacobi method to iterate to?"<<endl;
  cin>>ErrTol;              //Takes the desired Error tolerance and finds the max iteration number
  
  ItMax=GS/delta;
 
  
  while (ErrTotal>ErrTol){        //While the error on each iteration is greater than the error tolerance
    ErrTotal=0;                   //Resets the cumalitive error for each iteration to zero
   
    for (i=0;i<=ItMax;i++){        //Iterates through the whole grid size
     for(j=0;j<=ItMax; j++){

       if (B[i][j]==false){       //If the point is not a user defined boundary

	 Pre=Uj[i][j];           //Takes the value before operation to use in error calc
	 
	 if(j==0){
	   UNew[i][j]=(1.0/4.0)*(Uj[i+1][j]+Uj[i-1][j]+Uj[i][j+1]+Uj[i][j]);  //Case for if at j=0 boundary
	 }
	 else if(j==ItMax){
	   UNew[i][j]=(1.0/4.0)*(Uj[i+1][j]+Uj[i-1][j]+Uj[i][j]+Uj[i][j-1]);  //Case for if at j=MAX boundary
	 }
	 else if(i==0){
	   UNew[i][j]=(1.0/4.0)*(Uj[i+1][j]+Uj[i][j]+Uj[i][j+1]+Uj[i][j-1]);  //Case for if at i=0 boundary
	 }
	 else if(i==ItMax){
	   UNew[i][j]=(1.0/4.0)*(Uj[i][j]+Uj[i-1][j]+Uj[i][j]+Uj[i][j-1]);  //Case for if at i=MAX boundary
	  }
	 else{
	    UNew[i][j]=(1.0/4.0)*(Uj[i+1][j]+Uj[i-1][j]+Uj[i][j+1]+Uj[i][j-1]); //For all other points use Jacobi
	 }
	 
	 Post=UNew[i][j];       //Takes the value after the operation 
	 Err=abs(Pre-Post);    //Defines the error for each point as the difference before and after each operation
	 ErrTotal=ErrTotal+Err; //Totals all the errors for each whole grid iteration 
	  
       }
     }
   }
    for (i=0;i<=ItMax;i++){    //Iterates through the whole grid again
       for(j=0;j<=ItMax; j++){
	 if (B[i][j]==false){  //If not a user defined boundary
	   Uj[i][j]=UNew[i][j];  //equates the matrices for use in the next iteration
	  }
       }
     }
    it++;    //Adds to the iteration counter (Times iterated over whole grid)
}


  cout<<"The Jacobi Method took " << it <<" iterations to converge"<<endl;  //Outputs the number of iterations 

ofstream file;               //Opens file to write output data to
file.open("Jacobi.dat");

for(i=0; i<=ItMax;i++){     //Iterates to output all x values
  for(j=0; j<=ItMax; j++){  //Iterates to output all y values

      x=(i-(ItMax/2))*delta;       //Converts i and j to coordinates on the grid
      y=(j-(ItMax/2))*delta;
      
                            //Outputs x,y and function value at each point
    file<< x << "      "<< y<<"      "<< Uj[i][j]<< "\n";
    }
    file<<"\n";     //Inserts newline in data file
 }

file.close();      //closes file
}
