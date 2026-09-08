#pragma once

#include <string>
#include <vector>

namespace colosseum::lib::engine {

struct Config {
    std::string name, cmd, dir, args;
    std::vector<std::pair<std::string, std::string>> uci_options;
};

} // namspace colosseum::lib::engine