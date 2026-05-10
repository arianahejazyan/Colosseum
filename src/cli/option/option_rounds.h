#pragma once

#include "option/base/option_single.h"

namespace colosseum::cli {

class OptionRounds : public OptionSingle<int> {
public:
    // Default constructor
    OptionRounds(const std::string& str) : OptionSingle<int>(str) {}

protected:
    void parse(const int& arg, cli::Config& config) const override {
        config.tournament.rounds = arg;
    }
};

} // namspace colosseum