#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    const int floor = 150;
    const int ceiling = floor - 200 - 200;

    for (int i = -1000; i < 1000; i += 200) {
          for (int j = -1000; j < 1000; j += 200) {
              Square3 tmp(Vector3(i, floor, j), 100);
              tmp.rotateAroundX(tmp.center, 90);
              scene.floor.push_back(tmp);
          }
    }

    for (int i = -1000; i < 1000; i += 200) {
          for (int j = -1000; j < 1000; j += 200) {
              Square3 tmp(Vector3(i, ceiling, j), 100);
              tmp.rotateAroundX(tmp.center, 90);
              scene.ceiling.push_back(tmp);
           }
    }

    for (int i = -1000; i < 1000; i += 200) {

        for (int j = floor - 100; j > ceiling; j -= 200) {
            Square3 tmp(Vector3(100, j, i), 100);
            tmp.rotateAroundY(tmp.center, 90);
            scene.walls.push_back(tmp);
        }

        for (int j = floor - 100; j > ceiling; j -= 200) {
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

void MainWindow::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_W){
        img = scene.render(forward, neutral).scaledToWidth(1920);
        update();
    } else if (event->key() == Qt::Key_S) {
        img = scene.render(backward, neutral).scaledToWidth(1920);
        update();
    } else if (event->key() == Qt::Key_A) {
        img = scene.render(left, neutral).scaledToWidth(1920);
        update();
    } else if (event->key() == Qt::Key_D) {
        img = scene.render(right, neutral).scaledToWidth(1920);
        update();
    }

}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    const double currentMouse = event->x();
    img = scene.render(neutral, Vector3(0, static_cast<int>((lastMouse - currentMouse)/20), 0)).scaledToWidth(1920);
    lastMouse = currentMouse;
    update();
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    lastMouse = event->x();
}

void MainWindow::paintEvent(QPaintEvent*){
    QPainter p(this);
    p.drawImage(0, 0, img);

}

