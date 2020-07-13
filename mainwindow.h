#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <gimageprocess.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    GImageProcess * Imager;
    QImage *picture;

private:
    Ui::MainWindow *ui;

public slots:
    void doGaussian();
    void doSobel();
    void doPrewitt();
    void doGrayscale();
    void doRed();
    void doGreen();
    void doBlue();
private slots:
    void on_Prewitt_clicked();
};
#endif // MAINWINDOW_H
