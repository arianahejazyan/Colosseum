#pragma once

#include <vector>
#include "engine/engine_config.h"
#include "tournament/tournament_config.h"

namespace colosseum {

struct CLIConfig {
public:
    TournamentConfig tournament;
    std::vector<EngineConfig> engine_configs;
};

} // namspace colosseum