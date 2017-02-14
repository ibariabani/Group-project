#include"Methods.h"

using namespace std;

double Methods:: U[1000][1000];
bool Methods:: B[1000][1000];



void Methods::Jacobi(double a, double b,double c){
  
 float UNew[1000][1000];                                        //Declare large array outside stack
 float Uj[1000][1000];
 double x=0,y=0, Pre=0, Post=0,Err=0, it=0, ErrTotal=1;     //Declares all neccesary variables
 int i=0,j=0,m=0,n=0;
 double GS=b, delta=a, ErrTol=c;
 double ItMax=GS/delta;

 for(i=0; i<=ItMax; i++){
    for(j=0;j<=ItMax; j++){
      Uj[i][j]=U[i][j];
    }
  } 

 ofstream errfile("Jacobidiff.dat");

 
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

    errfile << it << "\t" << ErrTotal << endl;
}

errfile.close();

  
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



void Methods::Gauss(double a, double b, double c){
  

 float Ug[1000][1000];
 double GS=b, delta=a,GSErrTol=c;
 double ItMax=GS/delta;
 double x=0,y=0, Pre=0, Post=0,Err=0, ErrTotal=1,ArraySize=0;
  int i=0,j=0, m=0,n=0,Git=0;      //Declares all neccessary variables

  for(i=0; i<=ItMax; i++){
    for(j=0;j<=ItMax; j++){
      Ug[i][j]=U[i][j];
    }
  }

   ofstream errfile("Gaussdiff.dat");
  
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

   errfile << Git << "\t" << ErrTotal << endl;
 }
errfile.close();

 
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

void Methods::SOR(double a, double b,double c){

  

   float Us[1000][1000];
   double resid=0,x=0,y=0, ErrTotal=1, InitErr=0, omega=0, Pre=0, Post=0,err=0, Uold=0;
  int a1=1,b1=1,c1=1,d1=1,e1=-4, n=0,i=0,j=0;       //PDE coefficients set to solve Poisson's equation as it is for this potential problem
  double GS=b, delta=a ,ErrTol=c;
  double ItMax=GS/delta;
  double r_jac=cos(3.14159265359/(ItMax+1));
  
 for(i=0; i<=ItMax; i++){
    for(j=0;j<=ItMax; j++){
      Us[i][j]=U[i][j];
    }
  }


ofstream errfile("SORdiff.dat");   
                                     
   while (ErrTotal>ErrTol){            //Iterates whilst the cumalitive error on each full grid iteration is above the tolerance
     ErrTotal=0;                                  //resets the error to 0 for each new full grid iteration
     n++;                                      //increments iteration counter
    
     for (int OE=1; OE>=0; OE--) {       //divides each iterations in two half-steps, one with odd points, the other with even point
                                       //(cf: Numerical recipes p892 for info)
         if (n == 1) {                      //calculate omega, changes with each half-step
         	if (OE == 1) {
	            omega = 1;       //first iteration
	            }
	        else {
		  omega = 1/(1-r_jac*r_jac/2); //1.5th iteration
              	}	
          }
      
         else {
        	omega = 1/(1-r_jac*r_jac*omega/4); //other iterations, uses r_jac
          }
    
	 for (int j=OE; j<=ItMax; j+=2) {
	   for (int l=0; l<=ItMax; l++) {
              
	     if (B[j][l]==false) {          //if point is outwith any defined boundary zone

	       Uold = Us[j][l];           //boundary cases changed to avoid having unintended fixed boundaries, simulate infinite boundaries
	                             //residual comes from some equations somewhere, used for SOR method and error calculation
	       resid = e1*Us[j][l];
	       if (j == ItMax) resid += a1*Us[j][l];      //If at j=MAX boundary
	       else resid += a1*Us[j+1][l];         
	       if (j == 0) resid += b1*Us[j][l];          //If at j=0 boundary
	       else resid += b1*Us[j-1][l];
	       if (l == ItMax) resid += c1*Us[j][l];      //if at l=MAX boundary
	       else resid += c1*Us[j][l+1];
	       if (l == 0) resid += d1*Us[j][l];          //if at l=0 boundary
	       else resid += d1*Us[j][l-1];
	      
	       Us[j][l] -= omega*resid/e1;

	                                       //The value of each array point is taken before and after SOR and diff is the error
	       ErrTotal += fabs(Uold - Us[j][l]);        //error calculation
	  
	     }
	  
	}
	    
      }
    }
   errfile << n << "\t" << ErrTotal << endl;
   }

   cout<<"The SOR method took " << n << " iterations to converge to the desired accuracy"<<endl;      //Outputs iterations required

    
  ofstream file("SOR.dat");          //output the result to a file called "u.dat"
  for (int j=0; j<=ItMax; j++) {         //Iterates accross whole grid 
     x=(j-(ItMax/2))*delta;
       for (int l=0; l<=ItMax; l++) {

      y=(l-(ItMax/2))*delta;
     
      file << x << "      " << y << "       " << Us[j][l] << "\n";    //Outputs coordinates and corresponding potential
    }
     file<<"\n";     //Inserts newline in data file
  }
  file.close();           //Close file



   }

  
