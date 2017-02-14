#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <fstream>

using namespace std;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //return a.exec();

    QImage img( "test.jpg" );

    ofstream file;
    file.open("Colour.dat");

    if ( false == img.isNull() )
    {
        QVector<QRgb> v = img.colorTable();
        for ( int i = 0; i < img.width() - 1; ++i )
            for ( int j = 0; j < img.height() - 1; ++j )
            {
                QColor clrCurrent( img.pixel( i, j ) );

                if (clrCurrent.red() == 0 && clrCurrent.green() == 0 && clrCurrent.blue() == 0)
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


                /*file << "Pixel at [" << row << "," << col << "] contains color ("
                          << clrCurrent.red() << ", "
                          << clrCurrent.green() << ", "
                          << clrCurrent.blue() << ")."

                     << std::endl;
                     */

            }

}
    file.close();
}
