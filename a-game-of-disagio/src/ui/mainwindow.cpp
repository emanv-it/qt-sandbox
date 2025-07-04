#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "schemalayout.h"
#include "../handlers/levelhandler.h"

#define N_OF_TILES (10)

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    setWindowTitle("A Game of Disagio");
    setMaximumSize(510, 510);

//    QMenu *menu = new QMenu();
//    menu->setTitle("Game" );
//    ui->menubar->addMenu(menu);

    auto *layout = new SchemaLayout(N_OF_TILES, 500, ui->centralwidget);
    ui->centralwidget->setLayout(layout);

    LevelHandler::setLevel(N_OF_TILES, 0, ui->centralwidget);
}

MainWindow::~MainWindow() {
    delete ui;
}
