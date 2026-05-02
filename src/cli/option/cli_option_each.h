#pragma once

#include "cli_option.h"

namespace colosseum {

class CLIOptionEach : public CLIOption {
public:
    void parse(const std::vector<std::string>& args, CLIConfig& config) override {
        std::cout << "CLIOptionEach parse called" << std::endl;
    }
};

} // namspace colosseum