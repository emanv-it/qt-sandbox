#include "windowlayout.h"

WindowLayout::WindowLayout(QWidget *parent) : QBoxLayout(LeftToRight, parent) {
}

void WindowLayout::addSchema(int nOfTiles, QSize size) {
    handleDirection(size);
    schema = new SchemaWidget(nOfTiles, getSchemaSide(size));
    side = new SideWidget(getSideSize(size));
    addWidget(schema, 1, Qt::AlignCenter);
    addWidget(side, 1, Qt::AlignLeft);
}

void WindowLayout::handleDirection(QSize size) {
    setDirection((size.width() > size.height()) ? LeftToRight : TopToBottom);
}

int WindowLayout::getSchemaSide(QSize size) {
    int height = size.height();
    int schemaSize = size.width() * 2 / 3;
    return (schemaSize > height) ? height - 50 : schemaSize;
}

QSize WindowLayout::getSideSize(QSize size) {
    int sideWidth = size.width() / 3;
    return {sideWidth, size.height()};
}

void WindowLayout::resizeHandler(QSize size) {
    handleDirection(size);
    schema->resizeHandler(getSchemaSide(size));
    //side->resizeHandler(getSideSize(size));
}