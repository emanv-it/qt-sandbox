#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "windowlayout.h"
#include "../handlers/levelhandler.h"

#define N_OF_TILES (20)

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    setWindowTitle("A Game of Disagio");
    setMinimumSize(240, 240);

//    QMenu *menu = new QMenu();
//    menu->setTitle("Game" );
//    ui->menubar->addMenu(menu);

    auto *layout = new WindowLayout(ui->centralwidget);
    layout->addSchema(N_OF_TILES, size());
    ui->centralwidget->setLayout(layout);
    LevelHandler::setLevel(N_OF_TILES, 0, ui->centralwidget);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event) {
    ((WindowLayout *) ui->centralwidget->layout())->resizeHandler(size());
}
