#pragma once

#include <string>
#include <spawn.h>

namespace colosseum::engine {

class FileActions {
public:
    // Constructor
    FileActions();

    // Deconstructor
    ~FileActions();

    // Add dup2 to file actions
    void add_dup2(int fd, int newfd);

    // Add working directory to file actions
    void add_workdir(const std::string& wd);

private:
    posix_spawn_file_actions_t file_actions_{};
};

} // namspace colosseum