#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QImage>

#include <objects/line2.h>
#include <objects/line3.h>
#include <objects/vector2.h>
#include <objects/vector3.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Vector2 be = Vector2(300, 300);
        Vector2 sro = Vector2(400, 400);
      Line2 lin = Line2(Vector2(100,100), Vector2(300,101));
private slots:
    void on_pushButton_clicked();
    void paintEvent(QPaintEvent*);
private:
    Ui::MainWindow *ui;  
    QImage *img;
    void prosto(Line2 a);
};

#endif // MAINWINDOW_H
