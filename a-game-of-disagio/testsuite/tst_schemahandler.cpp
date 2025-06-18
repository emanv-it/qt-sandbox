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
    QVERIFY(
            handler->get().size == 5
    );
    QVERIFY(
            handler->get().matrix == expected
    );
}

void TestSchemaHandler::getDotSchema() {
    handler = new SchemaHandler();
    std::vector<std::vector<bool>> expected = {{false, false, false, false, false},
                                               {false, false, false, false, false},
                                               {false, false, false, false, false},
                                               {false, false, false, false, false},
                                               {false, false, true,  false, false}};
    QVERIFY(
            handler->get().size == 5
    );
    QVERIFY(
            handler->fromPattern('.')->get().matrix == expected
    );
}

void TestSchemaHandler::getUpperCaseDSchema() {
    handler = new SchemaHandler();
    std::vector<std::vector<bool>> expected = {{true, true,  true,  false, false},
                                               {true, false, false, true,  false},
                                               {true, false, false, false, true},
                                               {true, false, false, false, true},
                                               {true, true,  true,  true,  false}};
    QVERIFY(
            handler->get().size == 5
    );
    QVERIFY(
            handler->fromPattern('D')->get().matrix == expected
    );
}

void TestSchemaHandler::getLowerCaseISchema() {
    handler = new SchemaHandler();
    std::vector<std::vector<bool>> expected = {{false, false, true,  false, false},
                                               {false, false, false, false, false},
                                               {false, true,  true,  false, false},
                                               {false, false, true,  false, false},
                                               {false, true,  true,  true,  false}};
    QVERIFY(
            handler->get().size == 5
    );
    QVERIFY(
            handler->fromPattern('i')->get().matrix == expected
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
    QVERIFY(
            handler->get().size == 10
    );
    QVERIFY(
            handler->fromPattern('.')->get().matrix == expected
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
    QVERIFY(
            handler->get().size == 9
    );
    QVERIFY(
            handler->fromPattern('D')->get().matrix == expected
    );
}

void TestSchemaHandler::performClick() {
    handler = new SchemaHandler();
    std::vector<std::vector<bool>> expected = {{false, false, false, false, false},
                                               {false, false, false, false, false},
                                               {false, false, false, false, false},
                                               {false, false, false, false, false},
                                               {false, false, true,  false, false}};
    QVERIFY(
            handler->get().size == 5
    );
    QVERIFY(
            handler->fromPattern('.')->get().matrix == expected
    );
    expected = {{false, false, false, false, false},
                {false, false, false, false, false},
                {false, false, false, false, false},
                {false, false, true,  false, false},
                {false, true,  false, true,  false}};
    QVERIFY(
            handler->change(4, 2)->get().matrix == expected
    );
    expected = {{false, false, false, false, false},
                {false, false, false, false, false},
                {false, false, true,  false, false},
                {false, true,  false, true,  false},
                {false, true,  true,  true,  false}};
    QVERIFY(
            handler->change(3, 2)->get().matrix == expected
    );
}

QTEST_APPLESS_MAIN(TestSchemaHandler)
