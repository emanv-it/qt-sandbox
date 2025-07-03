#include "levelhandler.h"
#include "schemahandler.h"
#include "src/ui/schemalayout.h"

void LevelHandler::setLevel(int level, QWidget *parent) {
    std::vector<std::vector<QPushButton *>> buttons = ((SchemaLayout *) parent->layout())->getButtons();
    int size = static_cast<int>(buttons.size());
    std::vector<std::vector<bool>> matrix = LevelHandler::getSchemaFromLevel(size, level).getMatrix();
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            buttons[row][col]->setChecked(matrix[row][col]);
        }
    }
}

Schema LevelHandler::getSchemaFromLevel(int size, int level) {
    std::vector<char> pattern = {'D', 'i', 's', 'a', 'g', 'i', 'o', '.'};
    return SchemaHandler::fromPattern(pattern[level], size);
}
