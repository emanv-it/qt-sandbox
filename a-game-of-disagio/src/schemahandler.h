#ifndef SCHEMAHANDLER_H
#define SCHEMAHANDLER_H

#include <vector>

class SchemaHandler
{

public:
    SchemaHandler(int size);

    bool isEmpty();

    bool isFull();

    void setEmpty(int row, int col);

    void setFull(int row, int col);

private:
    int size;

    std::vector<std::vector<bool>> schema;

    void initSchema();

    void set(int row, int col, bool value);
};

#endif // SCHEMAHANDLER_H
