#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <fstream>
#include<cmath>
#include<cstdlib>
#include"fstream"
#include"Bcond.h"
#include "Methods.h"
#include <chrono> //required library for time measurements

// /!\ -std=c++11 is required in the compiler for the <chrono> library to work correctly /!\


using namespace std;

using std::chrono::steady_clock;
using std::chrono::time_point;
using std::chrono::duration_cast;
using std::chrono::milliseconds;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.show();

    //return a.exec();

    /*QImage img( "test.jpg" );

    ofstream file;
    file.open("Colour.dat");

    if ( false == img.isNull() )
    {
        QVector<QRgb> v = img.colorTable();
        for ( int i = 0; i < img.width() - 1; ++i )
            for ( int j = 0; j < img.height() - 1; ++j )
            {
                QColor clrCurrent( img.pixel( i, j ) );

                /*if (clrCurrent.red() == 0 && clrCurrent.green() == 0 && clrCurrent.blue() == 0)
                {
                    V[i][j] = 0;
                }

                else if (clrCurrent.red() == 255 && clrCurrent.green() == 0 && clrCurrent.blue() == 0)
                {
                    V[i][j] = -V0;
                }

                else if (clrCurrent.red() == 0 && clrCurrent.green() == 255 && clrCurrent.blue() == 0)
                {
                    V[i][j] = V0;
                }

                else if (clrCurrent.red() == 255 && clrCurrent.green() == 255 && clrCurrent.blue() == 255)
                {
                    //run function
                }


                file << "Pixel at [" << i << "," << j << "] contains color ("
                          << clrCurrent.red() << ", "
                          << clrCurrent.green() << ", "
                          << clrCurrent.blue() << ")."

                     << std::endl;


            }

}
    file.close();
    */


    double delta=1, GS=100000, ErrTol=0;
    char J,G,S,z,n;

    cout<<"This program numerically solves electrostatics problems and returns the potential and electric field."<<"\n"<<endl;
    cout<<"There are 3 numerical methods to choose from, and you can run several and compare efficiency etc if you wish."<<"\n"<<endl;
    cout<<"Before defining your setup, you must enter the dimensions of your setup, and a step size for the methods."<<"\n"<<endl;

    while((GS/delta)>1000){
      cout<<"Please enter the dimension of your setup (distance from side to side)"<<endl;
      cin>>GS;
      cout<<"What step size would you like to use?"<<endl;
      cin>>delta;
      cout<<"What error tolerances would you like to run your methods to?"<<endl;
      cin>>ErrTol;

      if(GS/delta>1000){
        cout<<"The dimension divided by the step size must not be larger than 1000"<<endl;
      }
    }


    cout<<"There are two preset examples with analytical solutions for comparisons,"<<endl;
    cout<< " would you like to run one of these? Type Y for yes or any other key to skip to defining your own boundaries"<<endl;
    cin>>z;
    if(z=='Y'){
      cout<<"Type 1 for concentric spheres, and 2 for a sphere between two parralel plates"<<endl;
      cin>>n;

      if(n=='1'){
        Bconds::Problem1(delta,GS);
      }
      else if(n=='2'){
         Bconds::Problem2(delta,GS);
      }
    }
else {
    Bconds::ud(delta, GS);
}
     for(int i=0;i<=(GS/delta);i++){
          for(int j=0;j<=(GS/delta);j++){
            //  cout<<Bconds::U[i][j];
        Methods::U[i][j]=Bconds::U[i][j];
        Methods::B[i][j]=Bconds::B[i][j];
      }
      }


    cout<<"Would you like to run the Jacobi Method? Type Y for yes, any other key for no,"<<endl;
    cin>>J;

    if(J=='Y'){
      time_point<steady_clock> Jstart = steady_clock::now(); //declaring start time

      Methods::Jacobi(delta,GS,ErrTol);

      time_point<steady_clock> Jend = steady_clock::now(); //end time
      milliseconds Jtime = duration_cast<milliseconds>(Jend-Jstart); //calculate time difference
      cout << "The Jacobi method took " << Jtime.count() << "ms to solve the problem." << endl;
    }

    cout<<"Would you like to run the Gauss Siedell? Press Y for yes, or any other key for no,"<<endl;
    cin>>G;

    if (G=='Y'){
      time_point<steady_clock> Gstart = steady_clock::now(); //declaring start time

      Methods::Gauss(delta, GS,ErrTol);

      time_point<steady_clock> Gend = steady_clock::now(); //end time
      milliseconds Gtime = duration_cast<milliseconds>(Gend-Gstart); //calculate time difference
      cout << "The Gauss-Seidell method took " << Gtime.count() << "ms to solve the problem." << endl;
    }

     cout<<"Would you like to run the SOR method?Press Y for yes or  any other key for no,"<<endl;
    cin>>S;

    if (S=='Y'){
      time_point<steady_clock> Sstart = steady_clock::now(); //declaring start time

      Methods::SOR(delta, GS,ErrTol);

      time_point<steady_clock> Send = steady_clock::now(); //end time
      milliseconds Stime = duration_cast<milliseconds>(Send-Sstart); //calculate time difference
      cout << "The SOR method took " << Stime.count() << "ms to solve the problem." << endl;
    }



}
