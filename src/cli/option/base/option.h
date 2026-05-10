#pragma once

#include <string>
#include <vector>
#include "config/config.h"

namespace colosseum::cli {

// Interface class
class Option {
public:
    virtual ~Option() = default;
    virtual void parse_arguments(const std::vector<std::string>& args, cli::Config& config) const = 0;
    virtual std::string name() const = 0;
};

// Base Class
class OptionBase : public Option {
protected:
    std::string name_;

public:
    // Default constructor
    OptionBase(const std::string& str) : name_(str) {}

    // Access name of the option
    std::string name() const override { return name_; }
};
    
} // namspace colosseum