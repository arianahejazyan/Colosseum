#pragma once

#include <memory>
#include <unordered_map>
#include <string>
#include <vector>
#include "cli_config.h"
#include "option/base/cli_option.h"

namespace colosseum {

class CLIParser {
public:
    // Default constructor
    CLIParser();

    // Parse command line arguments
    void parse(const std::vector<std::string>& args, CLIConfig& config);

private:

    template<typename T>
    void register_option() {
        auto option = std::make_unique<T>();
        options_[option->name()] = std::move(option);
    }

    std::unordered_map<std::string, std::unique_ptr<CLIOption>> options_;
};

} // namspace colosseum