#include <vector>
#include <iostream>
#include "parser.h"

namespace colosseum {

Parser::Parser() {
    register_options();
}

void Parser::parse(int argc, char const* argv[]) {
    const std::vector<std::string> args(argv + 1, argv + argc);

    for (int i = 0; i < args.size(); i++) {
        const auto& arg = args[i];

        params_.clear();
        while (i + 1 < args.size()) {
            if (args[i + 1].starts_with('-')) {
                break;
            }

            params_.push_back(args[++i]);
        }

        options_[arg]();
    }

    // std::vector<std::vector<std::string>> options;

    // for (const auto& arg: args) {
    //     if (arg[0] == '-') {
    //         options.push_back({arg});
    //     } else {
    //         options.back().push_back(arg);
    //     }
    // }

    // for (auto x: options) {
    //     std::cout << "option:";
    //     for (auto y: x) {
    //         std::cout << " " << y; 
    //     }
    //     std::cout << std::endl;
    // }

    // options_["-a"].func(params);

    // try {
    //     for (int i = 1; i < args.size(); i++) {
    //         const auto& arg = args[i];

    //         if (options_.contains(arg)) {
    //             std::vector<std::string> params;

    //             while (i + 1 < args.size()) {
    //                 const auto& param = args[i];

    //                 if (options_.contains(arg))
    //             }
    //         }

    //         else i++;
    //     }

    // } catch (const std::exception& e) {

    // }
}

void Parser::add_option(std::string name, Func callback) {
    options_.emplace(name, callback);
}

void Parser::register_options() {
    add_option("-engine", parse_engine);
    add_option("-each", parse_each);
}

void Parser::parse_engine() {
    std::cout << "parse_engine called" << std::endl;
}

void Parser::parse_each() {
    std::cout << "parse_each called" << std::endl;
}

} // namspace colosseum