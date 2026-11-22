// Scope: common
// SiCore's texts for a language (placeholder file and names: a translation
// unit of its own, whose static initialiser is lib/yebis/static's
// Unk_4cacd0.cpp).
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_LocaleTable.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiCore/Source/SiCore_StringTable_Impl.h>

// 0x710238e248, 0x710238e2e8, 0x710238e388: the neutral, English and Japanese
// texts
extern SiSDK3::ISiStringTable::Unk_Item Unk_238e248[];
extern SiSDK3::ISiStringTable::Unk_Item Unk_238e2e8[];
extern SiSDK3::ISiStringTable::Unk_Item Unk_238e388[];

// NON_MATCHING: two registers in one loop (see Unk_LocaleTable.h)
// 0x71004ca820
const SiSDK3::ISiStringTable::Unk_Item* Unk_4ca820(const Unk_4ca820_arg0& language) {
    UNK_LOCALE_TABLE(language, Unk_238e248, Unk_238e2e8, Unk_238e388);
}
