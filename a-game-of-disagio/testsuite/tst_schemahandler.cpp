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

QTEST_APPLESS_MAIN(TestSchemaHandler)
