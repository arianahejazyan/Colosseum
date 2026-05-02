#pragma once

#include <vector>
#include "engine/engine_config.h"

namespace colosseum {

struct CLIConfig {
public:
    std::vector<EngineConfig> engine_configs;
};

} // namspace colosseum