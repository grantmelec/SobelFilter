#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsScene>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    Imager = new GImageProcess();
    picture = new QImage("C:\\Users\\GrantM\\Desktop\\IProcc\\House.jpg");
    QImage MrGray = picture->convertToFormat(QImage::Format_Grayscale16);
    ui->Viewer->setPixmap(QPixmap::fromImage( *picture));
    ui->Viewer->setScaledContents(true);

    //Signal and Slots Connect
    connect(ui->Gaussian,SIGNAL(clicked()),this,SLOT(doGaussian()));
    connect(ui->Red,SIGNAL(clicked()),this,SLOT(doRed()));
    connect(ui->Green,SIGNAL(clicked()),this,SLOT(doGreen()));
    connect(ui->Blue,SIGNAL(clicked()),this,SLOT(doBlue()));
    connect(ui->Grayscale,SIGNAL(clicked()),this,SLOT(doGrayscale()));
    connect(ui->Sobel,SIGNAL(clicked()),this,SLOT(doSobel()));
    //connect(ui->,SIGNAL(clicked),this,SLOT(doPrewitt));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::doGaussian()
{
         ui->Viewer->clear();
         picture = new QImage( Imager->GausianFilter(picture));
         ui->Viewer->setPixmap(QPixmap::fromImage(* picture));
}

void MainWindow::doSobel()
{
    ui->Viewer->clear();
    picture = new QImage( Imager->SobelFilter(picture));
    ui->Viewer->setPixmap(QPixmap::fromImage(* picture));
}

void MainWindow::doPrewitt()
{
    ui->Viewer->clear();
    picture = new QImage( Imager->PrewittFilter(picture));
    ui->Viewer->setPixmap(QPixmap::fromImage(* picture));
}

void MainWindow::doGrayscale()
{
    ui->Viewer->clear();
    picture = new QImage( Imager->getGray(picture));
    ui->Viewer->setPixmap(QPixmap::fromImage(* picture));
}

void MainWindow::doRed()
{
    ui->Viewer->clear();
    picture = new QImage( Imager->getRedOnly(picture));
    ui->Viewer->setPixmap(QPixmap::fromImage(* picture));
}

void MainWindow::doGreen()
{
    ui->Viewer->clear();
    picture = new QImage( Imager->getGreenOnly(picture));
    ui->Viewer->setPixmap(QPixmap::fromImage(* picture));
}

void MainWindow::doBlue()
{
    ui->Viewer->clear();
    picture = new QImage( Imager->getBlueOnly(picture));
    ui->Viewer->setPixmap(QPixmap::fromImage(* picture));
}




//teams: tech station:
