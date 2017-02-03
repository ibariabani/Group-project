#include"Main.h"
#include"Gauss.h"
#include"Jacobi.h"
#include"BConds.h"
#include"SOR.h"

using namespace std;
float Ug[10000][10000];         //Decalres all arrays required in other files with global scope
float Uj[10000][10000];
float Us[10000][10000];
bool B[10000][10000]={false};

int main(){
  
  char J, G, S;    //Declares 3 characters to take the Yes or No for each method

  cout<<"This program allows you to enter a set up a electrostatic potential problem"<< endl;
  cout<<"with your own boundary conditions, and uses an array of numerical methods to" <<endl;
  cout<<"provide an approximation of the potential at all points."<<endl;
    

  BConds();     //Runs the boundary condition program and gets the user input boundary matrix 

  cout<<"Please choose which Numerical methods you would like to run on this problem" <<endl;
  cout<<"Would you like to run the Jacobi Method? Type Y for yes, any other key for no"<<endl;
  cin>>J;                    //Asks the user if they wish to use the Jacobi method

  if (J=='Y'){      //If yes then runs the Jacobi method
    Jacobi();
  }
  
  cout<<"Would you like to run the Gauss Siedell Method? Type Y for yes, any other key for no"<<endl;
  cin>>G;                 //Asks the user if they want to run the Gauss Siedell method

  if (G=='Y'){           // If yes Runs the method
    Gauss();
  }

  
  cout<<"Would you like to run the SOR  Method? Type Y for yes, any other key for no"<<endl;
  cin>>S;
 
  if (S=='Y'){
    SOR();
  }
  

  return 0;
}

  

  
  
  
