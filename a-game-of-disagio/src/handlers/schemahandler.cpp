#include <cmath>
#include "schemahandler.h"

SchemaHandler::SchemaHandler(int size) {
    this->size = size;
    initMap();
}

void SchemaHandler::initMap() {
    map[' '] = (std::vector<std::vector<bool>>) {{false, false, false, false, false},
                                                 {false, false, false, false, false},
                                                 {false, false, false, false, false},
                                                 {false, false, false, false, false},
                                                 {false, false, false, false, false}};
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

std::vector<std::vector<bool>> SchemaHandler::fromPattern() {
    return fromPattern(' ');
}

std::vector<std::vector<bool>> SchemaHandler::fromPattern(char pattern) {
    std::vector<std::vector<bool>> schema = map[pattern];
    if (schema.empty()) {
        schema = map[' '];
    }
    return resize(schema);
}

std::vector<std::vector<bool>> SchemaHandler::resize(std::vector<std::vector<bool>> schema) {
    if (size <= 5) {
        return schema;
    }
    float factor = 5 / static_cast<float>(size);
    std::vector<std::vector<bool>> resizedSchema;
    for (int row = 0; row < size; row++) {
        std::vector<bool> resizedRow;
        int rowOrig = resizePosition(row, factor);
        for (int col = 0; col < size; col++) {
            int colOrig = resizePosition(col, factor);
            resizedRow.push_back(schema[rowOrig][colOrig]);
        }
        resizedSchema.push_back(resizedRow);
    }
    return resizedSchema;
}

int SchemaHandler::resizePosition(int position, float factor) {
    int origin = static_cast<int>(std::round(static_cast<float>(position + 1) * factor));
    if (origin > 5) {
        origin = 5;
    }
    return origin - 1;
}