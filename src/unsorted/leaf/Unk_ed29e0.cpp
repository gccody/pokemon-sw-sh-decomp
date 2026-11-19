// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_ed29e0_148 {
    u8 _0[0x148];
    u64 field_148;
};
PKMN_OFFSET_ASSERT(Unk_ed29e0_148, field_148, 0x148);

struct Unk_ed29e0 {
    u8 _0[0x148];
    Unk_ed29e0_148* field_148;
};
PKMN_OFFSET_ASSERT(Unk_ed29e0, field_148, 0x148);

// 0x7100ed29e0
u64 Unk_ed29e0_get(const Unk_ed29e0* self) {
    return self->field_148->field_148;
}

struct Unk_ed2f20_148 {
    u8 _0[0xe0];
    u32 field_e0;
};
PKMN_OFFSET_ASSERT(Unk_ed2f20_148, field_e0, 0xe0);

struct Unk_ed2f20 {
    u8 _0[0x148];
    Unk_ed2f20_148* field_148;
};
PKMN_OFFSET_ASSERT(Unk_ed2f20, field_148, 0x148);

// 0x7100ed2f20
u32 Unk_ed2f20_get(const Unk_ed2f20* self) {
    return self->field_148->field_e0;
}

struct Unk_ed2f30_148 {
    u8 _0[0xec];
    u8 field_ec;
};
PKMN_OFFSET_ASSERT(Unk_ed2f30_148, field_ec, 0xec);

struct Unk_ed2f30 {
    u8 _0[0x148];
    Unk_ed2f30_148* field_148;
};
PKMN_OFFSET_ASSERT(Unk_ed2f30, field_148, 0x148);

// 0x7100ed2f30
u8 Unk_ed2f30_get(const Unk_ed2f30* self) {
    return self->field_148->field_ec;
}

struct Unk_ed30a0_148 {
    u8 _0[0x151];
    bool field_151;
};
PKMN_OFFSET_ASSERT(Unk_ed30a0_148, field_151, 0x151);

struct Unk_ed30a0 {
    u8 _0[0x148];
    Unk_ed30a0_148* field_148;
};
PKMN_OFFSET_ASSERT(Unk_ed30a0, field_148, 0x148);

// 0x7100ed30a0
void Unk_ed30a0_set(const Unk_ed30a0* self, bool value) {
    self->field_148->field_151 = value;
}

struct Unk_ed30b0_148 {
    u8 _0[0x180];
    bool field_180;
};
PKMN_OFFSET_ASSERT(Unk_ed30b0_148, field_180, 0x180);

struct Unk_ed30b0 {
    u8 _0[0x148];
    Unk_ed30b0_148* field_148;
};
PKMN_OFFSET_ASSERT(Unk_ed30b0, field_148, 0x148);

// 0x7100ed30b0
void Unk_ed30b0_set(const Unk_ed30b0* self, bool value) {
    self->field_148->field_180 = value;
}

struct Unk_ed30c0_148 {
    u8 _0[0x180];
    u8 field_180;
};
PKMN_OFFSET_ASSERT(Unk_ed30c0_148, field_180, 0x180);

struct Unk_ed30c0 {
    u8 _0[0x148];
    Unk_ed30c0_148* field_148;
};
PKMN_OFFSET_ASSERT(Unk_ed30c0, field_148, 0x148);

// 0x7100ed30c0
u8 Unk_ed30c0_get(const Unk_ed30c0* self) {
    return self->field_148->field_180;
}

struct Unk_ed30f0 {
    u8 _0[0x150];
    void* field_150;
};
PKMN_OFFSET_ASSERT(Unk_ed30f0, field_150, 0x150);

void Unk_5e1110(void*, void*, void*, u32);

// 0x7100ed30f0
void Unk_ed30f0_call(const Unk_ed30f0* self, void* value, void* arg2, u32 arg3) {
    Unk_5e1110(self->field_150, value, arg2, arg3);
}

struct Unk_ed3120_150 {
    u8 _0[0x78];
    u32 field_78;
};
PKMN_OFFSET_ASSERT(Unk_ed3120_150, field_78, 0x78);

struct Unk_ed3120 {
    u8 _0[0x150];
    Unk_ed3120_150* field_150;
};
PKMN_OFFSET_ASSERT(Unk_ed3120, field_150, 0x150);

// 0x7100ed3120
bool Unk_ed3120_check(const Unk_ed3120* self) {
    return self->field_150->field_78 == 0xffffffff;
}

struct Unk_ed32f0 {
    u8 _0[0x148];
    void* field_148;
};
PKMN_OFFSET_ASSERT(Unk_ed32f0, field_148, 0x148);

void Unk_ed3300(void*, u32);

// 0x7100ed32f0
void Unk_ed32f0_call(const Unk_ed32f0* self, bool value) {
    Unk_ed3300(self->field_148, value);
}

struct Unk_ed3380_148_188 {
    u8 _0[0x78];
    u32 field_78;
};
PKMN_OFFSET_ASSERT(Unk_ed3380_148_188, field_78, 0x78);

struct Unk_ed3380_148 {
    u8 _0[0x188];
    Unk_ed3380_148_188* field_188;
};
PKMN_OFFSET_ASSERT(Unk_ed3380_148, field_188, 0x188);

struct Unk_ed3380 {
    u8 _0[0x148];
    Unk_ed3380_148* field_148;
};
PKMN_OFFSET_ASSERT(Unk_ed3380, field_148, 0x148);

// 0x7100ed3380
bool Unk_ed3380_check(const Unk_ed3380* self) {
    if (self->field_148->field_188 == nullptr) {
        return false;
    }
    return self->field_148->field_188->field_78 == 0xffffffff;
}

struct Unk_ed33d0 {
    u8 _0[0x148];
    void* field_148;
};
PKMN_OFFSET_ASSERT(Unk_ed33d0, field_148, 0x148);

void Unk_ed33e0(void*, u32, void*);

// 0x7100ed33d0
void Unk_ed33d0_call(const Unk_ed33d0* self, u32 value, void* arg2) {
    Unk_ed33e0(self->field_148, value, arg2);
}

struct Unk_ed34f0_148_130 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14(u32, u32);
};

struct Unk_ed34f0_148 {
    u8 _0[0x130];
    Unk_ed34f0_148_130* field_130;
};
PKMN_OFFSET_ASSERT(Unk_ed34f0_148, field_130, 0x130);

struct Unk_ed34f0 {
    u8 _0[0x148];
    Unk_ed34f0_148* field_148;
};
PKMN_OFFSET_ASSERT(Unk_ed34f0, field_148, 0x148);

// 0x7100ed34f0
void Unk_ed34f0_call(const Unk_ed34f0* self, bool value) {
    if (self->field_148->field_130 != nullptr) {
        self->field_148->field_130->vf14(value, 0);
    }
}

struct Unk_ed3520_148_130 {
    u8 _0[0x78];
    u32 field_78;
};
PKMN_OFFSET_ASSERT(Unk_ed3520_148_130, field_78, 0x78);

struct Unk_ed3520_148 {
    u8 _0[0x130];
    Unk_ed3520_148_130* field_130;
};
PKMN_OFFSET_ASSERT(Unk_ed3520_148, field_130, 0x130);

struct Unk_ed3520 {
    u8 _0[0x148];
    Unk_ed3520_148* field_148;
};
PKMN_OFFSET_ASSERT(Unk_ed3520, field_148, 0x148);

// 0x7100ed3520
bool Unk_ed3520_check(const Unk_ed3520* self) {
    if (self->field_148->field_130 == nullptr) {
        return false;
    }
    return self->field_148->field_130->field_78 == 0xffffffff;
}

struct Unk_ed3650 {
    u8 _0[0x148];
    void* field_148;
};
PKMN_OFFSET_ASSERT(Unk_ed3650, field_148, 0x148);

void Unk_ed3660(void*, void*, u64);

// 0x7100ed3650
void Unk_ed3650_call(const Unk_ed3650* self, void* value, u64 arg2) {
    Unk_ed3660(self->field_148, value, arg2);
}

struct Unk_ed3830 {
    u8 _0[0x148];
    void* field_148;
};
PKMN_OFFSET_ASSERT(Unk_ed3830, field_148, 0x148);

void Unk_ed3840(void*);

// 0x7100ed3830
void Unk_ed3830_call(const Unk_ed3830* self) {
    Unk_ed3840(self->field_148);
}

struct Unk_ed3920_148 {
    u8 _0[0x108];
    void* field_108;
};
PKMN_OFFSET_ASSERT(Unk_ed3920_148, field_108, 0x108);

struct Unk_ed3920 {
    u8 _0[0x148];
    Unk_ed3920_148* field_148;
};
PKMN_OFFSET_ASSERT(Unk_ed3920, field_148, 0x148);

void Unk_68c490(void*, void*);

// 0x7100ed3920
void Unk_ed3920_call(const Unk_ed3920* self, void* value) {
    Unk_68c490(self->field_148->field_108, value);
}

struct Unk_ed3930_148 {
    u8 _0[0x108];
    void* field_108;
};
PKMN_OFFSET_ASSERT(Unk_ed3930_148, field_108, 0x108);

struct Unk_ed3930 {
    u8 _0[0x148];
    Unk_ed3930_148* field_148;
};
PKMN_OFFSET_ASSERT(Unk_ed3930, field_148, 0x148);

void Unk_68c510(void*, void*);

// 0x7100ed3930
void Unk_ed3930_call(const Unk_ed3930* self, void* value) {
    Unk_68c510(self->field_148->field_108, value);
}

struct Unk_ed3940_150 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14(u32, u32);
};

struct Unk_ed3940 {
    u8 _0[0x150];
    Unk_ed3940_150* field_150;
};
PKMN_OFFSET_ASSERT(Unk_ed3940, field_150, 0x150);

// 0x7100ed3940
void Unk_ed3940_call(const Unk_ed3940* self, bool value) {
    self->field_150->vf14(value, 0);
}

struct Unk_ed3ae0 {
    u8 _0[0x148];
    void* field_148;
};
PKMN_OFFSET_ASSERT(Unk_ed3ae0, field_148, 0x148);

void Unk_ed3af0(void*);

// 0x7100ed3ae0
void Unk_ed3ae0_call(const Unk_ed3ae0* self) {
    Unk_ed3af0(self->field_148);
}

struct Unk_ed3e40_148 {
    u8 _0[0x294];
    bool field_294;
};
PKMN_OFFSET_ASSERT(Unk_ed3e40_148, field_294, 0x294);

struct Unk_ed3e40 {
    u8 _0[0x148];
    Unk_ed3e40_148* field_148;
};
PKMN_OFFSET_ASSERT(Unk_ed3e40, field_148, 0x148);

// 0x7100ed3e40
void Unk_ed3e40_set(const Unk_ed3e40* self, bool value) {
    self->field_148->field_294 = value;
}

struct Unk_ed3e50_148 {
    u8 _0[0x294];
    u8 field_294;
};
PKMN_OFFSET_ASSERT(Unk_ed3e50_148, field_294, 0x294);

struct Unk_ed3e50 {
    u8 _0[0x148];
    Unk_ed3e50_148* field_148;
};
PKMN_OFFSET_ASSERT(Unk_ed3e50, field_148, 0x148);

// 0x7100ed3e50
u8 Unk_ed3e50_get(const Unk_ed3e50* self) {
    return self->field_148->field_294;
}

struct Unk_ed3eb0_148_128 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
};

struct Unk_ed3eb0_148 {
    u8 _0[0x128];
    Unk_ed3eb0_148_128* field_128;
};
PKMN_OFFSET_ASSERT(Unk_ed3eb0_148, field_128, 0x128);

struct Unk_ed3eb0 {
    u8 _0[0x148];
    Unk_ed3eb0_148* field_148;
};
PKMN_OFFSET_ASSERT(Unk_ed3eb0, field_148, 0x148);

// 0x7100ed3eb0
void Unk_ed3eb0_call(const Unk_ed3eb0* self) {
    self->field_148->field_128->vf11();
}

// 0x7100ed9430
void Unk_ed9430_update() {}

struct Unk_ed9440 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_ed9440, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ed9440, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_ed9440, field_10, 0x10);

// 0x7100ed9440
void Unk_ed9440_set(const Unk_ed9440* self, Unk_ed9440* value) {
    *value = *self;
}

struct Unk_ed9460 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_ed9460, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ed9460, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_ed9460, field_10, 0x10);

// 0x7100ed9460
void Unk_ed9460_set(const Unk_ed9460* self, Unk_ed9460* value) {
    *value = *self;
}

// 0x7100eda7c0
void Unk_eda7c0_update() {}

struct Unk_eda7d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_eda7d0_arg1, field_0, 0x0);

struct Unk_eda7d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_eda7d0, field_0, 0x0);

// 0x7100eda7d0
void Unk_eda7d0_set(const Unk_eda7d0* self, Unk_eda7d0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_eda7e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_eda7e0_arg1, field_0, 0x0);

struct Unk_eda7e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_eda7e0, field_0, 0x0);

// 0x7100eda7e0
void Unk_eda7e0_set(const Unk_eda7e0* self, Unk_eda7e0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100eda7f0
void Unk_eda7f0_update() {}

// 0x7100eda800
void Unk_eda800_update() {}

// 0x7100eda810
void Unk_eda810_update() {}

// 0x7100eda820
void Unk_eda820_update() {}

struct Unk_ede180 {
    u8 _0[0x78];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_ede180, field_78, 0x78);

void Unk_edb0b0(u64, u64, u64, u64);

// 0x7100ede180
void Unk_ede180_call(const Unk_ede180* self, u64 value, u64 arg2) {
    Unk_edb0b0(self->field_78, value, arg2, 0);
}

struct Unk_ede190 {
    u8 _0[0x78];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_ede190, field_78, 0x78);

void Unk_edb4e0(u64, u64, u64, u64);

// 0x7100ede190
void Unk_ede190_call(const Unk_ede190* self, u64 value, u64 arg2) {
    Unk_edb4e0(self->field_78, value, arg2, 0);
}

struct Unk_ede1a0 {
    u8 _0[0x78];
    void* field_78;
};
PKMN_OFFSET_ASSERT(Unk_ede1a0, field_78, 0x78);

void Unk_edb910(void*, void*);

// 0x7100ede1a0
void Unk_ede1a0_call(const Unk_ede1a0* self, void* value) {
    Unk_edb910(self->field_78, value);
}

struct Unk_ede1b0 {
    u8 _0[0x78];
    void* field_78;
};
PKMN_OFFSET_ASSERT(Unk_ede1b0, field_78, 0x78);

void Unk_edb9f0(void*, void*);

// 0x7100ede1b0
void Unk_ede1b0_call(const Unk_ede1b0* self, void* value) {
    Unk_edb9f0(self->field_78, value);
}

struct Unk_ede1c0 {
    u8 _0[0x78];
    void* field_78;
};
PKMN_OFFSET_ASSERT(Unk_ede1c0, field_78, 0x78);

void Unk_edbad0(void*, void*);

// 0x7100ede1c0
void Unk_ede1c0_call(const Unk_ede1c0* self, void* value) {
    Unk_edbad0(self->field_78, value);
}

struct Unk_ede1d0 {
    u8 _0[0x78];
    void* field_78;
};
PKMN_OFFSET_ASSERT(Unk_ede1d0, field_78, 0x78);

void Unk_edbbb0(void*, void*, void*);

// 0x7100ede1d0
void Unk_ede1d0_call(const Unk_ede1d0* self, void* value, void* arg2) {
    Unk_edbbb0(self->field_78, value, arg2);
}

struct Unk_ede1e0 {
    u8 _0[0x78];
    void* field_78;
};
PKMN_OFFSET_ASSERT(Unk_ede1e0, field_78, 0x78);

void Unk_edbcc0(void*, void*, void*);

// 0x7100ede1e0
void Unk_ede1e0_call(const Unk_ede1e0* self, void* value, void* arg2) {
    Unk_edbcc0(self->field_78, value, arg2);
}

struct Unk_ede1f0 {
    u8 _0[0x78];
    void* field_78;
};
PKMN_OFFSET_ASSERT(Unk_ede1f0, field_78, 0x78);

void Unk_edbdd0(void*, void*);

// 0x7100ede1f0
void Unk_ede1f0_call(const Unk_ede1f0* self, void* value) {
    Unk_edbdd0(self->field_78, value);
}

struct Unk_ede200 {
    u8 _0[0x78];
    void* field_78;
};
PKMN_OFFSET_ASSERT(Unk_ede200, field_78, 0x78);

void Unk_edc3d0(void*, void*);

// 0x7100ede200
void Unk_ede200_call(const Unk_ede200* self, void* value) {
    Unk_edc3d0(self->field_78, value);
}

struct Unk_ede210 {
    u8 _0[0x78];
    void* field_78;
};
PKMN_OFFSET_ASSERT(Unk_ede210, field_78, 0x78);

void Unk_edc9b0(void*, void*);

// 0x7100ede210
void Unk_ede210_call(const Unk_ede210* self, void* value) {
    Unk_edc9b0(self->field_78, value);
}

struct Unk_ede220 {
    u8 _0[0x78];
    void* field_78;
};
PKMN_OFFSET_ASSERT(Unk_ede220, field_78, 0x78);

void Unk_edcfb0(void*, void*);

// 0x7100ede220
void Unk_ede220_call(const Unk_ede220* self, void* value) {
    Unk_edcfb0(self->field_78, value);
}

struct Unk_ede230 {
    u8 _0[0x78];
    void* field_78;
};
PKMN_OFFSET_ASSERT(Unk_ede230, field_78, 0x78);

void Unk_edd150(void*, void*);

// 0x7100ede230
void Unk_ede230_call(const Unk_ede230* self, void* value) {
    Unk_edd150(self->field_78, value);
}

struct Unk_ede240 {
    u8 _0[0x78];
    void* field_78;
};
PKMN_OFFSET_ASSERT(Unk_ede240, field_78, 0x78);

void Unk_edd2d0(void*, void*);

// 0x7100ede240
void Unk_ede240_call(const Unk_ede240* self, void* value) {
    Unk_edd2d0(self->field_78, value);
}

struct Unk_ee38e0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_ee38e0, field_0, 0x0);

// 0x7100ee38e0
void Unk_ee38e0_call(Unk_ee38e0* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

// 0x7100ee3d80
void Unk_ee3d80_update() {}

// 0x7100ee3f60
void Unk_ee3f60_update() {}

// 0x7100ee3f70
void Unk_ee3f70_update() {}
