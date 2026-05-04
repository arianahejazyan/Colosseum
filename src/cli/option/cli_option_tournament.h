#pragma once

#include "base/cli_option_single.h"

namespace colosseum {

class CLIOptionTournament : public CLIOptionSingle<std::string> {
public:
    CLIOptionTournament() { name_ = "-tournament"; }

protected:
    void parse(const std::string& arg, CLIConfig& config) const override {
        std::cout << "CLIOptionTournament parse called" << std::endl;
    }
};

} // namspace colosseum