#pragma once

#include "base/cli_option_single.h"

namespace colosseum {

class CLIOptionRounds : public CLIOptionSingle<int> {
public:
    CLIOptionRounds() { name_ = "-rounds"; }

protected:
    void parse(const int& arg, CLIConfig& config) const override {
        std::cout << "CLIOptionRounds parse called" << std::endl;
    }
};

} // namspace colosseum