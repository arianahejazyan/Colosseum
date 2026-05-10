#pragma once

#include "option.h"
#include "exception.h"
#include "utility.h"

namespace colosseum::cli {

class OptionKeyValue : public OptionBase {
protected:
    using KeyValue = std::pair<std::string, std::string>;

    // Derived classes implement this
    virtual void parse(const std::vector<KeyValue>& key_values, cli::Config& config) const = 0;

    void parse_engine_options(const std::vector<KeyValue>& key_values, engine::Config& engine) const {
        for (const auto& [key, value]: key_values) {
    
            if (key.starts_with("option.")) {
                engine.uci_options.emplace_back(key.substr(7), value);
            }
    
            else if (key == "name") { engine.name = value; }
            else if (key == "cmd" ) { engine.cmd  = value; }
            else if (key == "dir" ) { engine.dir  = value; }
            else if (key == "args") { engine.args = value; }
    
            else throw colosseum_exception("Unknown engine option key: " + key);
        }
    }

public:
    // Default constructor
    OptionKeyValue(const std::string& str) : OptionBase(str) {}

    // Parses multiple "key=value" arguments, then forwards to parse()
    void parse_arguments(const std::vector<std::string>& args, cli::Config& config) const override {
        if (args.empty()) {
            throw colosseum_exception(
                "Option '" + this->name() + "' expects at least one 'key=value' argument, but received none"
            );
        }

        std::vector<KeyValue> key_values;
        key_values.reserve(args.size());
        
        for (const auto& arg: args) {
            if (!is_key_value_format(arg)) {
                throw colosseum_exception(
                    "Option '" + this->name() + "' requires arguments in 'key=value' format, but got: '" + arg + "'"
                );
            }

            std::size_t pos   = arg.find('=');
            std::string key   = arg.substr(0, pos);
            std::string value = arg.substr(pos + 1);

            key_values.push_back(std::make_pair(key, value));
        }

        parse(key_values, config);
    }
};

} // namspace colosseum