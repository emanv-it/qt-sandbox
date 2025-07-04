#include "tilebutton.h"
#include "schemalayout.h"
#include "../handlers/tilehandler.h"

TileButton::TileButton(int size, int row, int col, QWidget *p) : QPushButton(p) {
    generatePushButton(size, row, col);
    connect(this, &TileButton::clicked, this, &TileButton::onClick);
}

void TileButton::generatePushButton(int size, int row, int col) {
    setObjectName(TileHandler::getName(row, col));
    setMinimumSize(size, size);
    setCheckable(true);
    show();
}

void TileButton::onClick() {
    TileHandler::onClick(objectName(), parentWidget());
}
