#pragma once

#include "base/cli_option_pair.h"
#include "exception.h"

namespace colosseum {

class CLIOptionEngine : public CLIOptionPair {
public:
    CLIOptionEngine() { name_ = "-engine"; }

protected:
    void parse(const std::vector<Pair>& pairs, CLIConfig& config) const override {

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