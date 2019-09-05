#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    nodes = new Node*[areaSize];

    for (unsigned int i = 0; i < areaSize; i++) {
        nodes[i] = new Node[areaSize];
    }

    dfs(0, 0, 0);

    initScene(nodes);

    for (unsigned int i = 0; i < areaSize; i++) {
        delete [] nodes[i];
    }
    delete [] nodes;

    img = scene.render(Vector3(0, 0, 0), Vector3(0, 0, 0)).scaledToWidth(1920);
    update();;
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::dfs(const int &x, const int &y, const int &length){
    nodes[x][y].visited = true;
    std::array<int, 4> arr = { 1, 2, 3, 4 };
    std::random_shuffle(arr.begin(), arr.end());
    bool isEnd = true;
    for (int& number : arr) {
        switch (number) {
            case 1:
                if(inArea(x + 1, y) && !nodes[x + 1][y].visited){
                    isEnd = false;
                    nodes[x][y].right = true;
                    nodes[x + 1][y].left = true;
                    dfs(x + 1, y, length + 1);
                }
                break;
            case 2:
                if(inArea(x - 1, y) && !nodes[x - 1][y].visited){
                    isEnd = false;
                    nodes[x][y].left = true;
                    nodes[x - 1][y].right = true;
                    dfs(x - 1, y, length + 1);
                }
                break;
            case 3:
                if(inArea(x, y + 1) && !nodes[x][y + 1].visited){
                     isEnd = false;
                     nodes[x][y].forward = true;
                     nodes[x][y + 1].backward = true;
                     dfs(x, y + 1, length + 1);
                }
                break;
            case 4:
                if(inArea(x, y - 1) && !nodes[x][y - 1].visited){
                     isEnd = false;
                     nodes[x][y].backward = true;
                     nodes[x][y - 1].forward = true;
                     dfs(x, y - 1, length + 1);
                }
                break;
        }
    }
    if(isEnd){
        possibleEndings.push_back(std::make_pair(length, Vector2(x,y)));
    }
}

bool MainWindow::inArea(const int &x, const int &y){
    return x >= 0 && y >= 0 && x < static_cast<int>(areaSize) && y < static_cast<int>(areaSize);
}


void MainWindow::initScene(Node **nodes){
    const unsigned int squareSize = 10;
    const unsigned int squaresPerWall = 10;
    const unsigned int size = squareSize * squaresPerWall;
    const int floor = 50;
    Square3 tmp(Vector3(0,0,0), size);

    for (unsigned int i = 0; i < areaSize; i++) {

        const int x = static_cast<int>(i * size * 2 - size + squareSize);

        for (unsigned int j = 0; j < areaSize; j++) {
            const int y = static_cast<int>(j * size * 2 - 1000 - size + squareSize);

            for (unsigned int kx = 0; kx < squaresPerWall; kx++) {
                for (unsigned int ky = 0; ky < squaresPerWall; ky++) {
                    tmp = Square3(Vector3(x + static_cast<int>(kx * squareSize * 2), floor, y + static_cast<int>(ky * squareSize * 2)), static_cast<int>(squareSize));
                    tmp.rotateAroundX(tmp.center, 90);
                    scene.floor.push_back(tmp);


                    tmp = Square3(Vector3(x + static_cast<int>(kx * squareSize * 2), floor - static_cast<int>(2 * size), y + static_cast<int>(ky * squareSize * 2)), static_cast<int>(squareSize));
                    tmp.rotateAroundX(tmp.center, 90);
                    scene.ceiling.push_back(tmp);
                }
            }


            if(!nodes[i][j].left){
                for (unsigned int kx = 0; kx < squaresPerWall; kx++) {
                    for (unsigned int ky = 0; ky < squaresPerWall; ky++) {
                        tmp = Square3(Vector3(x - static_cast<int>(squareSize), floor - static_cast<int>(squareSize + kx * squareSize * 2),  y + static_cast<int>(ky * squareSize * 2)), static_cast<int>(squareSize));
                        tmp.rotateAroundY(tmp.center, 90);
                        scene.addUniqueWall(tmp);
                    }
                }
            }


            if(!nodes[i][j].right){
                for (unsigned int kx = 0; kx < squaresPerWall; kx++) {
                    for (unsigned int ky = 0; ky < squaresPerWall; ky++) {
                        tmp = Square3(Vector3(x + static_cast<int>(size * 2 - squareSize), floor - static_cast<int>(squareSize + kx * squareSize * 2),  y + static_cast<int>(ky * squareSize * 2)), static_cast<int>(squareSize));
                        tmp.rotateAroundY(tmp.center, 90);
                        scene.addUniqueWall(tmp);
                    }
                }
            }

            if(!nodes[i][j].forward){
                for (unsigned int kx = 0; kx < squaresPerWall; kx++) {
                    for (unsigned int ky = 0; ky < squaresPerWall; ky++) {
                        tmp = Square3(Vector3(x + static_cast<int>(kx * squareSize * 2),  floor - static_cast<int>(squareSize + ky * squareSize * 2),  y + static_cast<int>(size * 2 - squareSize)), static_cast<int>(squareSize));
                        scene.addUniqueWall(tmp);
                    }
                }
            }


            if(!nodes[i][j].backward){
                for (unsigned int kx = 0; kx < squaresPerWall; kx++) {
                    for (unsigned int ky = 0; ky < squaresPerWall; ky++) {
                        tmp = Square3(Vector3(x + static_cast<int>(kx * squareSize * 2),  floor - static_cast<int>(squareSize + ky * squareSize * 2),  y - static_cast<int>(squareSize)), static_cast<int>(squareSize));
                        scene.addUniqueWall(tmp);
                    }
                }
            }
        }
    }


        const unsigned int endIndex = static_cast<unsigned int>(rand()) % static_cast<unsigned int>(possibleEndings.size());
        const int x = static_cast<int>(possibleEndings[endIndex].second.x * size * 2 - size + squareSize);
        for (unsigned int kx = 0; kx < squaresPerWall; kx++) {
              const int y = static_cast<int>(possibleEndings[endIndex].second.y * size * 2 - 1000 - size + squareSize);
            for (unsigned int ky = 0; ky < squaresPerWall; ky++) {
                tmp = Square3(Vector3(x + static_cast<int>(kx * squareSize * 2), floor, y + static_cast<int>(ky * squareSize * 2)), static_cast<int>(squareSize));
                tmp.rotateAroundX(tmp.center, 90);
                scene.addSpecialFloor(tmp);
            }
        }
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
    const Vector2 currentMouse(event->x(), event->y());
    img = scene.render(neutral, Vector3(static_cast<int>((lastMouse - currentMouse).y/20), static_cast<int>((lastMouse - currentMouse).x/-20), 0)).scaledToWidth(1920);
    lastMouse = currentMouse;
    update();
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    lastMouse = Vector2(event->x(), event->y());
}

void MainWindow::paintEvent(QPaintEvent*){
    QPainter p(this);
    p.drawImage(0, 0, img);

}

