#include "match.h"
#include <iostream>

namespace colosseum::cli::commands {

int MatchCommand::run(const std::vector<std::string>& args) {
    std::cout << "match" << std::endl;
    return 0;
}

} // namspace colosseum::cli::commands