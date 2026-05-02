#pragma once

#include <string>
#include <vector>

namespace colosseum {

struct EngineConfig {
public:
    std::string name;
    std::string cmd;
    std::string dir;
    std::string args;
    std::vector<std::pair<std::string, std::string>> options;
};

} // namspace colosseum