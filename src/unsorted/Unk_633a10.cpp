// Scope: common
// A setter of the interface at +0x1a0 of the gflib3 object with vtable
// 0x710239d668 (Unk_239d658), written on the placeholder class of that vtable
// as src/unsorted/Unk_633890.cpp writes the +0x198 interface's (the object's
// pointer at +0x1a8 is its +0x8).
#include <types.h>

#include "unsorted/Unk_633890.h"

class Unk_239dac8 {
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
    virtual void vf13(const Unk_239d658_1a8_a8& value);

    Unk_239d658_1a8* field_8;
};
PKMN_OFFSET_ASSERT(Unk_239dac8, field_8, 0x8);

// 0x7100633ca0
void Unk_239dac8::vf13(const Unk_239d658_1a8_a8& value) {
    field_8->field_a8 = value;
}
