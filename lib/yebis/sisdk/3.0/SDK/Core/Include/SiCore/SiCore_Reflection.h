// SiSDK3's reflection, as far as YEBIS's code shows it (placeholder members).
#pragma once

#include "SiCore_Array.h"

namespace SiSDK3 {

// 0x78 bytes: a property handle and its children (RTTI:
// SiSDK3::SiArray<SiSDK3::SiReflectionPropertyHandle, 16>, whose destructor
// destroys its elements with 0x710040f550, the destructor a static handle of
// many TUs registers with __cxa_atexit).
class SiReflectionPropertyHandle {
public:
    SiReflectionPropertyHandle()
        : field_0(nullptr), field_8(nullptr), field_10(nullptr), field_18(nullptr), field_20(-1) {}

    void* field_0;
    void* field_8;
    void* field_10;
    void* field_18;
    int field_20;
    SiArray<SiReflectionPropertyHandle, 16> field_28;
};
PKMN_SIZE_ASSERT(SiReflectionPropertyHandle, 0x78);

}  // namespace SiSDK3
