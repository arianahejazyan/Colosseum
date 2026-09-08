#pragma once

#include <string>

namespace colosseum::lib::tournament {

struct Config {
    std::string setup;
    int wait = 0;
    int rounds = 1;
    int concurrency = 1;
    bool force_concurrency = false;
};

} // namspace colosseum::lib::tournament