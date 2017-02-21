#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"QGraphicsView"
#include <QtGui>

namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:


    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:

    void on_Problem1_clicked();

    void on_Problem2_clicked();

    void on_GaussSeidell_clicked();

    void on_SOR_clicked();

    void on_Jacobi_clicked(bool checked);

    void on_deltaVal_valueChanged(double arg1);

    void on_UD_clicked();



    void on_red_clicked();

    void on_green_clicked();

    void on_black_clicked();

    void on_ErrTol_valueChanged(double arg1);

    void on_circle_clicked();

    void on_line_clicked();

    void on_rectangle_clicked();

    void on_HorizLinear_valueChanged(double arg1);

    void on_VertLinear_valueChanged(double arg1);

    void on_VertLinear_3_valueChanged(double arg1);

    void on_HorizLinear_2_valueChanged(double arg1);

    void on_VertLinear_2_valueChanged(double arg1);

    void on_HorizLinear_3_valueChanged(double arg1);

    void on_VertLinear_4_valueChanged(double arg1);

    void on_HorizLinear_4_valueChanged(double arg1);

    void on_VertLinear_6_valueChanged(double arg1);

    void on_HorizLinear_5_valueChanged(double arg1);

    void on_VertLinear_5_valueChanged(double arg1);

    void on_Draw_clicked();

    void on_Draw_2_clicked();

    void on_pushButton_clicked();

    void on_Other_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_spinBox_2_valueChanged(int arg1);

    void on_spinBox_3_valueChanged(int arg1);

    void on_doubleSpinBox_valueChanged(double arg1);

    void on_SetColour_clicked();

private:
    Ui::MainWindow *ui;
    QPixmap image;
    QImage  *imageObject;
    QGraphicsScene *scene;


};

#endif // MAINWINDOW_H
