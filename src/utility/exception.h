#pragma once

#include <exception>
#include <string>

namespace colosseum {

class colosseum_exception : public std::exception {
public:
    explicit colosseum_exception(const std::string& message) : message_(message) {}
    const char* what() const noexcept override { return message_.c_str(); }

private:
    std::string message_;
};

} // namspace colosseum