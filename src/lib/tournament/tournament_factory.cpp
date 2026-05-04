#include <memory>
#include <unordered_map>
#include "tournament_factory.h"
#include "type/tournament_gaunlet.h"
#include "type/tournament_roundrobin.h"
#include "type/tournament.h"
#include "exception.h"

namespace colosseum {

std::unique_ptr<Tournament> TournamentFactory::create(const TournamentConfig& config) {
    auto type = config.type;

    if (type == "roundrobin") return std::make_unique<TournamentRoundRobin>();
    if (type == "gaunlet"   ) return std::make_unique<TournamentGaunlet>();

    throw colosseum_exception("Unknown tournament type: " + type);
}
  
} // namspace colosseum