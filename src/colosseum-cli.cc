#include "cli.h"

int main(int argc, char const* argv[])
{
    colosseum::CLI cli;
    return cli.run(argc, argv);
}