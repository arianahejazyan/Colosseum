#pragma once

#include <string>

namespace colosseum {

template<typename T>
std::string get_type_name() {
    if constexpr (std::is_same_v<T, int>        ) return "integer"; else 
    if constexpr (std::is_same_v<T, float>      ) return "float"  ; else 
    if constexpr (std::is_same_v<T, double>     ) return "double" ; else 
    if constexpr (std::is_same_v<T, std::string>) return "text"   ; else 
    return "unknown";
}

// Check if string follows "key=value" format
bool is_key_value_format(const std::string& str) noexcept;

} // namspace colosseum