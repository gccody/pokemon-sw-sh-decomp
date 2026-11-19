// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x710076bef0
u32 Unk_76bef0_get() {
    return 8;
}

struct Unk_76c090_8 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3(u64, u64, u64);
};

struct Unk_76c090 {
    u64 field_0;
    Unk_76c090_8* field_8;
    u64 field_10;
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_76c090, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_76c090, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_76c090, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_76c090, field_18, 0x18);

// 0x710076c090
void Unk_76c090_call(Unk_76c090* self) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    if (v0 != 0) {
        self->field_8->vf3(v0, self->field_10, self->field_18);
    }
}

struct Unk_76c490 {
    u8 _0[0x31];
    u8 field_31;
};
PKMN_OFFSET_ASSERT(Unk_76c490, field_31, 0x31);

// 0x710076c490
u32 Unk_76c490_get(const Unk_76c490* self) {
    return (self->field_31 >> 6) & 1;
}
