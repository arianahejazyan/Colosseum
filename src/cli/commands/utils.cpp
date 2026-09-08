#include "utils.h"
#include <iostream>

namespace colosseum::cli::commands {

int UtilsCommand::run(const std::vector<std::string>& args) {
    std::cout << "utils" << std::endl;
    return 0;
}

} // namspace colosseum::cli::commands