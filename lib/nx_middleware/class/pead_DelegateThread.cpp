// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_1721160 {
    u8 _0[0x30];
    u8 field_30;
};
PKMN_OFFSET_ASSERT(Unk_1721160, field_30, 0x30);

struct Unk_1721e90 {
    u8 _0[0xe8];
    u32 field_e8;
};
PKMN_OFFSET_ASSERT(Unk_1721e90, field_e8, 0xe8);

struct Unk_1721180 {
    u8 _0[0xb8];
    u32 field_b8;
};
PKMN_OFFSET_ASSERT(Unk_1721180, field_b8, 0xb8);

struct Unk_1721190 {
    u8 _0[0x80];
    u32 field_80;
};
PKMN_OFFSET_ASSERT(Unk_1721190, field_80, 0x80);

struct Unk_1721e60 {
    u8 _0[0xe0];
    u64 field_e0;
};
PKMN_OFFSET_ASSERT(Unk_1721e60, field_e0, 0xe0);

namespace pead {
class DelegateThread {
public:
    const u8* vf5();
    u32 vf12();
    u32 vf13();
    u32 vf14();
    u32 vf15();
    u64 vf17();
};
}  // namespace pead

// 0x7101721160
const u8* pead::DelegateThread::vf5() {
    const Unk_1721160* self = reinterpret_cast<const Unk_1721160*>(this);
    return &self->field_30;
}

// 0x7101721180
u32 pead::DelegateThread::vf13() {
    const Unk_1721180* self = reinterpret_cast<const Unk_1721180*>(this);
    return self->field_b8;
}

// 0x7101721190
u32 pead::DelegateThread::vf14() {
    const Unk_1721190* self = reinterpret_cast<const Unk_1721190*>(this);
    return self->field_80;
}

// 0x7101721210
u32 pead::DelegateThread::vf15() {
    return 0;
}

// 0x7101721e60
u64 pead::DelegateThread::vf17() {
    const Unk_1721e60* self = reinterpret_cast<const Unk_1721e60*>(this);
    return self->field_e0;
}

// 0x7101721e90
u32 pead::DelegateThread::vf12() {
    const Unk_1721e90* self = reinterpret_cast<const Unk_1721e90*>(this);
    return self->field_e8;
}
