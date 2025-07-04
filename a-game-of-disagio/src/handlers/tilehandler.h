#ifndef TILEHANDLER_H
#define TILEHANDLER_H

#include <QList>
#include <QPushButton>
#include <QString>
#include <QWidget>

class TileHandler {

public:

    static QString getName(int row, int col);

    static void onClick(QString name, QWidget *parent);

private:

    static QList<QPushButton *> getCross(QString name, QWidget *parent);

    static void addButtonFromName(QString name, QList<QPushButton *> *buttons, QWidget *parent);

    static QList<int> getRowCol(QString name);

};


#endif //TILEHANDLER_H
