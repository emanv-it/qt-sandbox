#include <cmath>
#include "schemahandler.h"
#include "../exceptions.h"

SchemaHandler::SchemaHandler(int size) {
    current.init(size);
    initMap();
}

SchemaHandler::SchemaHandler() {
    initMap();
}

void SchemaHandler::initMap() {
    map['.'] = (std::vector<std::vector<bool>>) {{false, false, false, false, false},
                                                 {false, false, false, false, false},
                                                 {false, false, false, false, false},
                                                 {false, false, false, false, false},
                                                 {false, false, true,  false, false}};
    map['D'] = (std::vector<std::vector<bool>>) {{true, true,  true,  false, false},
                                                 {true, false, false, true,  false},
                                                 {true, false, false, false, true},
                                                 {true, false, false, false, true},
                                                 {true, true,  true,  true,  false}};
    map['i'] = (std::vector<std::vector<bool>>) {{false, false, true,  false, false},
                                                 {false, false, false, false, false},
                                                 {false, true,  true,  false, false},
                                                 {false, false, true,  false, false},
                                                 {false, true,  true,  true,  false}};
}

Schema SchemaHandler::get() {
    return current;
}

SchemaHandler *SchemaHandler::fromPattern(char pattern) {
    std::vector<std::vector<bool>> matrix = map[pattern];
    if (matrix.empty()) {
        throw UnknownPatternException();
    }
    set(matrix);
    return this;
}

void SchemaHandler::set(std::vector<std::vector<bool>> matrix) {
    float factor = 5 / static_cast<float>(current.size);
    current.matrix.clear();
    for (int row = 0; row < current.size; row++) {
        std::vector<bool> entry;
        int rowOrig = resizePosition(row, factor);
        for (int col = 0; col < current.size; col++) {
            int colOrig = resizePosition(col, factor);
            entry.push_back(matrix[rowOrig][colOrig]);
        }
        current.matrix.push_back(entry);
    }
}

int SchemaHandler::resizePosition(int position, float factor) {
    int origin = static_cast<int>(std::round(static_cast<float>(position + 1) * factor));
    origin = (origin > current.size) ? current.size : origin;
    return origin - 1;
}

SchemaHandler *SchemaHandler::change(int row, int col) {
    if (row >= current.size || col >= current.size) {
        throw OutOfSchemaException();
    }
    current.matrix.at(row).at(col) = !current.matrix.at(row).at(col);
    if (row > 0) {
        current.matrix.at(row - 1).at(col) = !current.matrix.at(row - 1).at(col);
    }
    if (row < current.size - 1) {
        current.matrix.at(row + 1).at(col) = !current.matrix.at(row + 1).at(col);
    }
    if (col > 0) {
        current.matrix.at(row).at(col - 1) = !current.matrix.at(row).at(col - 1);
    }
    if (col < current.size - 1) {
        current.matrix.at(row).at(col + 1) = !current.matrix.at(row).at(col + 1);
    }
    return this;
}