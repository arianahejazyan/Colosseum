#pragma once

#include <iostream>
#include "tournament/config/config.h"

namespace colosseum
{

class Tournament {
public:
    virtual ~Tournament() = default;
    virtual void start(const tournament::Config& config) = 0;
};

} // namspace colosseum