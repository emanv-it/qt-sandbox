#ifndef SCHEMALAYOUT_H
#define SCHEMALAYOUT_H

#include <QGridLayout>
#include "tilebutton.h"
#include "ui_mainwindow.h"

class SchemaLayout : public QGridLayout {

Q_OBJECT

public:
    SchemaLayout(int s, int c, QWidget *p);

    std::vector<std::vector<QPushButton *>> getButtons();

private:
    int size;

    int count;

    std::vector<std::vector<QPushButton *>> buttons;

    void addButtons();

    void clearButtons();
};

#endif // SCHEMALAYOUT_H
