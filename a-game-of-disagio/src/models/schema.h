#ifndef SCHEMA_H
#define SCHEMA_H

#include <vector>

class Schema {
public:
    Schema();

    void init(int s, std::vector<std::vector<bool>> m);

    void init(int s);

    int size;

    std::vector<std::vector<bool>> matrix;
};

#endif //SCHEMA_H
