#include <QtTest>

class TestSchemaHandler : public QObject
{
    Q_OBJECT

public:
    TestSchemaHandler();

private slots:
    void isEmptyAndIsFullWithSize0();

    void isEmptyOrIsFullWithSize1();

    void isEmptyOrIsFullWithSize10();

    void setFullWithException();
};
