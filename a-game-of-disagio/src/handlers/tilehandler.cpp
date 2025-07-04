#include "tilehandler.h"
#include <string>
#include <sstream>

QString TileHandler::getName(int row, int col) {
    return "tile_" + QString::number(row) + "_" + QString::number(col);
}

void TileHandler::onClick(QString name, QWidget *parent) {
    QList<QPushButton *> buttons = TileHandler::getCross(name, parent);
    for (QPushButton *button: buttons) {
        button->setChecked(!button->isChecked());
    }
}

QList<QPushButton *> TileHandler::getCross(QString name, QWidget *parent) {
    QList<int> rowCol = TileHandler::getRowCol(name);
    int row = rowCol[0];
    int col = rowCol[1];
    QList<QPushButton *> buttons;
    TileHandler::addButtonFromName(TileHandler::getName(row - 1, col), &buttons, parent);
    TileHandler::addButtonFromName(TileHandler::getName(row, col - 1), &buttons, parent);
    TileHandler::addButtonFromName(TileHandler::getName(row + 1, col), &buttons, parent);
    TileHandler::addButtonFromName(TileHandler::getName(row, col + 1), &buttons, parent);
    return buttons;
}

void TileHandler::addButtonFromName(QString name, QList<QPushButton *> * buttons, QWidget *parent) {
    QPushButton *button = parent->findChild<QPushButton *>(name);
    if (button) {
        buttons->push_back(button);
    }
}

QList<int> TileHandler::getRowCol(QString name) {
    std::stringstream toSplit(name.toStdString());
    QList<int> toReturn;
    std::string segment;
    std::getline(toSplit, segment, '_');
    std::getline(toSplit, segment, '_');
    toReturn.push_back(std::stoi(segment));
    std::getline(toSplit, segment, '_');
    toReturn.push_back(std::stoi(segment));
    return toReturn;
}
