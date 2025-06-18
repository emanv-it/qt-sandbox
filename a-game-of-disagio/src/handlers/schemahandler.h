#ifndef SCHEMAHANDLER_H
#define SCHEMAHANDLER_H

#include "../models/schema.h"
#include <map>

class SchemaHandler {

public:

    SchemaHandler(int size);

    SchemaHandler();

    Schema get();

    SchemaHandler *fromPattern(char pattern);

    SchemaHandler *change(int row, int col);

private:
    Schema current;

    std::map<char, std::vector<std::vector<bool>>> map;

    void initMap();

    void set(std::vector<std::vector<bool>> schema);

    int resizePosition(int position, float factor);
};

#endif // SCHEMAHANDLER_H
