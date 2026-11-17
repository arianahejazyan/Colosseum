#pragma once

#include "config/config.h"
#include "parser/parser.h"

namespace colosseum {

class CLI {
public:
    // Default constructor
    CLI() = default;

    // Main entry point
    int run(int argc, char const* argv[]);

private:
    cli::Config config_;
    cli::Parser parser_;
};

} // namspace colosseum
