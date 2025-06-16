#include "tst_schemahandler.h"
#include "../src/handlers/schemahandler.h"
#include "../src/exceptions.h"

TestSchemaHandler::TestSchemaHandler() {}

void TestSchemaHandler::isEmptyAndIsFullWithSize0() {
    SchemaHandler *handler = new SchemaHandler(0);
    QVERIFY(handler->isEmpty());
    QVERIFY(handler->isFull());
}

void TestSchemaHandler::isEmptyOrIsFullWithSize1() {
    SchemaHandler *handler = new SchemaHandler(1);
    QVERIFY(handler->isEmpty());
    QVERIFY(!handler->isFull());
    handler->setFull(0, 0);
    QVERIFY(!handler->isEmpty());
    QVERIFY(handler->isFull());
}

void TestSchemaHandler::isEmptyOrIsFullWithSize10() {
    SchemaHandler *handler = new SchemaHandler(10);
    QVERIFY(handler->isEmpty());
    QVERIFY(!handler->isFull());
    for (int row = 0; row < 10; row++) {
        for (int col = 0; col < 10; col++) {
            handler->setFull(row, col);
            if (row != 9 && col != 9) {
                QVERIFY(!handler->isEmpty());
                QVERIFY(!handler->isFull());
            }
        }
    }
    QVERIFY(!handler->isEmpty());
    QVERIFY(handler->isFull());
    for (int row = 0; row < 10; row++) {
        for (int col = 0; col < 10; col++) {
            handler->setEmpty(row, col);
            if (row != 9 && col != 9) {
                QVERIFY(!handler->isEmpty());
                QVERIFY(!handler->isFull());
            }
        }
    }
    QVERIFY(handler->isEmpty());
    QVERIFY(!handler->isFull());
}

void TestSchemaHandler::setFullWithException() {
    SchemaHandler *handler = new SchemaHandler(1);
    QVERIFY(handler->isEmpty());
    QVERIFY_EXCEPTION_THROWN(handler->setFull(1, 0), OutOfSchema);
    QVERIFY(handler->isEmpty());
}

QTEST_APPLESS_MAIN(TestSchemaHandler)
