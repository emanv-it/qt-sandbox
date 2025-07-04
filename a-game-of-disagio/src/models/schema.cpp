#include "../exceptions.h"
#include "schema.h"

Schema::Schema() : Schema(5) {
}

Schema::Schema(int s) {
    QVector<QVector<bool>> m;
    m.resize(s);
    for (int row = 0; row < s; row++) {
        m[row].resize(s);
    }
    set(s, m);
}

Schema::Schema(int s, const QVector<QVector<bool>> &m) {
    set(s, m);
}

void Schema::set(int s, const QVector<QVector<bool>> &m) {
    if (m.size() != s) {
        throw IncoherentSizeException();
    }
    size = s;
    matrix.clear();
    for (const QVector<bool> &entry: m) {
        if (entry.size() != size) {
            throw IncoherentSizeException();
        }
        matrix.push_back(entry);
    }
}

int Schema::getSize() const {
    return size;
}

QVector<QVector<bool>> Schema::getMatrix() {
    return matrix;
}
