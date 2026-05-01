#pragma once

#include "cli_option.h"

namespace colosseum {

class CLIOptionEngine : public CLIOption {
public:
    void parse(const std::vector<std::string>& args) override {
        std::cout << "CLIOptionEngine parse called" << std::endl;
    }
};

} // namspace colosseum