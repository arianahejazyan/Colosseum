#pragma once

#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include "cli_config.h"
#include "exception.h"

namespace colosseum {

// Interface class
class CLIOption {
public:
    virtual ~CLIOption() = default;
    virtual void parse(const std::vector<std::string>& args, CLIConfig& config) = 0;
};

// Base class for CLI options that parse key-value pairs (e.g., -engine cmd=COMMAND dir=DIRECTORY)
class CLIOptionPair : public CLIOption {
protected:
    using Pair = std::pair<std::string, std::string>; 
    virtual void parse_pairs(const std::vector<Pair>& pairs, CLIConfig& config) = 0;

public:
    void parse(const std::vector<std::string>& args, CLIConfig& config) override {
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

        parse_pairs(pairs, config);
    }
};
    
} // namspace colosseum