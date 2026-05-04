#pragma once

#include "tournament.h"

namespace colosseum
{

class TournamentGaunlet : public Tournament {
public:
    void start(const TournamentConfig& config) override {
        std::cout << "TournamentGaunlet started ..." << std::endl;
    }
};

} // namspace colosseum