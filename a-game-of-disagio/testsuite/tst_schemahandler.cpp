#include "tst_schemahandler.h"

TestSchemaHandler::TestSchemaHandler() {
}

void TestSchemaHandler::getEmptySchema() {
    handler = new SchemaHandler();
    std::vector<std::vector<bool>> expected = {{false, false, false, false, false},
                                               {false, false, false, false, false},
                                               {false, false, false, false, false},
                                               {false, false, false, false, false},
                                               {false, false, false, false, false}};
    Schema schema = handler->get();
    QVERIFY(
            schema.getSize() == 5
    );
    QVERIFY(
            schema.getMatrix() == expected
    );
}

void TestSchemaHandler::getDotSchema() {
    handler = new SchemaHandler();
    std::vector<std::vector<bool>> expected = {{false, false, false, false, false},
                                               {false, false, false, false, false},
                                               {false, false, false, false, false},
                                               {false, false, false, false, false},
                                               {false, false, true,  false, false}};
    Schema schema = handler->get();
    QVERIFY(
            schema.getSize() == 5
    );
    schema = handler->fromPattern('.')->get();
    QVERIFY(
            schema.getMatrix() == expected
    );
}

void TestSchemaHandler::getUpperCaseDSchema() {
    handler = new SchemaHandler();
    std::vector<std::vector<bool>> expected = {{true, true,  true,  false, false},
                                               {true, false, false, true,  false},
                                               {true, false, false, false, true},
                                               {true, false, false, false, true},
                                               {true, true,  true,  true,  false}};
    Schema schema = handler->get();
    QVERIFY(
            schema.getSize() == 5
    );
    schema = handler->fromPattern('D')->get();
    QVERIFY(
            schema.getMatrix() == expected
    );
}

void TestSchemaHandler::getLowerCaseISchema() {
    handler = new SchemaHandler();
    std::vector<std::vector<bool>> expected = {{false, false, true,  false, false},
                                               {false, false, false, false, false},
                                               {false, true,  true,  false, false},
                                               {false, false, true,  false, false},
                                               {false, true,  true,  true,  false}};
    Schema schema = handler->get();
    QVERIFY(
            schema.getSize() == 5
    );
    schema = handler->fromPattern('i')->get();
    QVERIFY(
            schema.getMatrix() == expected
    );
}

void TestSchemaHandler::getDoubleDotSchema() {
    handler = new SchemaHandler(10);
    std::vector<std::vector<bool>> expected = {{false, false, false, false, false, false, false, false, false, false},
                                               {false, false, false, false, false, false, false, false, false, false},
                                               {false, false, false, false, false, false, false, false, false, false},
                                               {false, false, false, false, false, false, false, false, false, false},
                                               {false, false, false, false, false, false, false, false, false, false},
                                               {false, false, false, false, false, false, false, false, false, false},
                                               {false, false, false, false, false, false, false, false, false, false},
                                               {false, false, false, false, false, false, false, false, false, false},
                                               {false, false, false, false, true,  true,  false, false, false, false},
                                               {false, false, false, false, true,  true,  false, false, false, false}};
    Schema schema = handler->get();
    QVERIFY(
            schema.getSize() == 10
    );
    schema = handler->fromPattern('.')->get();
    QVERIFY(
            schema.getMatrix() == expected
    );
}

void TestSchemaHandler::getDoubleDSchema() {
    handler = new SchemaHandler(9);
    std::vector<std::vector<bool>> expected = {{true, true, true,  true,  true,  true,  false, false, false},
                                               {true, true, true,  true,  true,  true,  false, false, false},
                                               {true, true, false, false, false, false, true,  true,  false},
                                               {true, true, false, false, false, false, true,  true,  false},
                                               {true, true, false, false, false, false, false, false, true},
                                               {true, true, false, false, false, false, false, false, true},
                                               {true, true, false, false, false, false, false, false, true},
                                               {true, true, false, false, false, false, false, false, true},
                                               {true, true, true,  true,  true,  true,  true,  true,  false}};
    Schema schema = handler->get();
    QVERIFY(
            schema.getSize() == 9
    );
    schema = handler->fromPattern('D')->get();
    QVERIFY(
            schema.getMatrix() == expected
    );
}

void TestSchemaHandler::performClick() {
    handler = new SchemaHandler();
    std::vector<std::vector<bool>> expected = {{false, false, false, false, false},
                                               {false, false, false, false, false},
                                               {false, false, false, false, false},
                                               {false, false, false, false, false},
                                               {false, false, true,  false, false}};
    Schema schema = handler->get();
    QVERIFY(
            schema.getSize() == 5
    );
    schema = handler->fromPattern('.')->get();
    QVERIFY(
            schema.getMatrix() == expected
    );
    expected = {{false, false, false, false, false},
                {false, false, false, false, false},
                {false, false, false, false, false},
                {false, false, true,  false, false},
                {false, true,  false, true,  false}};
    schema = handler->change(4, 2)->get();
    QVERIFY(
            schema.getMatrix() == expected
    );
    expected = {{false, false, false, false, false},
                {false, false, false, false, false},
                {false, false, true,  false, false},
                {false, true,  false, true,  false},
                {false, true,  true,  true,  false}};
    schema = handler->change(3, 2)->get();
    QVERIFY(
            schema.getMatrix() == expected
    );
}

void TestSchemaHandler::checkEmptySchema() {
    handler = new SchemaHandler();
    QVERIFY(
            handler->get().getSize() == 5
    );
    QVERIFY(
            handler->isEmpty()
    );
    QVERIFY(
            !handler->change(0, 0)->isEmpty()
    );
}

void TestSchemaHandler::setDoubleDotSchema() {
    handler = new SchemaHandler();
    std::vector<std::vector<bool>> expected = {{false, false, false, false, false},
                                               {false, false, false, false, false},
                                               {false, false, false, false, false},
                                               {false, false, false, false, false},
                                               {false, false, false, false, false}};
    Schema schema = handler->get();
    QVERIFY(
            schema.getSize() == 5
    );
    QVERIFY(
            schema.getMatrix() == expected
    );
    Schema toSet(10, {{false, false, false, false, false, false, false, false, false, false},
                      {false, false, false, false, false, false, false, false, false, false},
                      {false, false, false, false, false, false, false, false, false, false},
                      {false, false, false, false, false, false, false, false, false, false},
                      {false, false, false, false, false, false, false, false, false, false},
                      {false, false, false, false, false, false, false, false, false, false},
                      {false, false, false, false, false, false, false, false, false, false},
                      {false, false, false, false, false, false, false, false, false, false},
                      {false, false, false, false, true,  true,  false, false, false, false},
                      {false, false, false, false, true,  true,  false, false, false, false}});
    schema = handler->set(toSet)->get();
    QVERIFY(
            schema.getSize() == toSet.getSize()
    );
    QVERIFY(
            schema.getMatrix() == toSet.getMatrix()
    );
}


QTEST_APPLESS_MAIN(TestSchemaHandler)
