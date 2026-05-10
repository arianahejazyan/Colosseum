#pragma once

#include <string>
#include "option/base/option_single.h"

namespace colosseum::cli {

class OptionSetup : public OptionSingle<std::string> {
public:
    // Default constructor
    OptionSetup(const std::string& str) : OptionSingle<std::string>(str) {}
   
protected:
    void parse(const std::string& arg, cli::Config& config) const override {
        if (arg == "modern" || arg == "classic") {
            config.tournament.setup = arg;
            return;
        } else {             
            throw colosseum_exception(
                "Unsupported setup: '" + arg + "'. Choose 'modern' or 'classic'."
            );
        }
    }
};

} // namspace colosseum