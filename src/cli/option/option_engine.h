#pragma once

#include "option/base/option_key_value.h"

namespace colosseum::cli {

class OptionEngine : public OptionKeyValue {
public:
    // Default constructor
    OptionEngine(const std::string& str) : OptionKeyValue(str) {}

protected:
    void parse(const std::vector<KeyValue>& key_values, cli::Config& config) const override {
        auto& engine = config.engine.emplace_back();
        parse_engine_options(key_values, engine);
    }
};

} // namspace colosseum