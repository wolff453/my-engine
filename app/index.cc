#include "v8.h"

#include "./src/george.hpp"

int main(int argc, char *argv[])
{
    char *filename = argv[1];
    auto *george = new George();
    std::unique_ptr<v8::Platform> platform =
        george->initializeV8(argc, argv);
    
    george->initializeVM();
    george->InitializeProgram(filename);
    george->Shutdown();

    return 0;
}