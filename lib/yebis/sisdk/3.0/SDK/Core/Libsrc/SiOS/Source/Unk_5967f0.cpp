// Scope: common
// SiOS's texts for a language (placeholder file and names: a translation
// unit of its own, whose static initialiser is lib/yebis/static's
// Unk_596ca0.cpp).
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_LocaleTable.h>

// 0x71023981e8, 0x7102398228, 0x7102398268: the neutral, English and Japanese
// texts
extern Unk_LocaleTableItem Unk_23981e8[];
extern Unk_LocaleTableItem Unk_2398228[];
extern Unk_LocaleTableItem Unk_2398268[];

// NON_MATCHING: two registers in one loop (see Unk_LocaleTable.h)
// 0x71005967f0
const void* Unk_5967f0(const Unk_4ca820_arg0& language) {
    UNK_LOCALE_TABLE(language, Unk_23981e8, Unk_2398228, Unk_2398268);
}
