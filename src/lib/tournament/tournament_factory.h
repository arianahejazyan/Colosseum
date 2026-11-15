#pragma once

#include <memory>
#include "tournament/config/config.h"
#include "type/tournament.h"

namespace colosseum {

class TournamentFactory {
public:
    std::unique_ptr<Tournament> create(const tournament::Config& config);
};

} // namspace colosseum