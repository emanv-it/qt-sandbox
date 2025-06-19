#include "mainwindow.h"
#include "centrallayout.h"
#include "button.h"
#include "ui_mainwindow.h"

#define SIZE (10)

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    setWindowTitle("A Game of Disagio");
    setMaximumSize(510, 510);

//    QMenu *menu = new QMenu();
//    menu->setTitle("Game" );
//    ui->menubar->addMenu(menu);

    CentralLayout *layout = new CentralLayout(500, SIZE);
    ui->centralwidget->setLayout(layout->getLayout());

    for (std::vector<Button *> entry: layout->getButtons()) {
        for (Button *button: entry) {
            connect(button->getPushButton(), SIGNAL(clicked()), this, SLOT(Button::onClick(button)));
        }
    }
}

MainWindow::~MainWindow() {
    delete ui;
}
