#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    img =  QImage(1000, 500, QImage::Format_RGB32);



    for (int i = -10000;i<10000;i+=200) {
          //scene.add(Cube(Vector3(i,0,100), 100));
          for (int j = -1000;j<10000;j+=200) {
              Square3 tmp(Vector3(i,300,j), 100);
              tmp.rotateAroundX(tmp.center,90);
           scene.add(tmp);
          }
    }

    Cube s = Cube(Vector3(200,200,200), 100);
      scene.add(s);










laod();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mouseMoveEvent(QMouseEvent *event){
  Vector2 currentMouse = Vector2(-event->x(), event->y()) - Vector2(this->size().width()/2,this->size().height()/2);
   Vector2 deltaMove = currentMouse - lastMouse;
   rotation.setY(rotation.getY() + std::round(deltaMove.getX()/10.0));
    rotation.setX(rotation.getX() + std::round(deltaMove.getY()/10.0));
    lastMouse = currentMouse;
   laod();

}

void MainWindow::mousePressEvent(QMouseEvent *event){
    lastMouse = Vector2(-event->x(), event->y())-Vector2(this->size().width()/2,this->size().height()/2);
}

void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter p(this);
    p.drawImage(0, 0, img);

}




void MainWindow::on_horizontalSlider_valueChanged(int value)
{
       position.setX(value);
     laod();
}

void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    position.setY(value);
    laod();
}

void MainWindow::laod()
{
   // Scene3 scene(this->size().width(),this->size().height());

  //  scene.add(Vector3(100,100,100));
  //  Square3 s = Square3(Vector3(200,200,200), 100);
  //  scene.add(s);

  //  scene.add(Cube(Vector3(0,0,1500), 100));

  //  Cube cub = Cube(Vector3(200,0,1000), 50);
    //cub.rotateAroundY(Vector3(200,0,0),20);
   //scene.add(cub);


      //  scene.add( Line3(Vector3(0,0,1000),Vector3(0,0,-1000)));
   //  scene.add(Cube(Vector3(800,300,400), 50));

   // scene.add(Cube(Vector3(100,100,100),100));
  //  s.rotateAroundX(Vector3(200,200,200),30);
   // scene.add(s);

    img = scene.render(position, rotation);


   update();
}

void MainWindow::on_horizontalSlider_3_valueChanged(int value)
{
    position.setZ(value);
    laod();
}

void MainWindow::on_verticalSlider_valueChanged(int value)
{
    rotation.setX(value);
    laod();
}


void MainWindow::on_verticalSlider_2_valueChanged(int value)
{
    rotation.setY(value);
    laod();
}

void MainWindow::on_verticalSlider_3_valueChanged(int value)
{
    rotation.setZ(value);
    laod();
}


void MainWindow::on_pushButton_clicked()
{
    img = scene.render( Vector3(0,0,-100), Vector3(0,0,0)).scaledToWidth(1920);
    update();
}


void MainWindow::on_pushButton_2_clicked()
{
    img = scene.render( Vector3(0,0,100), Vector3(0,0,0)).scaledToWidth(1920);
    update();
}

void MainWindow::on_pushButton_3_clicked()
{
    img = scene.render(Vector3(0,0,0), Vector3(0,5,0)).scaledToWidth(1920);
    update();
}

void MainWindow::on_pushButton_4_clicked()
{
    img = scene.render(Vector3(0,0,0), Vector3(0,-5,0)).scaledToWidth(1920);
    update();
}


