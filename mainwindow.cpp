#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    img =  QImage(1000, 500, QImage::Format_RGB32);

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


void MainWindow::on_pushButton_clicked()
{

  laod();
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
    Scene3 scene(this->size().width(),this->size().height());

  //  scene.add(Vector3(100,100,100));
  //  Square3 s = Square3(Vector3(200,200,200), 100);
  //  scene.add(s);

    scene.add(Cube(Vector3(0,0,0), 100));

    //Cube cub = Cube(Vector3(200,0,0), 50);
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
