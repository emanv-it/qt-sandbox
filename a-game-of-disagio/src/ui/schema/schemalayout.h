#ifndef SCHEMALAYOUT_H
#define SCHEMALAYOUT_H

#include <QGridLayout>
#include <QList>
#include "tilebutton.h"

class SchemaLayout : public QGridLayout {

Q_OBJECT

public:
    SchemaLayout(int nOfTiles, int side, QWidget *parent);

    void resizeHandler(int side);

private:

    QList<TileButton *> buttons;

    void addButtons(int nOfTiles, int side);
};

#endif // SCHEMALAYOUT_H
