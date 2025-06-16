#ifndef SCHEMAHANDLER_H
#define SCHEMAHANDLER_H

#include <vector>

class SchemaHandler {

public:
    SchemaHandler();

    std::vector<std::vector<bool>> fromPattern();

    std::vector<std::vector<bool>> fromPattern(char pattern);
};

#endif // SCHEMAHANDLER_H
