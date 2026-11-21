// SiSDK3::SI_GUID (RTTI: SiSDK3::SiReflectionProperty<SiSDK3::SI_GUID>): 16
// bytes that name a string table. The header's name isn't in the executable.
#pragma once

#include <types.h>

namespace SiSDK3 {

struct SI_GUID {
    u8 field_0[16];
};

}  // namespace SiSDK3

// 0x71004c8f70: the id of nothing
SiSDK3::SI_GUID Unk_4c8f70();
// 0x71004c8f80: whether two ids are the same (the name it had first takes
// them as `const void*`)
bool Unk_4c8f80(const void* a, const void* b);
