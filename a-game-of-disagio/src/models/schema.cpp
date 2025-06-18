#include "../exceptions.h"
#include "schema.h"

Schema::Schema() {
    init(5);
}

void Schema::init(int s, std::vector<std::vector<bool>> m) {
    if (m.size() != s) {
        throw IncoherentSizeException();
    }
    size = s;
    matrix.clear();
    for (std::vector<bool> entry: m) {
        if (entry.size() != size) {
            throw IncoherentSizeException();
        }
        matrix.push_back(entry);
    }
}

void Schema::init(int s) {
    std::vector<std::vector<bool>> m;
    for (int row = 0; row < s; row++) {
        std::vector<bool> r;
        for (int col = 0; col < s; col++) {
            r.push_back(false);
        }
        m.push_back(r);
    }
    init(s, m);
}