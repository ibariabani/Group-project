#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"Bcond.h"
#include"Methods.h"
#include"QProcess"
#include"QPixmap"
#include"QImage"
#include"QGraphicsScene"
#include"QFile"
#include"fstream"
#include"QGraphicsPixmapItem"
#include"QGraphicsView"
#include<QtWidgets>
#include"QApplication"
#include"QPainter"
#include <unistd.h>
#include<QString>
#include"sortvec.h"

using namespace std;

double delta=0.01, GS=3, ErrTol=0.01, radius=0, cx=0, cy=0, l1x=0, l1y=0, l2x=0, l2y=0, tlx=0, tly=0, brx=0, bry=0;
bool p1=false,p2=false,p3=false;
QColor colour;
int shape=0;
int Grid=int(GS/delta);


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


void MainWindow::on_deltaVal_valueChanged(double arg1)
{
    delta=arg1;
    if (p1==true){
        on_Problem1_clicked();
    }
    else if (p2==true){
        on_Problem2_clicked();
    }
    else if (p3==true){
        on_UD_clicked();
    }

    }

void MainWindow::on_ErrTol_valueChanged(double arg1)
{
    ErrTol=arg1;
   }


void MainWindow::on_Problem1_clicked()
{    
    ui->label_2->setEnabled(false);
    ui->Circlegroup->setEnabled(false);
    ui->Rectanglegroup->setEnabled(false);
    ui->Linegroup->setEnabled(false);
    ui->Draw->setEnabled(false);
    ui->Draw_2->setEnabled(false);
    ui->groupBox_3->setEnabled(false);
    ui->groupBox_4->setEnabled(false);

        p1=true;
        p2=false;
        p3=false;
    Bconds::Problem1(delta, GS);
    QProcess::startDetached("./Users/ibariezeabani/Desktop/Group Project/Qt/QtTues/TempPlotter.sh vAnalytical1");
    sleep(5);

    QImage image("/Users/ibariezeabani/Desktop/Group Project/Qt/QtTues/vAnalytical1.png");

            QGraphicsScene* scene = new QGraphicsScene();
            QGraphicsPixmapItem* Item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
            QGraphicsView* Display= new QGraphicsView(scene);
                        scene->addItem(Item);
                        Display->show();
}

void MainWindow::on_Problem2_clicked()
{
    ui->label_2->setEnabled(false);
    ui->Circlegroup->setEnabled(false);
    ui->Rectanglegroup->setEnabled(false);
    ui->Linegroup->setEnabled(false);
    ui->Draw->setEnabled(false);
    ui->Draw_2->setEnabled(false);
    ui->groupBox_3->setEnabled(false);
    ui->groupBox_4->setEnabled(false);

    p1=false;
    p2=true;
    p3=false;
    Bconds::Problem2(delta, GS);
    QProcess::startDetached("./TempPlotter.sh vAnalytical2");
    sleep(5);
    QImage image("vAnalytical2.png");


    QGraphicsScene* scene = new QGraphicsScene();
    QGraphicsPixmapItem* Item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    QGraphicsView* Display1= new QGraphicsView(scene);
                scene->addItem(Item);
                Display1->show();  
}

void MainWindow::on_red_clicked()
{
    colour = Qt::red;
    ui->groupBox_4->setEnabled(true);
    ui->label_2->setEnabled(true);
}

void MainWindow::on_green_clicked()
{
    colour = Qt::green;
    ui->groupBox_4->setEnabled(true);
    ui->label_2->setEnabled(true);
}

void MainWindow::on_black_clicked()
{
    colour = Qt::black;
    ui->groupBox_4->setEnabled(true);
    ui->label_2->setEnabled(true);
}

void MainWindow::on_UD_clicked()
{
    radius=0, cx=0, cy=0, l1x=0, l1y=0, l2x=0, l2y=0, tlx=0, tly=0, brx=0, bry=0;
    p1=false;
    p2=false;
    p3=true;
    QPixmap pixmap(QSize(301,301));
    QPainter painter(&pixmap);
    pixmap.fill(Qt::white);
    pixmap.save("test1.png", "PNG", 100);

    //activate options
    ui->groupBox_3->setEnabled(true);
    ui->Jacobi->setEnabled(false);
    ui->GaussSeidell->setEnabled(false);
    ui->SOR->setEnabled(false);
}


void MainWindow::on_GaussSeidell_clicked()
{
    for(int i=0;i<=(GS/delta);i++){
         for(int j=0;j<=(GS/delta);j++){
       Methods::U[i][j]=Bconds::U[i][j];
       Methods::B[i][j]=Bconds::B[i][j];
     }
     }
 Methods::Gauss(delta, GS, ErrTol);
 QProcess::startDetached("./TempPlotter.sh vGS" );
 vecsort("eSOR", Grid);
 QProcess::startDetached("./Eplotter.sh eGS " );
 sleep(5);

 QImage imageC("eGS.png");
 QGraphicsScene* sceneC = new QGraphicsScene();
 QGraphicsPixmapItem* ItemC = new QGraphicsPixmapItem(QPixmap::fromImage(imageC));
 QGraphicsView* DisplayC= new QGraphicsView(sceneC);
             sceneC->addItem(ItemC);
             DisplayC->show();

 QImage image("vGS.png");
 QGraphicsScene* scene = new QGraphicsScene();
 QGraphicsPixmapItem* Item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
 QGraphicsView* Display2= new QGraphicsView(scene);
             scene->addItem(Item);
             Display2->show();
}

void MainWindow::on_SOR_clicked()
{
    for(int i=0;i<=(GS/delta);i++){
         for(int j=0;j<=(GS/delta);j++){
       Methods::U[i][j]=Bconds::U[i][j];
       Methods::B[i][j]=Bconds::B[i][j];
     }
     }
 Methods::SOR(delta, GS, ErrTol);
 QProcess::startDetached("./TempPlotter.sh vSOR" );
 vecsort("eSOR", Grid);
 QProcess::startDetached("./Eplotter.sh eSOR " );
  sleep(5);

  QImage imageA("eSOR.png");
  QGraphicsScene* sceneA = new QGraphicsScene();
  QGraphicsPixmapItem* ItemA = new QGraphicsPixmapItem(QPixmap::fromImage(imageA));
  QGraphicsView* DisplayA= new QGraphicsView(sceneA);
              sceneA->addItem(ItemA);
              DisplayA->show();

 QImage image("vSOR.png");
 QGraphicsScene* scene = new QGraphicsScene();
 QGraphicsPixmapItem* Item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
 QGraphicsView* Display3= new QGraphicsView(scene);
             scene->addItem(Item);
             Display3->show();
}


void MainWindow::on_Jacobi_clicked(bool checked)
{
    for(int i=0;i<=(GS/delta);i++){
         for(int j=0;j<=(GS/delta);j++){
       Methods::U[i][j]=Bconds::U[i][j];
       Methods::B[i][j]=Bconds::B[i][j];
     }
     }
 Methods::Jacobi(delta, GS, ErrTol);
 QProcess::startDetached("./TempPlotter.sh vJacobi" );
 vecsort("eSOR", Grid);
 QProcess::startDetached("./Eplotter.sh eJacobi " );
  sleep(5);


  QImage imageB("eJacobi.png");
  QGraphicsScene* sceneB = new QGraphicsScene();
  QGraphicsPixmapItem* ItemB = new QGraphicsPixmapItem(QPixmap::fromImage(imageB));
  QGraphicsView* DisplayB= new QGraphicsView(sceneB);
              sceneB->addItem(ItemB);
              DisplayB->show();

 QImage image("vJacobi.png");
 QGraphicsScene* scene = new QGraphicsScene();
 QGraphicsPixmapItem* Item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
 QGraphicsView* Display4= new QGraphicsView(scene);
             scene->addItem(Item);
             Display4->show();
}


MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_circle_clicked()
{
    shape = 1;
    ui->Circlegroup->setEnabled(true);
    ui->Rectanglegroup->setEnabled(false);
    ui->Linegroup->setEnabled(false);
    ui->Draw->setEnabled(true);
    ui->Draw_2->setEnabled(true);
}

void MainWindow::on_line_clicked()
{
    shape = 2;
    ui->Linegroup->setEnabled(true);
    ui->Circlegroup->setEnabled(false);
    ui->Rectanglegroup->setEnabled(false);
    ui->Draw->setEnabled(true);
    ui->Draw_2->setEnabled(true);
}

void MainWindow::on_rectangle_clicked()
{
    shape = 3;
    ui->Rectanglegroup->setEnabled(true);
    ui->Circlegroup->setEnabled(false);
    ui->Linegroup->setEnabled(false);
    ui->Draw->setEnabled(true);
    ui->Draw_2->setEnabled(true);
}

void MainWindow::on_HorizLinear_valueChanged(double arg1)
{
    cx = arg1;
}

void MainWindow::on_VertLinear_valueChanged(double arg1)
{
    cy = (GS/delta)-arg1;
}

void MainWindow::on_VertLinear_3_valueChanged(double arg1)
{
    radius = arg1;
}

void MainWindow::on_HorizLinear_2_valueChanged(double arg1)
{
    l1x = arg1;
}

void MainWindow::on_VertLinear_2_valueChanged(double arg1)
{
    l1y = (GS/delta)-arg1;
}

void MainWindow::on_HorizLinear_3_valueChanged(double arg1)
{
    l2x = arg1;
}

void MainWindow::on_VertLinear_4_valueChanged(double arg1)
{
    l2y = (GS/delta)-arg1;
}

void MainWindow::on_HorizLinear_4_valueChanged(double arg1)
{
    tlx = arg1;
}

void MainWindow::on_VertLinear_6_valueChanged(double arg1)
{
    tly = (GS/delta)-arg1;
}

void MainWindow::on_HorizLinear_5_valueChanged(double arg1)
{
    brx = arg1;
}

void MainWindow::on_VertLinear_5_valueChanged(double arg1)
{
    bry = (GS/delta)-arg1;
}

void MainWindow::on_Draw_clicked()
{
    QPixmap pixmap(QSize(300,300));
    pixmap.load("test1.png");
    QPainter painter(&pixmap);

    if (shape == 1)
    {
        painter.setPen(colour);
        painter.drawEllipse(QPointF(cx,cy), radius, radius);
    }

    else if (shape == 2)
    {
        painter.setPen(colour);
        QLineF line(l1x, l1y, l2x, l2y);
        painter.drawLine(line);
    }

    else if (shape == 3)
    {
        painter.setPen(colour);
        QRectF rect(QPointF(tlx,tly),QPointF(brx,bry));
        painter.drawRect(rect);
    }

    pixmap.save("test1.png", "PNG", 100);
    QImage image("test1.png");
    QGraphicsScene* scene = new QGraphicsScene();
    QGraphicsPixmapItem* Item = new QGraphicsPixmapItem(QPixmap::fromImage(image));

    scene->addItem(Item);
    ui->graphicsView->setScene(scene);

    ui->Circlegroup->setEnabled(false);
    ui->Linegroup->setEnabled(false);
    ui->Rectanglegroup->setEnabled(false);
    ui->groupBox_4->setEnabled(false);
    ui->Draw->setEnabled(false);
    }

void MainWindow::on_Draw_2_clicked()
{
    Bconds::ud(delta,GS);
    ui->Jacobi->setEnabled(true);
    ui->GaussSeidell->setEnabled(true);
    ui->SOR->setEnabled(true);
    ui->Draw_2->setEnabled(false);
    ui->label_2->setEnabled(false);
    ui->Circlegroup->setEnabled(false);
    ui->Rectanglegroup->setEnabled(false);
    ui->Linegroup->setEnabled(false);
    ui->Draw->setEnabled(false);
    ui->groupBox_3->setEnabled(false);
    ui->groupBox_4->setEnabled(false);
}


void MainWindow::on_pushButton_clicked()
{
    ui->deltaVal->setEnabled(false);
    ui->ErrTol->setEnabled(false);
    ui->groupBox_2->setEnabled(true);
    ui->Jacobi->setEnabled(true);
    ui->GaussSeidell->setEnabled(true);
    ui->SOR->setEnabled(true);
    ui->pushButton->setEnabled(false);
}

void MainWindow::on_Other_clicked()
{
    ui->OtherColourBox->setEnabled(true);
    ui->groupBox_4->setEnabled(true);
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    Bconds::rval = arg1;
}

void MainWindow::on_spinBox_2_valueChanged(int arg1)
{
    Bconds::gval = arg1;
}

void MainWindow::on_spinBox_3_valueChanged(int arg1)
{
    Bconds::bval = arg1;
}

void MainWindow::on_doubleSpinBox_valueChanged(double arg1)
{
    Bconds::UV = arg1;
}

void MainWindow::on_SetColour_clicked()
{
    colour = QColor(Bconds::rval,Bconds::gval,Bconds::bval,255);
    ui->OtherColourBox->setEnabled(false);
}
