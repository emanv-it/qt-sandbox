#include "schemalayout.h"

SchemaLayout::SchemaLayout(int nOfTiles, int size, QWidget *parent) : QGridLayout(parent) {
    parentWidget()->setStyleSheet("QPushButton:checked { background-color: red; }");
    addButtons(nOfTiles, size);
}

void SchemaLayout::addButtons(int nOfTiles, int size) {
    for (int row = 0; row < nOfTiles; row++) {
        for (int col = 0; col < nOfTiles; col++) {
            QPushButton *button = new TileButton(size / nOfTiles, row, col, parentWidget());
            addWidget(button, row, col, Qt::AlignCenter);
        }
    }
}
