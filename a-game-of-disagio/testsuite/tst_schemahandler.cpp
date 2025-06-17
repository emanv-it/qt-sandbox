#include "tst_schemahandler.h"

TestSchemaHandler::TestSchemaHandler() {
    handler = new SchemaHandler(5);
}

void TestSchemaHandler::getEmptySchema() {
    std::vector<std::vector<bool>> expected = {{false, false, false, false, false},
                                               {false, false, false, false, false},
                                               {false, false, false, false, false},
                                               {false, false, false, false, false},
                                               {false, false, false, false, false}};
    QVERIFY(
            handler->fromPattern() == expected
    );
}

void TestSchemaHandler::getDotSchema() {
    std::vector<std::vector<bool>> expected = {{false, false, false, false, false},
                                               {false, false, false, false, false},
                                               {false, false, false, false, false},
                                               {false, false, false, false, false},
                                               {false, false, true,  false, false}};
    QVERIFY(
            handler->fromPattern('.') == expected
    );
}

void TestSchemaHandler::getUpperCaseDSchema() {
    std::vector<std::vector<bool>> expected = {{true, true,  true,  false, false},
                                               {true, false, false, true,  false},
                                               {true, false, false, false, true},
                                               {true, false, false, false, true},
                                               {true, true,  true,  true,  false}};
    QVERIFY(
            handler->fromPattern('D') == expected
    );
}

void TestSchemaHandler::getLowerCaseISchema() {
    std::vector<std::vector<bool>> expected = {{false, false, true,  false, false},
                                               {false, false, false, false, false},
                                               {false, true,  true,  false, false},
                                               {false, false, true,  false, false},
                                               {false, true,  true,  true,  false}};
    QVERIFY(
            handler->fromPattern('i') == expected
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
            handler->fromPattern('.') == expected
    );
}

QTEST_APPLESS_MAIN(TestSchemaHandler)
