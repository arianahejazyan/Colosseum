#pragma once

#include "cli_option.h"
#include "exception.h"

namespace colosseum {

class CLIOptionEngine : public CLIOptionPair {
protected:
    void parse_pairs(const std::vector<Pair>& pairs, CLIConfig& config) override {

        auto& engine = config.engine_configs.emplace_back();

        for (const auto& [key, value]: pairs) {

            if (key.starts_with("option.")) {
                engine.options.emplace_back(key.substr(7), value);
            }

            else if (key == "name") { engine.name = value; }
            else if (key == "cmd" ) { engine.cmd  = value; }
            else if (key == "dir" ) { engine.dir  = value; }
            else if (key == "args") { engine.args = value; }

            else throw colosseum_exception("Unknown engine option key: " + key);
        }
    }
};

} // namspace colosseum