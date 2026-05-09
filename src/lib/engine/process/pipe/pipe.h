#pragma once

#include <array>
#include <unistd.h>

namespace colosseum::engine {

class Pipe {
public: 
    enum End {
        READ  = 0, 
        WRITE = 1,
    };

    // Constructor
    Pipe();

    // Deconstructor
    ~Pipe();

    // Accessing pipe ends
    int end(End which) const;

    // Closing pipe ends
    void close_end(End which);

private:
    std::array<int, 2> fd_;
};

} // namspace colosseum