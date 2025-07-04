#include "tilebutton.h"
#include "schemalayout.h"
#include "src/handlers/tilehandler.h"

TileButton::TileButton(int side, int row, int col, QWidget *p) : QPushButton(p) {
    generatePushButton(TileHandler::getName(row, col), side);
    connect(this, &TileButton::clicked, this, &TileButton::onClick);
}

void TileButton::generatePushButton(const QString &name, int side) {
    setObjectName(name);
    setFixedSize(side, side);
    setCheckable(true);
    show();
}

void TileButton::onClick() {
    TileHandler::onClick(objectName(), parentWidget());
}

void TileButton::resizeHandler(int side) {
    setFixedSize(side, side);
}
