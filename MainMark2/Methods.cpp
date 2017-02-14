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
 double Ex,Ey;

 for(i=0; i<=ItMax; i++){
    for(j=0;j<=ItMax; j++){
      Uj[i][j]=U[i][j];
    }
  } 

 ofstream errfile("dJacobi");

 
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

  ofstream vfile;               //Opens file to write output data to
  vfile.open("vJacobi");
  
  for(i=0; i<=ItMax;i++){     //Iterates to output all x values
    for(j=0; j<=ItMax; j++){  //Iterates to output all y values
      
      x=(i-(ItMax/2))*delta;       //Converts i and j to coordinates on the grid
      y=(j-(ItMax/2))*delta;
      
      //Outputs x,y and function value at each point
      vfile<< x << "      "<< y<<"      "<< Uj[i][j]<< "\n";
    }
    vfile<<"\n";     //Inserts newline in data file
  }
  
  vfile.close();      //closes file


  ofstream eFile("eJacobi");
  for(int k=0; k<=ItMax; k++) {
    x = (k - (ItMax/2)) * delta;
    for(int m=0; m<=ItMax; m++) {
      y = (m - (ItMax/2)) * delta;
      if (k == 0) {
	Ex = (Uj[k][m] - Uj[k+1][m]) / (delta);
      } else if (k == ItMax) {
	Ex = (Uj[k-1][m] - Uj[k][m]) / (delta);
      } else {
	Ex = (Uj[k-1][m] - Uj[k+1][m]) / (2*delta);
      }
      if (m == 0) {
	Ey = (Uj[k][m] - Uj[k][m+1]) / (delta);
      } else if (m == ItMax) {
	Ey = (Uj[k][m-1] - Uj[k][m]) / (delta);
      } else {
	Ey = (Uj[k][m-1] - Uj[k][m+1]) / (2*delta);
      }
      eFile << x << "\t" << y << "\t" << Ex << "\t" << Ey << "\n";
    }
  }
  eFile.close();
}


void Methods::Gauss(double a, double b, double c){
  

  float Ug[1000][1000];
  double GS=b, delta=a,GSErrTol=c;
  double ItMax=GS/delta;
  double x=0,y=0, Pre=0, Post=0,Err=0, ErrTotal=1,ArraySize=0;
  int i=0,j=0, m=0,n=0,Git=0;      //Declares all neccessary variables
  double Ex,Ey;

  for(i=0; i<=ItMax; i++){
    for(j=0;j<=ItMax; j++){
      Ug[i][j]=U[i][j];
    }
  }

   ofstream errfile("dGS");
  
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
  file.open("vGS");
  
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
  

  ofstream eFile("eGS");
  for(int k=0; k<=ItMax; k++) {
    x = (k - (ItMax/2)) * delta;
    for(int m=0; m<=ItMax; m++) {
      y = (m - (ItMax/2)) * delta;
      if (k == 0) {
	Ex = (Ug[k][m] - Ug[k+1][m]) / (delta);
      } else if (k == ItMax) {
	Ex = (Ug[k-1][m] - Ug[k][m]) / (delta);
      } else {
	Ex = (Ug[k-1][m] - Ug[k+1][m]) / (2*delta);
      }
      if (m == 0) {
	Ey = (Ug[k][m] - Ug[k][m+1]) / (delta);
      } else if (m == ItMax) {
	Ey = (Ug[k][m-1] - Ug[k][m]) / (delta);
      } else {
	Ey = (Ug[k][m-1] - Ug[k][m+1]) / (2*delta);
      }
      eFile << x << "\t" << y << "\t" << Ex << "\t" << Ey << "\n";
    }
  }
  eFile.close();

}

void Methods::SOR(double a, double b,double c){

  

   float Us[1000][1000];
   double resid=0,x=0,y=0, ErrTotal=1, InitErr=0, omega=0, Pre=0, Post=0,err=0, Uold=0;
  int n=0,i=0,j=0;       //PDE coefficients set to solve Poisson's equation as it is for this potential problem
  double GS=b, delta=a ,ErrTol=c;
  double ItMax=GS/delta;
  double r_jac=cos(3.14159265359/(ItMax+1));
  double Ex,Ey,z;
  
 for(i=0; i<=ItMax; i++){
    for(j=0;j<=ItMax; j++){
      Us[i][j]=U[i][j];
    }
  }


ofstream errfile("dSOR");   
                                     
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
    
	 for (int j=0; j<=ItMax; j++) {
	   if (OE) z = j%2;
	   else z = !(j%2);
	   for (int l=z; l<=ItMax; l+=2) {
              
	     if (B[j][l]==false) {          //if point is outwith any defined boundary zone

	       Uold = Us[j][l];           //boundary cases changed to avoid having unintended fixed boundaries, simulate infinite boundaries
	                             //residual comes from some equations somewhere, used for SOR method and error calculation
	       resid = -4*Us[j][l];
	       if (j == ItMax) resid += Us[j][l];      //If at j=MAX boundary
	       else resid += Us[j+1][l];         
	       if (j == 0) resid += Us[j][l];          //If at j=0 boundary
	       else resid += Us[j-1][l];
	       if (l == ItMax) resid += Us[j][l];      //if at l=MAX boundary
	       else resid += Us[j][l+1];
	       if (l == 0) resid += Us[j][l];          //if at l=0 boundary
	       else resid += Us[j][l-1];
	      
	       Us[j][l] -= omega*resid/(-4);

	                                       //The value of each array point is taken before and after SOR and diff is the error
	       ErrTotal += fabs(Uold - Us[j][l]);        //error calculation
	  
	     }
	  
	}
	    
      }
    }
   errfile << n << "\t" << ErrTotal << endl;
   }

   cout<<"The SOR method took " << n << " iterations to converge to the desired accuracy"<<endl;      //Outputs iterations required

    
  ofstream file("vSOR");          //output the result to a file called "u.dat"
  for (int j=0; j<=ItMax; j++) {         //Iterates accross whole grid 
     x=(j-(ItMax/2))*delta;
       for (int l=0; l<=ItMax; l++) {

      y=(l-(ItMax/2))*delta;
     
      file << x << "      " << y << "       " << Us[j][l] << "\n";    //Outputs coordinates and corresponding potential
    }
     file<<"\n";     //Inserts newline in data file
  }
  file.close();           //Close file


  ofstream eFile("eSOR");
  for(int k=0; k<=ItMax; k++) {
    x = (k - (ItMax/2)) * delta;
    for(int m=0; m<=ItMax; m++) {
      y = (m - (ItMax/2)) * delta;
      if (k == 0) {
	Ex = (Us[k][m] - Us[k+1][m]) / (delta);
      } else if (k == ItMax) {
	Ex = (Us[k-1][m] - Us[k][m]) / (delta);
      } else {
	Ex = (Us[k-1][m] - Us[k+1][m]) / (2*delta);
      }
      if (m == 0) {
	Ey = (Us[k][m] - Us[k][m+1]) / (delta);
      } else if (m == ItMax) {
	Ey = (Us[k][m-1] - Us[k][m]) / (delta);
      } else {
	Ey = (Us[k][m-1] - Us[k][m+1]) / (2*delta);
      }
      eFile << x << "\t" << y << "\t" << Ex << "\t" << Ey << "\n";
    }
  }
  eFile.close();

}

  
