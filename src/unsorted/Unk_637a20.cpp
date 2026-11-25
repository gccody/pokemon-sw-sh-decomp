// Scope: common
// A setter of the interface at +0x98 of the gflib3 object with vtable
// 0x710239dbf0 (Unk_239dbe0). In the original it's a this-adjusting thunk
// of the object's overrider with the body inlined; written here on the
// placeholder class of that vtable (0x710239e1e8), as
// src/unsorted/virtual/Unk_620110.cpp writes its other functions.
#include <types.h>

// 16 bytes copied as a whole (not a vector: it isn't 16-byte aligned).
struct Unk_239e1d8_10 {
    u64 field_0;
    u64 field_8;
};
static_assert(sizeof(Unk_239e1d8_10) == 0x10, "Unk_239e1d8_10");

class Unk_239e1d8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual u8* vf5();
    virtual u8* vf6();
    virtual void vf7(f32 fvalue);
    virtual f32 vf8();
    virtual void vf9(f32 fvalue);
    virtual f32 vf10();
    virtual void vf11(f32 fvalue);
    virtual f32 vf12();
    virtual void vf13(const Unk_239e1d8_10& value);

    u8 _8[0x8];
    Unk_239e1d8_10 field_10;
};
PKMN_OFFSET_ASSERT(Unk_239e1d8, field_10, 0x10);

// 0x7100637a50
void Unk_239e1d8::vf13(const Unk_239e1d8_10& value) {
    field_10 = value;
}
