#pragma once

#include <vector>
#include <string>
#include "lib/engine/config.h"

namespace colosseum::cli {

lib::engine::Config parse_engine(const std::vector<std::string>& args);
std::string         parse_string(const std::vector<std::string>& args);
bool                parse_flag  (const std::vector<std::string>& args);
int                 parse_int   (const std::vector<std::string>& args);

inline std::vector<std::string> consume(const std::vector<std::string>& args, size_t start, size_t& index) {
    std::vector<std::string> result;

    while ((++index + start) < args.size() && args[start + index][0] != '-') {
        result.push_back(args[start + index]);
    }

    return result;
}

} // namspace colosseum::cli