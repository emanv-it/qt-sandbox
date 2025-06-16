#include "schemahandler.h"
#include "../exceptions.h"

SchemaHandler::SchemaHandler(int size) {
    this->size = size;
    initSchema();
}

void SchemaHandler::initSchema() {
    for (int i = 0; i < size; i++) {
        std::vector<bool> row(size, false);
        schema.push_back(row);
    }
}

bool SchemaHandler::isEmpty() {
    for (const std::vector<bool>& row : schema) {
        for (const bool& element : row) {
            if (element) {
                return false;
            }
        }
    }
    return true;
}

bool SchemaHandler::isFull() {
    for (const std::vector<bool>& row : schema) {
        for (const bool& element : row) {
            if (!element) {
                return false;
            }
        }
    }
    return true;
}

void SchemaHandler::setEmpty(int row, int col) {
    set(row, col, false);
}

void SchemaHandler::set(int row, int col, bool value) {
    if ((row >= size) || (col >= size)) {
        throw OutOfSchema();
    }
    schema.at(row).at(col) = value;
}

void SchemaHandler::setFull(int row, int col) {
    set(row, col, true);
}
