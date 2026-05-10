#pragma once

#include "option/base/option_single.h"

namespace colosseum::cli {

class OptionWait : public OptionSingle<int> {
public:
    // Default constructor
    OptionWait(const std::string& str) : OptionSingle<int>(str) {}
   
protected:
    void parse(const int& arg, cli::Config& config) const override {
        config.tournament.wait = arg;
    }
};

} // namspace colosseum