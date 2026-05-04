#pragma once

#include <cstdint>
#include <string>

namespace colosseum {

struct TournamentConfig {

    std::string type = "roundrobin";
    std::size_t games = 2;
    std::size_t rounds = 2;
};

} // namspace colosseum