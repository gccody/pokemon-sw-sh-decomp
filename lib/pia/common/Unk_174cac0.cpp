// Scope: common
// Unk_174c9f0::Unk_174cac0, which creates the object behind Unk_27fc2d8
// (lib/pia/common/Unk_174be20.h), in a file of its own: it calls the
// constructor (lib/pia/common/Unk_174c650.cpp), which clang would inline.
#include "pia/common/Unk_174be20.h"

namespace nn {
namespace pia {
namespace transport {

// 0x710174cac0
// NON_MATCHING: clang unrolls the loop that clears the memory into 29 stores;
// the original keeps it a loop over the byte offset (as in Unk_174bcc0). The
// rest is the same.
Unk_165e060 Unk_174c9f0::Unk_174cac0(const Unk_174cac0_arg0& setting) {
    if (!Unk_17363e0_get()) {
        return Unk_165e060Value<0x10c0c>();
    }
    if (!Unk_17363f0_get()) {
        return Unk_165e060Value<0x10c08>();
    }
    if (Unk_27fc2d8 != nullptr) {
        return Unk_165e060Value<0x10c0f>();
    }
    if (setting.field_14 < 0) {
        return Unk_165e060Value<0x10c07>();
    }
    u32* buffer = static_cast<u32*>(operator new(sizeof(Unk_174c9f0), Unk_1652bd0(), 8));
    if (buffer != nullptr) {
        for (u32 i = 0; i < sizeof(Unk_174c9f0) / sizeof(u32); i++) {
            buffer[i] = 0;
        }
    }
    Unk_27fc2e0 = buffer;
    if (Unk_27fc2e0 == nullptr) {
        return Unk_165e060Value<0x10c01>();
    }
    Unk_27fc2d8 = new (Unk_27fc2e0) Unk_174c9f0();
    Unk_165e060 result = Unk_27fc2d8->Unk_174cc70(setting);
    if (result.m_Value != 0) {
        Unk_27fc2d8->~Unk_174c9f0();
        u32* memory = Unk_27fc2e0;
        Unk_27fc2d8 = nullptr;
        if (memory != nullptr) {
            Unk_17163e0(memory);
            Unk_1716390(memory);
            Unk_27fc2e0 = nullptr;
        }
        return result;
    }
    return Unk_165e060Value<0>();
}

}  // namespace transport
}  // namespace pia
}  // namespace nn
