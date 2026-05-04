#pragma once

#include "base/cli_option_single.h"

namespace colosseum {

class CLIOptionMode : public CLIOptionSingle<std::string> {
public:
    CLIOptionMode() { name_ = "-mode"; }

protected:
    void parse(const std::string& arg, CLIConfig& config) const override {
        std::cout << "CLIOptionMode parse called" << std::endl;
    }
};

} // namspace colosseum