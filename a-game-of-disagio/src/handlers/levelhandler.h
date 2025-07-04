#ifndef LEVELHANDLER_H
#define LEVELHANDLER_H

#include <QWidget>
#include "../models/schema.h"

class LevelHandler {

public:

    static void setLevel(int nOfTiles, int level, QWidget *parent);

private:

    static Schema getSchemaFromLevel(int nOfTiles, int level);
};

#endif //LEVELHANDLER_H
