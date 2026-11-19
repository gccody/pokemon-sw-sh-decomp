// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_1105c00_60 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

struct Unk_1105c00 {
    u8 _0[0x60];
    Unk_1105c00_60* field_60;
};
PKMN_OFFSET_ASSERT(Unk_1105c00, field_60, 0x60);

// 0x7101105c00
void Unk_1105c00_call(const Unk_1105c00* self) {
    self->field_60->vf6();
}

struct Unk_11061d0 {
    u64 field_0;
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_11061d0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11061d0, field_8, 0x8);

// 0x71011061d0
void Unk_11061d0_set(Unk_11061d0* self) {
    self->field_0 = 0;
    self->field_8 = 0xffffffff;
}

struct Unk_11061e0_arg1 {
    u64 field_0;
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_11061e0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11061e0_arg1, field_8, 0x8);

struct Unk_11061e0 {
    u64 field_0;
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_11061e0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11061e0, field_8, 0x8);

// 0x71011061e0
void Unk_11061e0_set(Unk_11061e0* self, const Unk_11061e0_arg1* value) {
    self->field_0 = 0;
    self->field_8 = 0xffffffff;
    self->field_0 = value->field_0;
    self->field_8 = value->field_8;
}

struct Unk_1106200_arg1 {
    u64 field_0;
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1106200_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1106200_arg1, field_8, 0x8);

struct Unk_1106200 {
    u64 field_0;
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1106200, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1106200, field_8, 0x8);

// 0x7101106200
void Unk_1106200_set(Unk_1106200* self, const Unk_1106200_arg1* value) {
    self->field_0 = value->field_0;
    self->field_8 = value->field_8;
}

struct Unk_767720;
struct Unk_1108720 {
    u8 _0[0x58];
    Unk_767720* field_58;
};
PKMN_OFFSET_ASSERT(Unk_1108720, field_58, 0x58);

void Unk_767720_call(const Unk_767720*);

// 0x7101108720
void Unk_1108720_call(const Unk_1108720* self) {
    Unk_767720_call(self->field_58);
}

struct Unk_1108730 {
    u8 _0[0x58];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_1108730, field_58, 0x58);

// 0x7101108730
u64 Unk_1108730_getField58(const Unk_1108730* self) {
    return self->field_58;
}

u32 Unk_1108740(void*);

// 0x7101108910
u32 Unk_1108910_call(void* self, u32 value) {
    u32 r0 = Unk_1108740(self);
    return r0 - value;
}

struct Unk_1108940 {
    u8 _0[0x54];
    u8 field_54;
    u8 _55[0x3];
    void* field_58;
};
PKMN_OFFSET_ASSERT(Unk_1108940, field_54, 0x54);
PKMN_OFFSET_ASSERT(Unk_1108940, field_58, 0x58);
void Unk_767730(void*, u32);

// 0x7101108940
void Unk_1108940_update(const Unk_1108940* self, u32 value) {
    if (self->field_54 != 0) {
        return;
    }
    Unk_767730(self->field_58, value);
}

struct Unk_1108a70 {
    u8 _0[0x58];
    void* field_58;
};
PKMN_OFFSET_ASSERT(Unk_1108a70, field_58, 0x58);

void Unk_763030(void*, u32);

// 0x7101108a70
void Unk_1108a70_call(const Unk_1108a70* self, u32 value) {
    Unk_763030(self->field_58, value);
}

struct Unk_110ca80 {
    u8 _0[0x120];
    u32 field_120;
};
PKMN_OFFSET_ASSERT(Unk_110ca80, field_120, 0x120);

// 0x710110ca80
u32 Unk_110ca80_getField120(const Unk_110ca80* self) {
    return self->field_120;
}

struct Unk_110ca90 {
    u8 _0[0x124];
    u32 field_124;
};
PKMN_OFFSET_ASSERT(Unk_110ca90, field_124, 0x124);

// 0x710110ca90
u32 Unk_110ca90_getField124(const Unk_110ca90* self) {
    return self->field_124;
}

struct Unk_110caa0 {
    u8 _0[0x120];
    u32 field_120;
    u32 field_124;
};
PKMN_OFFSET_ASSERT(Unk_110caa0, field_120, 0x120);
PKMN_OFFSET_ASSERT(Unk_110caa0, field_124, 0x124);

// 0x710110caa0
void Unk_110caa0_set(Unk_110caa0* self, u32 value, u32 arg2) {
    self->field_124 = value;
    self->field_120 = arg2;
}

// 0x710110d7c0
void Unk_110d7c0_update() {}

struct Unk_110dbc0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_110dbc0_arg1, field_0, 0x0);

struct Unk_110dbc0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_110dbc0, field_0, 0x0);

// 0x710110dbc0
void Unk_110dbc0_set(const Unk_110dbc0* self, Unk_110dbc0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_110dbd0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_110dbd0_arg1, field_0, 0x0);

struct Unk_110dbd0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_110dbd0, field_0, 0x0);

// 0x710110dbd0
void Unk_110dbd0_set(const Unk_110dbd0* self, Unk_110dbd0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x710110e330
void Unk_110e330_update() {}

struct Unk_110ea90_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_110ea90_arg1, field_0, 0x0);

struct Unk_110ea90 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_110ea90, field_0, 0x0);

// 0x710110ea90
void Unk_110ea90_set(const Unk_110ea90* self, Unk_110ea90_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_110eaa0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_110eaa0_arg1, field_0, 0x0);

struct Unk_110eaa0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_110eaa0, field_0, 0x0);

// 0x710110eaa0
void Unk_110eaa0_set(const Unk_110eaa0* self, Unk_110eaa0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x710110f200
void Unk_110f200_update() {}

struct Unk_110f490_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_110f490_arg1, field_0, 0x0);

struct Unk_110f490 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_110f490, field_0, 0x0);

// 0x710110f490
void Unk_110f490_set(const Unk_110f490* self, Unk_110f490_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_110f4a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_110f4a0_arg1, field_0, 0x0);

struct Unk_110f4a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_110f4a0, field_0, 0x0);

// 0x710110f4a0
void Unk_110f4a0_set(const Unk_110f4a0* self, Unk_110f4a0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x710110fc00
void Unk_110fc00_update() {}

struct Unk_11101d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11101d0_arg1, field_0, 0x0);

struct Unk_11101d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11101d0, field_0, 0x0);

// 0x71011101d0
void Unk_11101d0_set(const Unk_11101d0* self, Unk_11101d0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11101e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11101e0_arg1, field_0, 0x0);

struct Unk_11101e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11101e0, field_0, 0x0);

// 0x71011101e0
void Unk_11101e0_set(const Unk_11101e0* self, Unk_11101e0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7101110230
void Unk_1110230_update() {}

struct Unk_1110ef0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1110ef0_arg1, field_0, 0x0);

struct Unk_1110ef0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1110ef0, field_0, 0x0);

// 0x7101110ef0
void Unk_1110ef0_set(const Unk_1110ef0* self, Unk_1110ef0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1110f00_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1110f00_arg1, field_0, 0x0);

struct Unk_1110f00 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1110f00, field_0, 0x0);

// 0x7101110f00
void Unk_1110f00_set(const Unk_1110f00* self, Unk_1110f00_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7101110f50
void Unk_1110f50_update() {}

struct Unk_11114e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11114e0_arg1, field_0, 0x0);

struct Unk_11114e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11114e0, field_0, 0x0);

// 0x71011114e0
void Unk_11114e0_set(const Unk_11114e0* self, Unk_11114e0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11114f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11114f0_arg1, field_0, 0x0);

struct Unk_11114f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11114f0, field_0, 0x0);

// 0x71011114f0
void Unk_11114f0_set(const Unk_11114f0* self, Unk_11114f0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7101111c50
void Unk_1111c50_update() {}

struct Unk_1111fb0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1111fb0_arg1, field_0, 0x0);

struct Unk_1111fb0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1111fb0, field_0, 0x0);

// 0x7101111fb0
void Unk_1111fb0_set(const Unk_1111fb0* self, Unk_1111fb0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1111fc0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1111fc0_arg1, field_0, 0x0);

struct Unk_1111fc0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1111fc0, field_0, 0x0);

// 0x7101111fc0
void Unk_1111fc0_set(const Unk_1111fc0* self, Unk_1111fc0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7101112720
void Unk_1112720_update() {}

struct Unk_11131a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11131a0_arg1, field_0, 0x0);

struct Unk_11131a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11131a0, field_0, 0x0);

// 0x71011131a0
void Unk_11131a0_set(const Unk_11131a0* self, Unk_11131a0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11131b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11131b0_arg1, field_0, 0x0);

struct Unk_11131b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11131b0, field_0, 0x0);

// 0x71011131b0
void Unk_11131b0_set(const Unk_11131b0* self, Unk_11131b0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7101113910
void Unk_1113910_update() {}

struct Unk_1113c30_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1113c30_arg1, field_0, 0x0);

struct Unk_1113c30 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1113c30, field_0, 0x0);

// 0x7101113c30
void Unk_1113c30_set(const Unk_1113c30* self, Unk_1113c30_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1113c40_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1113c40_arg1, field_0, 0x0);

struct Unk_1113c40 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1113c40, field_0, 0x0);

// 0x7101113c40
void Unk_1113c40_set(const Unk_1113c40* self, Unk_1113c40_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1113c50 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1113c50, field_0, 0x0);

// 0x7101113c50
void Unk_1113c50_call(Unk_1113c50* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_1113d80 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1113d80, field_0, 0x0);

// 0x7101113d80
void Unk_1113d80_call(Unk_1113d80* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}
