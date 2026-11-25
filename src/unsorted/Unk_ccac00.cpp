// Scope: common
// Unk_23e14a8's virtual functions, slots 4 to 13 (src/unsorted/Unk_ccac00.h).
// vf4 is its key function: its vtable, inline destructors and vf14 are
// emitted here. Placeholder names.
#include "unsorted/Unk_ccac00.h"

// The two singletons vf13 reads, as it uses them: an object each, held by a
// reference while it asks the second about field_18.
struct Unk_24ba5a8_Type {
    u8 _0[0x90];
    Unk_239a418_Ref2<Unk_239a418> field_90;
};
PKMN_OFFSET_ASSERT(Unk_24ba5a8_Type, field_90, 0x90);

struct Unk_24ba4e0_Type {
    u8 _0[0x1b8];
    Unk_239a418_Ref2<Unk_239a418> field_1b8;
};
PKMN_OFFSET_ASSERT(Unk_24ba4e0_Type, field_1b8, 0x1b8);

extern Unk_24ba5a8_Type* Unk_24ba5a8;
extern Unk_24ba4e0_Type* Unk_24ba4e0;

// 0x710135a1a0, not decompiled.
bool Unk_135a1a0(Unk_239a418* object, u64 value);

// 0x7100ccacd0
void Unk_23e14a8::vf4() {
    if (Unk_23dc940* object = Unk_Object()) {
        if (!object->vf17())
            object->vf16();
    }
}

// 0x7100ccad40
bool Unk_23e14a8::vf5() {
    return field_70.m_ptr == nullptr || field_70.m_ptr->field_54.load() == 0;
}

// 0x7100ccad70
Unk_23dc940* Unk_23e14a8::vf6() {
    Unk_23dc940* object = Unk_Object();
    if (object == nullptr)
        return nullptr;
    return object->vf17() ? nullptr : object;
}

// 0x7100ccadf0
u64 Unk_23e14a8::vf7() {
    return field_8->Get<u64>(0x16, 0);
}

// 0x7100ccae30
u64 Unk_23e14a8::vf8() {
    return field_8->Get<u64>(0x18, 0);
}

// 0x7100ccae80
float32x4_t Unk_23e14a8::vf10() {
    f32 x = field_8->Get<f32>(4, 0);
    f32 y = field_8->Get<f32>(6, 0);
    f32 z = field_8->Get<f32>(8, 0);
    return float32x4_t{x, y, z, 0};
}

// 0x7100ccaf10
void Unk_23e14a8::vf12(const u64& value) {
    field_18 = value;
}

// 0x7100ccaf20
bool Unk_23e14a8::vf13() {
    Unk_239a418_Ref2<Unk_239a418> first = Unk_24ba5a8->field_90;
    Unk_239a418_Ref2<Unk_239a418> second = Unk_24ba4e0->field_1b8;
    return Unk_135a1a0(second.m_ptr, field_18);
}
