// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
// RTTI: N4pead14DelegateThreadE
#include <types.h>

struct Unk_1721150 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
};

struct Unk_1721160 {
    u8 _0[0x30];
    u8 field_30;
};
PKMN_OFFSET_ASSERT(Unk_1721160, field_30, 0x30);

struct Unk_1721170 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10(u32);
};

struct Unk_17212c0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7(u32);
    virtual void vf8();
};

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

struct Unk_1721130_f0 {
    virtual void vf0(void*, u64);
};

struct Unk_1721130 {
    u8 _0[0xf0];
    Unk_1721130_f0* field_f0;
};
PKMN_OFFSET_ASSERT(Unk_1721130, field_f0, 0xf0);

struct Unk_1721e60 {
    u8 _0[0xe0];
    u64 field_e0;
};
PKMN_OFFSET_ASSERT(Unk_1721e60, field_e0, 0xe0);

namespace pead {
class DelegateThread {
public:
    void vf2();
    const u8* vf5();
    void vf9(bool value);
    void vf10(bool value);
    u32 vf12();
    u32 vf13();
    u32 vf14();
    u32 vf15();
    void vf16(u64 value);
    u64 vf17();
};
}  // namespace pead

// 0x7101721130
void pead::DelegateThread::vf16(u64 value) {
    Unk_1721130* self = reinterpret_cast<Unk_1721130*>(this);
    self->field_f0->vf0(self, value);
}

// 0x7101721150
void pead::DelegateThread::vf2() {
    Unk_1721150* self = reinterpret_cast<Unk_1721150*>(this);
    self->vf8();
}

// 0x7101721160
const u8* pead::DelegateThread::vf5() {
    const Unk_1721160* self = reinterpret_cast<const Unk_1721160*>(this);
    return &self->field_30;
}

// 0x7101721170
void pead::DelegateThread::vf9(bool value) {
    Unk_1721170* self = reinterpret_cast<Unk_1721170*>(this);
    self->vf10(value);
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

// 0x71017212c0
void pead::DelegateThread::vf10(bool value) {
    Unk_17212c0* self = reinterpret_cast<Unk_17212c0*>(this);
    self->vf7(value);
    self->vf8();
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
