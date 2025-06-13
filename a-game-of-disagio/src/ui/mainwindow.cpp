#include "mainwindow.h"
#include "centrallayout.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("A Game of Disagio");
    setMaximumSize(510, 510);

//    QMenu *menu = new QMenu();
//    menu->setTitle("Game" );
//    ui->menubar->addMenu(menu);

    CentralLayout* layout = new CentralLayout(500, 10);
    ui->centralwidget->setLayout(layout->getLayout());
}

MainWindow::~MainWindow()
{
    delete ui;
}
