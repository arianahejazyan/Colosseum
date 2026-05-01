#pragma once

#include <string>
#include <vector>
#include <iostream>

namespace colosseum {

class CLIOption {
public:
    virtual ~CLIOption() = default;
    virtual void parse(const std::vector<std::string>& args) = 0;
};

} // namspace colosseum