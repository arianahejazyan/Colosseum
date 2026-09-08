#include "perft.h"
#include "cli/parse.h"
#include "lib/engine/config.h"
#include <stdexcept>
#include <vector>

namespace colosseum::cli::commands {

int PerftCommand::run(const std::vector<std::string>& args) {

    std::vector<lib::engine::Config> engines;
    int concurrency = -1;

    for (size_t i = 0; i < args.size();) {

        size_t count = 0;
        auto option_args = consume(args, i, count);

        if (args[i] == "-engine") {
            auto engine = parse_engine(option_args);
            engines.push_back(engine);
        }
        else if (args[i] == "-concurrency") {
            concurrency = parse_int(option_args);
        }
        else {
            throw std::runtime_error("Unknown option: " + args[i] + '\n');
        }

        i += count;
    }

    if (engines.size() != 1) {
        throw std::runtime_error("Exactly one engine is required");
    }

    return 0;
}

} // namspace colosseum::cli::commands