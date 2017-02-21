/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *GaussSeidell;
    QPushButton *Jacobi;
    QPushButton *SOR;
    QGroupBox *groupBox;
    QDoubleSpinBox *deltaVal;
    QDoubleSpinBox *ErrTol;
    QLabel *label_2;
    QGraphicsView *graphicsView;
    QGroupBox *groupBox_2;
    QRadioButton *Problem1;
    QRadioButton *Problem2;
    QRadioButton *UD;
    QGroupBox *groupBox_3;
    QRadioButton *red;
    QRadioButton *green;
    QRadioButton *black;
    QRadioButton *Other;
    QGroupBox *groupBox_4;
    QRadioButton *circle;
    QRadioButton *line;
    QRadioButton *rectangle;
    QPushButton *Draw;
    QPushButton *Draw_2;
    QGroupBox *Circlegroup;
    QLabel *label_3;
    QDoubleSpinBox *HorizLinear;
    QLabel *label_4;
    QDoubleSpinBox *VertLinear;
    QLabel *label_9;
    QDoubleSpinBox *VertLinear_3;
    QGroupBox *Linegroup;
    QDoubleSpinBox *HorizLinear_3;
    QLabel *label_8;
    QDoubleSpinBox *VertLinear_4;
    QDoubleSpinBox *VertLinear_2;
    QLabel *label_11;
    QLabel *label_10;
    QLabel *label_7;
    QDoubleSpinBox *HorizLinear_2;
    QGroupBox *Rectanglegroup;
    QDoubleSpinBox *VertLinear_5;
    QLabel *label_16;
    QDoubleSpinBox *HorizLinear_4;
    QLabel *label_15;
    QDoubleSpinBox *HorizLinear_5;
    QDoubleSpinBox *VertLinear_6;
    QLabel *label_12;
    QLabel *label_14;
    QPushButton *pushButton;
    QTextEdit *AppOutput;
    QGroupBox *OtherColourBox;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_3;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QDoubleSpinBox *doubleSpinBox;
    QPushButton *SetColour;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(841, 628);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        GaussSeidell = new QPushButton(centralWidget);
        GaussSeidell->setObjectName(QStringLiteral("GaussSeidell"));
        GaussSeidell->setEnabled(false);
        GaussSeidell->setGeometry(QRect(260, 80, 101, 31));
        Jacobi = new QPushButton(centralWidget);
        Jacobi->setObjectName(QStringLiteral("Jacobi"));
        Jacobi->setEnabled(false);
        Jacobi->setGeometry(QRect(260, 20, 91, 31));
        SOR = new QPushButton(centralWidget);
        SOR->setObjectName(QStringLiteral("SOR"));
        SOR->setEnabled(false);
        SOR->setGeometry(QRect(260, 140, 91, 31));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 20, 211, 61));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(204, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 51, 51, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(229, 25, 25, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(102, 0, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(136, 0, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(229, 127, 127, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        groupBox->setPalette(palette);
        groupBox->setAutoFillBackground(true);
        deltaVal = new QDoubleSpinBox(groupBox);
        deltaVal->setObjectName(QStringLiteral("deltaVal"));
        deltaVal->setGeometry(QRect(10, 30, 69, 26));
        deltaVal->setMinimumSize(QSize(69, 26));
        deltaVal->setMaximumSize(QSize(69, 26));
        deltaVal->setMinimum(0.01);
        deltaVal->setMaximum(0.05);
        deltaVal->setSingleStep(0.01);
        ErrTol = new QDoubleSpinBox(groupBox);
        ErrTol->setObjectName(QStringLiteral("ErrTol"));
        ErrTol->setGeometry(QRect(120, 30, 69, 26));
        ErrTol->setDecimals(3);
        ErrTol->setMinimum(0.001);
        ErrTol->setMaximum(0.1);
        ErrTol->setSingleStep(0.001);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setEnabled(false);
        label_2->setGeometry(QRect(270, 180, 121, 21));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(490, 50, 341, 351));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setEnabled(false);
        groupBox_2->setGeometry(QRect(10, 100, 181, 161));
        Problem1 = new QRadioButton(groupBox_2);
        Problem1->setObjectName(QStringLiteral("Problem1"));
        Problem1->setGeometry(QRect(20, 30, 112, 23));
        Problem2 = new QRadioButton(groupBox_2);
        Problem2->setObjectName(QStringLiteral("Problem2"));
        Problem2->setGeometry(QRect(20, 70, 112, 23));
        UD = new QRadioButton(groupBox_2);
        UD->setObjectName(QStringLiteral("UD"));
        UD->setGeometry(QRect(20, 110, 121, 23));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setEnabled(false);
        groupBox_3->setGeometry(QRect(10, 270, 81, 141));
        groupBox_3->setCheckable(false);
        red = new QRadioButton(groupBox_3);
        red->setObjectName(QStringLiteral("red"));
        red->setGeometry(QRect(10, 20, 112, 23));
        green = new QRadioButton(groupBox_3);
        green->setObjectName(QStringLiteral("green"));
        green->setGeometry(QRect(10, 50, 112, 23));
        black = new QRadioButton(groupBox_3);
        black->setObjectName(QStringLiteral("black"));
        black->setGeometry(QRect(10, 80, 112, 23));
        Other = new QRadioButton(groupBox_3);
        Other->setObjectName(QStringLiteral("Other"));
        Other->setGeometry(QRect(10, 110, 112, 23));
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setEnabled(false);
        groupBox_4->setGeometry(QRect(100, 270, 101, 111));
        circle = new QRadioButton(groupBox_4);
        circle->setObjectName(QStringLiteral("circle"));
        circle->setGeometry(QRect(10, 20, 112, 23));
        line = new QRadioButton(groupBox_4);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(10, 50, 112, 23));
        rectangle = new QRadioButton(groupBox_4);
        rectangle->setObjectName(QStringLiteral("rectangle"));
        rectangle->setGeometry(QRect(10, 80, 112, 23));
        Draw = new QPushButton(centralWidget);
        Draw->setObjectName(QStringLiteral("Draw"));
        Draw->setEnabled(false);
        Draw->setGeometry(QRect(220, 530, 89, 25));
        Draw_2 = new QPushButton(centralWidget);
        Draw_2->setObjectName(QStringLiteral("Draw_2"));
        Draw_2->setEnabled(false);
        Draw_2->setGeometry(QRect(310, 530, 111, 25));
        Circlegroup = new QGroupBox(centralWidget);
        Circlegroup->setObjectName(QStringLiteral("Circlegroup"));
        Circlegroup->setEnabled(false);
        Circlegroup->setGeometry(QRect(200, 210, 141, 121));
        label_3 = new QLabel(Circlegroup);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 30, 71, 16));
        HorizLinear = new QDoubleSpinBox(Circlegroup);
        HorizLinear->setObjectName(QStringLiteral("HorizLinear"));
        HorizLinear->setGeometry(QRect(70, 30, 71, 21));
        HorizLinear->setMaximum(300);
        label_4 = new QLabel(Circlegroup);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(0, 60, 71, 17));
        VertLinear = new QDoubleSpinBox(Circlegroup);
        VertLinear->setObjectName(QStringLiteral("VertLinear"));
        VertLinear->setGeometry(QRect(70, 60, 69, 21));
        VertLinear->setMaximum(300);
        label_9 = new QLabel(Circlegroup);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 90, 71, 17));
        VertLinear_3 = new QDoubleSpinBox(Circlegroup);
        VertLinear_3->setObjectName(QStringLiteral("VertLinear_3"));
        VertLinear_3->setGeometry(QRect(70, 90, 69, 21));
        VertLinear_3->setMaximum(150);
        Linegroup = new QGroupBox(centralWidget);
        Linegroup->setObjectName(QStringLiteral("Linegroup"));
        Linegroup->setEnabled(false);
        Linegroup->setGeometry(QRect(350, 210, 141, 151));
        HorizLinear_3 = new QDoubleSpinBox(Linegroup);
        HorizLinear_3->setObjectName(QStringLiteral("HorizLinear_3"));
        HorizLinear_3->setGeometry(QRect(70, 90, 69, 21));
        HorizLinear_3->setMaximum(300);
        label_8 = new QLabel(Linegroup);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(0, 60, 61, 17));
        VertLinear_4 = new QDoubleSpinBox(Linegroup);
        VertLinear_4->setObjectName(QStringLiteral("VertLinear_4"));
        VertLinear_4->setGeometry(QRect(70, 120, 69, 21));
        VertLinear_4->setMaximum(300);
        VertLinear_2 = new QDoubleSpinBox(Linegroup);
        VertLinear_2->setObjectName(QStringLiteral("VertLinear_2"));
        VertLinear_2->setGeometry(QRect(70, 60, 69, 21));
        VertLinear_2->setMaximum(300);
        label_11 = new QLabel(Linegroup);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(0, 120, 61, 17));
        label_10 = new QLabel(Linegroup);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(0, 90, 61, 17));
        label_7 = new QLabel(Linegroup);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(0, 30, 61, 17));
        HorizLinear_2 = new QDoubleSpinBox(Linegroup);
        HorizLinear_2->setObjectName(QStringLiteral("HorizLinear_2"));
        HorizLinear_2->setGeometry(QRect(70, 30, 69, 21));
        HorizLinear_2->setMaximum(300);
        Rectanglegroup = new QGroupBox(centralWidget);
        Rectanglegroup->setObjectName(QStringLiteral("Rectanglegroup"));
        Rectanglegroup->setEnabled(false);
        Rectanglegroup->setGeometry(QRect(210, 360, 201, 161));
        VertLinear_5 = new QDoubleSpinBox(Rectanglegroup);
        VertLinear_5->setObjectName(QStringLiteral("VertLinear_5"));
        VertLinear_5->setGeometry(QRect(120, 120, 69, 21));
        VertLinear_5->setMaximum(300);
        label_16 = new QLabel(Rectanglegroup);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(0, 120, 111, 20));
        HorizLinear_4 = new QDoubleSpinBox(Rectanglegroup);
        HorizLinear_4->setObjectName(QStringLiteral("HorizLinear_4"));
        HorizLinear_4->setGeometry(QRect(120, 30, 69, 21));
        HorizLinear_4->setMaximum(300);
        label_15 = new QLabel(Rectanglegroup);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(30, 60, 81, 20));
        HorizLinear_5 = new QDoubleSpinBox(Rectanglegroup);
        HorizLinear_5->setObjectName(QStringLiteral("HorizLinear_5"));
        HorizLinear_5->setGeometry(QRect(120, 90, 69, 21));
        HorizLinear_5->setMaximum(300);
        VertLinear_6 = new QDoubleSpinBox(Rectanglegroup);
        VertLinear_6->setObjectName(QStringLiteral("VertLinear_6"));
        VertLinear_6->setGeometry(QRect(120, 60, 69, 21));
        VertLinear_6->setMaximum(300);
        label_12 = new QLabel(Rectanglegroup);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(0, 90, 111, 20));
        label_14 = new QLabel(Rectanglegroup);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(30, 30, 81, 20));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(60, 80, 89, 25));
        AppOutput = new QTextEdit(centralWidget);
        AppOutput->setObjectName(QStringLiteral("AppOutput"));
        AppOutput->setGeometry(QRect(490, 410, 341, 70));
        OtherColourBox = new QGroupBox(centralWidget);
        OtherColourBox->setObjectName(QStringLiteral("OtherColourBox"));
        OtherColourBox->setEnabled(false);
        OtherColourBox->setGeometry(QRect(10, 420, 191, 161));
        spinBox = new QSpinBox(OtherColourBox);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(50, 30, 48, 26));
        spinBox->setMaximum(255);
        spinBox_2 = new QSpinBox(OtherColourBox);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setGeometry(QRect(50, 60, 48, 26));
        spinBox_2->setMaximum(255);
        spinBox_3 = new QSpinBox(OtherColourBox);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        spinBox_3->setGeometry(QRect(50, 90, 48, 26));
        spinBox_3->setMaximum(255);
        label_17 = new QLabel(OtherColourBox);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(20, 30, 31, 20));
        label_18 = new QLabel(OtherColourBox);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(20, 60, 31, 20));
        label_19 = new QLabel(OtherColourBox);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(20, 90, 31, 20));
        label_20 = new QLabel(OtherColourBox);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(100, 70, 31, 20));
        doubleSpinBox = new QDoubleSpinBox(OtherColourBox);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(120, 70, 69, 26));
        doubleSpinBox->setMinimum(-1000);
        doubleSpinBox->setMaximum(1000);
        SetColour = new QPushButton(OtherColourBox);
        SetColour->setObjectName(QStringLiteral("SetColour"));
        SetColour->setGeometry(QRect(10, 120, 89, 25));
        MainWindow->setCentralWidget(centralWidget);
        groupBox_3->raise();
        groupBox_2->raise();
        groupBox->raise();
        GaussSeidell->raise();
        Jacobi->raise();
        SOR->raise();
        label_2->raise();
        graphicsView->raise();
        groupBox_4->raise();
        Draw->raise();
        Draw_2->raise();
        Circlegroup->raise();
        Linegroup->raise();
        Rectanglegroup->raise();
        pushButton->raise();
        AppOutput->raise();
        OtherColourBox->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 841, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        GaussSeidell->setText(QApplication::translate("MainWindow", "Gauss-Siedell", Q_NULLPTR));
        Jacobi->setText(QApplication::translate("MainWindow", "Jacobi", Q_NULLPTR));
        SOR->setText(QApplication::translate("MainWindow", "SOR", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "  Step Size         Error Tolerance", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Boundary Coords", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Problem", Q_NULLPTR));
        Problem1->setText(QApplication::translate("MainWindow", "Problem1", Q_NULLPTR));
        Problem2->setText(QApplication::translate("MainWindow", "Problem2", Q_NULLPTR));
        UD->setText(QApplication::translate("MainWindow", "User Defined", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Colour", Q_NULLPTR));
        red->setText(QApplication::translate("MainWindow", "Red", Q_NULLPTR));
        green->setText(QApplication::translate("MainWindow", "Green", Q_NULLPTR));
        black->setText(QApplication::translate("MainWindow", "Black", Q_NULLPTR));
        Other->setText(QApplication::translate("MainWindow", "Other", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Shape", Q_NULLPTR));
        circle->setText(QApplication::translate("MainWindow", "Circle", Q_NULLPTR));
        line->setText(QApplication::translate("MainWindow", "Line", Q_NULLPTR));
        rectangle->setText(QApplication::translate("MainWindow", "Rectangle", Q_NULLPTR));
        Draw->setText(QApplication::translate("MainWindow", "Draw", Q_NULLPTR));
        Draw_2->setText(QApplication::translate("MainWindow", "Done Drawing", Q_NULLPTR));
        Circlegroup->setTitle(QApplication::translate("MainWindow", "CIrcle", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Centre X:", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Centre Y:", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "Radius:", Q_NULLPTR));
        Linegroup->setTitle(QApplication::translate("MainWindow", "Line", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Start Y:", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "End Y:", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "End X:", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Start X:", Q_NULLPTR));
        Rectanglegroup->setTitle(QApplication::translate("MainWindow", "Rectangle", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "Bottom Right Y:", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "Top Left Y:", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "Bottom Right X:", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "Top Left X:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Set", Q_NULLPTR));
        OtherColourBox->setTitle(QApplication::translate("MainWindow", "Other Colour", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "R:", Q_NULLPTR));
        label_18->setText(QApplication::translate("MainWindow", "G:", Q_NULLPTR));
        label_19->setText(QApplication::translate("MainWindow", "B:", Q_NULLPTR));
        label_20->setText(QApplication::translate("MainWindow", "V:", Q_NULLPTR));
        SetColour->setText(QApplication::translate("MainWindow", "Set Colour", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
