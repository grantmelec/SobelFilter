#include "gimageprocess.h"

#include <QColor>
#include <QGenericMatrix>
#include <math.h>



//------------------------------------------------------------------
//                  Constructors and Deconstructors
GImageProcess::GImageProcess(){}
GImageProcess::~GImageProcess(){}
//------------------------------------------------------------------

QImage GImageProcess::GausianFilter(QImage *myImage)
{
    //define Gaussian discrete mask
    double kernal[3][3] = {{0.0625,0.125,0.0625},{0.125,0.25,0.125},{ 0.0625,0.125 ,0.0625}};
    QImage xImage= Convolute(myImage,kernal);
    return xImage;

}

QImage GImageProcess::SobelFilter(QImage *myImage)
{
    //define Gaussian discrete mask
    double xdirection[3][3] = {{1,0,-1},{2,0,-2},{1,0,-1}};             //Gx
    double ydirection[3][3] = {{1,2,1},{0,0,0},{-1,-2,-1}};             //Gx


    QImage xImage= Convolute(myImage,xdirection);
    QImage yImage= Convolute(myImage,ydirection);
    QImage Edge(xImage.width(),yImage.height(),myImage->format());

    for(int width = 0;width<xImage.width();width++)
    {
        for(int height = 0;height<yImage.height();height++)
        {
            Edge.setPixel(width,height,xImage.pixel(width,height)+yImage.pixel(width,height));

        }

    }

    return Edge;
}

QImage GImageProcess::PrewittFilter(QImage *myImage)
{
    //define Gaussian discrete mask
    double xdirection[3][3] = {{1,1,1},{0,0,0},{-1,-1,-1}};             //Gx
    double ydirection[3][3] = {{-1,0,1},{-1,0,1},{-1,0,1}};             //Gx


    QImage xImage= Convolute(myImage,xdirection);
    QImage yImage= Convolute(myImage,ydirection);
    QImage Edge(xImage.width(),yImage.height(),myImage->format());

    for(int width = 0;width<xImage.width();width++)
    {
        for(int height = 0;height<yImage.height();height++)
        {
            Edge.setPixel(width,height,xImage.pixel(width,height)+yImage.pixel(width,height));

        }

    }

    return Edge;
}



QImage GImageProcess::getRedOnly(QImage *myImage)
{
    int Xmax = myImage->width();
    int Ymax =myImage->height();


    QImage alpha(Xmax,Ymax,QImage::Format_ARGB32);
    QVector<QRgb>color = myImage->colorTable();

    //Transver Vector table
    QImage Red = myImage->convertToFormat(QImage::Format_RGB16);
    for(int w = 0; w<Red.width();w++)
    {
        for(int h = 0; h < Red.height();h++)
        {
            QColor C = Red.pixelColor(w,h);                     //preserve the Red channel
            QColor myPixel(C.red(),0,0);                        //create a pixel

            Red.setPixel(w,h,qRgb(C.red(),0,0));
        }
    }

    return Red;
}

QImage GImageProcess::getGreenOnly(QImage *myImage)
{
    int Xmax = myImage->width();
    int Ymax =myImage->height();


    QImage alpha(Xmax,Ymax,QImage::Format_ARGB32);
    QVector<QRgb>color = myImage->colorTable();

    //Transver Vector table
    QImage Green = myImage->convertToFormat(QImage::Format_RGB16);
    for(int w = 0; w<Green.width();w++)
    {
        for(int h = 0; h < Green.height();h++)
        {
            QColor C = Green.pixelColor(w,h);                     //preserve the Green channel
            QColor myPixel(C.green(),0,0);                        //create a pixel

            Green.setPixel(w,h,qRgb(0,C.green(),0));
        }
    }

    return Green;
}

QImage GImageProcess::getBlueOnly(QImage *myImage)
{
    int Xmax = myImage->width();
    int Ymax =myImage->height();


    QImage alpha(Xmax,Ymax,QImage::Format_ARGB32);
    QVector<QRgb>color = myImage->colorTable();

    //Transver Vector table
    QImage Blue = myImage->convertToFormat(QImage::Format_RGB16);
    for(int w = 0; w<Blue.width();w++)
    {
        for(int h = 0; h < Blue.height();h++)
        {
            QColor C = Blue.pixelColor(w,h);                     //preserve the Blue channel
            QColor myPixel(C.blue(),0,0);                        //create a pixel

            Blue.setPixel(w,h,qRgb(0,0,C.blue()));
        }
    }

    return Blue;
}

QImage GImageProcess::getGray(QImage *myImage)
{
    int Xmax = myImage->width();
    int Ymax =myImage->height();


    QImage alpha(Xmax,Ymax,QImage::Format_Grayscale8);
    QVector<QRgb>color = myImage->colorTable();

    //Transverse Vector table
    QImage titan = myImage->convertToFormat(QImage::Format_ARGB32);
    for(int w = 0; w<titan.width();w++)
    {
        for(int h = 0; h < titan.height();h++)
        {
            alpha.setPixel(w,h,  qRgb(0.2126*titan.pixelColor(w,h).red(),0.7152*titan.pixelColor(w,h).green(),0.0722*titan.pixelColor(w,h).blue()));
        }
    }

return alpha;
}

QImage GImageProcess::Convolute(QImage *myImage,double mask[3][3])
{

    int Xmax = myImage->width();
    int Ymax =myImage->height();


    QImage alpha(Xmax,Ymax,myImage->format());

    for(int w = 3; w<myImage->width();w++)
    {
        for(int h = 3; h < myImage->height();h++)
        {

            QColor P[3][3] = {
                                {myImage->pixelColor(w-3,h-3),myImage->pixelColor(w-2,h-3),myImage->pixelColor(w-1,h-3)},
                                {myImage->pixelColor(w-3,h-2),myImage->pixelColor(w-2,h-2),myImage->pixelColor(w-1,h-3)},
                                {myImage->pixelColor(w-3,h-1),myImage->pixelColor(w-2,h-1),myImage->pixelColor(w-1,h-1)},
                            };


            int R =     abs(P[2][2].red()*mask[0][0] +  P[2][1].red()*mask[0][1] + P[2][0].red()*mask[0][2] +
                            P[1][2].red()*mask[1][0] +  P[1][1].red()*mask[1][1] + P[1][0].red()*mask[1][2] +
                            P[0][2].red()*mask[2][0] +  P[0][1].red()*mask[2][1] + P[0][0].red()*mask[2][2]);

            int G =     abs(P[2][2].green()*mask[0][0] +  P[2][1].green()*mask[0][1] + P[2][0].green()*mask[0][2] +
                            P[1][2].green()*mask[1][0] +  P[1][1].green()*mask[1][1] + P[1][0].green()*mask[1][2] +
                            P[0][2].green()*mask[2][0] +  P[0][1].green()*mask[2][1] + P[0][0].green()*mask[2][2]);

            int B =     abs(P[2][2].blue()*mask[0][0] +  P[2][1].blue()*mask[0][1] + P[2][0].blue()*mask[0][2] +
                            P[1][2].blue()*mask[1][0] +  P[1][1].blue()*mask[1][1] + P[1][0].blue()*mask[1][2] +
                            P[0][2].blue()*mask[2][0] +  P[0][1].blue()*mask[2][1] + P[0][0].blue()*mask[2][2]);


            alpha.setPixel(w-2,h-2,qRgb(R,G,B));

        }
    }

    return alpha;
}




