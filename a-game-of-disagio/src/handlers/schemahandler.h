#ifndef SCHEMAHANDLER_H
#define SCHEMAHANDLER_H

#include <vector>
#include <map>

class SchemaHandler {

public:
    SchemaHandler();

    std::vector<std::vector<bool>> fromPattern();

    std::vector<std::vector<bool>> fromPattern(char pattern);

private:
    std::map<char, std::vector<std::vector<bool>>> map;
};

#endif // SCHEMAHANDLER_H
