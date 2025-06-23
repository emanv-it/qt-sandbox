#ifndef SCHEMA_H
#define SCHEMA_H

#include <vector>

class Schema {
public:
    Schema();

    explicit Schema(int s);

    Schema(int s, const std::vector<std::vector<bool>>& m);

    void set(int s, const std::vector<std::vector<bool>>& m);

    int getSize() const;

    std::vector<std::vector<bool>> getMatrix();

private:
    int size = 0;

    std::vector<std::vector<bool>> matrix;
};

#endif //SCHEMA_H
