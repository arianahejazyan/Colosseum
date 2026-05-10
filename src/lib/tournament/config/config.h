#pragma once

#include <string>

namespace colosseum::tournament {

struct Config {
public:
    std::string setup = "modern";
    std::string mode = "team";
    int wait = 0;
    int rounds = 1;
    int concurrency = 1;
    bool force_concurrency = false;
};

} // namspace colosseum