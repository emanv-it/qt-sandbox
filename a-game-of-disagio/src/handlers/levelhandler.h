#ifndef LEVELHANDLER_H
#define LEVELHANDLER_H

#include <QWidget>
#include "src/models/schema.h"

class LevelHandler {

public:

    static void setLevel(int level, QWidget *p);

private:

    static Schema getSchemaFromLevel(int size, int level);
};

#endif //LEVELHANDLER_H
