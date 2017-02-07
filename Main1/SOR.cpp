#include"SOR.h"

//this program solves Poissons equation using the SOR scheme (kinda)

/* Rho Jacobi, it's an important parameter of the SOR (and what makes it actually work better than other methods)
 but a pain to calculate, so I set a random value
 For the numerical problem we have to solve, 0.98 seems to be very good */

//put functions everywhere 

using namespace std;

int SOR(){

  double resid=0,x=0,y=0, ItMax=0, error=1, InitErr=0, omega=0,ErrTol=1, Pre=0, Post=0,err=0;
  int a=1,b=1,c=1,d=1,e=-4, n=0;              //PDE coefficients set to solve Poisson's equation as it is for this potential problem
  double r_jac=cos(3.14159265359/(ItMax+1));
  
  ItMax=GS/delta;                            //Calculate the maximum number of iterations required
  
   cout<<"Please enter the reduction factor that you want Succesive Over Relaxation to iterate to"<<endl;
   cin>>ErrTol;                              //Takes the desired error tolerance for the SOR

                                     
   while (error>(ErrTol*InitErr)){            //Iterates whilst the cumalitive error on each full grid iteration is above the tolerance
     error=0;                                  //resets the error to 0 for each new full grid iteration
     n++;                                      //increments iteration counter
     cout<<n<<endl;
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
	                                //boundary cases changed to avoid having unintended fixed boundaries, simulate infinite boundaries
	                             //residual comes from some equations somewhere, used for SOR method and error calculation
	       resid = e*Us[j][l];
	       if (j == ItMax) resid += a*Us[j][l];      //If at j=MAX boundary
	       else resid += a*Us[j+1][l];         
	       if (j == 0) resid += b*Us[j][l];          //If at j=0 boundary
	       else resid += b*Us[j-1][l];
	       if (l == ItMax) resid += c*Us[j][l];      //if at l=MAX boundary
	       else resid += c*Us[j][l+1];
	       if (l == 0) resid += d*Us[j][l];          //if at l=0 boundary
	       else resid += d*Us[j][l-1];
	      
	       Us[j][l] -= omega*resid/e;

	                                       //The value of each array point is taken before and after SOR and diff is the error
	       error += fabs(resid);         //error calculation
	  
	     }
	  
	}
	    
      }
	 if(n==1){
	   InitErr=error;
	 }
    }
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


  return 0;
   }

  
