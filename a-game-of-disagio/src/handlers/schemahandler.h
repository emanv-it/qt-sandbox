#ifndef SCHEMAHANDLER_H
#define SCHEMAHANDLER_H

#include <vector>
#include <map>

class SchemaHandler {

public:
    SchemaHandler(int size);

    std::vector<std::vector<bool>> fromPattern();

    std::vector<std::vector<bool>> fromPattern(char pattern);

private:
    int size;

    std::map<char, std::vector<std::vector<bool>>> map;

    void initMap();

    std::vector<std::vector<bool>> resize(std::vector<std::vector<bool>> schema);

    int resizePosition(int position, float factor);
};

#endif // SCHEMAHANDLER_H
