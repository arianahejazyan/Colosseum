#pragma once

#include <vector>
#include "engine/config/config.h"
#include "tournament/config/config.h"

namespace colosseum::cli {

struct Config {
public:
    tournament::Config tournament;
    std::vector<engine::Config> engine;
};

} // namspace colosseum