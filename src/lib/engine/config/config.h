#pragma once

#include <string>
#include <vector>

namespace colosseum::engine {

struct Config {
public:
    std::string name;
    std::string cmd;
    std::string dir;
    std::string args;
    std::vector<std::pair<std::string, std::string>> uci_options;
};

} // namspace colosseum