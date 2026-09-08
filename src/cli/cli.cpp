#include <iostream>
#include <vector>
#include <memory>
#include "cli.h"
#include "command.h"
#include "commands/compare.h"
#include "commands/connect.h"
#include "commands/match.h"
#include "commands/perft.h"
#include "commands/utils.h"

namespace colosseum::cli {

int CLI::run(int argc, char const* argv[]) {

    if (argc < 2) {
        std::cerr << "Usage: colosseum <command> [options]\n";
        return 1;
    }

    std::string name = argv[1];
    std::vector<std::string> args(argv + 2, argv + argc);

    std::unique_ptr<Command> cmd;

    if (name == "connect") {
        cmd = std::make_unique<commands::ConnectCommand>();
    } else if (name == "compare") {
        cmd = std::make_unique<commands::CompareCommand>();
    } else if (name == "match") {
        cmd = std::make_unique<commands::MatchCommand>();
    } else if (name == "perft") {
        cmd = std::make_unique<commands::PerftCommand>();
    } else if (name == "utils") {
        cmd = std::make_unique<commands::UtilsCommand>();
    } else {
        std::cerr << "Unknown command: " << name << "\n";
        return 1;
    }

    return cmd->run(args);
}

} // namspace colosseum::clicli/