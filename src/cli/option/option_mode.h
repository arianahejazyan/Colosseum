#pragma once

#include "option/base/option_single.h"

namespace colosseum::cli {

class OptionMode : public OptionSingle<std::string> {
public:
    // Default constructor
    OptionMode(const std::string& str) : OptionSingle<std::string>(str) {}

protected:
    void parse(const std::string& arg, cli::Config& config) const override {
        if (arg == "team") {
            // Team mode is the default implementation, nothing to configure
            return;
        } else if (arg == "ffa") {
            throw colosseum_exception(
                "FFA (Free-For-All) mode is not yet implemented. Only 'team' mode is available."
            );
        } else {
            throw colosseum_exception(
                "Unsupported mode: '" + arg + "'. Only 'team' mode is available."
            );
        }
    }
};

} // namspace colosseum