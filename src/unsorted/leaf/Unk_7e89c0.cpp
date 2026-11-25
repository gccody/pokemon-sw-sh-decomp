// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_7e89c0 {
    u8 field_0;
    u8 _1[0x3];
    u32 field_4;
};
PKMN_OFFSET_ASSERT(Unk_7e89c0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_7e89c0, field_4, 0x4);

// 0x71007e89c0
void Unk_7e89c0_set(Unk_7e89c0* self) {
    self->field_0 = 5;
    self->field_4 = 5;
}

struct Unk_7e89d0 {
    u8 field_0;
    u8 _1[0x3];
    u32 field_4;
};
PKMN_OFFSET_ASSERT(Unk_7e89d0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_7e89d0, field_4, 0x4);

// 0x71007e89d0
void Unk_7e89d0_set(Unk_7e89d0* self) {
    self->field_0 = 5;
    self->field_4 = 5;
}

struct Unk_7e89e0 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7e89e0, field_0, 0x0);

// 0x71007e89e0
u8 Unk_7e89e0_getField0(const Unk_7e89e0* self) {
    return self->field_0;
}

struct Unk_7e89f0 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7e89f0, field_0, 0x0);

// 0x71007e89f0
void Unk_7e89f0_setField0(Unk_7e89f0* self, u8 value) {
    self->field_0 = value;
}

struct Unk_7e8a00 {
    u8 _0[0x4];
    u32 field_4;
};
PKMN_OFFSET_ASSERT(Unk_7e8a00, field_4, 0x4);

// 0x71007e8a00
u32 Unk_7e8a00_getField4(const Unk_7e8a00* self) {
    return self->field_4;
}

struct Unk_7e8a10 {
    u8 _0[0x4];
    u32 field_4;
};
PKMN_OFFSET_ASSERT(Unk_7e8a10, field_4, 0x4);

// 0x71007e8a10
void Unk_7e8a10_setField4(Unk_7e8a10* self, u32 value) {
    self->field_4 = value;
}

struct Unk_7e8c30 {
    u8 _0[0x30];
    void* field_30;
    u8 _38[0x18];
    void* field_50;
    u8 _58[0x18];
    u64 field_70;
    u32 field_78;
};
PKMN_OFFSET_ASSERT(Unk_7e8c30, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_7e8c30, field_50, 0x50);
PKMN_OFFSET_ASSERT(Unk_7e8c30, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_7e8c30, field_78, 0x78);

void Unk_7ea110(void*);
void Unk_7ea5d0(void*);

// 0x71007e8c30
void Unk_7e8c30_call(Unk_7e8c30* self) {
    self->field_78 = 0;
    self->field_70 = 0;
    Unk_7ea5d0(self->field_50);
    Unk_7ea110(self->field_30);
}

struct Unk_7fe240;
struct Unk_7e8c60 {
    u8 _0[0x8];
    Unk_7fe240* field_8;
};
PKMN_OFFSET_ASSERT(Unk_7e8c60, field_8, 0x8);

u64 Unk_7fe240_getField88(const Unk_7fe240*);

// 0x71007e8c60
void Unk_7e8c60_call(const Unk_7e8c60* self) {
    Unk_7fe240_getField88(self->field_8);
}

void Unk_7e8f70(void*, u64, u32, u32);

// 0x71007e8f60
void Unk_7e8f60_call(void* self, u64 value) {
    Unk_7e8f70(self, value, 9, 1);
}

void Unk_7e8f70(void*, u64, u32, u32);

// 0x71007e9050
void Unk_7e9050_call(void* self, u64 value) {
    Unk_7e8f70(self, value, 9, 0);
}

struct Unk_7e9970 {
    u8 _0[0x10];
    u64 field_10;
    u64 field_18;
    u64 field_20;
    u64 field_28;
    u64 field_30;
    u64 field_38;
    u64 field_40;
    u64 field_48;
    u64 field_50;
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_7e9970, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_7e9970, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_7e9970, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_7e9970, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_7e9970, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_7e9970, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_7e9970, field_40, 0x40);
PKMN_OFFSET_ASSERT(Unk_7e9970, field_48, 0x48);
PKMN_OFFSET_ASSERT(Unk_7e9970, field_50, 0x50);
PKMN_OFFSET_ASSERT(Unk_7e9970, field_58, 0x58);

// 0x71007e9970
void Unk_7e9970_set(Unk_7e9970* self) {
    self->field_50 = 0;
    self->field_58 = 0;
    self->field_40 = 0;
    self->field_48 = 0;
    self->field_30 = 0;
    self->field_38 = 0;
    self->field_20 = 0;
    self->field_28 = 0;
    self->field_10 = 0;
    self->field_18 = 0;
}

struct Unk_7e99e0 {
    u8 _0[0x8];
    u16 field_8;
};
PKMN_OFFSET_ASSERT(Unk_7e99e0, field_8, 0x8);

// 0x71007e99e0
u16 Unk_7e99e0_getField8(const Unk_7e99e0* self) {
    return self->field_8;
}

struct Unk_7e99f0 {
    u8 _0[0x40];
    u64 field_40;
    u64 field_48;
    u64 field_50;
    u32 field_58;
};
PKMN_OFFSET_ASSERT(Unk_7e99f0, field_40, 0x40);
PKMN_OFFSET_ASSERT(Unk_7e99f0, field_48, 0x48);
PKMN_OFFSET_ASSERT(Unk_7e99f0, field_50, 0x50);
PKMN_OFFSET_ASSERT(Unk_7e99f0, field_58, 0x58);

// 0x71007e99f0
void Unk_7e99f0_set(Unk_7e99f0* self) {
    self->field_58 = 0;
    self->field_48 = 0;
    self->field_50 = 0;
    self->field_40 = 0;
}

struct Unk_7e9a20 {
    u8 _0[0x3c];
    u32 field_3c;
};
PKMN_OFFSET_ASSERT(Unk_7e9a20, field_3c, 0x3c);

// 0x71007e9a20
void Unk_7e9a20_set(Unk_7e9a20* self) {
    self->field_3c = self->field_3c | 0x10000000;
}

struct Unk_7e9a50 {
    u8 _0[0x3c];
    u32 field_3c;
};
PKMN_OFFSET_ASSERT(Unk_7e9a50, field_3c, 0x3c);

// 0x71007e9a50
void Unk_7e9a50_set(Unk_7e9a50* self) {
    self->field_3c = self->field_3c & 0xfdffffff;
}

struct Unk_7e9a60 {
    u8 _0[0x3b];
    u8 field_3b;
};
PKMN_OFFSET_ASSERT(Unk_7e9a60, field_3b, 0x3b);

// 0x71007e9a60
u8 Unk_7e9a60_getField3b(const Unk_7e9a60* self) {
    return self->field_3b;
}

struct Unk_7e9a70 {
    u8 _0[0x28];
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_7e9a70, field_28, 0x28);

// 0x71007e9a70
void Unk_7e9a70_setField28(Unk_7e9a70* self, u64 value) {
    self->field_28 = value;
}

struct Unk_7e9a80 {
    u8 _0[0x28];
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_7e9a80, field_28, 0x28);

// 0x71007e9a80
void Unk_7e9a80_clearField28(Unk_7e9a80* self) {
    self->field_28 = 0;
}

struct Unk_7e9a90 {
    u8 _0[0x28];
    u64 field_28;
};
PKMN_OFFSET_ASSERT(Unk_7e9a90, field_28, 0x28);

// 0x71007e9a90
u64 Unk_7e9a90_getField28(const Unk_7e9a90* self) {
    return self->field_28;
}

struct Unk_7e9aa0 {
    u8 _0[0x30];
    u8 field_30;
};
PKMN_OFFSET_ASSERT(Unk_7e9aa0, field_30, 0x30);

// 0x71007e9aa0
void Unk_7e9aa0_set(Unk_7e9aa0* self) {
    self->field_30 = 8;
}

struct Unk_7e9ab0 {
    u8 _0[0x30];
    u8 field_30;
};
PKMN_OFFSET_ASSERT(Unk_7e9ab0, field_30, 0x30);

// 0x71007e9ab0
bool Unk_7e9ab0_check(const Unk_7e9ab0* self) {
    return self->field_30 == 8;
}

struct Unk_7e9ac0 {
    u8 _0[0x3c];
    u32 field_3c;
};
PKMN_OFFSET_ASSERT(Unk_7e9ac0, field_3c, 0x3c);

// 0x71007e9ac0
u32 Unk_7e9ac0_update(Unk_7e9ac0* self) {
    if ((self->field_3c & 0x8000000) != 0) {
        return 0;
    }
    self->field_3c = self->field_3c | 0x8000000;
    return 1;
}

struct Unk_7e9ae0 {
    u8 _0[0x3c];
    u32 field_3c;
};
PKMN_OFFSET_ASSERT(Unk_7e9ae0, field_3c, 0x3c);

// 0x71007e9ae0
u32 Unk_7e9ae0_update(Unk_7e9ae0* self) {
    if ((self->field_3c & 0x8000000) == 0) {
        return 0;
    }
    self->field_3c = self->field_3c & 0xf7ffffff;
    return 1;
}

struct Unk_7e9b30 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_7e9b30, field_18, 0x18);

// 0x71007e9b30
u64 Unk_7e9b30_getField18(const Unk_7e9b30* self) {
    return self->field_18;
}

struct Unk_7e9b40 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_7e9b40, field_10, 0x10);

// 0x71007e9b40
u64 Unk_7e9b40_getField10(const Unk_7e9b40* self) {
    return self->field_10;
}

struct Unk_7e9b50 {
    u8 _0[0x3c];
    u32 field_3c;
};
PKMN_OFFSET_ASSERT(Unk_7e9b50, field_3c, 0x3c);

// 0x71007e9b50
u32 Unk_7e9b50_getField3c(const Unk_7e9b50* self) {
    return self->field_3c;
}

struct Unk_7e9b60 {
    u8 _0[0x3c];
    u16 field_3c;
};
PKMN_OFFSET_ASSERT(Unk_7e9b60, field_3c, 0x3c);

// 0x71007e9b60
void Unk_7e9b60_setField3c(Unk_7e9b60* self, u16 value) {
    self->field_3c = value;
}

struct Unk_7e9b70 {
    u8 _0[0x30];
    u8 field_30;
};
PKMN_OFFSET_ASSERT(Unk_7e9b70, field_30, 0x30);

// 0x71007e9b70
u8 Unk_7e9b70_getField30(const Unk_7e9b70* self) {
    return self->field_30;
}

struct Unk_7e9b80 {
    u8 _0[0x34];
    u32 field_34;
};
PKMN_OFFSET_ASSERT(Unk_7e9b80, field_34, 0x34);

// 0x71007e9b80
u32 Unk_7e9b80_getField34(const Unk_7e9b80* self) {
    return self->field_34;
}

struct Unk_7e9b90 {
    u8 _0[0x3a];
    u8 field_3a;
};
PKMN_OFFSET_ASSERT(Unk_7e9b90, field_3a, 0x3a);

// 0x71007e9b90
u8 Unk_7e9b90_getField3a(const Unk_7e9b90* self) {
    return self->field_3a;
}

struct Unk_7e9ba0 {
    u8 _0[0x38];
    u16 field_38;
};
PKMN_OFFSET_ASSERT(Unk_7e9ba0, field_38, 0x38);

// 0x71007e9ba0
u16 Unk_7e9ba0_getField38(const Unk_7e9ba0* self) {
    return self->field_38;
}

struct Unk_7e9bb0 {
    u8 _0[0x3f];
    u8 field_3f;
};
PKMN_OFFSET_ASSERT(Unk_7e9bb0, field_3f, 0x3f);

// 0x71007e9bb0
u32 Unk_7e9bb0_get(const Unk_7e9bb0* self) {
    return (self->field_3f >> 5) & 1;
}

struct Unk_7e9bc0 {
    u8 _0[0x3f];
    u8 field_3f;
};
PKMN_OFFSET_ASSERT(Unk_7e9bc0, field_3f, 0x3f);

// 0x71007e9bc0
u32 Unk_7e9bc0_get(const Unk_7e9bc0* self) {
    return (self->field_3f >> 2) & 1;
}

struct Unk_7e9bd0 {
    u8 _0[0x3f];
    u8 field_3f;
};
PKMN_OFFSET_ASSERT(Unk_7e9bd0, field_3f, 0x3f);

// 0x71007e9bd0
u32 Unk_7e9bd0_get(const Unk_7e9bd0* self) {
    return self->field_3f & 1;
}

struct Unk_7e9be0 {
    u8 _0[0x3f];
    u8 field_3f;
};
PKMN_OFFSET_ASSERT(Unk_7e9be0, field_3f, 0x3f);

// 0x71007e9be0
u32 Unk_7e9be0_get(const Unk_7e9be0* self) {
    return (self->field_3f >> 1) & 1;
}

struct Unk_7e9bf0 {
    u8 _0[0x3f];
    u8 field_3f;
};
PKMN_OFFSET_ASSERT(Unk_7e9bf0, field_3f, 0x3f);

// 0x71007e9bf0
u32 Unk_7e9bf0_get(const Unk_7e9bf0* self) {
    return (self->field_3f >> 3) & 1;
}

struct Unk_7e9c00 {
    u8 _0[0x3f];
    u8 field_3f;
};
PKMN_OFFSET_ASSERT(Unk_7e9c00, field_3f, 0x3f);

// 0x71007e9c00
u32 Unk_7e9c00_get(const Unk_7e9c00* self) {
    return (self->field_3f >> 4) & 1;
}

struct Unk_7e9c10 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_7e9c10, field_20, 0x20);

// 0x71007e9c10
u64 Unk_7e9c10_getField20(const Unk_7e9c10* self) {
    return self->field_20;
}

struct Unk_7e9c20 {
    u8 _0[0x3e];
    u16 field_3e;
};
PKMN_OFFSET_ASSERT(Unk_7e9c20, field_3e, 0x3e);

// 0x71007e9c20
u16 Unk_7e9c20_getField3e(const Unk_7e9c20* self) {
    return self->field_3e;
}

struct Unk_7e9c30 {
    u8 _0[0x30];
    u8 field_30;
};
PKMN_OFFSET_ASSERT(Unk_7e9c30, field_30, 0x30);

// 0x71007e9c30
void Unk_7e9c30_setField30(Unk_7e9c30* self, u8 value) {
    self->field_30 = value;
}

struct Unk_7e9c40 {
    u8 _0[0x34];
    u32 field_34;
};
PKMN_OFFSET_ASSERT(Unk_7e9c40, field_34, 0x34);

// 0x71007e9c40
void Unk_7e9c40_setField34(Unk_7e9c40* self, u32 value) {
    self->field_34 = value;
}

struct Unk_7e9c50 {
    u8 _0[0x38];
    u16 field_38;
};
PKMN_OFFSET_ASSERT(Unk_7e9c50, field_38, 0x38);

// 0x71007e9c50
void Unk_7e9c50_setField38(Unk_7e9c50* self, u16 value) {
    self->field_38 = value;
}

struct Unk_7e9c60 {
    u8 _0[0x3a];
    u8 field_3a;
};
PKMN_OFFSET_ASSERT(Unk_7e9c60, field_3a, 0x3a);

// 0x71007e9c60
void Unk_7e9c60_setField3a(Unk_7e9c60* self, u8 value) {
    self->field_3a = value;
}

struct Unk_7e9c70 {
    u8 _0[0x3b];
    u8 field_3b;
};
PKMN_OFFSET_ASSERT(Unk_7e9c70, field_3b, 0x3b);

// 0x71007e9c70
void Unk_7e9c70_setField3b(Unk_7e9c70* self, u8 value) {
    self->field_3b = value;
}

struct Unk_7e9ce0 {
    u8 _0[0x20];
    u64 field_20;
    u8 _28[0x16];
    u8 field_3e;
};
PKMN_OFFSET_ASSERT(Unk_7e9ce0, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_7e9ce0, field_3e, 0x3e);

// 0x71007e9ce0
void Unk_7e9ce0_set(Unk_7e9ce0* self, u64 value, u8 arg2) {
    self->field_20 = value;
    self->field_3e = arg2;
}

struct Unk_7e9e10 {
    u8 _0[0x8];
    u16 field_8;
};
PKMN_OFFSET_ASSERT(Unk_7e9e10, field_8, 0x8);

// 0x71007e9e10
void Unk_7e9e10_setField8(Unk_7e9e10* self, u16 value) {
    self->field_8 = value;
}

struct Unk_7e9e20 {
    u8 _0[0xa];
    u8 field_a;
    u8 _b[0x1];
    u32 field_c;
    u64 field_10;
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_7e9e20, field_a, 0xa);
PKMN_OFFSET_ASSERT(Unk_7e9e20, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_7e9e20, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_7e9e20, field_18, 0x18);

// 0x71007e9e20
void Unk_7e9e20_set(Unk_7e9e20* self, u32 value) {
    self->field_c = value;
    self->field_a = 0;
    self->field_10 = 0;
    self->field_18 = 0;
}

struct Unk_7e9e30 {
    u8 _0[0xa];
    u8 field_a;
    u8 _b[0x1];
    u32 field_c;
    u64 field_10;
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_7e9e30, field_a, 0xa);
PKMN_OFFSET_ASSERT(Unk_7e9e30, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_7e9e30, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_7e9e30, field_18, 0x18);

// 0x71007e9e30
void Unk_7e9e30_set(Unk_7e9e30* self, u32 value) {
    self->field_c = value;
    self->field_a = 4;
    self->field_10 = 0;
    self->field_18 = 0;
}

struct Unk_7e9e50 {
    u8 _0[0xa];
    u8 field_a;
    u8 _b[0x1];
    u32 field_c;
    u64 field_10;
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_7e9e50, field_a, 0xa);
PKMN_OFFSET_ASSERT(Unk_7e9e50, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_7e9e50, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_7e9e50, field_18, 0x18);

// 0x71007e9e50
void Unk_7e9e50_set(Unk_7e9e50* self, u32 value) {
    self->field_c = value;
    self->field_a = 1;
    self->field_10 = 0;
    self->field_18 = 0;
}

struct Unk_7e9e70 {
    u8 _0[0xa];
    u8 field_a;
    u8 _b[0x1];
    u32 field_c;
};
PKMN_OFFSET_ASSERT(Unk_7e9e70, field_a, 0xa);
PKMN_OFFSET_ASSERT(Unk_7e9e70, field_c, 0xc);

// 0x71007e9e70
u32 Unk_7e9e70_update(Unk_7e9e70* self, u32 value) {
    if (self->field_a <= 1) {
        self->field_c = value;
        if (self->field_a == 1) {
            self->field_a = 2;
            return 1;
        }
        return 1;
    }
    return 0;
}

struct Unk_7e9ea0 {
    u8 _0[0xa];
    u8 field_a;
};
PKMN_OFFSET_ASSERT(Unk_7e9ea0, field_a, 0xa);

// 0x71007e9ea0
void Unk_7e9ea0_set(Unk_7e9ea0* self) {
    self->field_a = 1;
}

struct Unk_7e9eb0 {
    u8 _0[0xa];
    u8 field_a;
    u8 _b[0x1];
    u32 field_c;
    u32 field_10;
    u32 field_14;
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_7e9eb0, field_a, 0xa);
PKMN_OFFSET_ASSERT(Unk_7e9eb0, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_7e9eb0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_7e9eb0, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_7e9eb0, field_18, 0x18);

// 0x71007e9eb0
void Unk_7e9eb0_set(Unk_7e9eb0* self, u32 value, u32 arg2, u32 arg3) {
    self->field_c = value;
    self->field_10 = arg2;
    self->field_14 = arg3;
    self->field_18 = 0;
    self->field_a = 3;
}

struct Unk_7e9f40 {
    u8 _0[0x8];
    u16 field_8;
};
PKMN_OFFSET_ASSERT(Unk_7e9f40, field_8, 0x8);

// 0x71007e9f40
u16 Unk_7e9f40_getField8(const Unk_7e9f40* self) {
    return self->field_8;
}

struct Unk_7e9f50 {
    u8 _0[0xc];
    u32 field_c;
};
PKMN_OFFSET_ASSERT(Unk_7e9f50, field_c, 0xc);

// 0x71007e9f50
u32 Unk_7e9f50_getFieldc(const Unk_7e9f50* self) {
    return self->field_c;
}

struct Unk_7e9f60 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_7e9f60, field_18, 0x18);

// 0x71007e9f60
u64 Unk_7e9f60_getField18(const Unk_7e9f60* self) {
    return self->field_18;
}

struct Unk_7ea260 {
    u8 _0[0xc08];
    u32 field_c08;
};
PKMN_OFFSET_ASSERT(Unk_7ea260, field_c08, 0xc08);

// 0x71007ea260
bool Unk_7ea260_check(const Unk_7ea260* self) {
    return self->field_c08 == 0;
}

struct Unk_7ea810 {
    u8 _0[0x408];
    u32 field_408;
};
PKMN_OFFSET_ASSERT(Unk_7ea810, field_408, 0x408);

// 0x71007ea810
void Unk_7ea810_set(Unk_7ea810* self) {
    if (self->field_408 <= 0x1e) {
        self->field_408 = self->field_408 + 1;
    }
}

struct Unk_7eaf40 {
    u8 _0[0x1588];
    u64 field_1588;
};
PKMN_OFFSET_ASSERT(Unk_7eaf40, field_1588, 0x1588);

// 0x71007eaf40
u64 Unk_7eaf40_getField1588(const Unk_7eaf40* self) {
    return self->field_1588;
}

void Unk_7eb3d0(u32);

// 0x71007eb460
void Unk_7eb460_call(u32 self) {
    Unk_7eb3d0(self);
}

// 0x71007eb5c0
bool Unk_7eb5c0_check(u16 self) {
    return (self) == 0xf1;
}

extern const u8 Unk_1f10c68[] __attribute__((visibility("hidden")));
struct Unk_7eba90 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7eba90, field_0, 0x0);

// 0x71007eba90
const u8* Unk_7eba90_update(Unk_7eba90* self) {
    self->field_0 = 0x1fb;
    return Unk_1f10c68;
}

struct Unk_7ebf80 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_7ebf80, field_0, 0x0);

// 0x71007ebf80
void Unk_7ebf80_call(Unk_7ebf80* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

extern Unk_239a418* Unk_27cec58;

// 0x71007ec0c0
void Unk_7ec0c0_call() {
    Unk_239a418* v0 = Unk_27cec58;
    if (v0 != 0) {
        Unk_27cec58 = nullptr;
        static_cast<Unk_239a458*>(v0)->vf5();
    }
}
