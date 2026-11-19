// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_30d590 {
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
    virtual void vf27();
    virtual void vf28(u64);
};

struct Unk_30d490 {
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
    virtual void vf19(u32);
};

struct Unk_30d4c0 {
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
    u8 _8[0x214];
    u32 field_21c;
};
PKMN_OFFSET_ASSERT(Unk_30d4c0, field_21c, 0x21c);

struct Unk_30d610 {
    u8 _0[0x16c];
    u16 field_16c;
    u8 _16e[0xa6];
    f32 field_214;
};
PKMN_OFFSET_ASSERT(Unk_30d610, field_16c, 0x16c);
PKMN_OFFSET_ASSERT(Unk_30d610, field_214, 0x214);

class Unk_237c628 {
public:
    void vf8();
    void vf9();
    void vf25(u64 value);
    u64 vf26();
    void vf27();
    void vf29();
    void vf30();
    void vf32(u32 value, f32 fvalue);
    void vf33();
    void vf34();
    void vf35();
    u64 vf5();
    u32 vf6();
    void vf7();
};

// 0x710030d2c0
void Unk_237c628::vf8() {
}

// 0x710030d2d0
void Unk_237c628::vf9() {
}

// 0x710030d490
void Unk_237c628::vf29() {
    Unk_30d490* self = reinterpret_cast<Unk_30d490*>(this);
    self->vf19(1);
}

// 0x710030d4c0
void Unk_237c628::vf30() {
    Unk_30d4c0* self = reinterpret_cast<Unk_30d4c0*>(this);
    self->vf20();
    self->field_21c = 0x3f800000;
    self->vf13();
}

// 0x710030d550
void Unk_237c628::vf34() {
}

// 0x710030d570
void Unk_237c628::vf35() {
}

// 0x710030d590
void Unk_237c628::vf25(u64 value) {
    Unk_30d590* self = reinterpret_cast<Unk_30d590*>(this);
    self->vf28(value);
}

// 0x710030d610
void Unk_237c628::vf32(u32 value, f32 fvalue) {
    Unk_30d610* self = reinterpret_cast<Unk_30d610*>(this);
    if (value == 0x36) {
        self->field_214 = fvalue;
        self->field_16c = self->field_16c & 0xffffffdf;
    }
}

// 0x710030d860
u64 Unk_237c628::vf26() {
    return 0x1ffbfe3fffe60b9;
}

// 0x710030d870
void Unk_237c628::vf27() {
}

// 0x710030d880
void Unk_237c628::vf33() {
}

// 0x710030d890
u64 Unk_237c628::vf5() {
    return 0x1ffbfe3fffe60b9;
}

// 0x710030d8b0
void Unk_237c628::vf7() {
}

// 0x7100351820
u32 Unk_237c628::vf6() {
    return 1;
}
