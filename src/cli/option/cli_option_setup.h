#pragma once

#include "base/cli_option_single.h"

namespace colosseum {

class CLIOptionSetup : public CLIOptionSingle<std::string> {
public:
    CLIOptionSetup() { name_ = "-setup"; }
   
protected:
    void parse(const std::string& arg, CLIConfig& config) const override {
        std::cout << "CLIOptionSetup parse called" << std::endl;
    }
};

} // namspace colosseum