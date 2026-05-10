#pragma once

#include "option/base/option_single.h"

namespace colosseum::cli {

class OptionConcurrency : public OptionSingle<int> {
public:
    // Default constructor
    OptionConcurrency(const std::string& str) : OptionSingle<int>(str) {}

protected:
    void parse(const int& arg, cli::Config& config) const override {
        config.tournament.concurrency = arg;
    }
};

} // namspace colosseum