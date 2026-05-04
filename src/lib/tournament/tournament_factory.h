#pragma once

#include <memory>
#include "tournament_config.h"
#include "type/tournament.h"

namespace colosseum {

class TournamentFactory {
public:
    std::unique_ptr<Tournament> create(const TournamentConfig& config);
};

} // namspace colosseum