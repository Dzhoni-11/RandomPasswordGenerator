#ifndef RANDOM_PASSWORD_DEFS_H
#define RANDOM_PASSWORD_DEFS_H

#include <cstdint>
#include <string>

constexpr char DELIMITER[] = "\\";

constexpr char HELP[] = "\\h";

constexpr char SET_PASSWORD_LENGTH[]  = "\\l";
constexpr char ENABLE_SPECIAL_CHARS[] = "\\s";
constexpr char ENABLE_NUMERAL_CHARS[] = "\\n";
constexpr char ENABLE_ALPHABT_CHARS[] = "\\a";
constexpr char OMIT_FOLLOWING_CHARS[] = "\\o";

std::string HELP_NOTE = "Random Password Generator Help Screen\n";


std::string LENGTH_NOTE = "Set_Password_Length \\l\n\
                           Sets the Password Length to Integer Succeeding Command.\n\
                           Minimum: 8\n\
                           Maximum: 16\n\n";


std::string SPECIA_NOTE = "Enable_Special_Characters \\s\
                           Enable/Disable Special Characters. i.e. {~, *, ^} etc.\n\
                           Enable: 1\n\
                           Disable: 0\n\n";


std::string NUMERL_NOTE = "Enable_Numeral_Characters \\n\
                           Enable / Disable Numeral Characters.i.e. {1, 2, 3} etc.\n\
                           Enable : 1\n\
                           Disable : 0\n\n";


std::string ALPHAB_NOTE = "Enable_Alphabet_Characters \\a\
                           Enable/Disable Alphabet Characters. i.e. {a, z, G} etc.\n\
                           Enable: 1\n\
                           Disable: 0\n\n";


std::string OMITTN_NOTE = "Omit_Usr_Selected_Characters \\o\
                           Omit the Characters Succeeding the Command\n\
                           Example: _ @ 3 K ` ) ( ; , .\n\n";

#endif

