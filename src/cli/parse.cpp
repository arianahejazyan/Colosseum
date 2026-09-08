#include <stdexcept>
#include "parse.h"

namespace colosseum::cli {

lib::engine::Config parse_engine(const std::vector<std::string>& args) {

    if (args.empty())
        throw std::runtime_error("Expected engine arguments");

    lib::engine::Config engine;

    for (const auto& arg : args) {
        const auto pos = arg.find('=');

        if (pos == std::string::npos)
            throw std::runtime_error("Invalid engine argument: " + arg);

        const std::string key = arg.substr(0, pos);
        const std::string value = arg.substr(pos + 1);

        if (key.empty() || value.empty())
            throw std::runtime_error("Invalid engine argument: " + arg);

        if (key == "name") {
            engine.name = value;
        }
        else if (key == "cmd") {
            engine.cmd = value;
        }
        else if (key == "dir") {
            engine.dir = value;
        }
        else if (key == "args") {
            engine.args = value;
        }
        else if (key.starts_with("option.")) {
            const std::string option_name = key.substr(7);

            if (option_name.empty())
                throw std::runtime_error("Empty engine option");

            engine.uci_options.emplace_back(option_name, value);
        }
        else {
            throw std::runtime_error("Unknown engine argument: " + key);
        }
    }

    return engine;
}

std::string parse_string(const std::vector<std::string>& args) {

    if (args.size() != 1)
        throw std::runtime_error("Expected one string argument");

    return args[0];
}

bool parse_flag(const std::vector<std::string>& args) {

    if (!args.empty())
        throw std::runtime_error("Expected no argument for flags");

    return true;
}

int parse_int(const std::vector<std::string>& args) {

    if (args.size() != 1)
        throw std::runtime_error("Expected one integer argument");

    return std::stoi(args[0]);
}

} // namspace colosseum::cli