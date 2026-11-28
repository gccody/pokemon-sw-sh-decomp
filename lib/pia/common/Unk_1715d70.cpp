// Scope: common
// Members of one of Pia's objects (it has a vtable), between the getters
// tools/leafgen.py wrote (lib/nx_middleware/leaf/Unk_170e810.cpp): indexed
// getters of its arrays and the flags it combines. Names are placeholders
// (lib/pia/README.md).
#include "types.h"

// What 0x710165c080 reads (a 0x40-byte entry): a count it works out from the
// bytes at field_8, 0 when there are none.
struct Unk_165c080_arg0 {
    u8 _0[0x40];
};
PKMN_SIZE_ASSERT(Unk_165c080_arg0, 0x40);

u32 Unk_165c080(const Unk_165c080_arg0* self);

struct Unk_1715e00_entry {
    u8 _0[0x10];
};
PKMN_SIZE_ASSERT(Unk_1715e00_entry, 0x10);

struct Unk_1715e30_entry {
    u8 _0[0x120];
};
PKMN_SIZE_ASSERT(Unk_1715e30_entry, 0x120);

// The object: slot 7 of its vtable takes a flag and returns one (placeholder
// names vf<slot>).
class Unk_1715de0_arg0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual bool vf7(u32 value);

    u32 field_8;
    u8 _c[0x30 - 0xc];
    bool field_30[6];
    u8 _36[0x394 - 0x36];
    bool field_394;
    u8 _395[0x39c - 0x395];
    bool field_39c;
    u8 _39d[0x3a4 - 0x39d];
    bool field_3a4;
    u8 _3a5[0x3d0 - 0x3a5];
    bool field_3d0;
    u8 _3d1;
    bool field_3d2;
    u8 _3d3[0x3d8 - 0x3d3];
    Unk_165c080_arg0 field_3d8[3];
    Unk_1715e00_entry field_498[3];
    Unk_165c080_arg0 field_4c8[1];
    Unk_1715e30_entry field_508[1];
    u32 field_628;
};
PKMN_OFFSET_ASSERT(Unk_1715de0_arg0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1715de0_arg0, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_1715de0_arg0, field_394, 0x394);
PKMN_OFFSET_ASSERT(Unk_1715de0_arg0, field_39c, 0x39c);
PKMN_OFFSET_ASSERT(Unk_1715de0_arg0, field_3a4, 0x3a4);
PKMN_OFFSET_ASSERT(Unk_1715de0_arg0, field_3d0, 0x3d0);
PKMN_OFFSET_ASSERT(Unk_1715de0_arg0, field_3d2, 0x3d2);
PKMN_OFFSET_ASSERT(Unk_1715de0_arg0, field_3d8, 0x3d8);
PKMN_OFFSET_ASSERT(Unk_1715de0_arg0, field_498, 0x498);
PKMN_OFFSET_ASSERT(Unk_1715de0_arg0, field_4c8, 0x4c8);
PKMN_OFFSET_ASSERT(Unk_1715de0_arg0, field_508, 0x508);
PKMN_OFFSET_ASSERT(Unk_1715de0_arg0, field_628, 0x628);

// 0x7101715de0
Unk_165c080_arg0* Unk_1715de0(Unk_1715de0_arg0* self, u32 index) {
    if (index > 2) {
        return nullptr;
    }
    return &self->field_3d8[index];
}

// 0x7101715e00
Unk_1715e00_entry* Unk_1715e00(Unk_1715de0_arg0* self, u32 index) {
    return &self->field_498[index];
}

// 0x7101715e10
Unk_165c080_arg0* Unk_1715e10(Unk_1715de0_arg0* self, u32 index) {
    if (index != 0) {
        return nullptr;
    }
    return &self->field_4c8[index];
}

// 0x7101715e30
Unk_1715e30_entry* Unk_1715e30(Unk_1715de0_arg0* self, u32 index) {
    if (index != 0) {
        return nullptr;
    }
    return &self->field_508[index];
}

// 0x7101715e50
bool Unk_1715e50(const Unk_1715de0_arg0* self) {
    bool result = self->field_394 | self->field_39c | self->field_3a4 | self->field_3d0 |
                  self->field_3d2;
    for (int i = 0; i < 3; i++) {
        result |= Unk_165c080(&self->field_3d8[i]) != 0;
    }
    result |= Unk_165c080(&self->field_4c8[0]) != 0;
    return result;
}

// 0x71017160a0
u32 Unk_17160a0(const Unk_1715de0_arg0* self) {
    return self->field_628 | ((self->field_8 & 2) << 1);
}

// 0x71017160c0
bool Unk_17160c0(Unk_1715de0_arg0* self) {
    if (self->field_628 == 0) {
        if (self->vf7(1)) {
            return true;
        }
    }
    return false;
}

// 0x7101716100
bool Unk_1716100(Unk_1715de0_arg0* self) {
    if (self->field_628 != 0) {
        return false;
    }
    if (self->vf7(1)) {
        return false;
    }
    bool result = false;
    for (int i = 0; i < 6; i++) {
        result |= self->field_30[i];
    }
    return result;
}
