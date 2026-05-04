#pragma once

#include <exception>
#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include "cli_config.h"
#include "exception.h"
#include "cli_option.h"

namespace colosseum {

template<typename T>
class CLIOptionSingle : public CLIOptionBase {
protected:
    virtual void parse(const T& arg, CLIConfig& config) const = 0;

public:
    void parse_parameters(const std::vector<std::string>& args, CLIConfig& config) const override {
        if (args.size() != 1) {
            throw colosseum_exception("Option " + this->name() + " accepts a single parameter but received " + std::to_string(args.size()));
        }

        const std::string& str = args[0];
        T arg;

        try {

            if constexpr (std::is_same_v<T, int>) {
                arg = std::stoi(str);
            } else if constexpr (std::is_same_v<T, float>) {
                arg = std::stof(str);
            } else if constexpr (std::is_same_v<T, double>) {
                arg = std::stod(str);
            } else {
                arg = str;
            } 

        } catch (const std::exception& e) {
            throw colosseum_exception("Option " + this->name() + " expects argument of type " + typeid(T).name() + " but received argument: " + str);
        }

        parse(arg, config);
    }
};

} // namspace colosseum