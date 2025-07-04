#ifndef SCHEMALAYOUT_H
#define SCHEMALAYOUT_H

#include <QGridLayout>
#include "tilebutton.h"
#include "ui_mainwindow.h"

class SchemaLayout : public QGridLayout {

Q_OBJECT

public:
    SchemaLayout(int nOfTiles, int size, QWidget *parent);

private:

    void addButtons(int nOfTiles, int size);
};

#endif // SCHEMALAYOUT_H
