#include <iostream>
#include "application.h"

using namespace colosseum;

int main(int argc, char* argv[])
{
    std::cout << "cli" << std::endl;

    Application app(argc, argv);

    return app.exec();
}