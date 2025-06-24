#include <cmath>
#include "schemahandler.h"
#include "../exceptions.h"

Schema SchemaHandler::fromPattern(char pattern, int size) {
    return resize(getMap(pattern), size);
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

Schema SchemaHandler::resize(Schema schema, int size) {
    Schema toReturn(size);
    int oldSize = schema.getSize();
    float factor = static_cast<float>(oldSize) / static_cast<float>(size);
    std::vector<std::vector<bool>> newMatrix;
    for (int row = 0; row < size; row++) {
        std::vector<bool> entry;
        int oldRow = resizePosition(row, size, factor);
        for (int col = 0; col < size; col++) {
            int oldCol = resizePosition(col, size, factor);
            entry.push_back(schema.getMatrix()[oldRow][oldCol]);
        }
        newMatrix.push_back(entry);
    }
    try {
        toReturn.set(size, newMatrix);
    } catch (IncoherentSizeException &exception) {
        throw UnknownPatternException();
    }
    return toReturn;
}

int SchemaHandler::resizePosition(int position, int size, float factor) {
    int origin = static_cast<int>(std::round(static_cast<float>(position + 1) * factor));
    origin = (origin > size) ? size : origin;
    return origin - 1;
}