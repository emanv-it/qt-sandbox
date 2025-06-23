#ifndef SCHEMAHANDLER_H
#define SCHEMAHANDLER_H

#include "../models/schema.h"
#include <map>

class SchemaHandler {

public:

    SchemaHandler();

    explicit SchemaHandler(int size);

    Schema get();

    SchemaHandler *fromPattern(char pattern);

    SchemaHandler *resize(Schema schema);

private:
    Schema current;

    std::map<char, Schema> map;

    void initMap();

    int resizePosition(int position, float factor);
};

#endif // SCHEMAHANDLER_H
