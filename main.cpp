#include "mainwindow.h"
#include <QApplication>
#include<iostream>  /*Includes all necessary libraries and other header files*/
#include<cmath>
#include<cstdlib>
#include"fstream"
#include"Bcond.h"
#include"Methods.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
