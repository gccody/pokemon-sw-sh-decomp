// What each SiSDK3 library's function that gives its texts for a language
// does (0x71004ca820, 0x7100579c60, 0x7100587be0, 0x71005952e0,
// 0x71005967f0: the same code five times, each in a translation unit of its
// own). Placeholder names; the header's name isn't in the executable.
#pragma once

#include "Unk_4ca820_arg0.h"
#include "Unk_StringCompare.h"
#include "Unk_StringFuncs.h"

// An entry of such a table: an id and its text, up to an id of 0 (the layout
// of ISiStringTable::Unk_Item, which SiCore's own table is declared with).
struct Unk_LocaleTableItem {
    int field_0;
    const char* field_8;
};

// 0x71004c9390: a language's name and its country's
void Unk_4c9390(const Unk_4ca820_arg0& language, SiSDK3::SiString<char>* languageName,
                SiSDK3::SiString<char>* countryName);

// NON_MATCHING (all five functions, by the same eight instructions): the
// code is the original's but for two registers in the loop that compares the
// language with "en". The original has the string's address in x26 and the
// index in x25, this the other way round. Their live ranges are within half
// an instruction of each other when registers are assigned, and the longer
// one gets the lower register; here the address's is the longer one.
// The body of such a function: returns the table for a language, the neutral
// one, the English one or the Japanese one, or none. (A macro: the code is in
// each of the five functions, and it is too large for an inline function to
// have been inlined.)
#define UNK_LOCALE_TABLE(language, neutral, english, japanese)                                           \
    SiSDK3::ISiAllocator* pAllocator = SiSDK3::Unk_GetKernel()->vf12();                                  \
    char languageBuffer[0x40];                                                                           \
    char countryBuffer[0x40];                                                                            \
    SiSDK3::SiString<char> languageName(pAllocator, languageBuffer, sizeof(languageBuffer));             \
    SiSDK3::SiString<char> countryName(pAllocator, countryBuffer, sizeof(countryBuffer));                \
    Unk_4c9390(language, &languageName, &countryName);                                                   \
    if (languageName.field_10 == 0) {                                                                    \
        SiSDK3::Unk_StringAssign(&languageName, "neutral");                                              \
    }                                                                                                    \
    if (countryName.field_10 == 0) {                                                                     \
        SiSDK3::Unk_StringAssign(&countryName, "neutral");                                               \
    }                                                                                                    \
    if (SiSDK3::Unk_CompareNoCase(&languageName, "neutral") == 0 &&                                      \
        SiSDK3::Unk_CompareNoCase(&countryName, "neutral") == 0) {                                       \
        return neutral;                                                                                  \
    }                                                                                                    \
    if (SiSDK3::Unk_CompareNoCase(&languageName, "en") == 0 &&                                           \
        SiSDK3::Unk_CompareNoCase(&countryName, "neutral") == 0) {                                       \
        return english;                                                                                  \
    }                                                                                                    \
    if (SiSDK3::Unk_CompareNoCase(&languageName, "ja") == 0 &&                                           \
        SiSDK3::Unk_CompareNoCase(&countryName, "neutral") == 0) {                                       \
        return japanese;                                                                                 \
    }                                                                                                    \
    return nullptr
