// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_14bf040 {
    u8 _0[0x58];
    void* field_58;
};
PKMN_OFFSET_ASSERT(Unk_14bf040, field_58, 0x58);

void Unk_14bf050(void*);

// 0x71014bf040
void Unk_14bf040_call(const Unk_14bf040* self) {
    Unk_14bf050(self->field_58);
}

struct Unk_14bf2f0 {
    u8 _0[0x58];
    void* field_58;
};
PKMN_OFFSET_ASSERT(Unk_14bf2f0, field_58, 0x58);

void Unk_14bf300(void*);

// 0x71014bf2f0
void Unk_14bf2f0_call(const Unk_14bf2f0* self) {
    Unk_14bf300(self->field_58);
}

struct Unk_14bf490 {
    u8 _0[0x58];
    void* field_58;
};
PKMN_OFFSET_ASSERT(Unk_14bf490, field_58, 0x58);

void Unk_14bf4a0(void*);

// 0x71014bf490
void Unk_14bf490_call(const Unk_14bf490* self) {
    Unk_14bf4a0(self->field_58);
}

struct Unk_14bf750 {
    u8 _0[0x58];
    void* field_58;
};
PKMN_OFFSET_ASSERT(Unk_14bf750, field_58, 0x58);

void Unk_14bf760(void*, u32, void*);

// 0x71014bf750
void Unk_14bf750_call(const Unk_14bf750* self, u32 value, void* arg2) {
    Unk_14bf760(self->field_58, value, arg2);
}

struct Unk_14bfa40_58 {
    u8 _0[0x5b8];
    u32 field_5b8;
    u8 field_5bc;
};
PKMN_OFFSET_ASSERT(Unk_14bfa40_58, field_5b8, 0x5b8);
PKMN_OFFSET_ASSERT(Unk_14bfa40_58, field_5bc, 0x5bc);

struct Unk_14bfa40 {
    u8 _0[0x58];
    Unk_14bfa40_58* field_58;
};
PKMN_OFFSET_ASSERT(Unk_14bfa40, field_58, 0x58);

// 0x71014bfa40
void Unk_14bfa40_set(const Unk_14bfa40* self, u32 value) {
    Unk_14bfa40_58* p0 = self->field_58;
    p0->field_5b8 = value;
    p0->field_5bc = 1;
}

struct Unk_14bfa60_58 {
    u8 _0[0x5c8];
    u32 field_5c8;
    u8 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_14bfa60_58, field_5c8, 0x5c8);
PKMN_OFFSET_ASSERT(Unk_14bfa60_58, field_5cc, 0x5cc);

struct Unk_14bfa60 {
    u8 _0[0x58];
    Unk_14bfa60_58* field_58;
};
PKMN_OFFSET_ASSERT(Unk_14bfa60, field_58, 0x58);

// 0x71014bfa60
void Unk_14bfa60_set(const Unk_14bfa60* self, u32 value) {
    Unk_14bfa60_58* p0 = self->field_58;
    p0->field_5c8 = value;
    p0->field_5cc = 1;
}

struct Unk_14bfa80_58 {
    u8 _0[0x150];
    u32 field_150;
};
PKMN_OFFSET_ASSERT(Unk_14bfa80_58, field_150, 0x150);

struct Unk_14bfa80 {
    u8 _0[0x58];
    Unk_14bfa80_58* field_58;
};
PKMN_OFFSET_ASSERT(Unk_14bfa80, field_58, 0x58);

// 0x71014bfa80
void Unk_14bfa80_set(const Unk_14bfa80* self, u32 value) {
    self->field_58->field_150 = value;
}

struct Unk_14bfb70_58 {
    u8 _0[0x670];
    u8 field_670;
};
PKMN_OFFSET_ASSERT(Unk_14bfb70_58, field_670, 0x670);

struct Unk_14bfb70 {
    u8 _0[0x58];
    Unk_14bfb70_58* field_58;
};
PKMN_OFFSET_ASSERT(Unk_14bfb70, field_58, 0x58);

// 0x71014bfb70
u8 Unk_14bfb70_get(const Unk_14bfb70* self) {
    return self->field_58->field_670;
}

struct Unk_14bfb80_58 {
    u8 _0[0x66c];
    u32 field_66c;
};
PKMN_OFFSET_ASSERT(Unk_14bfb80_58, field_66c, 0x66c);

struct Unk_14bfb80 {
    u8 _0[0x58];
    Unk_14bfb80_58* field_58;
};
PKMN_OFFSET_ASSERT(Unk_14bfb80, field_58, 0x58);

// 0x71014bfb80
bool Unk_14bfb80_check(const Unk_14bfb80* self) {
    return (self->field_58->field_66c | 2) == 2;
}

struct Unk_14bfba0_58 {
    u8 _0[0x671];
    u8 field_671;
};
PKMN_OFFSET_ASSERT(Unk_14bfba0_58, field_671, 0x671);

struct Unk_14bfba0 {
    u8 _0[0x58];
    Unk_14bfba0_58* field_58;
};
PKMN_OFFSET_ASSERT(Unk_14bfba0, field_58, 0x58);

// 0x71014bfba0
u8 Unk_14bfba0_get(const Unk_14bfba0* self) {
    return self->field_58->field_671;
}

// 0x71014c33f0
void Unk_14c33f0_update() {}

struct Unk_14c3400 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_14c3400, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_14c3400, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_14c3400, field_10, 0x10);

// 0x71014c3400
void Unk_14c3400_set(const Unk_14c3400* self, Unk_14c3400* value) {
    *value = *self;
}

struct Unk_14c3420 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_14c3420, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_14c3420, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_14c3420, field_10, 0x10);

// 0x71014c3420
void Unk_14c3420_set(const Unk_14c3420* self, Unk_14c3420* value) {
    *value = *self;
}

struct Unk_14c5180_58 {
    u8 _0[0x89];
    u8 field_89;
};
PKMN_OFFSET_ASSERT(Unk_14c5180_58, field_89, 0x89);
struct Unk_14c5180 {
    u8 _0[0x58];
    Unk_14c5180_58* field_58;
};
PKMN_OFFSET_ASSERT(Unk_14c5180, field_58, 0x58);

// 0x71014c5180
u32 Unk_14c5180_update(const Unk_14c5180* self) {
    if (self->field_58->field_89 != 1) {
        if (self->field_58->field_89 == 0) {
            self->field_58->field_89 = 1;
            return 1;
        }
        return 0;
    }
    return 1;
}

struct Unk_14c51b0 {
    u8 _0[0x58];
    void* field_58;
};
PKMN_OFFSET_ASSERT(Unk_14c51b0, field_58, 0x58);

void Unk_14c51c0(void*);

// 0x71014c51b0
void Unk_14c51b0_call(const Unk_14c51b0* self) {
    Unk_14c51c0(self->field_58);
}

struct Unk_14c54f0_58 {
    u8 _0[0x68];
    u32 field_68;
    u8 _6c[0x4];
    u64 field_70;
};
PKMN_OFFSET_ASSERT(Unk_14c54f0_58, field_68, 0x68);
PKMN_OFFSET_ASSERT(Unk_14c54f0_58, field_70, 0x70);

struct Unk_14c54f0 {
    u8 _0[0x58];
    Unk_14c54f0_58* field_58;
};
PKMN_OFFSET_ASSERT(Unk_14c54f0, field_58, 0x58);

// 0x71014c54f0
void Unk_14c54f0_set(const Unk_14c54f0* self, u64 value) {
    Unk_14c54f0_58* p0 = self->field_58;
    p0->field_68 = 1;
    p0->field_70 = value;
}

struct Unk_14c5510_58 {
    u8 _0[0x68];
    u32 field_68;
};
PKMN_OFFSET_ASSERT(Unk_14c5510_58, field_68, 0x68);

struct Unk_14c5510 {
    u8 _0[0x58];
    Unk_14c5510_58* field_58;
};
PKMN_OFFSET_ASSERT(Unk_14c5510, field_58, 0x58);

// 0x71014c5510
void Unk_14c5510_set(const Unk_14c5510* self) {
    self->field_58->field_68 = 2;
}

struct Unk_14c57f0 {
    u8 _0[0x58];
    void* field_58;
};
PKMN_OFFSET_ASSERT(Unk_14c57f0, field_58, 0x58);

void Unk_14c5800(void*, u32);

// 0x71014c57f0
void Unk_14c57f0_call(const Unk_14c57f0* self, u32 value) {
    Unk_14c5800(self->field_58, value);
}

struct Unk_14c59f0 {
    u8 _0[0x58];
    void* field_58;
};
PKMN_OFFSET_ASSERT(Unk_14c59f0, field_58, 0x58);

void Unk_14c5a00(void*, u32);

// 0x71014c59f0
void Unk_14c59f0_call(const Unk_14c59f0* self, u32 value) {
    Unk_14c5a00(self->field_58, value);
}

struct Unk_14c5bf0 {
    u8 _0[0x58];
    void* field_58;
};
PKMN_OFFSET_ASSERT(Unk_14c5bf0, field_58, 0x58);

void Unk_14c5c00(void*);

// 0x71014c5bf0
void Unk_14c5bf0_call(const Unk_14c5bf0* self) {
    Unk_14c5c00(self->field_58);
}

struct Unk_14c5e60_58 {
    u8 _0[0x88];
    u8 field_88;
};
PKMN_OFFSET_ASSERT(Unk_14c5e60_58, field_88, 0x88);

struct Unk_14c5e60 {
    u8 _0[0x58];
    Unk_14c5e60_58* field_58;
};
PKMN_OFFSET_ASSERT(Unk_14c5e60, field_58, 0x58);

// 0x71014c5e60
u8 Unk_14c5e60_get(const Unk_14c5e60* self) {
    return self->field_58->field_88;
}

struct Unk_14c5e70_58 {
    u8 _0[0x88];
    u8 field_88;
};
PKMN_OFFSET_ASSERT(Unk_14c5e70_58, field_88, 0x88);

struct Unk_14c5e70 {
    u8 _0[0x58];
    Unk_14c5e70_58* field_58;
};
PKMN_OFFSET_ASSERT(Unk_14c5e70, field_58, 0x58);

// 0x71014c5e70
bool Unk_14c5e70_check(const Unk_14c5e70* self) {
    return self->field_58->field_88 == 0;
}

struct Unk_14c93e0 {
    u8 _0[0x58];
    void* field_58;
};
PKMN_OFFSET_ASSERT(Unk_14c93e0, field_58, 0x58);

void Unk_14c93f0(void*);

// 0x71014c93e0
void Unk_14c93e0_call(const Unk_14c93e0* self) {
    Unk_14c93f0(self->field_58);
}

struct Unk_14c9740 {
    u8 _0[0x58];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_14c9740, field_58, 0x58);

void Unk_14c9750(u64, u32, u32, u32);

// 0x71014c9740
void Unk_14c9740_call(const Unk_14c9740* self, u32 value, u32 arg2, u32 arg3) {
    Unk_14c9750(self->field_58, value, arg2, arg3);
}

// 0x71014ca680
void Unk_14ca680_update() {}

struct Unk_14ca690 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_14ca690, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_14ca690, field_8, 0x8);

// 0x71014ca690
void Unk_14ca690_set(const Unk_14ca690* self, Unk_14ca690* value) {
    *value = *self;
}

struct Unk_14ca6a0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_14ca6a0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_14ca6a0, field_8, 0x8);

// 0x71014ca6a0
void Unk_14ca6a0_set(const Unk_14ca6a0* self, Unk_14ca6a0* value) {
    *value = *self;
}

struct Unk_14cae50 {
    u8 _0[0x58];
    void* field_58;
};
PKMN_OFFSET_ASSERT(Unk_14cae50, field_58, 0x58);

void Unk_14ccbd0(void*);

// 0x71014cae50
void Unk_14cae50_call(const Unk_14cae50* self) {
    Unk_14ccbd0(self->field_58);
}

struct Unk_14cae60 {
    u8 _0[0x58];
    void* field_58;
};
PKMN_OFFSET_ASSERT(Unk_14cae60, field_58, 0x58);

void Unk_14cae70(void*);

// 0x71014cae60
void Unk_14cae60_call(const Unk_14cae60* self) {
    Unk_14cae70(self->field_58);
}

struct Unk_14cc350 {
    u8 _0[0x58];
    void* field_58;
};
PKMN_OFFSET_ASSERT(Unk_14cc350, field_58, 0x58);

void Unk_14cc360(void*, void*, void*);

// 0x71014cc350
void Unk_14cc350_call(const Unk_14cc350* self, void* value, void* arg2) {
    Unk_14cc360(self->field_58, value, arg2);
}

struct Unk_14cc490 {
    u8 _0[0x58];
    void* field_58;
};
PKMN_OFFSET_ASSERT(Unk_14cc490, field_58, 0x58);

void Unk_14cc4a0(void*, u32);

// 0x71014cc490
void Unk_14cc490_call(const Unk_14cc490* self, u32 value) {
    Unk_14cc4a0(self->field_58, value);
}

struct Unk_14cc6e0 {
    u8 _0[0x58];
    void* field_58;
};
PKMN_OFFSET_ASSERT(Unk_14cc6e0, field_58, 0x58);

void Unk_14cc6f0(void*);

// 0x71014cc6e0
void Unk_14cc6e0_call(const Unk_14cc6e0* self) {
    Unk_14cc6f0(self->field_58);
}

struct Unk_14cc8c0 {
    u8 _0[0x58];
    void* field_58;
};
PKMN_OFFSET_ASSERT(Unk_14cc8c0, field_58, 0x58);

void Unk_14d1b20(void*);

// 0x71014cc8c0
void Unk_14cc8c0_call(const Unk_14cc8c0* self) {
    Unk_14d1b20(self->field_58);
}

struct Unk_14cc8d0 {
    u8 _0[0x58];
    void* field_58;
};
PKMN_OFFSET_ASSERT(Unk_14cc8d0, field_58, 0x58);

void Unk_14cc8e0(void*);

// 0x71014cc8d0
void Unk_14cc8d0_call(const Unk_14cc8d0* self) {
    Unk_14cc8e0(self->field_58);
}

// 0x71014ce010
void Unk_14ce010_update() {}

struct Unk_14ce020 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_14ce020, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_14ce020, field_8, 0x8);

// 0x71014ce020
void Unk_14ce020_set(const Unk_14ce020* self, Unk_14ce020* value) {
    *value = *self;
}

struct Unk_14ce030 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_14ce030, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_14ce030, field_8, 0x8);

// 0x71014ce030
void Unk_14ce030_set(const Unk_14ce030* self, Unk_14ce030* value) {
    *value = *self;
}

// 0x71014ce060
void Unk_14ce060_update() {}

struct Unk_14ce070_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_14ce070_arg1, field_0, 0x0);

struct Unk_14ce070 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_14ce070, field_0, 0x0);

// 0x71014ce070
void Unk_14ce070_set(const Unk_14ce070* self, Unk_14ce070_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_14ce080_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_14ce080_arg1, field_0, 0x0);

struct Unk_14ce080 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_14ce080, field_0, 0x0);

// 0x71014ce080
void Unk_14ce080_set(const Unk_14ce080* self, Unk_14ce080_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_14ce090_0 {
    u8 _0[0xf58];
    u8 field_f58;
};
PKMN_OFFSET_ASSERT(Unk_14ce090_0, field_f58, 0xf58);

struct Unk_14ce090 {
    Unk_14ce090_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_14ce090, field_0, 0x0);

// 0x71014ce090
void Unk_14ce090_set(const Unk_14ce090* self) {
    self->field_0->field_f58 = 1;
}

// 0x71014ce0a0
void Unk_14ce0a0_update() {}

struct Unk_14ce0b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_14ce0b0_arg1, field_0, 0x0);

struct Unk_14ce0b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_14ce0b0, field_0, 0x0);

// 0x71014ce0b0
void Unk_14ce0b0_set(const Unk_14ce0b0* self, Unk_14ce0b0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_14ce0c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_14ce0c0_arg1, field_0, 0x0);

struct Unk_14ce0c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_14ce0c0, field_0, 0x0);

// 0x71014ce0c0
void Unk_14ce0c0_set(const Unk_14ce0c0* self, Unk_14ce0c0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71014ce1c0
void Unk_14ce1c0_update() {}

struct Unk_14ce1d0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_14ce1d0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_14ce1d0, field_8, 0x8);

// 0x71014ce1d0
void Unk_14ce1d0_set(const Unk_14ce1d0* self, Unk_14ce1d0* value) {
    *value = *self;
}

struct Unk_14ce1e0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_14ce1e0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_14ce1e0, field_8, 0x8);

// 0x71014ce1e0
void Unk_14ce1e0_set(const Unk_14ce1e0* self, Unk_14ce1e0* value) {
    *value = *self;
}

struct Unk_14d1390_arg1 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_14d1390_arg1, field_58, 0x58);

// 0x71014d1390
void Unk_14d1390_set(void* /*unused*/, Unk_14d1390_arg1* value) {
    value->field_58 = value->field_58 | 1;
}

// 0x71014d13c0
void Unk_14d13c0_update() {}

struct Unk_14d13d0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_14d13d0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_14d13d0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_14d13d0, field_10, 0x10);

// 0x71014d13d0
void Unk_14d13d0_set(const Unk_14d13d0* self, Unk_14d13d0* value) {
    *value = *self;
}

struct Unk_14d13f0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_14d13f0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_14d13f0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_14d13f0, field_10, 0x10);

// 0x71014d13f0
void Unk_14d13f0_set(const Unk_14d13f0* self, Unk_14d13f0* value) {
    *value = *self;
}

struct Unk_14d3f20_5f8 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_14d3f20_5f8, field_58, 0x58);

struct Unk_14d3f20 {
    u8 _0[0x5f8];
    Unk_14d3f20_5f8* field_5f8;
};
PKMN_OFFSET_ASSERT(Unk_14d3f20, field_5f8, 0x5f8);

// 0x71014d3f20
void Unk_14d3f20_set(const Unk_14d3f20* self, bool value) {
    if (self->field_5f8 != nullptr) {
        self->field_5f8->field_58 = (self->field_5f8->field_58 & 0xfffffffe) | (value);
    }
}

struct Unk_14d44d0_600 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_14d44d0_600, field_58, 0x58);

struct Unk_14d44d0 {
    u8 _0[0x600];
    Unk_14d44d0_600* field_600;
};
PKMN_OFFSET_ASSERT(Unk_14d44d0, field_600, 0x600);

// 0x71014d44d0
void Unk_14d44d0_set(const Unk_14d44d0* self, bool value) {
    self->field_600->field_58 = (self->field_600->field_58 & 0xfffffffe) | (value);
}

struct Unk_14d5250_78 {
    u8 _0[0x170];
    u8 field_170;
};
PKMN_OFFSET_ASSERT(Unk_14d5250_78, field_170, 0x170);

struct Unk_14d5250 {
    u8 _0[0x78];
    Unk_14d5250_78* field_78;
};
PKMN_OFFSET_ASSERT(Unk_14d5250, field_78, 0x78);

// 0x71014d5250
bool Unk_14d5250_check(const Unk_14d5250* self) {
    if (self->field_78 == nullptr) {
        return false;
    }
    return self->field_78->field_170 != 0;
}

struct Unk_14d5270 {
    u8 _0[0x60];
    void* field_60;
};
PKMN_OFFSET_ASSERT(Unk_14d5270, field_60, 0x60);

void Unk_68f670(void*, u64);

// 0x71014d5270
void Unk_14d5270_call(const Unk_14d5270* self, u64 value) {
    Unk_68f670(self->field_60, value);
}

void Unk_14d5290(void*);

// 0x71014d5280
void Unk_14d5280_call(void* self) {
    Unk_14d5290(self);
}

struct Unk_14d5a10_68 {
    u8 _0[0x170];
    u8 field_170;
};
PKMN_OFFSET_ASSERT(Unk_14d5a10_68, field_170, 0x170);

struct Unk_14d5a10 {
    u8 _0[0x68];
    Unk_14d5a10_68* field_68;
};
PKMN_OFFSET_ASSERT(Unk_14d5a10, field_68, 0x68);

// 0x71014d5a10
u8 Unk_14d5a10_get(const Unk_14d5a10* self) {
    if (self->field_68 == nullptr) {
        return 0;
    }
    return self->field_68->field_170;
}

struct Unk_14d5a80 {
    u8 _0[0x68];
    u64 field_68;
};
PKMN_OFFSET_ASSERT(Unk_14d5a80, field_68, 0x68);

// 0x71014d5a80
bool Unk_14d5a80_check(const Unk_14d5a80* self) {
    return self->field_68 == 0;
}

struct Unk_14d6820_68 {
    u8 _0[0x170];
    u8 field_170;
};
PKMN_OFFSET_ASSERT(Unk_14d6820_68, field_170, 0x170);

struct Unk_14d6820 {
    u8 _0[0x68];
    Unk_14d6820_68* field_68;
};
PKMN_OFFSET_ASSERT(Unk_14d6820, field_68, 0x68);

// 0x71014d6820
bool Unk_14d6820_check(const Unk_14d6820* self) {
    if (self->field_68 == nullptr) {
        return false;
    }
    return self->field_68->field_170 != 0;
}

struct Unk_14d6890 {
    u8 _0[0x68];
    u64 field_68;
};
PKMN_OFFSET_ASSERT(Unk_14d6890, field_68, 0x68);

// 0x71014d6890
bool Unk_14d6890_check(const Unk_14d6890* self) {
    return self->field_68 == 0;
}

struct Unk_14d8890 {
    u8 _0[0x98];
    u32 field_98;
};
PKMN_OFFSET_ASSERT(Unk_14d8890, field_98, 0x98);

void Unk_14d88a0(void*, u32);

// 0x71014d8890
void Unk_14d8890_call(Unk_14d8890* self) {
    Unk_14d88a0(self, self->field_98);
}

struct Unk_14d9c20 {
    u8 _0[0x16c];
    u32 field_16c;
    u32 field_170;
    u32 field_174;
    u32 field_178;
    u8 _17c[0x1c];
    u8 field_198;
};
PKMN_OFFSET_ASSERT(Unk_14d9c20, field_16c, 0x16c);
PKMN_OFFSET_ASSERT(Unk_14d9c20, field_170, 0x170);
PKMN_OFFSET_ASSERT(Unk_14d9c20, field_174, 0x174);
PKMN_OFFSET_ASSERT(Unk_14d9c20, field_178, 0x178);
PKMN_OFFSET_ASSERT(Unk_14d9c20, field_198, 0x198);

// 0x71014d9c20
void Unk_14d9c20_set(Unk_14d9c20* self, u32 value, u32 arg2, u32 arg3, u32 arg4) {
    self->field_174 = value;
    self->field_16c = arg2;
    self->field_170 = arg3;
    self->field_178 = arg4;
    self->field_198 = 1;
}

struct Unk_14d9fe0 {
    u8 _0[0x188];
    void* field_188;
};
PKMN_OFFSET_ASSERT(Unk_14d9fe0, field_188, 0x188);

void Unk_142aa00(void*);

// 0x71014d9fe0
void Unk_14d9fe0_call(const Unk_14d9fe0* self) {
    Unk_142aa00(self->field_188);
}

struct Unk_14dbb00 {
    u8 _0[0x68];
    u64 field_68;
};
PKMN_OFFSET_ASSERT(Unk_14dbb00, field_68, 0x68);

// 0x71014dbb00
bool Unk_14dbb00_check(const Unk_14dbb00* self) {
    return self->field_68 == 0;
}

struct Unk_14e0840_arg1 {
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 field_3;
};
PKMN_OFFSET_ASSERT(Unk_14e0840_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_14e0840_arg1, field_1, 0x1);
PKMN_OFFSET_ASSERT(Unk_14e0840_arg1, field_2, 0x2);
PKMN_OFFSET_ASSERT(Unk_14e0840_arg1, field_3, 0x3);
void Unk_14e0350(void*, u32, u32);
void Unk_14e0450(void*, u32, u32);

// 0x71014e0840
void Unk_14e0840_call(void* self, const Unk_14e0840_arg1* value) {
    if (value->field_1 != 0) {
        Unk_14e0350(self, 1, 1);
        if (value->field_2 != 0) {
            Unk_14e0350(self, 2, 1);
            if (value->field_3 != 0) {
                Unk_14e0350(self, 4, 1);
                if (value->field_0 != 0) {
                    return;
                }
                Unk_14e0450(self, 0, 0);
                return;
            }
            if (value->field_0 != 0) {
                return;
            }
            Unk_14e0450(self, 0, 0);
            return;
        }
        if (value->field_3 != 0) {
            Unk_14e0350(self, 4, 1);
            if (value->field_0 != 0) {
                return;
            }
            Unk_14e0450(self, 0, 0);
            return;
        }
        if (value->field_0 != 0) {
            return;
        }
        Unk_14e0450(self, 0, 0);
        return;
    }
    if (value->field_2 != 0) {
        Unk_14e0350(self, 2, 1);
        if (value->field_3 != 0) {
            Unk_14e0350(self, 4, 1);
            if (value->field_0 != 0) {
                return;
            }
            Unk_14e0450(self, 0, 0);
            return;
        }
        if (value->field_0 != 0) {
            return;
        }
        Unk_14e0450(self, 0, 0);
        return;
    }
    if (value->field_3 != 0) {
        Unk_14e0350(self, 4, 1);
        if (value->field_0 != 0) {
            return;
        }
        Unk_14e0450(self, 0, 0);
        return;
    }
    if (value->field_0 != 0) {
        return;
    }
    Unk_14e0450(self, 0, 0);
}

struct Unk_27f17cc_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27f17cc_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27f17cc_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27f17cc_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27f17cc_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27f17cc_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27f17cc_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27f17cc_Data, field_18, 0x18);

extern Unk_27f17cc_Data Unk_27f17cc __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71014e1460
void Unk_14e1460_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27f17cc.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27f17cc.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27f17cc.field_18 = 0xffff;
    Unk_27f17cc.field_10 = 0;
    Unk_27f17cc.field_8 = r2;
    Unk_27f17cc.field_c = 0;
    Unk_27f17cc.field_14 = 0xffffffff;
}
