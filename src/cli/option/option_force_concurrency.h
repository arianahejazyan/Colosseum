#pragma once

#include "option/base/option_bool.h"

namespace colosseum::cli {

class OptionForceConcurrency : public OptionBool {
public:
    // Default constructor
    OptionForceConcurrency(const std::string& str) : OptionBool(str) {}

protected:
    void parse(cli::Config& config) const override {
        config.tournament.force_concurrency = true;
    }
};

} // namspace colosseum