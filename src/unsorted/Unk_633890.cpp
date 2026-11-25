// Scope: common
// Setters of the interface at +0x198 of the gflib3 object with vtable
// 0x710239d668 (Unk_239d658). In the original they're this-adjusting thunks
// of the object's overriders with the body inlined; written here on the
// placeholder class of that vtable, as src/unsorted/virtual/Unk_620110.cpp
// writes its other functions (the object's pointer at +0x1a8 is its +0x10).
#include <types.h>

#include "gflib3/Unk_239a418_Make.h"
#include "unsorted/Unk_633890.h"

class Unk_239d9e8 {
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
    virtual u8* vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17(const Unk_239d658_Vector& value);
    virtual u8* vf18();
    virtual void vf19(const Unk_239d658_Vector& value);
    virtual u8* vf20();
    virtual void vf21(const Unk_239d658_Vector& value);
    virtual void vf22(const Unk_239d658_Vector& value);
    virtual void vf23(Unk_239a418* object);
    virtual void vf24(f32 fvalue);
    virtual f32 vf25();

    u8 _8[0x8];
    Unk_239d658_1a8* field_10;
};
PKMN_OFFSET_ASSERT(Unk_239d9e8, field_10, 0x10);

// 0x71006338e0
void Unk_239d9e8::vf13(const Unk_239d658_1a8_a8& value) {
    field_10->field_a8 = value;
}

// 0x7100633920
void Unk_239d9e8::vf17(const Unk_239d658_Vector& value) {
    field_10->field_120 = value;
}

// 0x7100633950
void Unk_239d9e8::vf19(const Unk_239d658_Vector& value) {
    field_10->field_100 = value;
}

// 0x7100633980
void Unk_239d9e8::vf21(const Unk_239d658_Vector& value) {
    field_10->field_110 = value;
}

// 0x71006339a0
void Unk_239d9e8::vf22(const Unk_239d658_Vector& value) {
    field_10->field_e0 = value;
}

// 0x71006339c0
void Unk_239d9e8::vf23(Unk_239a418* object) {
    Unk_Assign(field_10->field_130, object->vf2());
}
