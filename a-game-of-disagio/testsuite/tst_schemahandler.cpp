#include "tst_schemahandler.h"

TestSchemaHandler::TestSchemaHandler() {
    handler = new SchemaHandler();
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

QTEST_APPLESS_MAIN(TestSchemaHandler)
