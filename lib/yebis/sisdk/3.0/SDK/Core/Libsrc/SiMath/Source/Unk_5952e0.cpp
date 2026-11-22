// Scope: common
// SiMath's texts for a language (placeholder file and names: a translation
// unit of its own, whose static initialiser is lib/yebis/static's
// Unk_595790.cpp).
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_LocaleTable.h>

// 0x7102397ed8, 0x7102397f18, 0x7102397f58: the neutral, English and Japanese
// texts
extern Unk_LocaleTableItem Unk_2397ed8[];
extern Unk_LocaleTableItem Unk_2397f18[];
extern Unk_LocaleTableItem Unk_2397f58[];

// NON_MATCHING: two registers in one loop (see Unk_LocaleTable.h)
// 0x71005952e0
const void* Unk_5952e0(const Unk_4ca820_arg0& language) {
    UNK_LOCALE_TABLE(language, Unk_2397ed8, Unk_2397f18, Unk_2397f58);
}
