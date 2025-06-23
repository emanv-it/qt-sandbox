#ifndef LEVELHANDLER_H
#define LEVELHANDLER_H

#include <QWidget>
#include "../ui/button.h"
#include "../models/schema.h"

class LevelHandler {

public:

    LevelHandler(int size, QWidget *p);

    void setLevel(int level);

private:

    int size;

    QWidget *parent;

    Schema getSchema(int level);

    std::vector<std::vector<Button *>> getButtons();
};

#endif //LEVELHANDLER_H
