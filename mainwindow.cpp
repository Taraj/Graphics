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

    Scene scene(1000,500);

    scene.setPoints(std::vector<DVector2>{
                        DVector2(100,100, QColor(255,0,0)),
                        DVector2(100,500, QColor(255,255,0))
                    });

    scene.setLines(std::vector<DLine2>{
                DLine2(Vector2(123, 1231), Vector2(500,0), QColor(255,0,255))
                });

    img = scene.render();


   update();

}


