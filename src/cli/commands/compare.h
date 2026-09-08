#pragma once

#include "cli/command.h"

namespace colosseum::cli::commands {

class CompareCommand : public Command {
public:
    int run(const std::vector<std::string>& args) override;
};

} // namspace colosseum::cli::commands