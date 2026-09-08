#include "compare.h"
#include <iostream>

namespace colosseum::cli::commands {

int CompareCommand::run(const std::vector<std::string>& args) {
    std::cout << "compare" << std::endl;
    return 0;
}
    
} // namspace colosseum::cli::commands