#include "schemahandler.h"

SchemaHandler::SchemaHandler() {
}

std::vector<std::vector<bool>> SchemaHandler::fromPattern() {
    return (std::vector<std::vector<bool>>) {{false, false, false, false, false},
                                             {false, false, false, false, false},
                                             {false, false, false, false, false},
                                             {false, false, false, false, false},
                                             {false, false, false, false, false}};
}

std::vector<std::vector<bool>> SchemaHandler::fromPattern(char pattern) {
    return (std::vector<std::vector<bool>>) {{false, false, false, false, false},
                                             {false, false, false, false, false},
                                             {false, false, false, false, false},
                                             {false, false, false, false, false},
                                             {false, false, true,  false, false}};
}
