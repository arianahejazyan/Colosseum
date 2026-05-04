#pragma once

#include "base/cli_option_pair.h"

namespace colosseum {

class CLIOptionEach : public CLIOptionPair {
public:
    CLIOptionEach() { name_ = "-each"; }

protected:

    void parse(const std::vector<Pair>& pairs, CLIConfig& config) const override {
        std::cout << "CLIOptionEach parse called" << std::endl;
    }
};

} // namspace colosseum