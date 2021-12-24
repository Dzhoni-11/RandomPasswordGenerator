#include <ctime>
#include <cstdlib>

#include "RandCharGen.h"

namespace
{
    bool Found(std::vector<uint16_t>& vec, uint16_t compare)
    {
        bool found = false;
        for (const auto& x : vec)
        {
            found |= (x == compare);
            if (found == true) break;
        }
        return found;
    }

    uint8_t RandASCIIIndex(uint8_t maxRange)
    {
        return std::rand() % maxRange;
    }
}

RandCharGen::RandCharGen(void)
{
}

RandCharGen::~RandCharGen(void)
{
}

void RandCharGen::Init(uint8_t numOfChars,
                       bool enableSpecChars,
                       bool enableNumChars,
                       bool enableAlphaChars,
                       std::string omitTheseChars)
{
    if (numOfChars > MIN_PASSWORD_LENGTH && numOfChars < MAXX_PASSWORD_LENGTH)
        m_SizeOfPassword = numOfChars;

    std::vector<uint16_t> omit(omitTheseChars.begin(), omitTheseChars.end());

    if (enableSpecChars)
    {
        LoadSpecialRanges(omit);
    }
    if (enableNumChars)
    {
        LoadNumberRanges(omit);
    }
    if (enableAlphaChars)
    {
        LoadLetterRanges(omit);
    }

    m_Initialized = true;
}

std::vector<uint8_t> RandCharGen::GenerateChar(void)
{
    std::srand(std::time(NULL));

    std::vector<uint8_t> passwordSequence = {};

    if (m_Initialized)
    {
        uint8_t count(0);
        do {
            passwordSequence.push_back(m_AsciiList.at(RandASCIIIndex(m_AsciiList.size())));
        } while (++count != m_SizeOfPassword);
    }

    return passwordSequence;
}

void RandCharGen::LoadNumberRanges(std::vector<uint16_t> omit)
{
    uint8_t MAX_RANGE = 10;
    uint8_t START_INDEX = 48;

    for (size_t n = 0; n < MAX_RANGE; n++)
    {
        if (!Found(omit, START_INDEX))
        {
            m_AsciiList.push_back(START_INDEX);
        }
        ++START_INDEX;
    }
}

void RandCharGen::LoadSpecialRanges(std::vector<uint16_t> omit )
{
    uint8_t MAX_RANGE = 32;
    uint8_t START_INDEX = 33;


    for (size_t n = 0; n < MAX_RANGE; n++)
    {
        if (!Found(omit, START_INDEX))
        {
            m_AsciiList.push_back(START_INDEX);
        }
        ++START_INDEX;
        if (START_INDEX == 48) START_INDEX = 58;
        if (START_INDEX == 65) START_INDEX = 91;
        if (START_INDEX == 97) START_INDEX = 123;
    }
}

void RandCharGen::LoadLetterRanges(std::vector<uint16_t> omit)
{
    uint8_t MAX_RANGE = 52;
    uint8_t START_INDEX = 65;

    for (size_t n = 0; n < MAX_RANGE; n++)
    {
        if (!Found(omit, START_INDEX))
        {
            m_AsciiList.push_back(START_INDEX);
        }
        ++START_INDEX;
        if (START_INDEX == 91) START_INDEX = 97;
    }
}

