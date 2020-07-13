/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *Viewer;
    QPushButton *Gaussian;
    QPushButton *Grayscale;
    QPushButton *Red;
    QPushButton *Blue;
    QPushButton *Green;
    QPushButton *Sobel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1145, 951);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Viewer = new QLabel(centralwidget);
        Viewer->setObjectName(QString::fromUtf8("Viewer"));
        Viewer->setGeometry(QRect(10, 10, 891, 901));
        Gaussian = new QPushButton(centralwidget);
        Gaussian->setObjectName(QString::fromUtf8("Gaussian"));
        Gaussian->setGeometry(QRect(950, 20, 158, 40));
        QFont font;
        font.setPointSize(9);
        Gaussian->setFont(font);
        Grayscale = new QPushButton(centralwidget);
        Grayscale->setObjectName(QString::fromUtf8("Grayscale"));
        Grayscale->setGeometry(QRect(950, 60, 158, 40));
        Grayscale->setFont(font);
        Red = new QPushButton(centralwidget);
        Red->setObjectName(QString::fromUtf8("Red"));
        Red->setGeometry(QRect(950, 100, 158, 40));
        Red->setFont(font);
        Blue = new QPushButton(centralwidget);
        Blue->setObjectName(QString::fromUtf8("Blue"));
        Blue->setGeometry(QRect(950, 140, 158, 40));
        Blue->setFont(font);
        Green = new QPushButton(centralwidget);
        Green->setObjectName(QString::fromUtf8("Green"));
        Green->setGeometry(QRect(950, 180, 158, 40));
        Green->setFont(font);
        Sobel = new QPushButton(centralwidget);
        Sobel->setObjectName(QString::fromUtf8("Sobel"));
        Sobel->setGeometry(QRect(950, 220, 158, 40));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1145, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Viewer->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        Gaussian->setText(QCoreApplication::translate("MainWindow", "Gaussian", nullptr));
        Grayscale->setText(QCoreApplication::translate("MainWindow", "Grayscale", nullptr));
        Red->setText(QCoreApplication::translate("MainWindow", "Red", nullptr));
        Blue->setText(QCoreApplication::translate("MainWindow", "Green", nullptr));
        Green->setText(QCoreApplication::translate("MainWindow", "Blue", nullptr));
        Sobel->setText(QCoreApplication::translate("MainWindow", "Sobel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
