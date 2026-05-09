#include "pipe.h"
#include "exception.h"
#include <cassert>

namespace colosseum::engine {

Pipe::Pipe() {
    if (pipe(fd_.data()) != 0) {
        throw colosseum_exception("pipe() failed");
    }
}

Pipe::~Pipe() {
    close_end(Pipe::End::READ );
    close_end(Pipe::End::WRITE);
}

int Pipe::end(End which) const {
    assert(fd_[which] != -1);
    return fd_[which];
}

void Pipe::close_end(End which) {
    if (fd_[which] == - 1) return;
    close(fd_[which]);
    fd_[which] = -1;
}

} // namspace colosseum