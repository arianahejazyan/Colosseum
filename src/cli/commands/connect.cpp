#include "connect.h"
#include <iostream>

namespace colosseum::cli::commands {

int ConnectCommand::run(const std::vector<std::string>& args) {
    std::cout << "connect" << std::endl;
    return 0;
}
    
} // namspace colosseum::cli::commands