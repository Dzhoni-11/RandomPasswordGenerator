#ifndef RAND_CHAR_GEN_H
#define RAND_CHAR_GEN_H

#include <vector>
#include <cstdint>
#include <string>


class RandCharGen
{
public:

    struct RandomPaswordStruct
    {
        uint8_t passwordSize = 0;
        bool enableSpecial = true;
        bool enableNumeral = true;
        bool enableAlphabt = true;
        std::string omitChars = "";
    };

    RandCharGen(void);
    ~RandCharGen(void);

    /* uint8_t: password length,
       bool: enable special characters
       bool: enable numeral characters
       bool: enable alphabetical characters
       string: characters to omit from password
    */
    void Init(uint8_t,
              bool=true, bool=true, bool=true,
              std::string="");

    std::vector<uint8_t> GenerateChar(void);

private:
    void LoadNumberRanges(std::vector<uint16_t>);
    void LoadSpecialRanges(std::vector<uint16_t>);
    void LoadLetterRanges(std::vector<uint16_t>);

    uint8_t MIN_PASSWORD_LENGTH{ 4 };
    uint8_t MAXX_PASSWORD_LENGTH{ 16 };

    uint8_t m_SizeOfPassword{ MIN_PASSWORD_LENGTH };

    bool m_Initialized{ false };

    std::vector<uint8_t> m_AsciiList;
};

#endif

