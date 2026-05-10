#pragma once

#include "option/base/option_key_value.h"

namespace colosseum::cli {

class OptionEach : public OptionKeyValue {
public:
    // Default constructor
    OptionEach(const std::string& str) : OptionKeyValue(str) {}

protected:
    void parse(const std::vector<KeyValue>& key_values, cli::Config& config) const override {
        for (auto& engine: config.engine) {
            parse_engine_options(key_values, engine);
        }
    }
};

} // namspace colosseum