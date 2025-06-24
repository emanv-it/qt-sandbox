#include "tst_schemahandler.h"
#include "../src/handlers/schemahandler.h"

TestSchemaHandler::TestSchemaHandler() {
}

void TestSchemaHandler::getEmptySchema() {
    std::vector<std::vector<bool>> expected = {{false, false, false, false, false},
                                               {false, false, false, false, false},
                                               {false, false, false, false, false},
                                               {false, false, false, false, false},
                                               {false, false, false, false, false}};
    Schema schema;
    QVERIFY(
            schema.getSize() == 5
    );
    QVERIFY(
            schema.getMatrix() == expected
    );
}

void TestSchemaHandler::getDotSchema() {
    std::vector<std::vector<bool>> expected = {{false, false, false, false, false},
                                               {false, false, false, false, false},
                                               {false, false, false, false, false},
                                               {false, false, false, false, false},
                                               {false, false, true,  false, false}};
    Schema schema = SchemaHandler::fromPattern('.', 5);
    QVERIFY(
            schema.getSize() == 5
    );
    QVERIFY(
            schema.getMatrix() == expected
    );
}

void TestSchemaHandler::getUpperCaseDSchema() {
    std::vector<std::vector<bool>> expected = {{true, true,  true,  false, false},
                                               {true, false, false, true,  false},
                                               {true, false, false, false, true},
                                               {true, false, false, false, true},
                                               {true, true,  true,  true,  false}};
    Schema schema = SchemaHandler::fromPattern('D', 5);
    QVERIFY(
            schema.getSize() == 5
    );
    QVERIFY(
            schema.getMatrix() == expected
    );
}

void TestSchemaHandler::getLowerCaseISchema() {
    std::vector<std::vector<bool>> expected = {{false, false, true,  false, false},
                                               {false, false, false, false, false},
                                               {false, true,  true,  false, false},
                                               {false, false, true,  false, false},
                                               {false, true,  true,  true,  false}};
    Schema schema = SchemaHandler::fromPattern('i', 5);
    QVERIFY(
            schema.getSize() == 5
    );
    QVERIFY(
            schema.getMatrix() == expected
    );
}

void TestSchemaHandler::getDoubleDotSchema() {
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
    Schema schema = SchemaHandler::fromPattern('.', 10);
    QVERIFY(
            schema.getSize() == 10
    );
    QVERIFY(
            schema.getMatrix() == expected
    );
}

void TestSchemaHandler::getDoubleDSchema() {
    std::vector<std::vector<bool>> expected = {{true, true, true,  true,  true,  true,  false, false, false},
                                               {true, true, true,  true,  true,  true,  false, false, false},
                                               {true, true, false, false, false, false, true,  true,  false},
                                               {true, true, false, false, false, false, true,  true,  false},
                                               {true, true, false, false, false, false, false, false, true},
                                               {true, true, false, false, false, false, false, false, true},
                                               {true, true, false, false, false, false, false, false, true},
                                               {true, true, false, false, false, false, false, false, true},
                                               {true, true, true,  true,  true,  true,  true,  true,  false}};
    Schema schema = SchemaHandler::fromPattern('D', 9);
    QVERIFY(
            schema.getSize() == 9
    );
    QVERIFY(
            schema.getMatrix() == expected
    );
}


QTEST_APPLESS_MAIN(TestSchemaHandler)
