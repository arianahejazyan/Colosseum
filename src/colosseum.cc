#include "cli/cli.h"

int main(int argc, char const* argv[]) {
    colosseum::cli::CLI cli;
    return cli.run(argc, argv);
}