#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    for (int i = -10000; i < 10000; i += 200) {
          for (int j = -10000; j < 15000; j += 200) {
              Square3 tmp(Vector3(i, 300, j), 100);
              tmp.rotateAroundX(tmp.center, 90);
              scene.floor.push_back(tmp);
          }
    }

    for (int i = -10000; i < 10000; i += 200) {
          for (int j = -10000; j < 10000; j += 200) {
              Square3 tmp(Vector3(i, -100, j), 100);
              tmp.rotateAroundX(tmp.center, 90);
              scene.ceiling.push_back(tmp);
           }
    }

    for (int i = -10000; i < 10000; i += 200) {

        for (int j = -100; j < 300; j += 200) {
            Square3 tmp(Vector3(100, j, i), 100);
            tmp.rotateAroundY(tmp.center, 90);
            scene.walls.push_back(tmp);
        }

        for (int j = -100; j < 300; j += 200) {
            Square3 tmp(Vector3(-100, j, i), 100);
            tmp.rotateAroundY(tmp.center, 90);
            scene.walls.push_back(tmp);
        }
    }

    img = scene.render(Vector3(0, 0, 0), Vector3(0, 0, 0)).scaledToWidth(1920);
    update();;
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent*){
    QPainter p(this);
    p.drawImage(0, 0, img);

}

void MainWindow::on_pushButton_clicked(){
    img = scene.render(Vector3(0, 0, -100), Vector3(0, 0, 0)).scaledToWidth(1920);
    update();
}

void MainWindow::on_pushButton_2_clicked(){
    img = scene.render(Vector3(0, 0, 100), Vector3(0, 0, 0)).scaledToWidth(1920);
    update();
}

void MainWindow::on_pushButton_3_clicked(){
    img = scene.render(Vector3(0, 0, 0), Vector3(0, 5, 0)).scaledToWidth(1920);
    update();
}

void MainWindow::on_pushButton_4_clicked(){
    img = scene.render(Vector3(0, 0, 0), Vector3(0, -5, 0)).scaledToWidth(1920);
    update();
}

void MainWindow::on_pushButton_5_clicked(){
    img = scene.render(Vector3(100, 0, 0), Vector3(0, 0, 0)).scaledToWidth(1920);
    update();
}

void MainWindow::on_pushButton_6_clicked(){
    img = scene.render(Vector3(-100, 0, 0), Vector3(0, 0, 0)).scaledToWidth(1920);
    update();
}
