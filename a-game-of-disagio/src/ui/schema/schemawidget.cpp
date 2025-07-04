#include "schemawidget.h"

SchemaWidget::SchemaWidget(int nOfTiles, int side) {
    setStyleSheet("QPushButton:checked { background-color: red; }");
    setFixedSize(side, side);
    layout = new SchemaLayout(nOfTiles, side - 50, this);
    setLayout(layout);
}

void SchemaWidget::resizeHandler(int side) {
    setFixedSize(side, side);
    layout->resizeHandler(side - 50);
}