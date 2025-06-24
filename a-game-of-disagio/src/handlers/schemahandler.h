#ifndef SCHEMAHANDLER_H
#define SCHEMAHANDLER_H

#include "../models/schema.h"
#include <map>

class SchemaHandler {

public:

    static Schema fromPattern(char pattern, int size);

private:

    static Schema getMap(char pattern);

    static Schema resize(Schema schema, int size);

    static int resizePosition(int position, int size, float factor);
};

#endif // SCHEMAHANDLER_H
