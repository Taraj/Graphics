#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QImage>

#include <objects/line2.h>
#include <objects/line3.h>
#include <objects/vector2.h>
#include <objects/vector3.h>
#include <util/scene3.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Vector3 position = Vector3(0, 0, 0);
    Vector3 rotation = Vector3(0, 0, 0);

private slots:
    void on_pushButton_clicked();
    void paintEvent(QPaintEvent*);
    void on_horizontalSlider_valueChanged(int value);
    void on_horizontalSlider_2_valueChanged(int value);

    void on_horizontalSlider_3_valueChanged(int value);

    void on_verticalSlider_valueChanged(int value);

    void on_verticalSlider_2_valueChanged(int value);

    void on_verticalSlider_3_valueChanged(int value);

private:
    Ui::MainWindow *ui;  
    QImage img;
    void laod();
};

#endif // MAINWINDOW_H
