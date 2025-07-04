#ifndef SCHEMA_H
#define SCHEMA_H

#include <QVector>

class Schema {
public:
    Schema();

    explicit Schema(int s);

    Schema(int s, const QVector<QVector<bool>>& m);

    void set(int s, const QVector<QVector<bool>>& m);

    int getSize() const;

    QVector<QVector<bool>> getMatrix();

private:
    int size = 0;

    QVector<QVector<bool>> matrix;
};

#endif //SCHEMA_H
