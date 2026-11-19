// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7100ea9a30
void Unk_ea9a30_update() {}

struct Unk_ea9a40 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_ea9a40, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ea9a40, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_ea9a40, field_10, 0x10);

// 0x7100ea9a40
void Unk_ea9a40_set(const Unk_ea9a40* self, Unk_ea9a40* value) {
    *value = *self;
}

struct Unk_ea9a60 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_ea9a60, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ea9a60, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_ea9a60, field_10, 0x10);

// 0x7100ea9a60
void Unk_ea9a60_set(const Unk_ea9a60* self, Unk_ea9a60* value) {
    *value = *self;
}

struct Unk_ea9e40 {
    void* field_0;
};
PKMN_OFFSET_ASSERT(Unk_ea9e40, field_0, 0x0);

void Unk_ea9cc0(void*, void*);

// 0x7100ea9e40
void Unk_ea9e40_call(const Unk_ea9e40* self, void* value) {
    Unk_ea9cc0(self->field_0, value);
}

struct Unk_ea9e50_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ea9e50_arg1, field_0, 0x0);

struct Unk_ea9e50 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ea9e50, field_0, 0x0);

void Unk_ea9e60(u64, u64);

// 0x7100ea9e50
void Unk_ea9e50_call(const Unk_ea9e50* self, const Unk_ea9e50_arg1* value) {
    Unk_ea9e60(self->field_0, value->field_0);
}

struct Unk_eaa030 {
    u8 _0[0x50];
    u8 field_50;
};
PKMN_OFFSET_ASSERT(Unk_eaa030, field_50, 0x50);

// 0x7100eaa030
u8* Unk_eaa030_getField50Ptr(Unk_eaa030* self) {
    return &self->field_50;
}

struct Unk_eaa530 {
    u8 _0[0x50];
    void* field_50;
};
PKMN_OFFSET_ASSERT(Unk_eaa530, field_50, 0x50);

void Unk_eab310(void*, u32);

// 0x7100eaa530
void Unk_eaa530_call(const Unk_eaa530* self, u32 value) {
    Unk_eab310(self->field_50, value);
}

struct Unk_eaa540 {
    u8 _0[0x50];
    void* field_50;
};
PKMN_OFFSET_ASSERT(Unk_eaa540, field_50, 0x50);

void Unk_eab3e0(void*);

// 0x7100eaa540
void Unk_eaa540_call(const Unk_eaa540* self) {
    Unk_eab3e0(self->field_50);
}

struct Unk_eaa620 {
    u8 _0[0x50];
    void* field_50;
};
PKMN_OFFSET_ASSERT(Unk_eaa620, field_50, 0x50);

void Unk_eab610(void*, u32);

// 0x7100eaa620
void Unk_eaa620_call(const Unk_eaa620* self, u32 value) {
    Unk_eab610(self->field_50, value);
}

struct Unk_eaa630 {
    u8 _0[0x50];
    void* field_50;
};
PKMN_OFFSET_ASSERT(Unk_eaa630, field_50, 0x50);

void Unk_eab8c0(void*, u32, void*, void*);

// 0x7100eaa630
void Unk_eaa630_call(const Unk_eaa630* self, u32 value, void* arg2, void* arg3) {
    Unk_eab8c0(self->field_50, value, arg2, arg3);
}

struct Unk_eaa640 {
    u8 _0[0x50];
    void* field_50;
};
PKMN_OFFSET_ASSERT(Unk_eaa640, field_50, 0x50);

void Unk_eab960(void*, u32, void*);

// 0x7100eaa640
void Unk_eaa640_call(const Unk_eaa640* self, u32 value, void* arg2) {
    Unk_eab960(self->field_50, value, arg2);
}

struct Unk_eaa650 {
    u8 _0[0x50];
    void* field_50;
};
PKMN_OFFSET_ASSERT(Unk_eaa650, field_50, 0x50);

void Unk_eab9f0(void*, u32);

// 0x7100eaa650
void Unk_eaa650_call(const Unk_eaa650* self, u32 value) {
    Unk_eab9f0(self->field_50, value);
}

struct Unk_eaa660 {
    u8 _0[0x50];
    void* field_50;
};
PKMN_OFFSET_ASSERT(Unk_eaa660, field_50, 0x50);

void Unk_eaba50(void*);

// 0x7100eaa660
void Unk_eaa660_call(const Unk_eaa660* self) {
    Unk_eaba50(self->field_50);
}

struct Unk_eaa670 {
    u8 _0[0x50];
    void* field_50;
};
PKMN_OFFSET_ASSERT(Unk_eaa670, field_50, 0x50);

void Unk_eabaa0(void*);

// 0x7100eaa670
void Unk_eaa670_call(const Unk_eaa670* self) {
    Unk_eabaa0(self->field_50);
}

struct Unk_eaa680 {
    u8 _0[0x50];
    void* field_50;
};
PKMN_OFFSET_ASSERT(Unk_eaa680, field_50, 0x50);

void Unk_eabaf0(void*, u32, u64);

// 0x7100eaa680
void Unk_eaa680_call(const Unk_eaa680* self, u32 value, u64 arg2) {
    Unk_eabaf0(self->field_50, value, arg2);
}

struct Unk_eaa690 {
    u8 _0[0x50];
    void* field_50;
};
PKMN_OFFSET_ASSERT(Unk_eaa690, field_50, 0x50);

void Unk_eabb60(void*, u32, void*, u64);

// 0x7100eaa690
void Unk_eaa690_call(const Unk_eaa690* self, u32 value, void* arg2, u64 arg3) {
    Unk_eabb60(self->field_50, value, arg2, arg3);
}

struct Unk_eaa6a0 {
    u8 _0[0x50];
    void* field_50;
};
PKMN_OFFSET_ASSERT(Unk_eaa6a0, field_50, 0x50);

void Unk_eabbf0(void*, u32);

// 0x7100eaa6a0
void Unk_eaa6a0_call(const Unk_eaa6a0* self, bool value) {
    Unk_eabbf0(self->field_50, value);
}

struct Unk_eaa6b0 {
    u8 _0[0x50];
    void* field_50;
};
PKMN_OFFSET_ASSERT(Unk_eaa6b0, field_50, 0x50);

void Unk_eabc50(void*);

// 0x7100eaa6b0
void Unk_eaa6b0_call(const Unk_eaa6b0* self) {
    Unk_eabc50(self->field_50);
}

struct Unk_eaa6c0 {
    u8 _0[0x50];
    void* field_50;
};
PKMN_OFFSET_ASSERT(Unk_eaa6c0, field_50, 0x50);

void Unk_eabca0(void*, u32);

// 0x7100eaa6c0
void Unk_eaa6c0_call(const Unk_eaa6c0* self, u32 value) {
    Unk_eabca0(self->field_50, value);
}

struct Unk_eaa6d0 {
    u8 _0[0x50];
    void* field_50;
};
PKMN_OFFSET_ASSERT(Unk_eaa6d0, field_50, 0x50);

void Unk_eabd00(void*);

// 0x7100eaa6d0
void Unk_eaa6d0_call(const Unk_eaa6d0* self) {
    Unk_eabd00(self->field_50);
}

struct Unk_eab4b0_58 {
    u8 _0[0x168];
    u32 field_168;
};
PKMN_OFFSET_ASSERT(Unk_eab4b0_58, field_168, 0x168);

struct Unk_eab4b0 {
    u8 _0[0x58];
    Unk_eab4b0_58* field_58;
};
PKMN_OFFSET_ASSERT(Unk_eab4b0, field_58, 0x58);

// 0x7100eab4b0
u32 Unk_eab4b0_get(const Unk_eab4b0* self) {
    return self->field_58->field_168;
}

struct Unk_eab4c0_58 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_eab4c0_58, field_0, 0x0);

struct Unk_eab4c0 {
    u8 _0[0x58];
    Unk_eab4c0_58* field_58;
};
PKMN_OFFSET_ASSERT(Unk_eab4c0, field_58, 0x58);

// 0x7100eab4c0
bool Unk_eab4c0_check(const Unk_eab4c0* self) {
    return self->field_58->field_0 != 0xffffffff;
}

struct Unk_eab4e0 {
    u8 _0[0x58];
    void* field_58;
};
PKMN_OFFSET_ASSERT(Unk_eab4e0, field_58, 0x58);

void Unk_eaacb0(void*);

// 0x7100eab4e0
void Unk_eab4e0_call(const Unk_eab4e0* self) {
    Unk_eaacb0(self->field_58);
}

// 0x7100eacf00
void Unk_eacf00_update() {}

// 0x7100eacf10
void Unk_eacf10_update() {}

// 0x7100eacf20
void Unk_eacf20_update() {}

// 0x7100eacfc0
void Unk_eacfc0_update() {}

// 0x7100eacfd0
void Unk_eacfd0_update() {}

// 0x7100eacfe0
void Unk_eacfe0_update() {}

// 0x7100ead020
void Unk_ead020_update() {}

struct Unk_ead030_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ead030_arg1, field_0, 0x0);

struct Unk_ead030 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ead030, field_0, 0x0);

// 0x7100ead030
void Unk_ead030_set(const Unk_ead030* self, Unk_ead030_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ead040_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ead040_arg1, field_0, 0x0);

struct Unk_ead040 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ead040, field_0, 0x0);

// 0x7100ead040
void Unk_ead040_set(const Unk_ead040* self, Unk_ead040_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100ead060
void Unk_ead060_update() {}

struct Unk_ead080_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ead080_arg1, field_0, 0x0);

struct Unk_ead080 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ead080, field_0, 0x0);

// 0x7100ead080
void Unk_ead080_set(const Unk_ead080* self, Unk_ead080_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ead090_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ead090_arg1, field_0, 0x0);

struct Unk_ead090 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ead090, field_0, 0x0);

// 0x7100ead090
void Unk_ead090_set(const Unk_ead090* self, Unk_ead090_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ead140 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_ead140, field_10, 0x10);

// 0x7100ead140
u64 Unk_ead140_getField10(const Unk_ead140* self) {
    return self->field_10;
}
