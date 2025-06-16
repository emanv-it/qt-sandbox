#include "schemahandler.h"

SchemaHandler::SchemaHandler() {
    map[' '] = (std::vector<std::vector<bool>>) {{false, false, false, false, false},
                                                 {false, false, false, false, false},
                                                 {false, false, false, false, false},
                                                 {false, false, false, false, false},
                                                 {false, false, false, false, false}};
    map['.'] = (std::vector<std::vector<bool>>) {{false, false, false, false, false},
                                                 {false, false, false, false, false},
                                                 {false, false, false, false, false},
                                                 {false, false, false, false, false},
                                                 {false, false, true,  false, false}};
    map['D'] = (std::vector<std::vector<bool>>) {{true, true,  true,  false, false},
                                                 {true, false, false, true,  false},
                                                 {true, false, false, false, true},
                                                 {true, false, false, false, true},
                                                 {true, true,  true,  true,  false}};
    map['i'] = (std::vector<std::vector<bool>>) {{false, false, true,  false, false},
                                                 {false, false, false, false, false},
                                                 {false, true,  true,  false, false},
                                                 {false, false, true,  false, false},
                                                 {false, true,  true,  true,  false}};

}

std::vector<std::vector<bool>> SchemaHandler::fromPattern() {
    return map[' '];
}

std::vector<std::vector<bool>> SchemaHandler::fromPattern(char pattern) {
    std::vector<std::vector<bool>> schema = map[pattern];
    if (!schema.empty()) {
        return schema;
    }
    return map[' '];
}
