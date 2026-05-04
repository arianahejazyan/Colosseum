#pragma once

#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include "cli_config.h"
#include "exception.h"

namespace colosseum {

// Interface class
class CLIOption {
public:
    virtual ~CLIOption() = default;
    virtual void parse_parameters(const std::vector<std::string>& args, CLIConfig& config) const = 0;
    virtual std::string name() const = 0;
    // virtual void set_name(std::string& str) = 0;
};

// Base Class
class CLIOptionBase : public CLIOption {
protected:
    std::string name_;

public:
    std::string name() const override { return name_; }
    // void set_name(std::string& str) override { name_ = str; }
};
    
} // namspace colosseum