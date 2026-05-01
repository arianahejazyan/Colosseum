#pragma once

#include "cli_config.h"
#include "cli_parser.h"

namespace colosseum {

class CLI {
public:
    // Default constructor
    CLI() = default;

    // Main entry point
    int run(int argc, char const* argv[]);

private:
    CLIConfig config_;
    CLIParser parser_;
};

} // namspace colosseum