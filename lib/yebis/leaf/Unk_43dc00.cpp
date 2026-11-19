// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_43dc00_8 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};
struct Unk_43dc00_10 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};
struct Unk_43dc00 {
    u32 field_0;
    u8 _4[0x4];
    Unk_43dc00_8* field_8;
    Unk_43dc00_10* field_10;
};
PKMN_OFFSET_ASSERT(Unk_43dc00, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_43dc00, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_43dc00, field_10, 0x10);

// 0x710043dc00
u32 Unk_43dc00_get(Unk_43dc00* self) {
    if (self->field_0 != 0) {
        return 0;
    }
    if (self->field_8 != nullptr) {
        self->field_8->vf3();
        self->field_8 = nullptr;
        if (self->field_10 != nullptr) {
            self->field_10->vf3();
            self->field_10 = nullptr;
            self->field_0 = 1;
            return 0;
        }
        self->field_0 = 1;
        return 0;
    }
    if (self->field_10 != nullptr) {
        self->field_10->vf3();
        self->field_10 = nullptr;
        self->field_0 = 1;
        return 0;
    }
    self->field_0 = 1;
    return 0;
}

// 0x710043fc90
u32 Unk_43fc90_get(u64 /*unused*/) {
    return 0;
}

// 0x7100440c00
u32 Unk_440c00_get(u64 /*unused*/, u32 /*unused*/) {
    return 1;
}

// 0x7100440c40
u32 Unk_440c40_get(u64 /*unused*/, u32 /*unused*/) {
    return 1;
}

// 0x7100440c60
u32 Unk_440c60_get(u64 /*unused*/, u32 /*unused*/, u32 /*unused*/) {
    return 1;
}

// 0x7100440c80
u32 Unk_440c80_get(u64 /*unused*/) {
    return 1;
}

// 0x7100440cb0
u32 Unk_440cb0_get(u64 /*unused*/, u32 /*unused*/) {
    return 1;
}

// 0x7100440cf0
u32 Unk_440cf0_get(u64 /*unused*/, u32 /*unused*/) {
    return 1;
}

// 0x7100440d50
u32 Unk_440d50_get(u64 /*unused*/, u32 /*unused*/) {
    return 1;
}

// 0x7100442c50
u32 Unk_442c50_get(u64 /*unused*/) {
    return 1;
}
