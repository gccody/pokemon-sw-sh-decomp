// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_898dd0_0_8 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3(u64, u64, u64);
};

struct Unk_898dd0_0 {
    virtual void vf0();
    Unk_898dd0_0_8* field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_898dd0_0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_898dd0_0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_898dd0_0, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_898dd0_0, field_20, 0x20);

struct Unk_898dd0 {
    Unk_898dd0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_898dd0, field_0, 0x0);

// 0x7100898dd0
void Unk_898dd0_call(Unk_898dd0* self) {
    Unk_898dd0_0* v0 = self->field_0;
    self->field_0 = nullptr;
    if (v0 != nullptr) {
        Unk_898dd0_0_8* v1 = v0->field_8;
        u64 v2 = v0->field_10;
        u64 v3 = v0->field_18;
        u64 v4 = v0->field_20;
        v0->vf0();
        v1->vf3(v2, v3, v4);
    }
}

// 0x710089a2e0
void Unk_89a2e0_update() {}

struct Unk_89a2f0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_89a2f0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_89a2f0, field_8, 0x8);

// 0x710089a2f0
void Unk_89a2f0_set(const Unk_89a2f0* self, Unk_89a2f0* value) {
    *value = *self;
}

struct Unk_89a300 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_89a300, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_89a300, field_8, 0x8);

// 0x710089a300
void Unk_89a300_set(const Unk_89a300* self, Unk_89a300* value) {
    *value = *self;
}

// 0x710089a720
void Unk_89a720_update() {}

struct Unk_89abc0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_89abc0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_89abc0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_89abc0, field_10, 0x10);

// 0x710089abc0
void Unk_89abc0_set(const Unk_89abc0* self, Unk_89abc0* value) {
    *value = *self;
}

struct Unk_89abe0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_89abe0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_89abe0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_89abe0, field_10, 0x10);

// 0x710089abe0
void Unk_89abe0_set(const Unk_89abe0* self, Unk_89abe0* value) {
    *value = *self;
}

// 0x710089ace0
void Unk_89ace0_update() {}

struct Unk_89acf0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_89acf0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_89acf0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_89acf0, field_10, 0x10);

// 0x710089acf0
void Unk_89acf0_set(const Unk_89acf0* self, Unk_89acf0* value) {
    *value = *self;
}

struct Unk_89ad10 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_89ad10, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_89ad10, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_89ad10, field_10, 0x10);

// 0x710089ad10
void Unk_89ad10_set(const Unk_89ad10* self, Unk_89ad10* value) {
    *value = *self;
}
