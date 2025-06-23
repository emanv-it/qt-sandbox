#include <cmath>
#include "schemahandler.h"
#include "../exceptions.h"

SchemaHandler::SchemaHandler() : SchemaHandler(5) {
}

SchemaHandler::SchemaHandler(int s) : current(s) {
    initMap();
}

void SchemaHandler::initMap() {
    map['.'] = Schema(5, {{false, false, false, false, false},
                          {false, false, false, false, false},
                          {false, false, false, false, false},
                          {false, false, false, false, false},
                          {false, false, true,  false, false}});
    map['D'] = Schema(5, {{true, true,  true,  false, false},
                          {true, false, false, true,  false},
                          {true, false, false, false, true},
                          {true, false, false, false, true},
                          {true, true,  true,  true,  false}});
    map['i'] = Schema(5, {{false, false, true,  false, false},
                          {false, false, false, false, false},
                          {false, true,  true,  false, false},
                          {false, false, true,  false, false},
                          {false, true,  true,  true,  false}});
}

Schema SchemaHandler::get() {
    return current;
}

SchemaHandler *SchemaHandler::fromPattern(char pattern) {
    try {
        resize(map[pattern]);
    } catch (IncoherentSizeException &exception) {
        throw UnknownPatternException();
    }
    return this;
}

SchemaHandler *SchemaHandler::set(Schema schema) {
    current.set(schema.getSize(), schema.getMatrix());
    return this;
}

SchemaHandler *SchemaHandler::resize(Schema schema) {
    int oldSize = schema.getSize();
    int newSize = current.getSize();
    float factor = static_cast<float>(oldSize) / static_cast<float>(newSize);
    std::vector<std::vector<bool>> newMatrix;
    for (int row = 0; row < current.getSize(); row++) {
        std::vector<bool> entry;
        int oldRow = resizePosition(row, factor);
        for (int col = 0; col < current.getSize(); col++) {
            int oldCol = resizePosition(col, factor);
            entry.push_back(schema.getMatrix()[oldRow][oldCol]);
        }
        newMatrix.push_back(entry);
    }
    current.set(newSize, newMatrix);
    return this;
}

int SchemaHandler::resizePosition(int position, float factor) {
    int origin = static_cast<int>(std::round(static_cast<float>(position + 1) * factor));
    int newSize = current.getSize();
    origin = (origin > newSize) ? newSize : origin;
    return origin - 1;
}

SchemaHandler *SchemaHandler::change(int row, int col) {
    int size = current.getSize();
    if (row >= size || col >= size) {
        throw OutOfSchemaException();
    }
    std::vector<std::vector<bool>> matrix = current.getMatrix();
    matrix.at(row).at(col) = !matrix.at(row).at(col);
    if (row > 0) {
        matrix.at(row - 1).at(col) = !matrix.at(row - 1).at(col);
    }
    if (row < size - 1) {
        matrix.at(row + 1).at(col) = !matrix.at(row + 1).at(col);
    }
    if (col > 0) {
        matrix.at(row).at(col - 1) = !matrix.at(row).at(col - 1);
    }
    if (col < size - 1) {
        matrix.at(row).at(col + 1) = !matrix.at(row).at(col + 1);
    }
    Schema schema(size, matrix);
    set(schema);
    return this;
}

bool SchemaHandler::isEmpty() {
    for (std::vector<bool> entry: current.getMatrix()) {
        for (bool value: entry) {
            if (value) {
                return false;
            }
        }
    }
    return true;
}