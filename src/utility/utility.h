#pragma once

#include <string>

namespace colosseum {

template<typename T>
constexpr const char* get_type_name() noexcept {
    if constexpr (std::is_same_v<T, int>        ) return "integer"; else 
    if constexpr (std::is_same_v<T, float>      ) return "float"  ; else 
    if constexpr (std::is_same_v<T, double>     ) return "double" ; else 
    if constexpr (std::is_same_v<T, std::string>) return "text"   ; else 
    return "unknown";
}

// Check if string follows "key=value" format
bool is_key_value_format(const std::string& str) noexcept;

// Checks if string is a valid integer or floating point number
bool is_number(const std::string& str) noexcept;

} // namspace colosseum