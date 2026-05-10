#include "utility.h"

namespace colosseum {

bool is_key_value_format(const std::string& str) noexcept {
    auto pos = str.find('=');
    return pos != std::string::npos && 
           pos != 0 && 
           pos != str.length() - 1 &&
           str.find('=', pos + 1) == std::string::npos;
}

bool is_number(const std::string& str) noexcept {
    if (str.empty()) return false;
    
    size_t i = 0;
    
    // Optional leading sign
    if (
    str[i] == '-' ||
    str[i] == '+') {
        i++;
    }
    
    // At least one digit required
    if (i >= str.length() || !std::isdigit(str[i])) {
       return false; 
    } 
    // Check remaining characters (digits or single decimal point)
    bool has_decimal = false;
    for (; i < str.length(); i++) {
        if (std::isdigit(str[i])) {
            continue;
        } else if (str[i] == '.' && !has_decimal) {
            has_decimal = true;
        } else {
            return false;
        }
    }
    
    return true;
}

} // namspace colosseum