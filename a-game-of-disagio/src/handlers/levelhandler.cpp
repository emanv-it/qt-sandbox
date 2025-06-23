#include "levelhandler.h"
#include "schemahandler.h"
#include "../ui/centrallayout.h"

LevelHandler::LevelHandler(QWidget *p) : parent(p) {
}

void LevelHandler::setLevel(int level) {
    std::vector<std::vector<Button *>> buttons = ((CentralLayout *) parent->layout())->getButtons();
    int size = static_cast<int>(buttons.size());
    std::vector<std::vector<bool>> matrix = getSchema(size, level).getMatrix();
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            buttons.at(row).at(col)->setChecked(matrix[row][col]);
        }
    }
}

Schema LevelHandler::getSchema(int size, int level) {
    std::vector<char> pattern = {'D', 'i', 's', 'a', 'g', 'i', 'o', '.'};
    auto *schemaHandler = new SchemaHandler(size);
    return schemaHandler->fromPattern(pattern[level])->get();
}
