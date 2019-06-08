#include "mainwindow.h"
#include "ui_mainwindow.h"


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

         be.rotateAround(sro,5);

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

            lin.rotateAround(be, 10);


      prosto(lin);
   update();

}


void MainWindow::prosto(Line2 a){
    const int x1 = a.getA().getX();
    const int y1 = a.getA().getY();
    const int x2 = a.getB().getX();
    const int y2 = a.getB().getY();
     unsigned char *ptr = img->bits();
    // zmienne pomocnicze
         int d, dx, dy, ai, bi, xi, yi;
         int x = x1, y = y1;
         // ustalenie kierunku rysowania
         if (x1 < x2)
         {
             xi = 1;
             dx = x2 - x1;
         }
         else
         {
             xi = -1;
             dx = x1 - x2;
         }
         // ustalenie kierunku rysowania
         if (y1 < y2)
         {
             yi = 1;
             dy = y2 - y1;
         }
         else
         {
             yi = -1;
             dy = y1 - y2;
         }
         // pierwszy piksel
        ptr[500*4*y + 4*x + 1] = 255;
         // oś wiodąca OX
         if (dx > dy)
         {
             ai = (dy - dx) * 2;
             bi = dy * 2;
             d = bi - dx;
             // pętla po kolejnych x
             while (x != x2)
             {
                 // test współczynnika
                 if (d >= 0)
                 {
                     x += xi;
                     y += yi;
                     d += ai;
                 }
                 else
                 {
                     d += bi;
                     x += xi;
                 }
               ptr[500*4*y + 4*x + 1] = 255;
             }
         }
         // oś wiodąca OY
         else
         {
             ai = ( dx - dy ) * 2;
             bi = dx * 2;
             d = bi - dy;
             // pętla po kolejnych y
             while (y != y2)
             {
                 // test współczynnika
                 if (d >= 0)
                 {
                     x += xi;
                     y += yi;
                     d += ai;
                 }
                 else
                 {
                     d += bi;
                     y += yi;
                 }
                ptr[500*4*y + 4*x + 1] = 255;
             }
         }

      update();
}
