#ifndef SCHEMAHANDLER_H
#define SCHEMAHANDLER_H

#include <vector>

class SchemaHandler {

public:
    SchemaHandler();

    std::vector<std::vector<bool>> fromPattern();
};

#endif // SCHEMAHANDLER_H
