#pragma once

#include "cli_option.h"

namespace colosseum {

class CLIOptionEngine : public CLIOptionPair {
protected:
    void parse_pairs(const std::vector<Pair>& pairs, CLIConfig& config) override {
        std::cout << "CLIOptionEngine parse_pairs called" << std::endl;
    }
};

} // namspace colosseum