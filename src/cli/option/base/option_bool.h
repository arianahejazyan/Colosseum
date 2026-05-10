#pragma once

#include "option.h"
#include "exception.h"
#include <string>

namespace colosseum::cli {

class OptionBool : public OptionBase {
protected:
    // Derived classes implement this
    virtual void parse(cli::Config& config) const = 0;

public:
    // Default constructor
    OptionBool(const std::string& str) : OptionBase(str) {}

    // Validates that no arguments are provided (zero-argument option), then forwards to parse()
    void parse_arguments(const std::vector<std::string>& args, cli::Config& config) const override {
        if (!args.empty()) {
            throw colosseum_exception(
                "Option '" + this->name() + "' does not accept any arguments, but received " + std::to_string(args.size()) + " argument(s)"
            );
        }

        parse(config);
    }
};
    
} // namspace colosseum