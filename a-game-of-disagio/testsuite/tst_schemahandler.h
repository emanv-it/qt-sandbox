#include <QtTest>
#include "../src/handlers/schemahandler.h"

class TestSchemaHandler : public QObject {
Q_OBJECT

public:
    TestSchemaHandler();

private:
    SchemaHandler *handler;

private slots:

    void getEmptySchema();

    void getDotSchema();

    void getUpperCaseDSchema();

    void getLowerCaseISchema();

    void getDoubleDotSchema();

    void getDoubleDSchema();

    void performClick();
};
