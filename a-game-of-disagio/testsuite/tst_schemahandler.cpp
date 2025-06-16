#include "tst_schemahandler.h"

TestSchemaHandler::TestSchemaHandler() {
    handler = new SchemaHandler();
}

void TestSchemaHandler::getEmptySchema() {
    QVERIFY(
            handler->fromPattern() == (std::vector<std::vector<bool>>) {{false}}
    );
}

QTEST_APPLESS_MAIN(TestSchemaHandler)
