#pragma once

#include <unordered_map>
#include <string>
#include <functional>

namespace colosseum {

class Parser {
    using Func = std::function<void()>;

public:
    Parser();

    void parse(int argc, char const* argv[]);

private:
    void add_option(std::string name, Func callback);
    void register_options();

    static void parse_engine();
    static void parse_each();

    std::vector<std::string> params_;
    std::unordered_map<std::string, Func> options_;
};

} // namspace colosseum