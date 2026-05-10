#pragma once

#include "option.h"
#include "exception.h"
#include "utility.h"

namespace colosseum::cli {

template<typename T>
class OptionSingle : public OptionBase {
protected:
    // Derived classes implement this
    virtual void parse(const T& arg, cli::Config& config) const = 0;

public:
    // Default constructor
    OptionSingle(const std::string& str) : OptionBase(str) {}

    // Validates exactly one argument of type T, then forwards to parse()
    void parse_arguments(const std::vector<std::string>& args, cli::Config& config) const override {
        if (args.size() != 1) {
            throw colosseum_exception(
                "Option '" + this->name() + "' expects exactly 1 parameter, but received " + std::to_string(args.size())
            );
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
            throw colosseum_exception(
                "Option '" + this->name() + "' requires a value of type " + get_type_name<T>() + ", but received: '" + str + "'"
            );
        }

        parse(arg, config);
    }
};

} // namspace colosseum