#include "cli.h"
#include "cli_parser.h"
#include "cli_config.h"
#include <exception>
#include <iostream>
#include <memory>
#include "exception.h"
#include "tournament/tournament_config.h"
#include "tournament/tournament_factory.h"

namespace colosseum {

int CLI::run(int argc, char const* argv[]) {
    std::vector<std::string> args(argv + 1, argv + argc);

    for (auto arg: args)
    {
        if (arg == "--version") {
            std::cout << "--version has been called" << std::endl;
            return 0;
        }

        if (arg == "--help") {
            std::cout << "--help has been called" << std::endl;
            return 0;
        }
    }

    try {
        // Parse arguments
        parser_.parse(args, config_);

        // Create tournament
        auto tournament_factory = TournamentFactory();
        auto tournament = tournament_factory.create(config_.tournament);

        // Start tournament
        tournament->start(config_.tournament);

    } catch (const colosseum_exception& e) {

        std::cerr << e.what() << std::endl;
        std::cout << "Use --help to see all available options." << std::endl;
        return EXIT_FAILURE;

    } catch (const std::exception& e) {
        
        std::cerr << e.what() << std::endl;
        std::cerr << "Unexpected error occurred. Please submit the bug at https://github.com/arianahejazyan/Colosseum/issues along with your command line arguments and output logs. Thanks!" << std::endl;
        return EXIT_FAILURE;
    }

    return 0;
}

} // namspace colosseum