#include "file_actions.h"
#include "exception.h"
#include <spawn.h>
#include <string.h>

namespace colosseum::engine {

FileActions::FileActions() {
    const int rc = posix_spawn_file_actions_init(&file_actions_);
    if (rc != 0) {
        throw colosseum_exception(std::string("posix_spawn_file_actions_init() failed: ") + strerror(rc));
    }
}

FileActions::~FileActions() { 
    posix_spawn_file_actions_destroy(&file_actions_); 
}

void FileActions::add_dup2(int fd, int newfd) {
    const int rc = posix_spawn_file_actions_adddup2(&file_actions_, fd, newfd);
    if (rc != 0) {
        throw colosseum_exception(std::string("posix_spawn_file_actions_adddup2() failed: ") + strerror(rc));
    } 
}

void FileActions::add_workdir(const std::string& wd) {
    if (wd.empty()) {
        return;
    } 

    const int rc = posix_spawn_file_actions_addchdir_np(&file_actions_, wd.c_str());
    if (rc != 0) {
        throw colosseum_exception(std::string("posix_spawn_file_actions_addchdir failed") + strerror(rc));
    }
}

} // namspace colosseum