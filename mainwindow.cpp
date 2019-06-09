#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    img =  QImage(1000, 500, QImage::Format_RGB32);
    img.fill(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter p(this);
    p.drawImage(0, 0, img);

}


void MainWindow::on_pushButton_clicked()
{

    Scene3 scene(1000,500);

    scene.add(Vector3(100,100,100));
Square3 s = Square3(Vector3(200,200,200),100);
    scene.add(s);
s.rotateAroundX(Vector3(200,200,200),30);
scene.add(s);

    img = scene.render();


   update();

}


