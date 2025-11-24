#ifndef APPLICATION_H
#define APPLICATION_H

#include <QCoreApplication>

namespace colosseum
{

class Application : public QCoreApplication
{
    public:

        Application(int& argc, char* argv[]);

    private:


};

} // namspace colosseum

#endif /* APPLICATION_H */