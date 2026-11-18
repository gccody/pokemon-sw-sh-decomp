// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_938ab0(void*, u64, u32, u32);

// 0x7100938aa0
void Unk_938aa0_call(void* self, u64 value, bool arg2) {
    Unk_938ab0(self, value, arg2, 0);
}

void Unk_938ab0(void*, u64, u32, u32);

// 0x7100938d00
void Unk_938d00_call(void* self, u64 value) {
    Unk_938ab0(self, value, 0, 0);
}

void Unk_9394d0(void*, u64, u32, u32);

// 0x7100939600
void Unk_939600_call(void* self, u64 value, bool arg2) {
    Unk_9394d0(self, value, arg2, 1);
}

void Unk_9394d0(void*, u64, u32, u32);

// 0x7100939610
void Unk_939610_call(void* self, u64 value, bool arg2) {
    Unk_9394d0(self, value, arg2, 2);
}

void Unk_9394d0(void*, u64, u32, u32);

// 0x7100939620
void Unk_939620_call(void* self, u64 value, bool arg2) {
    Unk_9394d0(self, value, arg2, 3);
}

struct Unk_939650 {
    u8 _0[0x38];
    u64 field_38;
};
PKMN_OFFSET_ASSERT(Unk_939650, field_38, 0x38);

// 0x7100939650
void Unk_939650_setField38(Unk_939650* self, u64 value) {
    self->field_38 = value;
}

struct Unk_93a2a0 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_93a2a0, field_20, 0x20);

void Unk_93d6e0(u64);

// 0x710093a2a0
void Unk_93a2a0_call(const Unk_93a2a0* self) {
    Unk_93d6e0(self->field_20);
}

// 0x710093c8b0
void Unk_93c8b0_update() {}

struct Unk_93c8c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_93c8c0_arg1, field_0, 0x0);

struct Unk_93c8c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_93c8c0, field_0, 0x0);

// 0x710093c8c0
void Unk_93c8c0_set(const Unk_93c8c0* self, Unk_93c8c0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_93c8d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_93c8d0_arg1, field_0, 0x0);

struct Unk_93c8d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_93c8d0, field_0, 0x0);

// 0x710093c8d0
void Unk_93c8d0_set(const Unk_93c8d0* self, Unk_93c8d0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_93cbb0 {
    u8 _0[0x68];
    u64 field_68;
};
PKMN_OFFSET_ASSERT(Unk_93cbb0, field_68, 0x68);

void Unk_67db60(u64);

// 0x710093cbb0
void Unk_93cbb0_call(const Unk_93cbb0* self) {
    if (self->field_68 != 0) {
        Unk_67db60(self->field_68);
    }
}

struct Unk_93cbe0 {
    u8 _0[0x68];
    u64 field_68;
};
PKMN_OFFSET_ASSERT(Unk_93cbe0, field_68, 0x68);

void Unk_1309ba0(u64);

// 0x710093cbe0
void Unk_93cbe0_call(const Unk_93cbe0* self) {
    if (self->field_68 != 0) {
        Unk_1309ba0(self->field_68);
    }
}

struct Unk_93cc10_70 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_93cc10_70, field_58, 0x58);

struct Unk_93cc10 {
    u8 _0[0x70];
    Unk_93cc10_70* field_70;
};
PKMN_OFFSET_ASSERT(Unk_93cc10, field_70, 0x70);

// 0x710093cc10
void Unk_93cc10_set(const Unk_93cc10* self, bool value) {
    if (self->field_70 != nullptr) {
        self->field_70->field_58 = (self->field_70->field_58 & 0xfffffffe) | (value);
    }
}

struct Unk_93cc30 {
    u8 _0[0x68];
    u64 field_68;
};
PKMN_OFFSET_ASSERT(Unk_93cc30, field_68, 0x68);

void Unk_1308930(u64, u64, u32);

// 0x710093cc30
void Unk_93cc30_call(const Unk_93cc30* self, u64 value) {
    if (self->field_68 != 0) {
        Unk_1308930(self->field_68, value, 0);
    }
}

struct Unk_1309a70;
struct Unk_93cc50 {
    u8 _0[0x68];
    Unk_1309a70* field_68;
};
PKMN_OFFSET_ASSERT(Unk_93cc50, field_68, 0x68);

void Unk_1309a70_set(Unk_1309a70*, bool);

// 0x710093cc50
void Unk_93cc50_call(const Unk_93cc50* self, bool value) {
    if (self->field_68 != nullptr) {
        Unk_1309a70_set(self->field_68, value);
    }
}

struct Unk_1309a80;
struct Unk_93cc70 {
    u8 _0[0x68];
    Unk_1309a80* field_68;
};
PKMN_OFFSET_ASSERT(Unk_93cc70, field_68, 0x68);

void Unk_1309a80_set(Unk_1309a80*);

// 0x710093cc70
void Unk_93cc70_call(const Unk_93cc70* self) {
    if (self->field_68 != nullptr) {
        Unk_1309a80_set(self->field_68);
    }
}

struct Unk_93cc80 {
    u8 _0[0x68];
    u64 field_68;
};
PKMN_OFFSET_ASSERT(Unk_93cc80, field_68, 0x68);

void Unk_67e9d0(u64);

// 0x710093cc80
void Unk_93cc80_call(const Unk_93cc80* self) {
    if (self->field_68 != 0) {
        Unk_67e9d0(self->field_68);
    }
}

struct Unk_93cc90_78 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_93cc90_78, field_58, 0x58);

struct Unk_93cc90 {
    u8 _0[0x78];
    Unk_93cc90_78* field_78;
    u8 _80[0x10];
    bool field_90;
};
PKMN_OFFSET_ASSERT(Unk_93cc90, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_93cc90, field_90, 0x90);

// 0x710093cc90
void Unk_93cc90_set(Unk_93cc90* self, bool value, bool arg2) {
    self->field_90 = value;
    self->field_78->field_58 = (self->field_78->field_58 & 0xfffffffe) | (arg2);
}

struct Unk_93ccb0 {
    u8 _0[0x68];
    u64 field_68;
};
PKMN_OFFSET_ASSERT(Unk_93ccb0, field_68, 0x68);

void Unk_67ea60(u64);

// 0x710093ccb0
void Unk_93ccb0_call(const Unk_93ccb0* self) {
    if (self->field_68 != 0) {
        Unk_67ea60(self->field_68);
    }
}

void Unk_eb6230(void*, u32);

// 0x710093d6d0
void Unk_93d6d0_call(void* self) {
    Unk_eb6230(self, 3);
}

// 0x710093fee0
void Unk_93fee0_update() {}

struct Unk_93fef0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_93fef0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_93fef0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_93fef0, field_10, 0x10);

// 0x710093fef0
void Unk_93fef0_set(const Unk_93fef0* self, Unk_93fef0* value) {
    *value = *self;
}

struct Unk_93ff10 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_93ff10, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_93ff10, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_93ff10, field_10, 0x10);

// 0x710093ff10
void Unk_93ff10_set(const Unk_93ff10* self, Unk_93ff10* value) {
    *value = *self;
}

struct Unk_952910 {
    u8 _0[0x4c8];
    u64 field_4c8;
};
PKMN_OFFSET_ASSERT(Unk_952910, field_4c8, 0x4c8);

void Unk_9a8190(u64);

// 0x7100952910
void Unk_952910_call(const Unk_952910* self) {
    Unk_9a8190(self->field_4c8);
}

struct Unk_952930 {
    u8 _0[0x4c8];
    u64 field_4c8;
};
PKMN_OFFSET_ASSERT(Unk_952930, field_4c8, 0x4c8);

void Unk_9a8a20(u64);

// 0x7100952930
void Unk_952930_call(const Unk_952930* self) {
    Unk_9a8a20(self->field_4c8);
}

struct Unk_953950_458 {
    u8 _0[0x90];
    u64 field_90;
    u64 field_98;
};
PKMN_OFFSET_ASSERT(Unk_953950_458, field_90, 0x90);
PKMN_OFFSET_ASSERT(Unk_953950_458, field_98, 0x98);

struct Unk_953950_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_953950_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_953950_arg1, field_8, 0x8);

struct Unk_953950 {
    u8 _0[0x458];
    Unk_953950_458* field_458;
};
PKMN_OFFSET_ASSERT(Unk_953950, field_458, 0x458);

// 0x7100953950
void Unk_953950_set(const Unk_953950* self, const Unk_953950_arg1* value) {
    Unk_953950_458* p0 = self->field_458;
    p0->field_98 = value->field_8;
    p0->field_90 = value->field_0;
}

struct Unk_95abc0 {
    u8 _0[0x608];
    u64 field_608;
};
PKMN_OFFSET_ASSERT(Unk_95abc0, field_608, 0x608);

void Unk_9bbed0(u64, u32);

// 0x710095abc0
void Unk_95abc0_call(const Unk_95abc0* self) {
    Unk_9bbed0(self->field_608, 4);
}

struct Unk_95abd0 {
    u8 _0[0xa0];
    u32 field_a0;
};
PKMN_OFFSET_ASSERT(Unk_95abd0, field_a0, 0xa0);

// 0x710095abd0
bool Unk_95abd0_check(const Unk_95abd0* self) {
    return self->field_a0 == 0;
}

struct Unk_95abe0 {
    u8 _0[0x608];
    u64 field_608;
};
PKMN_OFFSET_ASSERT(Unk_95abe0, field_608, 0x608);

void Unk_9bc580(u64);

// 0x710095abe0
void Unk_95abe0_call(const Unk_95abe0* self) {
    Unk_9bc580(self->field_608);
}
