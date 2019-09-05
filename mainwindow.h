#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QImage>
#include <objects/vector3.h>
#include <util/scene3.h>
#include <QKeyEvent>
#include <QMouseEvent>
#include <util/node.h>
#include <random>
#include <chrono>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    const unsigned int ratio = 1;
    const unsigned int speed = 1;

    const Vector3 forward = Vector3(0, 0, -10 * static_cast<int>(speed));
    const Vector3 backward = Vector3(0, 0, 10 * static_cast<int>(speed));
    const Vector3 left = Vector3(10 * static_cast<int>(speed), 0, 0);
    const Vector3 right = Vector3(-10 * static_cast<int>(speed), 0, 0);

    const Vector3 neutral = Vector3(0, 0, 0);


    Vector2 lastMouse = Vector2(0, 0);
    Scene3 scene = Scene3(1920 / ratio, 1020 / ratio);



    const unsigned int areaSize = 10;
    void dfs(const int &x, const int &y, const int &length);
    bool inArea(const int &x, const int &y);
    Node **nodes;
    std::vector<std::pair<int, Vector2>> possibleEndings;

    void initScene(Node** nodes);


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
