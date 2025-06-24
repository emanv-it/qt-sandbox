#include <QtTest>

class TestSchemaHandler : public QObject {
Q_OBJECT

public:
    TestSchemaHandler();

private slots:

    void getEmptySchema();

    void getDotSchema();

    void getUpperCaseDSchema();

    void getLowerCaseISchema();

    void getDoubleDotSchema();

    void getDoubleDSchema();
};
