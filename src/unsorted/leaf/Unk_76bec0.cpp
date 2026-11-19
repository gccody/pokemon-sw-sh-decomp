// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

extern u64 Unk_2779c28 __attribute__((visibility("hidden")));
void Unk_76d790(u64, u32);

// 0x710076bec0
void Unk_76bec0_call(u32 self) {
    Unk_76d790(Unk_2779c28, self);
}

extern u64 Unk_2779c28 __attribute__((visibility("hidden")));
void Unk_76d7b0(u64, u32);

// 0x710076bed0
void Unk_76bed0_call(u32 self) {
    Unk_76d7b0(Unk_2779c28, self);
}

extern u64 Unk_2779c28 __attribute__((visibility("hidden")));
void Unk_76d750(u64, u32);

// 0x710076bee0
void Unk_76bee0_call(u32 self) {
    Unk_76d750(Unk_2779c28, self);
}

// 0x710076bef0
u32 Unk_76bef0_get() {
    return 8;
}

extern u64 Unk_2779ca8 __attribute__((visibility("hidden")));
void Unk_76dcb0(u64);

// 0x710076bfa0
void Unk_76bfa0_call() {
    Unk_76dcb0(Unk_2779ca8);
}

extern u64 Unk_2779ca8 __attribute__((visibility("hidden")));
void Unk_76dd50(u64, u32);

// 0x710076bfb0
void Unk_76bfb0_call(u32 self) {
    Unk_76dd50(Unk_2779ca8, self);
}

extern u64 Unk_2779ca8 __attribute__((visibility("hidden")));
void Unk_76dd80(u64, u32);

// 0x710076bfc0
void Unk_76bfc0_call(u32 self) {
    Unk_76dd80(Unk_2779ca8, self);
}

extern u64 Unk_2779ca8 __attribute__((visibility("hidden")));
void Unk_76de30(u64, u32);

// 0x710076bfd0
void Unk_76bfd0_call(u32 self) {
    Unk_76de30(Unk_2779ca8, self);
}

extern u64 Unk_2779ca8 __attribute__((visibility("hidden")));
void Unk_76dee0(u64, u32);

// 0x710076bfe0
void Unk_76bfe0_call(u32 self) {
    Unk_76dee0(Unk_2779ca8, self);
}

extern u64 Unk_2779ca8 __attribute__((visibility("hidden")));
void Unk_76df90(u64, u32);

// 0x710076bff0
void Unk_76bff0_call(u32 self) {
    Unk_76df90(Unk_2779ca8, self);
}

extern u64 Unk_2779ca8 __attribute__((visibility("hidden")));
void Unk_76e040(u64, u32);

// 0x710076c000
void Unk_76c000_call(u32 self) {
    Unk_76e040(Unk_2779ca8, self);
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
