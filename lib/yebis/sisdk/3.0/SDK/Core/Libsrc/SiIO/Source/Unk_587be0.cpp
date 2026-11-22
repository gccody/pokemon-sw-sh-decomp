// Scope: common
// SiIO's texts for a language (placeholder file and names: a translation
// unit of its own, whose static initialiser is lib/yebis/static's
// Unk_588090.cpp).
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_LocaleTable.h>

// 0x7102397868, 0x71023978a8, 0x71023978e8: the neutral, English and Japanese
// texts
extern Unk_LocaleTableItem Unk_2397868[];
extern Unk_LocaleTableItem Unk_23978a8[];
extern Unk_LocaleTableItem Unk_23978e8[];

// NON_MATCHING: two registers in one loop (see Unk_LocaleTable.h)
// 0x7100587be0
const void* Unk_587be0(const Unk_4ca820_arg0& language) {
    UNK_LOCALE_TABLE(language, Unk_2397868, Unk_23978a8, Unk_23978e8);
}
