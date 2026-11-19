// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_4bea70 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_4bea70, field_10, 0x10);

struct Unk_4bd8c0 {
    u8 _0[0x40];
    u32 field_40;
};
PKMN_OFFSET_ASSERT(Unk_4bd8c0, field_40, 0x40);

struct Unk_4bd8d0 {
    u8 _0[0x40];
    u32 field_40;
};
PKMN_OFFSET_ASSERT(Unk_4bd8d0, field_40, 0x40);

struct Unk_4be6c0 {
    u8 _0[0xa0];
    u64 field_a0;
};
PKMN_OFFSET_ASSERT(Unk_4be6c0, field_a0, 0xa0);

struct Unk_4be6d0 {
    u8 _0[0xa0];
    u64 field_a0;
};
PKMN_OFFSET_ASSERT(Unk_4be6d0, field_a0, 0xa0);

struct Unk_4be6e0 {
    u8 _0[0xb0];
    u64 field_b0;
};
PKMN_OFFSET_ASSERT(Unk_4be6e0, field_b0, 0xb0);

struct Unk_4be6f0 {
    u8 _0[0xb0];
    u64 field_b0;
};
PKMN_OFFSET_ASSERT(Unk_4be6f0, field_b0, 0xb0);

struct Unk_4be720 {
    u8 _0[0x68];
    u64 field_68;
};
PKMN_OFFSET_ASSERT(Unk_4be720, field_68, 0x68);

struct Unk_4be790 {
    u8 _0[0xb8];
    u64 field_b8;
};
PKMN_OFFSET_ASSERT(Unk_4be790, field_b8, 0xb8);

namespace SiSDK3 {
class SiFixedHeapAllocator2 {
public:
    u32 vf4();
    u32 vf5(u32 value);
    u32 vf6();
    void vf12(u64 value);
    u64 vf13();
    void vf14(u64 value);
    u64 vf15();
    u64 vf17();
    u64 vf20();
};
}  // namespace SiSDK3

// 0x71004bd8c0
u32 SiSDK3::SiFixedHeapAllocator2::vf5(u32 value) {
    Unk_4bd8c0* self = reinterpret_cast<Unk_4bd8c0*>(this);
    self->field_40 = value;
    return 1;
}

// 0x71004bd8d0
u32 SiSDK3::SiFixedHeapAllocator2::vf6() {
    const Unk_4bd8d0* self = reinterpret_cast<const Unk_4bd8d0*>(this);
    return self->field_40;
}

// 0x71004be6c0
void SiSDK3::SiFixedHeapAllocator2::vf12(u64 value) {
    Unk_4be6c0* self = reinterpret_cast<Unk_4be6c0*>(this);
    self->field_a0 = value;
}

// 0x71004be6d0
u64 SiSDK3::SiFixedHeapAllocator2::vf13() {
    const Unk_4be6d0* self = reinterpret_cast<const Unk_4be6d0*>(this);
    return self->field_a0;
}

// 0x71004be6e0
void SiSDK3::SiFixedHeapAllocator2::vf14(u64 value) {
    Unk_4be6e0* self = reinterpret_cast<Unk_4be6e0*>(this);
    self->field_b0 = value;
}

// 0x71004be6f0
u64 SiSDK3::SiFixedHeapAllocator2::vf15() {
    const Unk_4be6f0* self = reinterpret_cast<const Unk_4be6f0*>(this);
    return self->field_b0;
}

// 0x71004be720
u64 SiSDK3::SiFixedHeapAllocator2::vf17() {
    const Unk_4be720* self = reinterpret_cast<const Unk_4be720*>(this);
    return self->field_68;
}

// 0x71004be790
u64 SiSDK3::SiFixedHeapAllocator2::vf20() {
    const Unk_4be790* self = reinterpret_cast<const Unk_4be790*>(this);
    return self->field_b8;
}

// 0x71004bea70
u32 SiSDK3::SiFixedHeapAllocator2::vf4() {
    const Unk_4bea70* self = reinterpret_cast<const Unk_4bea70*>(this);
    return self->field_10;
}
