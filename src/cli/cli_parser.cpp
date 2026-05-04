#include <exception>
#include <memory>
#include <algorithm>
#include <iostream>
#include "cli_parser.h"
#include "option/base/cli_option.h"
#include "option/cli_option_each.h"
#include "option/cli_option_engine.h"
#include "option/cli_option_mode.h"
#include "option/cli_option_rounds.h"
#include "option/cli_option_setup.h"
#include "option/cli_option_tournament.h"
#include "exception.h"

namespace colosseum {

CLIParser::CLIParser() {
    // Register options
    register_option<CLIOptionEach>();
    register_option<CLIOptionEngine>();
    register_option<CLIOptionMode>();
    register_option<CLIOptionRounds>();
    register_option<CLIOptionSetup>();
    register_option<CLIOptionTournament>();
}

void CLIParser::parse(const std::vector<std::string>& args, CLIConfig& config) {

    for (int i = 0; i < args.size(); i++) {
        const auto& arg = args[i];

        if (!options_.contains(arg)) {
            throw colosseum_exception("Unkown option: " + arg);
        }

        std::vector<std::string> params;
        
        while (++i < args.size()) {
            const auto& param = args[i];

            if (param.starts_with('-') && !std::all_of(param.begin() + 1, param.end(), ::isdigit)) {
                i--;
                break;
            }

            params.push_back(param);
        }

        options_.at(arg)->parse_parameters(params, config);
    }
}

} // namspace colosseum