#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <cstring>

#include "../RandomCharGenerator/RandCharGen.h"

class Console
{
public:
    Console();

    ~Console();

    void ParseArgs(int argc, char* argv[], RandCharGen::RandomPaswordStruct& st);

private:
    std::map<const char*, std::string&> descriptions;

    bool SearchCommand(const char* arg, const char* cmd);

};

#endif

