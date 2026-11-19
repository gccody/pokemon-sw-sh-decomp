// Scope: common
// Getters of the battle's main module (0x71007c2d80 to 0x71007cdac0): its
// rule (+0x150), its setup (+0x88) and the objects it holds by reference.
// Placeholder names: rename once the class is known.
#include "battle/battle_engine/Unk_7ee6b0.h"
#include "gflib3/Unk_239a418.h"

using Unk_7c2d80_Ref = Unk_239a418_Ref<Unk_239a418>;

// What the setup holds at +0x350.
struct Unk_7caed0_Data {
    Unk_7caed0_Data(const Unk_7caed0_Data& other)
        : field_0(other.field_0),
          field_8(other.field_8),
          field_10(other.field_10),
          field_18(other.field_18) {}
    u64 field_0;
    u64 field_8;
    u64 field_10;
    Unk_7c2d80_Ref field_18;
};

// A party's entry in the setup.
struct Unk_7ca150_Entry {
    u8 _0[0x120];
};

// The battle's setup.
struct Unk_7c2d80_Setup {
    u8 _0[0x350];
    Unk_7caed0_Data field_350;
    u8 _370[0x3a5 - 0x370];
    u8 field_3a5;
    u8 _3a6;
    u8 field_3a7;
    u8 _3a8[0x430 - 0x3a8];
    Unk_7ca150_Entry field_430[4];
    u8 _8b0[0xa30 - 0x8b0];
    void* field_a30;
    void* field_a38;
    u8 _a40[0xae8 - 0xa40];
    void* field_ae8;
    u8 _af0[0xb2f - 0xaf0];
    u8 field_b2f[1];
};
PKMN_OFFSET_ASSERT(Unk_7c2d80_Setup, field_3a5, 0x3a5);
PKMN_OFFSET_ASSERT(Unk_7c2d80_Setup, field_a30, 0xa30);
PKMN_OFFSET_ASSERT(Unk_7c2d80_Setup, field_b2f, 0xb2f);

// What the main module holds at +0x1e8 for each client.
struct Unk_7ca170_Client {
    Unk_7c2d80_Ref field_0;
    u8 _8[0x70 - 0x8];
};
PKMN_SIZE_ASSERT(Unk_7ca170_Client, 0x70);

struct Unk_7fe1d0;
struct Unk_7ecc90_Con;
Unk_7ecc90_Con* Unk_7fe1d0_getField8(const Unk_7fe1d0* self);
Unk_7ee6b0* Unk_7ecc90(Unk_7ecc90_Con* self, u8 pokeId);
void Unk_7eff50(const Unk_7ee6b0* self, Unk_7ee6b0* other);

struct Unk_7c2d80_Main {
    u8 _0[0x88];
    Unk_7c2d80_Setup* field_88;
    u8 _90[0xe8 - 0x90];
    Unk_7c2d80_Ref field_e8[5];
    Unk_7c2d80_Ref field_110[5];
    u8 _138[0x140 - 0x138];
    Unk_7c2d80_Ref field_140;
    u8 _148[0x150 - 0x148];
    u32 field_150;
    u8 _154[0x158 - 0x154];
    u32 field_158;
    u8 _15c[0x16c - 0x15c];
    u32 field_16c;
    u32 field_170;
    u8 field_174;
    u8 _175[0x183 - 0x175];
    u8 field_183;
    u8 _184[0x1e8 - 0x184];
    Unk_7ca170_Client field_1e8[4];
    u8 _3a8[0x5c0 - 0x3a8];
    u8 field_5c0[2];
    u8 _5c2[0x5c8 - 0x5c2];
    Unk_7c2d80_Ref field_5c8;
    u8 _5d0[0x5f0 - 0x5d0];
    const Unk_7fe1d0* field_5f0;
    u8 _5f8[0x610 - 0x5f8];
    const Unk_7fe1d0* field_610;
    u8 _618[0x750 - 0x618];
    void* field_750;
    void* field_758;
};
PKMN_OFFSET_ASSERT(Unk_7c2d80_Main, field_150, 0x150);
PKMN_OFFSET_ASSERT(Unk_7c2d80_Main, field_1e8, 0x1e8);
PKMN_OFFSET_ASSERT(Unk_7c2d80_Main, field_5c0, 0x5c0);
PKMN_OFFSET_ASSERT(Unk_7c2d80_Main, field_750, 0x750);

// Leaf functions with their own placeholder types (src/unsorted/leaf).
struct Unk_894fa0;
bool Unk_894fa0_check(const Unk_894fa0* self);
struct Unk_7eef40;
u16 Unk_7eef40_getField70(const Unk_7eef40* self);

// Declared as src/unsorted/leaf/Unk_7c2d90.cpp names them.
u32 Unk_7fa500(u32 rule, u32 position);
u32 Unk_7fa580(u32 rule, u8 arg1, u32 arg2);
u32 Unk_7fbd00(u32 rule, u8 arg1, u32 arg2, u32 arg3);

u8 Unk_8048c0(u8 value);
u8 Unk_804920(u8 value);
u32 Unk_7fb890(u32 rule, u8 arg1, u32 arg2, u32 arg3);
u32 Unk_7f9a10(u32 rule, u8 arg1, u32 arg2);
u32 Unk_1367100(void* self, u32 arg1, u32 arg2, u32 arg3);
void Unk_1379f30(void* self, u32 species);
void Unk_8ada60(void* self);

// 0x71007ca080
bool Unk_7ca080(const Unk_7c2d80_Main* self) {
    if (self->field_750 != nullptr)
        return Unk_894fa0_check(static_cast<const Unk_894fa0*>(self->field_750));
    return true;
}

// 0x71007ca0a0
u8 Unk_7ca0a0(const Unk_7c2d80_Main* self, u8 position, u8 other) {
    if (position == other)
        return 0;
    u32 rule = self->field_150;
    u8 client = Unk_7fa500(rule, position);
    u8 otherClient = Unk_7fa500(rule, other);
    if (client == otherClient)
        return 2;
    return other < 2 ? 1 : 3;
}

// 0x71007ca110
Unk_7c2d80_Ref Unk_7ca110(const Unk_7c2d80_Main* self, u8 index, bool second) {
    if (second)
        return self->field_110[index];
    return self->field_e8[index];
}

// 0x71007ca150
Unk_7ca150_Entry* Unk_7ca150(const Unk_7c2d80_Main* self, u8 index) {
    return &self->field_88->field_430[index];
}

// 0x71007ca170
bool Unk_7ca170(const Unk_7c2d80_Main* self, u8 client) {
    return self->field_1e8[client].field_0.m_ptr == nullptr;
}

// 0x71007ca190
Unk_7c2d80_Ref Unk_7ca190(const Unk_7c2d80_Main* self, u8 client) {
    Unk_239a418* object = self->field_1e8[client].field_0.m_ptr;
    if (object != nullptr)
        return Unk_7c2d80_Ref(object);
    return Unk_7c2d80_Ref();
}

// 0x71007cac40
u32 Unk_7cac40(const Unk_7c2d80_Main* self, u8 position) {
    u32 client = Unk_7fa500(self->field_150, position);
    return Unk_7fa580(self->field_150, self->field_88->field_3a5, client);
}

// 0x71007cacb0
u32 Unk_7cacb0(const Unk_7c2d80_Main* self, u8 position) {
    u8 other = Unk_7fbd00(self->field_150, self->field_88->field_3a5, position, 0);
    u32 client = Unk_7fa500(self->field_150, other);
    return Unk_7fa580(self->field_150, self->field_88->field_3a5, client);
}

// 0x71007caed0
Unk_7caed0_Data Unk_7caed0(const Unk_7c2d80_Main* self) {
    return self->field_88->field_350;
}

// 0x71007cafa0
Unk_7c2d80_Ref Unk_7cafa0(const Unk_7c2d80_Main* self) {
    return self->field_140;
}

// 0x71007cb050
Unk_7c2d80_Ref Unk_7cb050(const Unk_7c2d80_Main* self) {
    return self->field_5c8;
}

// 0x71007cb1b0
bool Unk_7cb1b0(const Unk_7c2d80_Main* self, u8 value) {
    u8 side = Unk_8048c0(value);
    return self->field_174 == side;
}

// 0x71007cb1e0
void Unk_7cb1e0(const Unk_7c2d80_Main* self, const Unk_7eef40* poke) {
    void* dex = self->field_88->field_a38;
    if (dex != nullptr)
        Unk_1379f30(dex, Unk_7eef40_getField70(poke));
}

// 0x71007cb890
u8 Unk_7cb890(const Unk_7c2d80_Main* self, u8 position) {
    return Unk_7fb890(self->field_150, self->field_88->field_3a5, position, 0);
}

// 0x71007cb9a0
u32 Unk_7cb9a0(const Unk_7c2d80_Main* self, u8 side, u32 arg2) {
    if (self->field_88->field_3a7 == 1)
        return 0;
    if (self->field_174 != side)
        return 0;
    return Unk_1367100(self->field_88->field_a30, arg2, 1, 1);
}

// 0x71007cb9e0
bool Unk_7cb9e0(const Unk_7c2d80_Main* self) {
    if (self->field_88->field_ae8 == nullptr)
        return false;
    switch (self->field_88->field_3a7) {
        case 1:
            return false;
        default:
            return true;
    }
}

// 0x71007cbad0
void Unk_7cbad0(const Unk_7c2d80_Main* self, u8 value) {
    u8 side = Unk_8048c0(value);
    if (self->field_174 == side) {
        u8 index = Unk_804920(value);
        self->field_88->field_b2f[index] = 1;
    }
}

// 0x71007cbb40
void Unk_7cbb40(Unk_7c2d80_Main* self, u32 arg1, u32 arg2, bool force) {
    if (self->field_16c == 8 || force) {
        self->field_16c = arg1;
        self->field_170 = arg2;
        if (self->field_758 != nullptr)
            Unk_8ada60(self->field_758);
    }
}

// 0x71007cbcf0
void Unk_7cbcf0(Unk_7c2d80_Main* self, u32 amount) {
    if (!(self->field_183 & 8)) {
        u32 value = self->field_158 + amount;
        self->field_158 = value < 99999 ? value : 99999;
    }
}

// 0x71007cbd20
void Unk_7cbd20(Unk_7c2d80_Main* self, u32 index) {
    if (index <= 1)
        self->field_5c0[index] = 1;
}

// 0x71007cbed0
void Unk_7cbed0(const Unk_7c2d80_Main* self, u8 pokeId) {
    Unk_7ee6b0* other = Unk_7ecc90(Unk_7fe1d0_getField8(self->field_610), pokeId);
    Unk_7eff50(Unk_7ecc90(Unk_7fe1d0_getField8(self->field_5f0), pokeId), other);
}

// 0x71007cbf20
u8 Unk_7cbf20(const Unk_7c2d80_Main* self, u8 position) {
    return Unk_7f9a10(self->field_150, self->field_88->field_3a5, position);
}

// 0x71007cbf50
u8 Unk_7cbf50(const Unk_7c2d80_Main* self, u8 position) {
    return Unk_7f9a10(self->field_150, self->field_88->field_3a5, position);
}
