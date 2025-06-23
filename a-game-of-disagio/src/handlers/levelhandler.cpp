#include "levelhandler.h"
#include "schemahandler.h"
#include "../ui/centrallayout.h"

LevelHandler::LevelHandler(int s, QWidget *p) {
    size = s;
    parent = p;
}

void LevelHandler::setLevel(int level) {
    Schema schema = getSchema(level);
    std::vector<std::vector<Button *>> buttons = getButtons();
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            Button *button = buttons[row][col];
            button->setChecked(schema.getMatrix()[row][col]);
        }
    }
}

Schema LevelHandler::getSchema(int level) {
    SchemaHandler schemaHandler(size);
    std::vector<char> pattern = {'D', 'i', 's', 'a', 'g', 'i', 'o', '.'};
    return schemaHandler.fromPattern(pattern[level])->get();
}

std::vector<std::vector<Button *>> LevelHandler::getButtons() {
    return ((CentralLayout *) parent->layout())->getButtons();
}
