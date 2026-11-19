// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_6a0530_0 {
    virtual void vf0();
};

struct Unk_6a0530_8 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3(void*, u64, u64);
};

struct Unk_6a0530 {
    Unk_6a0530_0* field_0;
    Unk_6a0530_8* field_8;
    u64 field_10;
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_6a0530, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_6a0530, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_6a0530, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_6a0530, field_18, 0x18);

// 0x71006a0530
void Unk_6a0530_call(Unk_6a0530* self) {
    Unk_6a0530_0* v0 = self->field_0;
    self->field_0 = nullptr;
    if (v0 != nullptr) {
        v0->vf0();
        self->field_8->vf3(v0, self->field_10, self->field_18);
    }
}

extern u32 Unk_2778be0 __attribute__((visibility("hidden")));

// 0x71006a0ec0
u32 Unk_6a0ec0_get() {
    return Unk_2778be0;
}
