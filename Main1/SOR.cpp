#include"SOR.h"

//this program solves Poissons equation using the SOR scheme (kinda)

/* Rho Jacobi, it's an important parameter of the SOR (and what makes it actually work better than other methods)
 but a pain to calculate, so I set a random value
 For the numerical problem we have to solve, 0.98 seems to be very good */

//put functions everywhere 

using namespace std;

int SOR(){

  double resid=0,x=0,y=0, ItMax=0, ErrTol=0,omega=0,ErrTotal=1, Pre=0, Post=0,err=0;
  int a=1,b=1,c=1,d=1,e=-4, n=0;              //PDE coefficients set to solve Poisson's equation as it is for this potential problem
  double r_jac=cos(3.14159265359/(ItMax+1));
  
  ItMax=GS/delta;
  
   cout<<"Please enter the error tolerance that you want Succesive Over Relaxation to iterate to"<<endl;
   cin>>ErrTol;

                                       //performs the SOR computation
 while (ErrTotal>ErrTol){                 //number of total iterations
  ErrTotal=0;
  n++;

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
	       Pre=Us[j][l];              //boundary cases changed to avoid having unintended fixed boundaries, simulate infinite boundaries
	                             //residual comes from some equations somewhere, used for SOR method and error calculation
	       resid = e*Us[j][l];
	       if (j == ItMax) resid += a*Us[j][l];
	       else resid += a*Us[j+1][l];
	       if (j == 0) resid += b*Us[j][l];
	       else resid += b*Us[j-1][l];
	       if (l == ItMax) resid += c*Us[j][l];
	       else resid += c*Us[j][l+1];
	       if (l == 0) resid += d*Us[j][l];
	       else resid += d*Us[j][l-1];
	      
	       Us[j][l] -= omega*resid/e;
	                                      //calculates the updated u(j,l) using omega and resid
	       Post=Us[j][l];
	       // error += fabs(resid);         //error calculation
	       err=abs(Pre-Post);
	       ErrTotal=ErrTotal+err;
	     }
	  
	}
	    
      }
    }
   }

    cout<<"The SOR method took " << n << " iterations to converge to the desired accuracy"<<endl;

    
  ofstream file("SOR.dat");          //output the result to a file called "u.dat"
  for (int j=0; j<=ItMax; j++) {
     x=(j-(ItMax/2))*delta;
                              
    for (int l=0; l<=ItMax; l++) {

      y=(l-(ItMax/2))*delta;
     
      file << x << "      " << y << "       " << Us[j][l] << "\n";
    }
     file<<"\n";     //Inserts newline in data file
  }
  file.close();


  return 0;
   }

  
