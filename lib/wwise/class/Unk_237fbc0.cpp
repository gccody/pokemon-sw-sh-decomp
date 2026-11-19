// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_34da20 {
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
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20(u64);
};

struct Unk_3557a0_70 {
    u8 _0[0x70];
    u16 field_70;
};
PKMN_OFFSET_ASSERT(Unk_3557a0_70, field_70, 0x70);

struct Unk_3557a0 {
    u8 _0[0x70];
    Unk_3557a0_70* field_70;
    u8 _78[0x24];
    u32 field_9c;
};
PKMN_OFFSET_ASSERT(Unk_3557a0, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_3557a0, field_9c, 0x9c);

struct Unk_34dbf0 {
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
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27(u64, u64, u64);
};

class Unk_237fbc0 {
public:
    void vf7();
    u32 vf17();
    void vf21(u64 value);
    void vf51(u32 value);
    void vf63(u64 value, u64 arg2, u64 arg3);
    void vf70();
};

// 0x710034d860
u32 Unk_237fbc0::vf17() {
    return 0xa;
}

// 0x710034da20
void Unk_237fbc0::vf21(u64 value) {
    Unk_34da20* self = reinterpret_cast<Unk_34da20*>(this);
    self->vf20(value);
}

// 0x710034dbf0
void Unk_237fbc0::vf63(u64 value, u64 arg2, u64 arg3) {
    Unk_34dbf0* self = reinterpret_cast<Unk_34dbf0*>(this);
    self->vf27(value, arg2, arg3);
}

// 0x710034dc00
void Unk_237fbc0::vf70() {
}

// 0x71003557a0
void Unk_237fbc0::vf51(u32 value) {
    Unk_3557a0* self = reinterpret_cast<Unk_3557a0*>(this);
    if (self->field_70 != nullptr) {
        self->field_70->field_70 = value;
    }
    self->field_9c = (self->field_9c & 0xfffffc00) | (value & 0x3ff);
}

// 0x7100356710
void Unk_237fbc0::vf7() {
}
