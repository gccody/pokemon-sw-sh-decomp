// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x71007a3140
bool Unk_7a3140_check(void* /*unused*/, u32 value) {
    return value >= 0x4ff && value <= 0x62a;
}

struct Unk_7a3810 {
    u8 _0[0x698];
    u64 field_698;
};
PKMN_OFFSET_ASSERT(Unk_7a3810, field_698, 0x698);

void Unk_14e1a00(u64, u32);

// 0x71007a3810
void Unk_7a3810_call(const Unk_7a3810* self, bool value) {
    if (self->field_698 != 0) {
        Unk_14e1a00(self->field_698, value);
    }
}

// 0x71007a3de0
void Unk_7a3de0_update() {}

struct Unk_7a3df0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a3df0_arg1, field_0, 0x0);

struct Unk_7a3df0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a3df0, field_0, 0x0);

// 0x71007a3df0
void Unk_7a3df0_set(const Unk_7a3df0* self, Unk_7a3df0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_7a3e00_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a3e00_arg1, field_0, 0x0);

struct Unk_7a3e00 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a3e00, field_0, 0x0);

// 0x71007a3e00
void Unk_7a3e00_set(const Unk_7a3e00* self, Unk_7a3e00_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71007a3ee0
void Unk_7a3ee0_update() {}

struct Unk_7a3ef0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a3ef0_arg1, field_0, 0x0);

struct Unk_7a3ef0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a3ef0, field_0, 0x0);

// 0x71007a3ef0
void Unk_7a3ef0_set(const Unk_7a3ef0* self, Unk_7a3ef0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_7a3f00_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a3f00_arg1, field_0, 0x0);

struct Unk_7a3f00 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a3f00, field_0, 0x0);

// 0x71007a3f00
void Unk_7a3f00_set(const Unk_7a3f00* self, Unk_7a3f00_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71007a5d00
void Unk_7a5d00_update() {}

struct Unk_7a5d10_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a5d10_arg1, field_0, 0x0);

struct Unk_7a5d10 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a5d10, field_0, 0x0);

// 0x71007a5d10
void Unk_7a5d10_set(const Unk_7a5d10* self, Unk_7a5d10_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_7a5d20_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a5d20_arg1, field_0, 0x0);

struct Unk_7a5d20 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a5d20, field_0, 0x0);

// 0x71007a5d20
void Unk_7a5d20_set(const Unk_7a5d20* self, Unk_7a5d20_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_7a5d30_0 {
    u8 _0[0x4c0];
    u64 field_4c0;
};
PKMN_OFFSET_ASSERT(Unk_7a5d30_0, field_4c0, 0x4c0);

struct Unk_7a5d30 {
    Unk_7a5d30_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a5d30, field_0, 0x0);

void Unk_1500c40(u64);

// 0x71007a5d30
void Unk_7a5d30_call(const Unk_7a5d30* self) {
    if (self->field_0->field_4c0 != 0) {
        Unk_1500c40(self->field_0->field_4c0);
    }
}

// 0x71007a5d50
void Unk_7a5d50_update() {}

struct Unk_7a5d60_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a5d60_arg1, field_0, 0x0);

struct Unk_7a5d60 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a5d60, field_0, 0x0);

// 0x71007a5d60
void Unk_7a5d60_set(const Unk_7a5d60* self, Unk_7a5d60_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_7a5d70_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a5d70_arg1, field_0, 0x0);

struct Unk_7a5d70 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a5d70, field_0, 0x0);

// 0x71007a5d70
void Unk_7a5d70_set(const Unk_7a5d70* self, Unk_7a5d70_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71007a67d0
void Unk_7a67d0_update() {}

struct Unk_7a67e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a67e0_arg1, field_0, 0x0);

struct Unk_7a67e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a67e0, field_0, 0x0);

// 0x71007a67e0
void Unk_7a67e0_set(const Unk_7a67e0* self, Unk_7a67e0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_7a67f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a67f0_arg1, field_0, 0x0);

struct Unk_7a67f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a67f0, field_0, 0x0);

// 0x71007a67f0
void Unk_7a67f0_set(const Unk_7a67f0* self, Unk_7a67f0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71007a6830
void Unk_7a6830_update() {}

struct Unk_7a6840_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a6840_arg1, field_0, 0x0);

struct Unk_7a6840 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a6840, field_0, 0x0);

// 0x71007a6840
void Unk_7a6840_set(const Unk_7a6840* self, Unk_7a6840_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_7a6850_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a6850_arg1, field_0, 0x0);

struct Unk_7a6850 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a6850, field_0, 0x0);

// 0x71007a6850
void Unk_7a6850_set(const Unk_7a6850* self, Unk_7a6850_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71007a6910
void Unk_7a6910_update() {}

struct Unk_7a6920_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a6920_arg1, field_0, 0x0);

struct Unk_7a6920 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a6920, field_0, 0x0);

// 0x71007a6920
void Unk_7a6920_set(const Unk_7a6920* self, Unk_7a6920_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_7a6930_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a6930_arg1, field_0, 0x0);

struct Unk_7a6930 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a6930, field_0, 0x0);

// 0x71007a6930
void Unk_7a6930_set(const Unk_7a6930* self, Unk_7a6930_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71007a6b50
void Unk_7a6b50_update() {}

struct Unk_7a6b60_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a6b60_arg1, field_0, 0x0);

struct Unk_7a6b60 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a6b60, field_0, 0x0);

// 0x71007a6b60
void Unk_7a6b60_set(const Unk_7a6b60* self, Unk_7a6b60_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_7a6b70_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a6b70_arg1, field_0, 0x0);

struct Unk_7a6b70 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a6b70, field_0, 0x0);

// 0x71007a6b70
void Unk_7a6b70_set(const Unk_7a6b70* self, Unk_7a6b70_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_7a6b80_0 {
    u8 _0[0x810];
    u32 field_810;
};
PKMN_OFFSET_ASSERT(Unk_7a6b80_0, field_810, 0x810);

struct Unk_7a6b80_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a6b80_arg1, field_0, 0x0);

struct Unk_7a6b80 {
    Unk_7a6b80_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a6b80, field_0, 0x0);

// 0x71007a6b80
void Unk_7a6b80_set(const Unk_7a6b80* self, const Unk_7a6b80_arg1* value) {
    self->field_0->field_810 = value->field_0;
}

// 0x71007a6b90
void Unk_7a6b90_update() {}

struct Unk_7a6ba0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a6ba0_arg1, field_0, 0x0);

struct Unk_7a6ba0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a6ba0, field_0, 0x0);

// 0x71007a6ba0
void Unk_7a6ba0_set(const Unk_7a6ba0* self, Unk_7a6ba0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_7a6bb0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a6bb0_arg1, field_0, 0x0);

struct Unk_7a6bb0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a6bb0, field_0, 0x0);

// 0x71007a6bb0
void Unk_7a6bb0_set(const Unk_7a6bb0* self, Unk_7a6bb0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71007a6c00
void Unk_7a6c00_update() {}

struct Unk_7a6c10_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a6c10_arg1, field_0, 0x0);

struct Unk_7a6c10 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a6c10, field_0, 0x0);

// 0x71007a6c10
void Unk_7a6c10_set(const Unk_7a6c10* self, Unk_7a6c10_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_7a6c20_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a6c20_arg1, field_0, 0x0);

struct Unk_7a6c20 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a6c20, field_0, 0x0);

// 0x71007a6c20
void Unk_7a6c20_set(const Unk_7a6c20* self, Unk_7a6c20_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71007a6c70
void Unk_7a6c70_update() {}

struct Unk_7a6c80_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a6c80_arg1, field_0, 0x0);

struct Unk_7a6c80 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a6c80, field_0, 0x0);

// 0x71007a6c80
void Unk_7a6c80_set(const Unk_7a6c80* self, Unk_7a6c80_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_7a6c90_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a6c90_arg1, field_0, 0x0);

struct Unk_7a6c90 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a6c90, field_0, 0x0);

// 0x71007a6c90
void Unk_7a6c90_set(const Unk_7a6c90* self, Unk_7a6c90_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_7a6ca0_0 {
    u8 _0[0x4c0];
    u64 field_4c0;
};
PKMN_OFFSET_ASSERT(Unk_7a6ca0_0, field_4c0, 0x4c0);

struct Unk_7a6ca0 {
    Unk_7a6ca0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a6ca0, field_0, 0x0);

void Unk_1500c40(u64);

// 0x71007a6ca0
void Unk_7a6ca0_call(const Unk_7a6ca0* self) {
    if (self->field_0->field_4c0 != 0) {
        Unk_1500c40(self->field_0->field_4c0);
    }
}

// 0x71007a6cc0
void Unk_7a6cc0_update() {}

struct Unk_7a6cd0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a6cd0_arg1, field_0, 0x0);

struct Unk_7a6cd0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a6cd0, field_0, 0x0);

// 0x71007a6cd0
void Unk_7a6cd0_set(const Unk_7a6cd0* self, Unk_7a6cd0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_7a6ce0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a6ce0_arg1, field_0, 0x0);

struct Unk_7a6ce0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a6ce0, field_0, 0x0);

// 0x71007a6ce0
void Unk_7a6ce0_set(const Unk_7a6ce0* self, Unk_7a6ce0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_7a6cf0_0 {
    u8 _0[0x4c0];
    u64 field_4c0;
};
PKMN_OFFSET_ASSERT(Unk_7a6cf0_0, field_4c0, 0x4c0);

struct Unk_7a6cf0 {
    Unk_7a6cf0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a6cf0, field_0, 0x0);

void Unk_1500c40(u64);

// 0x71007a6cf0
void Unk_7a6cf0_call(const Unk_7a6cf0* self) {
    if (self->field_0->field_4c0 != 0) {
        Unk_1500c40(self->field_0->field_4c0);
    }
}

// 0x71007a6d10
void Unk_7a6d10_update() {}

struct Unk_7a6d20_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a6d20_arg1, field_0, 0x0);

struct Unk_7a6d20 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a6d20, field_0, 0x0);

// 0x71007a6d20
void Unk_7a6d20_set(const Unk_7a6d20* self, Unk_7a6d20_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_7a6d30_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a6d30_arg1, field_0, 0x0);

struct Unk_7a6d30 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a6d30, field_0, 0x0);

// 0x71007a6d30
void Unk_7a6d30_set(const Unk_7a6d30* self, Unk_7a6d30_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_7a6d40_0 {
    u8 _0[0x4c0];
    u64 field_4c0;
    u8 _4c8[0x104];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_7a6d40_0, field_4c0, 0x4c0);
PKMN_OFFSET_ASSERT(Unk_7a6d40_0, field_5cc, 0x5cc);

struct Unk_7a6d40 {
    Unk_7a6d40_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a6d40, field_0, 0x0);

void Unk_1500c40(u64);

// 0x71007a6d40
void Unk_7a6d40_call(const Unk_7a6d40* self) {
    Unk_7a6d40_0* p0 = self->field_0;
    p0->field_5cc = 7;
    if (p0->field_4c0 != 0) {
        Unk_1500c40(p0->field_4c0);
    }
}

// 0x71007a6d60
void Unk_7a6d60_update() {}

struct Unk_7a6d70_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a6d70_arg1, field_0, 0x0);

struct Unk_7a6d70 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a6d70, field_0, 0x0);

// 0x71007a6d70
void Unk_7a6d70_set(const Unk_7a6d70* self, Unk_7a6d70_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_7a6d80_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a6d80_arg1, field_0, 0x0);

struct Unk_7a6d80 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7a6d80, field_0, 0x0);

// 0x71007a6d80
void Unk_7a6d80_set(const Unk_7a6d80* self, Unk_7a6d80_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_7a7e60 {
    u8 _0[0x120];
    u32 field_120;
};
PKMN_OFFSET_ASSERT(Unk_7a7e60, field_120, 0x120);

// 0x71007a7e60
u32 Unk_7a7e60_getField120(const Unk_7a7e60* self) {
    return self->field_120;
}

struct Unk_7a7e70 {
    u8 _0[0x120];
    u32 field_120;
};
PKMN_OFFSET_ASSERT(Unk_7a7e70, field_120, 0x120);

// 0x71007a7e70
void Unk_7a7e70_setField120(Unk_7a7e70* self, u32 value) {
    self->field_120 = value;
}
