// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_382440 {
    u8 _0[0x78];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_382440, field_78, 0x78);

class Unk_2382098 {
public:
    void vf7(u64 value);
    u32 vf18();
    u32 vf55();
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

// 0x7100382ab0
void Unk_2382098::vf15() {
}

// 0x7100385420
u32 Unk_2382098::vf67() {
    return 0;
}
