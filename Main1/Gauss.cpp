#include"Gauss.h"

/*This program takes a array of boundary condtions from BConds.cpp, and runs the Gauss method on it*/

using namespace std;

void Gauss(){

  double x=0,y=0, ItMax, Pre=0, Post=0,Err=0,GSErrTol=0, ErrTotal=1,ArraySize=0;
  int i=0,j=0, m=0,n=0,Git=0;      //Declares all neccessary variables


  cout<<"What error tolerance would you like the Gauss Siedell to iterate to?"<<endl;
  cin>>GSErrTol;   //Takes the desired error tolerance

  ItMax=GS/delta;  //Calculates the maximum iterations required

 
  
  while (ErrTotal>GSErrTol){         //iterates while the cumalitive error is larger than the tolerance required
    ErrTotal=0;                        //Resets the cumalitive error to zero
   
   for (i=0;i<= ItMax;i++){            //iterates over the entire grid 
     for(j=0;j<= ItMax; j++){

       if(B[i][j]==false){            //If point is not a user defined boundary

	 Pre=Ug[i][j];               //Takes the value of the array point before the operation
	   
	 if (j==0){              //Uses altered formuala if at J=0 boundary
	  Ug[i][j]=(1.0/4.0)*(Ug[i+1][j]+Ug[i-1][j]+Ug[i][j+1]+Ug[i][j]);
	  }

	 else if (j==ItMax){    //Uses altered formula if at j=MAX boundary
	  Ug[i][j]=(1.0/4.0)*(Ug[i+1][j]+Ug[i-1][j]+Ug[i][j]+Ug[i][j-1]);
	  }
	   
	 else if (i==0){       //Uses altered formula if at i=0 boundary
	  Ug[i][j]=(1.0/4.0)*(Ug[i+1][j]+Ug[i][j]+Ug[i][j+1]+Ug[i][j-1]);
	  }

	 else if (i==ItMax){     //Uses altered formula if at i=MAX boundary
	  Ug[i][j]=(1.0/4.0)*(Ug[i][j]+Ug[i-1][j]+Ug[i][j+1]+Ug[i][j-1]);
	  }
	 else{
	   Ug[i][j]=(1.0/4.0)*(Ug[i+1][j]+Ug[i-1][j]+Ug[i][j+1]+Ug[i][j-1]);  //if not at boundary use normal Gauss method		     
           }
	 
	 Post=Ug[i][j];          //Takes value after the operation is carried out
	 Err=abs(Pre-Post);     // Finds the error value of each point in the grid
	 ErrTotal=ErrTotal+Err; //finds a cumaltive error for the whole grid for each iteration
       }
     }
   }
   Git++;      //Increases iteration counter after every full grid iteration
 }


 
  cout<< "Gauss Siedell took "<<Git<<" iterations to converge"<< endl;  //Outputs 



 
ofstream file;               //Opens file to write output data to
file.open("GS.dat");

for(i=0; i<= ItMax;i++){     //Iterates to output all x values
  for(j=0; j<=ItMax; j++){  //Iterates to output all y values

      x=(i-(ItMax/2))*delta;       //Converts i and j to x and y coordinates
      y=(j-(ItMax/2))*delta;
      
                            //Outputs x,y and function value at each point
        file<< x << "      "<< y<<"      "<< Ug[i][j]<< "\n";
    }
    file<<"\n";     //Inserts newline in data file
}

file.close();      //closes file

}
