// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

extern u64 Unk_2773638 __attribute__((visibility("hidden")));

// 0x71005d12c0
u64 Unk_5d12c0_get() {
    return Unk_2773638;
}

struct Unk_5d1b50 {
    u8 _0[0x130];
    u64 field_130;
};
PKMN_OFFSET_ASSERT(Unk_5d1b50, field_130, 0x130);

// 0x71005d1b50
void Unk_5d1b50_set(Unk_5d1b50* self) {
    self->field_130 = self->field_130 | 0x10;
}

struct Unk_5d3840_8 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3(u64, u64, u64);
};

struct Unk_5d3840 {
    u64 field_0;
    Unk_5d3840_8* field_8;
    u64 field_10;
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_5d3840, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_5d3840, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_5d3840, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_5d3840, field_18, 0x18);

void Unk_5d3f50(u64);

// 0x71005d3840
void Unk_5d3840_call(Unk_5d3840* self) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    if (v0 != 0) {
        Unk_5d3f50(v0);
        self->field_8->vf3(v0, self->field_10, self->field_18);
    }
}

extern u64 Unk_2773640;

// 0x71005d42e0
u64 Unk_5d42e0_get() {
    return Unk_2773640;
}
