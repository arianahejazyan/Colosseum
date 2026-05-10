#pragma once

#include <memory>
#include <unordered_map>
#include <string>
#include <vector>
#include "config/config.h"
#include "option/base/option.h"

namespace colosseum::cli {

class Parser {
public:
    // Default constructor
    Parser();

    // Parse command line arguments
    void parse(const std::vector<std::string>& args, cli::Config& config);

private:
    std::unordered_map<std::string, std::unique_ptr<cli::Option>> options_;
};

} // namspace colosseum