#ifndef GIMAGEPROCESS_H
#define GIMAGEPROCESS_H

#include <QImage>
#include <QPixmap>
#include <QDebug>
#include <QObject>

#define StandardDeviationValue 1

class GImageProcess: public QObject
{



public:
    GImageProcess();
    ~GImageProcess();


    QImage GausianFilter(QImage *myImage);
    QImage SobelFilter(QImage *myImage);
    QImage PrewittFilter(QImage *myImage);


    QImage getRedOnly(QImage *myImage);
    QImage getGreenOnly(QImage *myImage);
    QImage getBlueOnly(QImage *myImage);
    QImage getGray(QImage *myImage);
    QImage Convolute(QImage *myImage,double mask[3][3]);


private:
    QString ImagePath;


};

#endif // GIMAGEPROCESS_H
