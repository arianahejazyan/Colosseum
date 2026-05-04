#pragma once

#include "tournament.h"

namespace colosseum
{

class TournamentRoundRobin : public Tournament {
public:
    void start(const TournamentConfig& config) override {
        std::cout << "TournamentRoundRobin started ..." << std::endl;
    }
};

} // namspace colosseum