#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "./util/vector2.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    img = new QImage(500, 500, QImage::Format_RGB32);
     img->fill(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter p(this);
    p.drawImage(0, 0, *img);

}


void MainWindow::on_pushButton_clicked()
{

    unsigned char *ptr = img->bits();
    for (int z = 0;z<600;z++) {
       be.rotateAround(sro,1);

       for (int y = be.getY()-5; y< be.getY()+5;y++) {
           for (int x = be.getX()-5; x< be.getX()+5;x++) {

                ptr[500*4*y + 4*x] =255;
                ptr[500*4*y + 4*x + 1] = 255;
                ptr[500*4*y + 4*x + 2] = 255;
           }
       }


          for (int y = sro.getY()-5; y< sro.getY()+5;y++) {
              for (int x = sro.getX()-5; x< sro.getX()+5;x++) {

                   ptr[500*4*y + 4*x] =255;
                   ptr[500*4*y + 4*x + 1] = 255;
                   ptr[500*4*y + 4*x + 2] = 0;
              }
          }
          }
       update();


}
