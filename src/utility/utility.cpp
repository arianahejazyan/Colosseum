#include "utility.h"

namespace colosseum {

bool is_key_value_format(const std::string& str) noexcept {
    auto pos = str.find('=');
    return pos != std::string::npos && 
           pos != 0 && 
           pos != str.length() - 1 &&
           str.find('=', pos + 1) == std::string::npos;
}

} // namspace colosseum