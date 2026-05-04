#pragma once

#include "../../cli_config.h"
#include "cli_option.h"

namespace colosseum {

// Boolean CLI Option 
class CLIOptionBool : public CLIOptionBase {
protected:
    virtual void parse(CLIConfig& config) const = 0;

public:
    void parse_parameters(const std::vector<std::string>& args, CLIConfig& config) const override {
        if (!args.empty()) {
            throw colosseum_exception("Option + name + accepts a single  arguemnt + T + but received: ");
        }

        parse(config);
    }
};
    
} // namspace colosseum