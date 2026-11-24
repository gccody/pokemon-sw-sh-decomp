// Scope: common
// SiGfx's texts for a language (placeholder file and names: a translation
// unit of its own, whose static initialiser is lib/yebis/static's
// Unk_57a110.cpp).
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_LocaleTable.h>

// 0x7102396b28, 0x7102396b68, 0x7102396ba8: the neutral, English and Japanese
// texts
extern Unk_LocaleTableItem Unk_2396b28[];
extern Unk_LocaleTableItem Unk_2396b68[];
extern Unk_LocaleTableItem Unk_2396ba8[];

// 0x7100579c60
const void* Unk_579c60(const Unk_4ca820_arg0& language) {
    UNK_LOCALE_TABLE(language, Unk_2396b28, Unk_2396b68, Unk_2396ba8);
}
