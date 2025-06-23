#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "centrallayout.h"
#include "src/handlers/levelhandler.h"

#define SIZE (10)

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    setWindowTitle("A Game of Disagio");
    setMaximumSize(510, 510);

//    QMenu *menu = new QMenu();
//    menu->setTitle("Game" );
//    ui->menubar->addMenu(menu);

    auto *layout = new CentralLayout(500, SIZE, ui->centralwidget);
    ui->centralwidget->setLayout(layout);

    auto *levelHandler = new LevelHandler(ui->centralwidget);
    levelHandler->setLevel(0);
}

MainWindow::~MainWindow() {
    delete ui;
}
