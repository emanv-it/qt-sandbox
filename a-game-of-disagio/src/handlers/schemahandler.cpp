#include <cmath>
#include "schemahandler.h"
#include "../exceptions.h"

Schema SchemaHandler::fromPattern(char pattern, int nOfTiles) {
    return resize(getMap(pattern), nOfTiles);
}

Schema SchemaHandler::getMap(char pattern) {
    switch (pattern) {
        case '.':
            return Schema(5, {{false, false, false, false, false},
                              {false, false, false, false, false},
                              {false, false, false, false, false},
                              {false, false, false, false, false},
                              {false, false, true,  false, false}});
        case 'D':
            return Schema(5, {{true, true,  true,  false, false},
                              {true, false, false, true,  false},
                              {true, false, false, false, true},
                              {true, false, false, false, true},
                              {true, true,  true,  true,  false}});
        case 'i':
            return Schema(5, {{false, false, true,  false, false},
                              {false, false, false, false, false},
                              {false, true,  true,  false, false},
                              {false, false, true,  false, false},
                              {false, true,  true,  true,  false}});
        default:
            return Schema(5);
    }
}

Schema SchemaHandler::resize(Schema schema, int nOfTiles) {
    Schema toReturn(nOfTiles);
    int oldSize = schema.getSize();
    float factor = static_cast<float>(oldSize) / static_cast<float>(nOfTiles);
    QVector<QVector<bool>> newMatrix;
    newMatrix.resize(nOfTiles);
    for (int row = 0; row < nOfTiles; row++) {
        newMatrix[row].resize(nOfTiles);
        int oldRow = resizePosition(row, nOfTiles, factor);
        for (int col = 0; col < nOfTiles; col++) {
            int oldCol = resizePosition(col, nOfTiles, factor);
            newMatrix[row][col] = schema.getMatrix()[oldRow][oldCol];
        }
    }
    try {
        toReturn.set(nOfTiles, newMatrix);
    } catch (IncoherentSizeException &exception) {
        throw UnknownPatternException();
    }
    return toReturn;
}

int SchemaHandler::resizePosition(int position, int nOfTiles, float factor) {
    int origin = static_cast<int>(std::round(static_cast<float>(position + 1) * factor));
    origin = (origin > nOfTiles) ? nOfTiles : origin;
    return origin - 1;
}