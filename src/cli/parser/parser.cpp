#include "parser.h"
#include "option/base/option.h"
#include "option/option_concurrency.h"
#include "option/option_each.h"
#include "option/option_engine.h"
#include "option/option_force_concurrency.h"
#include "option/option_mode.h"
#include "option/option_rounds.h"
#include "option/option_setup.h"
#include "option/option_wait.h"
#include "exception.h"

namespace colosseum::cli {

Parser::Parser() {
    // Register options
    options_["-concurrency"]       = std::make_unique<cli::OptionConcurrency>("-concurrency");
    options_["-each"]              = std::make_unique<cli::OptionEach>("-each");
    options_["-engine"]            = std::make_unique<cli::OptionEngine>("-engine");
    options_["-force-concurrency"] = std::make_unique<cli::OptionForceConcurrency>("-force-concurrency");;
    options_["-mode"]              = std::make_unique<cli::OptionMode>("-mode");
    options_["-rounds"]            = std::make_unique<cli::OptionRounds>("-rounds");
    options_["-setup"]             = std::make_unique<cli::OptionSetup>("-setup");
    options_["-wait"]              = std::make_unique<cli::OptionWait>("-wait");
}

void Parser::parse(const std::vector<std::string>& args, cli::Config& config) {

    for (int i = 0; i < args.size(); i++) {
        const auto& arg = args[i];

        if (!options_.contains(arg)) {
            throw colosseum_exception("Unkown option: " + arg);
        }

        std::vector<std::string> option_arguments;
        
        while (i + 1 < args.size()) {
            const auto& token = args[i + 1];

            // Allow negative numbers
            if (token.starts_with('-')) {
                if (is_number(token)) {
                    // It's a negative number, treat as parameter
                    option_arguments.push_back(token);
                    ++i;
                } else {
                    // It's a new option flag, stop collecting
                    break;
                }
            } else {
                // Regular parameter
                option_arguments.push_back(token);
                ++i;
            }
        }

        options_.at(arg)->parse_arguments(option_arguments, config);
    }
}

} // namspace colosseum