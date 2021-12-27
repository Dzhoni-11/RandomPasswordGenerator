#include "Console.h"

#include "../RandomCharGenerator/RandomPaswordDefs.h"


Console::Console()
{
    descriptions.insert(std::pair<const char*, std::string&>(HELP, HELP_NOTE));
    descriptions.insert(std::pair<const char*, std::string&>(SET_PASSWORD_LENGTH, LENGTH_NOTE));
    descriptions.insert(std::pair<const char*, std::string&>(ENABLE_SPECIAL_CHARS, SPECIA_NOTE));
    descriptions.insert(std::pair<const char*, std::string&>(ENABLE_NUMERAL_CHARS, NUMERL_NOTE));
    descriptions.insert(std::pair<const char*, std::string&>(ENABLE_ALPHABT_CHARS, ALPHAB_NOTE));
    descriptions.insert(std::pair<const char*, std::string&>(OMIT_FOLLOWING_CHARS, OMITTN_NOTE));
}

Console::~Console()
{
}

void Console::ParseArgs(int argc, char* argv[], RandCharGen::RandomPaswordStruct& st)
{
    for (int c = 1; c < argc; c++)
    {
        char* z = argv[c];

        if (SearchCommand(z, HELP))
        {
            for (const auto& d : descriptions)
            {
                std::cout << d.second;
            }
            return;
        }
        else if (SearchCommand(z, SET_PASSWORD_LENGTH))
        {
            st.passwordSize = std::stoi(argv[++c]);
        }
        else if (SearchCommand(z, ENABLE_SPECIAL_CHARS))
        {
            st.enableSpecial = std::stoi(argv[++c]);
        }
        else if (SearchCommand(z, ENABLE_NUMERAL_CHARS))
        {
            st.enableNumeral = std::stoi(argv[++c]);
        }
        else if (SearchCommand(z, ENABLE_ALPHABT_CHARS))
        {
            st.enableAlphabt = std::stoi(argv[++c]);
        }
        else if (SearchCommand(z, OMIT_FOLLOWING_CHARS))
        {
            ++c;
            while (true)
            {
                if (c == argc)
                    break;
                if (argv[c] == nullptr)
                    break;
                if (std::strncmp(argv[c], DELIMITER, 1) == 0)
                {
                    --c;
                    break;
                }
                st.omitChars.append(argv[c]);
                ++c;
            }
        }
    }
}

bool Console::SearchCommand(const char* arg, const char* cmd)
{
    if (std::strcmp(arg, cmd) == 0)
    {
        return true;
    }
    return false;
}