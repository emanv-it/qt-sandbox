#ifndef LEVELHANDLER_H
#define LEVELHANDLER_H

#include <QWidget>
#include "../ui/button.h"
#include "../models/schema.h"

class LevelHandler {

public:

    explicit LevelHandler(QWidget *p);

    void setLevel(int level);

private:

    QWidget *parent;

    static Schema getSchema(int size, int level);
};

#endif //LEVELHANDLER_H
