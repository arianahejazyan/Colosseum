#pragma once

#include <vector>
#include <string>

namespace colosseum::cli {

class Command {
public:
    virtual ~Command() = default;
    virtual int run(const std::vector<std::string>& args) = 0;
};

} // namspace colosseum::cli