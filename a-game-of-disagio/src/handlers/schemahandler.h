#ifndef SCHEMAHANDLER_H
#define SCHEMAHANDLER_H

#include "../models/schema.h"
#include <map>

class SchemaHandler {

public:

    static Schema fromPattern(char pattern, int nOfTiles);

private:

    static Schema getMap(char pattern);

    static Schema resize(Schema schema, int nOfTiles);

    static int resizePosition(int position, int nOfTiles, float factor);
};

#endif // SCHEMAHANDLER_H
