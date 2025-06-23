#include "../exceptions.h"
#include "schema.h"

Schema::Schema() : Schema(5) {
}

Schema::Schema(int s) {
    std::vector<std::vector<bool>> m;
    for (int row = 0; row < s; row++) {
        std::vector<bool> r;
        for (int col = 0; col < s; col++) {
            r.push_back(false);
        }
        m.push_back(r);
    }
    set(s, m);
}

Schema::Schema(int s, const std::vector<std::vector<bool>> &m) {
    set(s, m);
}

void Schema::set(int s, const std::vector<std::vector<bool>> &m) {
    if (m.size() != s) {
        throw IncoherentSizeException();
    }
    size = s;
    matrix.clear();
    for (const std::vector<bool> &entry: m) {
        if (entry.size() != size) {
            throw IncoherentSizeException();
        }
        matrix.push_back(entry);
    }
}

int Schema::getSize() const {
    return size;
}

std::vector<std::vector<bool>> Schema::getMatrix() {
    return matrix;
}
