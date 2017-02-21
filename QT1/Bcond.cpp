#include"Bcond.h"
#include <QImage>
#include <QVector>
#include <QRgb>
#include<iostream>
#include"mainwindow.h"
using namespace std;

double Bconds:: U[1000][1000];
bool Bconds:: B[1000][1000];
int h=0, w=0;

int Bconds:: rval;
int Bconds:: gval;
int Bconds:: bval;
double Bconds:: UV;

void Bconds::Problem1(double a, double b){

  double GS=b, delta=a,r=0,r1=0.5,r2=1.4, V=0,V0=10,x=0,y=0;
  double ItMax=GS/delta;

/*cout<< "Please enter the radius of the inner sphere"<<endl;
cin>>r1;
cout<< "Please enter the radius of the outer sphere"<<endl;
cin>>r2;
cout<< "Please enter the potential at the outer sphere"<<endl;
cin>>V0;
*/
 for (int i=0;i<=ItMax;i++){              //This loops throught the whole grid
     for(int j=0;j<=ItMax; j++){

       x=(i-(ItMax/2))*delta;       //Converts i and j to coordinates centered on inner spheres centre.
       y=(j-(ItMax/2))*delta;
       r=sqrt(pow(x,2)+pow(y,2));

       if (r>=r2){  //If point is on, or close to on, the outer circle, define as V0
         U[i][j]=V0;                    //Slight inaccuray due to the inexact nature of the x and y coordinate conversion
     B[i][j]=true;
         }
       else if (r<=r1){
     U[i][j]=0;                 // Otherwise set the value to zero for the Gauss to work on
     B[i][j]=true;
     }
       else{
     U[i][j]=0;
       B[i][j]=false;
       }
     }
 }

ofstream file;                         //Opens a file to write the analytical solution data to
file.open("vAnalytical1");

 for(int i=0; i<=ItMax; i++){                //Loops through the entire grid
    for(int j=0; j<=ItMax; j++){
      x=(i-(ItMax/2))*delta;       //Converts i and j to coordinates centered on inner spheres centre.
      y=(j-(ItMax/2))*delta;
      r = sqrt(pow(x,2) + pow(y,2));    //Calculates the radius of each point

      if( (r<=r1)){          //If the point lies outwith the larger sphere, or within the inner sphere, set=0
        V=0;
      }
      else if(r>=r2) {
          V=V0;
      }
      else{                       //Otherwise use the derived analytical solution
        V = ((V0/log(r2/r1))*log(r)) - ((V0*log(r1))/(log(r2/r1)));
      }

      file << x << "    " << y << "    " << V << endl;    //Outputs data to the file
      }
   file<<"\n";
 }


 }


void Bconds::Problem2(double a, double b){
  double sr=0.5, V0=10, V=0, d=3, x=0,y=0,r=0;
  int i=0,j=0;
  double GS=b, delta=a;
  double ItMax=GS/delta;

  /*cout<< "Please enter the radius of the sphere"<<endl;
  cin>>sr;
  cout<< "Please enter the absolute value of the potential at the plates"<<endl;
  cin>>V0;
  cout<< "Please enter the seperation of the plates. This must be larger than the diameter of the sphere"<<endl;
  cin>>d;


  if ((2*sr)>d)
    {
      cout<<"The plates lie within the sphere. Please fix this"<<endl;
     }
     */


 for (i=0;i<=ItMax;i++){     //Iterates through all x and y to set initial boundary conditions
     for(j=0;j<=ItMax; j++){


       x=(i-(ItMax/2))*delta;       //Converts i and j to coordinates centered on inner spheres centre.
       y=(j-(ItMax/2))*delta;
       r=sqrt(pow(x,2)+pow(y,2));    //Calculates the radius from the centre of the sphere.

       if(i==0){             //Sets the two plate values; Left plate =V0, Right plate=-V0
     U[i][j]=V0;
     B[i][j]=true;
       }
       else if(i==ItMax){
     U[i][j]=-V0;
     B[i][j]=true;
       }
       else if(sr>r){
     U[i][j]=0;    //Sets all other values to 0
     B[i][j]=true;
     }
       else{
         U[i][j]=0;
     B[i][j]=false;
       }

     }
 }


 ofstream file;                //Opens data file to write analytical solution to
 file.open("vAnalytical2");

 for(i=0; i<=ItMax; i++){           //Iterates accross whole grid
   for(j=0; j<=ItMax; j++){

     x=(i-(ItMax/2))*delta;       //Converts i and j to coordinates centered on inner spheres centre.
     y=(j-(ItMax/2))*delta;
     r = sqrt(pow(x,2) + pow(y,2));  //Calcs radius of each point

     if(sr>r){                             //If point within the sphere set to ground
       V=0;
     }
     else{                                 //Otherwise use the analytical solution
       V = -(V0)*(2*x/d)*(1 - (pow(sr,3)/pow(r,3)));
     }
     file << x << "    " << y << "    " << V << endl;  //Outputs the data to file
   }
   file<<"\n";                            //insert vertical tab
 }
 file.close();                           //close file

}

void Bconds::ud(double a, double b){
    double V0=10;
    int j2;
    QImage img( "test1.png" );
    h=img.height();
    w=img.width();

    cout << "rval " << rval << " gval " << gval << " bval " << bval << " UV " << UV <<endl;

    if ( false == img.isNull() )
    {
        QVector<QRgb> v = img.colorTable();
        for ( int i = 0; i <=w-1; ++i ){
            for ( int j = h-1; j>=0; --j )
            {
                j2 = h-j;

                QColor clrCurrent( img.pixel( i, j ) );

                if (clrCurrent.red() == 0 && clrCurrent.green() == 0 && clrCurrent.blue() == 0)
                {
                    U[i][j2] = 0;
                    B[i][j2] = true;
                }

                else if (clrCurrent.red() == rval && clrCurrent.green() == gval && clrCurrent.blue() == bval)
                {
                    U[i][j2] = UV;
                    B[i][j2] = true;

                    cout << "i= " << i << " j2= " << j2 << endl;
                }

                else if (clrCurrent.red() == 255 && clrCurrent.green() == 0 && clrCurrent.blue() == 0)
                {
                    U[i][j2] = V0;
                    B[i][j2] = true;
                }

                else if (clrCurrent.red() == 0 && clrCurrent.green() == 255 && clrCurrent.blue() == 0)
                {
                    U[i][j2] = -V0;
                    B[i][j2] = true;
                }

                else if (clrCurrent.red() == 255 && clrCurrent.green() == 255 && clrCurrent.blue() == 255)
                {
                    U[i][j2] = 0;
                    B[i][j2] = false;

               }

}
}
}

}
