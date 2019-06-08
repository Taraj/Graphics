#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QImage>
#include <util/vector2.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Vector2 be = Vector2(100, 100);
    Vector2 sro= Vector2(200, 200);
private slots:
    void on_pushButton_clicked();
    void paintEvent(QPaintEvent*);
private:
    Ui::MainWindow *ui;  
    QImage *img;
};

#endif // MAINWINDOW_H
