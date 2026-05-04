#pragma once

#include <iostream>
#include "../tournament_config.h"

namespace colosseum
{

class Tournament {
public:
    virtual ~Tournament() = default;
    virtual void start(const TournamentConfig& config) = 0;
};

} // namspace colosseum