// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_382440 {
    u8 _0[0x78];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_382440, field_78, 0x78);

struct Unk_382a90_80 {
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
    virtual void vf12(void*);
};

struct Unk_382a90 {
    u8 _0[0x80];
    Unk_382a90_80* field_80;
};
PKMN_OFFSET_ASSERT(Unk_382a90, field_80, 0x80);

struct Unk_34c180 {
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
    u8 _8[0x90];
    u16 field_98;
};
PKMN_OFFSET_ASSERT(Unk_34c180, field_98, 0x98);

class Unk_2382098 {
public:
    void vf7(u64 value);
    void vf14();
    u32 vf18();
    u32 vf55();
    void vf63(u64 value, u64 arg2, u64 arg3);
    u32 vf10();
    void vf12();
    void vf13();
    void vf15();
    void vf28();
    void vf49();
    void vf50();
    void vf48();
    u32 vf61();
    u32 vf62();
    u32 vf67();
    void vf16();
};

// 0x710034b710
u32 Unk_2382098::vf18() {
    return 1;
}

// 0x710034bc40
void Unk_2382098::vf28() {
}

// 0x710034c010
void Unk_2382098::vf49() {
}

// 0x710034c020
void Unk_2382098::vf50() {
}

// 0x710034c030
u32 Unk_2382098::vf55() {
    return 2;
}

// 0x710034c180
void Unk_2382098::vf63(u64 value, u64 arg2, u64 arg3) {
    Unk_34c180* self = reinterpret_cast<Unk_34c180*>(this);
    if ((self->field_98 & 0xffe) != 0) {
        self->vf27(value, arg2, arg3);
    }
}

// 0x710034c2a0
void Unk_2382098::vf48() {
}

// 0x710034dbd0
u32 Unk_2382098::vf61() {
    return 0;
}

// 0x710034dbe0
u32 Unk_2382098::vf62() {
    return 1;
}

// 0x7100380ff0
void Unk_2382098::vf13() {
}

// 0x7100381000
void Unk_2382098::vf16() {
}

// 0x7100382440
void Unk_2382098::vf7(u64 value) {
    Unk_382440* self = reinterpret_cast<Unk_382440*>(this);
    self->field_78 = value;
}

// 0x7100382a70
u32 Unk_2382098::vf10() {
    return 0;
}

// 0x7100382a80
void Unk_2382098::vf12() {
}

// 0x7100382a90
void Unk_2382098::vf14() {
    Unk_382a90* self = reinterpret_cast<Unk_382a90*>(this);
    if (self->field_80 != nullptr) {
        self->field_80->vf12(self);
    }
}

// 0x7100382ab0
void Unk_2382098::vf15() {
}

// 0x7100385420
u32 Unk_2382098::vf67() {
    return 0;
}
