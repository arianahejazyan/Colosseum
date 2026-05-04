#pragma once

#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include "../../cli_config.h"
#include "cli_option.h"
#include "exception.h"

namespace colosseum {

// Base class for CLI options that parse key-value pairs (e.g., -engine cmd=COMMAND dir=DIRECTORY)
class CLIOptionPair : public CLIOptionBase {
protected:
    using Pair = std::pair<std::string, std::string>; 
    virtual void parse(const std::vector<Pair>& pairs, CLIConfig& config) const = 0;

public:
    void parse_parameters(const std::vector<std::string>& args, CLIConfig& config) const override {
        std::vector<Pair> pairs;
        
        for (const auto& pair: args) {
            std::size_t pos = pair.find('=');

            if (pos == std::string::npos) {
                throw colosseum_exception("Argument format must be key=value format: " + pair);
            }

            std::string key   = pair.substr(0, pos);
            std::string value = pair.substr(pos + 1);

            if (key.empty()) {
                throw colosseum_exception("Argument key cannot be empty in: " + pair);
            }

            if (value.empty()) {
                throw colosseum_exception("Argument value cannot be empty in: " + pair);
            }

            pairs.push_back(std::make_pair(key, value));
        }

        parse(pairs, config);
    }
};

} // namspace colosseum