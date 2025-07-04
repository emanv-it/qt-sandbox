#include "schemalayout.h"

SchemaLayout::SchemaLayout(int nOfTiles, int side, QWidget *parent) : QGridLayout(parent) {
    addButtons(nOfTiles, side);
}

void SchemaLayout::addButtons(int nOfTiles, int side) {
    buttons.clear();
    for (int row = 0; row < nOfTiles; row++) {
        for (int col = 0; col < nOfTiles; col++) {
            auto *button = new TileButton(side / nOfTiles, row, col, parentWidget());
            addWidget(button, row, col, Qt::AlignCenter);
            buttons.push_back(button);
        }
    }
}

void SchemaLayout::resizeHandler(int side) {
    for (TileButton *button: buttons) {
        button->resizeHandler(side - 50);
    }
}
