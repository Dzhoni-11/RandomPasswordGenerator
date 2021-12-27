#include <iostream>

#include "Console/Console.h"
#include "RandomCharGenerator/RandCharGen.h"


int main(int argc, char* argv[])
{
    auto st = RandCharGen::RandomPaswordStruct();
    auto console = Console();
    console.ParseArgs(argc, argv, st);

    RandCharGen gen;

    gen.Init(st.passwordSize,
             st.enableSpecial,
             st.enableNumeral,
             st.enableAlphabt,
             st.omitChars);

    std::vector<uint8_t> password =  gen.GenerateChar();

    for (const auto& x : password)
    {
        std::cout << x;
    }

    return 0;
}

