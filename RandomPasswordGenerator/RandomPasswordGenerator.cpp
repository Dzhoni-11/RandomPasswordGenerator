#include <iostream>

#include "RandCharGen.h"

int main()
{
    RandCharGen gen;

    gen.Init(16, false);
    std::vector<uint8_t> xxx =  gen.GenerateChar();

    for (const auto& x : xxx)
    {
        std::cout << x;
    }
}

