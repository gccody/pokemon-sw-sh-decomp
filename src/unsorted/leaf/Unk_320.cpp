// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_320_0_8 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3(u64, u64, u64);
};

struct Unk_320_0 {
    virtual void vf0();
    Unk_320_0_8* field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_320_0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_320_0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_320_0, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_320_0, field_20, 0x20);

struct Unk_320 {
    Unk_320_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_320, field_0, 0x0);

// 0x7100000320
void Unk_320_call(Unk_320* self) {
    Unk_320_0* v0 = self->field_0;
    self->field_0 = nullptr;
    if (v0 != nullptr) {
        Unk_320_0_8* v1 = v0->field_8;
        u64 v2 = v0->field_10;
        u64 v3 = v0->field_18;
        u64 v4 = v0->field_20;
        v0->vf0();
        v1->vf3(v2, v3, v4);
    }
}
