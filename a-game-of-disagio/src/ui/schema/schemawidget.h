#ifndef SCHEMAWIDGET_H
#define SCHEMAWIDGET_H

#include <QWidget>
#include <QSize>
#include "schemalayout.h"

class SchemaWidget : public QWidget {

Q_OBJECT

public:
    SchemaWidget(int nOfTiles, int side);

    void resizeHandler(int side);

private:

    SchemaLayout* layout;
};

#endif //SCHEMAWIDGET_H
