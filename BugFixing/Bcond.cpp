#include"Bcond.h"
#include <QImage>
#include <QVector>
#include <QRgb>
#include<iostream>
#include"mainwindow.h"
#include"sortvec.h"
using namespace std;

double Bconds:: U[1000][1000];
bool Bconds:: B[1000][1000];
int h=0, w=0;

int Bconds:: rval;
int Bconds:: gval;
int Bconds:: bval;
double Bconds:: UV;
double Bconds:: delta;

void Bconds::Problem0(int GridSize){

  double Range=3,r=0,r1=0.5,r2=1.4,V0=10,x=0,y=0, Ex=0, Ey=0;
  double delta=Range/GridSize;
   Bconds::delta=delta;


 for (int i=0;i<=GridSize;i++){              //This loops throught the whole grid
     for(int j=0;j<=GridSize; j++){

       x=(i-(GridSize/2))*delta;       //Converts i and j to coordinates centered on inner spheres centre.
       y=(j-(GridSize/2))*delta;
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

 for(int i=0; i<=GridSize; i++){                //Loops through the entire grid
    for(int j=0; j<=GridSize; j++){
      x=(i-(GridSize/2))*delta;       //Converts i and j to coordinates centered on inner spheres centre.
      y=(j-(GridSize/2))*delta;
      r = sqrt(pow(x,2) + pow(y,2));    //Calculates the radius of each point

      if( (r<=r1)){          //If the point lies outwith the larger sphere, or within the inner sphere, set=0
        U[i][j]=0;
      }
      else if(r>=r2) {
          U[i][j]=V0;
      }
      else{                       //Otherwise use the derived analytical solution
        U[i][j] = ((V0/log(r2/r1))*log(r)) - ((V0*log(r1))/(log(r2/r1)));
      }

      file << x << "    " << y << "    " << U[i][j] << endl;    //Outputs data to the file
      }
   file<<"\n";
 }

ofstream eFile("eAnalytical1");
  for(int k=0; k<=GridSize; k++) {
    x = (k - (GridSize/2)) * delta;
    for(int m=0; m<=GridSize; m++) {
      y = (m - (GridSize/2)) * delta;
      if (k == 0) {
    Ex = (U[k][m] - U[k+1][m]) / (delta);
      } else if (k == GridSize) {
    Ex = (U[k-1][m] - U[k][m]) / (delta);
      } else {
    Ex = (U[k-1][m] - U[k+1][m]) / (2*delta);
      }
      if (m == 0) {
    Ey = (U[k][m] - U[k][m+1]) / (delta);
      } else if (m == GridSize) {
    Ey = (U[k][m-1] - U[k][m]) / (delta);
      } else {
    Ey = (U[k][m-1] - U[k][m+1]) / (2*delta);
      }
      eFile << x << "\t" << y << "\t" << Ex << "\t" << Ey << "\n";
    }
  }
  eFile.close();
  
  vecsort("eAnalytical1", GridSize);
  QProcess::startDetached("./Eplotter.sh eAnalytical1 " );
 }


void Bconds::Problem1(int GridSize){
  double Range=3, sr=0.5, V0=10, d=3, x=0,y=0,r=0, Ex, Ey;
  int i=0,j=0;
  double delta=Range/GridSize;
  Bconds::delta=delta;

 for (i=0;i<=GridSize;i++){     //Iterates through all x and y to set initial boundary conditions
     for(j=0;j<=GridSize; j++){


       x=(i-(GridSize/2))*delta;       //Converts i and j to coordinates centered on inner spheres centre.
       y=(j-(GridSize/2))*delta;
       r=sqrt(pow(x,2)+pow(y,2));    //Calculates the radius from the centre of the sphere.

       if(i==0){             //Sets the two plate values; Left plate =V0, Right plate=-V0
     U[i][j]=V0;
     B[i][j]=true;
       }
       else if(i==GridSize){
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

 for(i=0; i<=GridSize; i++){           //Iterates accross whole grid
   for(j=0; j<=GridSize; j++){

     x=(i-(GridSize/2))*delta;       //Converts i and j to coordinates centered on inner spheres centre.
     y=(j-(GridSize/2))*delta;
     r = sqrt(pow(x,2) + pow(y,2));  //Calcs radius of each point

     if(r<=sr){                             //If point within the sphere set to ground
       U[i][j]=0;
     }
     else if(r>=d && x>0){
         U[i][j]=-V0;
     }
     else if(r>=d && x<0){
         U[i][j]=V0;
     }
     else{                                 //Otherwise use the analytical solution
       U[i][j] = -(V0)*(2*x/d)*(1 - (pow(sr,3)/pow(r,3)));
     }
     file << x << "    " << y << "    " << U[i][j] << endl;  //Outputs the data to file
   }
   file<<"\n";                            //insert vertical tab
 }
 file.close(); //close file

  ofstream eFile("eAnalytical2");
  for(int k=0; k<=GridSize; k++) {
    x = (k - (GridSize/2)) * delta;
    for(int m=0; m<=GridSize; m++) {
      y = (m - (GridSize/2)) * delta;
      if (k == 0) {
    Ex = (U[k][m] - U[k+1][m]) / (delta);
      } else if (k == GridSize) {
    Ex = (U[k-1][m] - U[k][m]) / (delta);
      } else {
    Ex = (U[k-1][m] - U[k+1][m]) / (2*delta);
      }
      if (m == 0) {
    Ey = (U[k][m] - U[k][m+1]) / (delta);
      } else if (m == GridSize) {
    Ey = (U[k][m-1] - U[k][m]) / (delta);
      } else {
    Ey = (U[k][m-1] - U[k][m+1]) / (2*delta);
      }
      eFile << x << "\t" << y << "\t" << Ex << "\t" << Ey << "\n";
    }
  }
  eFile.close();

  vecsort("eAnalytical2", GridSize);
  QProcess::startDetached("./Eplotter.sh eAnalytical2" );
  
}

void Bconds::ud(int GridSize){
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
