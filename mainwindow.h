#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QImage>
#include <objects/vector3.h>
#include <util/scene3.h>
#include <QKeyEvent>
#include <QMouseEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    const unsigned int ratio = 3;
    const unsigned int speed = 4;

    const Vector3 forward = Vector3(0, 0, -10 * static_cast<int>(speed));
    const Vector3 backward = Vector3(0, 0, 10 * static_cast<int>(speed));
    const Vector3 left = Vector3(10 * static_cast<int>(speed), 0, 0);
    const Vector3 right = Vector3(-10 * static_cast<int>(speed), 0, 0);

    const Vector3 neutral = Vector3(0, 0, 0);

    double lastMouse = 0;
    Scene3 scene = Scene3(1920 / ratio, 1020 / ratio);
private slots:

    void keyPressEvent(QKeyEvent *event);

    void mouseMoveEvent(QMouseEvent *event);

    void mousePressEvent(QMouseEvent *event);

    void paintEvent(QPaintEvent*);

private:
    Ui::MainWindow *ui;  
    QImage img;
};

#endif // MAINWINDOW_H
