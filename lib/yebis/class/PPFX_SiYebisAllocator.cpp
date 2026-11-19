// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N4PPFX16SiYebisAllocatorE
#include <types.h>

struct Unk_43c1e0 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_43c1e0, field_10, 0x10);

struct Unk_43c1f0 {
    u8 _0[0x18];
    u32 field_18;
};
PKMN_OFFSET_ASSERT(Unk_43c1f0, field_18, 0x18);

struct Unk_43c200 {
    u8 _0[0x18];
    u32 field_18;
};
PKMN_OFFSET_ASSERT(Unk_43c200, field_18, 0x18);

namespace PPFX {
class SiYebisAllocator {
public:
    u32 vf4();
    u32 vf5(u32 value);
    u32 vf6();
    void vf11();
    void vf12();
    u64 vf13();
    void vf14();
    u64 vf15();
    u64 vf16();
    u64 vf17();
    void vf18();
    void vf19();
    u64 vf20();
};
}  // namespace PPFX

// 0x710043c1e0
u32 PPFX::SiYebisAllocator::vf4() {
    const Unk_43c1e0* self = reinterpret_cast<const Unk_43c1e0*>(this);
    return self->field_10;
}

// 0x710043c1f0
u32 PPFX::SiYebisAllocator::vf5(u32 value) {
    Unk_43c1f0* self = reinterpret_cast<Unk_43c1f0*>(this);
    self->field_18 = value;
    return 1;
}

// 0x710043c200
u32 PPFX::SiYebisAllocator::vf6() {
    const Unk_43c200* self = reinterpret_cast<const Unk_43c200*>(this);
    return self->field_18;
}

// 0x710043c300
void PPFX::SiYebisAllocator::vf11() {
}

// 0x710043c310
void PPFX::SiYebisAllocator::vf12() {
}

// 0x710043c320
u64 PPFX::SiYebisAllocator::vf13() {
    return 0;
}

// 0x710043c330
void PPFX::SiYebisAllocator::vf14() {
}

// 0x710043c340
u64 PPFX::SiYebisAllocator::vf15() {
    return 0;
}

// 0x710043c350
u64 PPFX::SiYebisAllocator::vf16() {
    return 0;
}

// 0x710043c360
u64 PPFX::SiYebisAllocator::vf17() {
    return 0;
}

// 0x710043c370
void PPFX::SiYebisAllocator::vf18() {
}

// 0x710043c380
void PPFX::SiYebisAllocator::vf19() {
}

// 0x710043c390
u64 PPFX::SiYebisAllocator::vf20() {
    return 0;
}
