#include "levelhandler.h"
#include "schemahandler.h"
#include "tilehandler.h"

void LevelHandler::setLevel(int nOfTiles, int level, QWidget *parent) {
    QVector<QVector<bool>> matrix = LevelHandler::getSchemaFromLevel(nOfTiles, level).getMatrix();
    for (int row = 0; row < nOfTiles; row++) {
        for (int col = 0; col < nOfTiles; col++) {
            auto *button = parent->findChild<QPushButton *>(TileHandler::getName(row, col));
            if (button) {
                button->setChecked(matrix[row][col]);
            }
        }
    }

}

Schema LevelHandler::getSchemaFromLevel(int nOfTiles, int level) {
    QList<char> pattern = {'D', 'i', 's', 'a', 'g', 'i', 'o', '.'};
    return SchemaHandler::fromPattern(pattern[level], nOfTiles);
}
