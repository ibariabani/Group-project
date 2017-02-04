#include"Main.h"             //Includes all the header files of the linked cpp programs
#include"Gauss.h"
#include"Jacobi.h"
#include"BConds.h"
#include"SOR.h"
#include"Problem1.h"
#include"Problem2.h"

using namespace std;
float Ug[10000][10000];         //Decalres all arrays required in other files with global scope, ready for extern 
float Uj[10000][10000];
float Us[10000][10000];
bool B[10000][10000]={false};   //Boolean matrix is either true or false- default is set to false

int main(){
  
  char E,J, G, S;    //Declares characters to take the Yes or No for each method

  cout<<"This program allows you to enter a set up a electrostatic potential problem"<< endl;
  cout<<"with your own boundary conditions, and uses an array of numerical methods to" <<endl;
  cout<<"provide an approximation of the potential at all points."<<"\n"<<endl;  //Spiel about the point of the program

  //This next few lines asks if the user wants to run one of the two preset examples
  cout<<"There are two preset examples which have analytical solutions to compare the numerical approximations to."<<endl;
  cout<<"Type 1 to run the first example, 2 to run the 2nd example, or any other key to skip to defining your own problem."<<endl;
  cin>>E;
  if (E=='1'){        //Runs example 1 if that is what asked for
    Problem1();
  }
  else if(E=='2'){    //Runs example 2 if that is what is asked for
    Problem2();
    }

  
  else{
    BConds();     //If neither example wanted, runs the boundary condition program and gets the user input boundary matrix 
  
    cout<<"Please choose which Numerical methods you would like to run on this problem" <<endl;
    cout<<"Would you like to run the Jacobi Method? Type Y for yes, any other key for no"<<endl;
    cin>>J;                    //Asks the user if they wish to use the Jacobi method

    if (J=='Y'){      //If yes then runs the Jacobi method on the set up defined in the BConds file
      Jacobi();
    }
  
    cout<<"Would you like to run the Gauss Siedell Method? Type Y for yes, any other key for no"<<endl;
    cin>>G;                 //Asks the user if they want to run the Gauss Siedell method

    if (G=='Y'){           // If yes Runs the Gauss method on the set up entered in the bconds file
      Gauss();
    }

  
    cout<<"Would you like to run the SOR  Method? Type Y for yes, any other key for no"<<endl;
    cin>>S;                //Asks the user if they want to run the SOR method 
 
    if (S=='Y'){          // If yes then runs the SOR method on the users set up
      SOR(); 
    }
  
  }
  return 0;
}

  

  
  
  
