// Scope: common
// Slots 252 to 259 of Unk_23b9048 (Unk_8a8e30.h): the battle's positions and
// parties, through the module at +0x68 and the main module at +0x58, and the
// function its constructor calls to make the object it owns.
#include "battle/battle_logic/source/netwatch/Unk_8a8e30.h"

// Leaf functions with their own placeholder types (src/unsorted/leaf).
struct Unk_7fe1d0;
Unk_7ecc90_Con* Unk_7fe1d0_getField8(const Unk_7fe1d0* self);
struct Unk_7dfdb0;
u8 Unk_7dfdb0_getField2a6(const Unk_7dfdb0* self);
struct Unk_7c56e0;
bool Unk_7c56e0_check(const Unk_7c56e0* self, u32 value);
u8 Unk_7ee6b0_getField7d(const Unk_7ee6b0* self);
struct Unk_7ef320;
u64 Unk_7ef320_getField60(const Unk_7ef320* self);

// src/battle/battle_engine/Unk_7ecc90.cpp
Unk_7ee6b0* Unk_7ed560(Unk_7ecc90_Con* self, u8 position);
Unk_7ee6b0* Unk_7ed220(Unk_7ecc90_Con* self, u8 pokeId);
Unk_7fc430_Party* Unk_7ed1a0(Unk_7ecc90_Con* self, u32 client);

// src/battle/battle_engine/Unk_7ee6b0.cpp
void Unk_7f13e0(Unk_7ee6b0* self, u16 amount);
s32 Unk_7eef50(void* self, u32 index);
// Copies a Pokémon's battle state (from +0x2a0) from another.
void Unk_7eebd0(Unk_7ee6b0* self, const Unk_7ee6b0* other);

// The main module's functions (src/battle/battle_engine/Unk_7c2d80.cpp).
u8 Unk_7cb860(u64 self);
u8 Unk_7cb8c0(u64 self, u32 value);

// 0x71008a8f00
void Unk_23b9048::Unk_8a8f00(Unk_239a418_Allocator* allocator) {
    field_78 = Unk_2771620_MakeUnique<Unk_8a82e0>(allocator,
                                                  Unk_8a82e0_Args{allocator, field_58, field_68});
}

// 0x71008a9090
Unk_7ecc90_Con* Unk_23b9048::vf252() {
    return Unk_7fe1d0_getField8(static_cast<const Unk_7fe1d0*>(field_68));
}

// 0x71008a90a0
Unk_7ee6b0* Unk_23b9048::vf253(u8 client) {
    u8 position = vf228(client);
    if (position == 5)
        return nullptr;
    return Unk_7ed560(vf252(), position);
}

// 0x71008a9100
bool Unk_23b9048::vf254(Unk_7ee6b0* out, u32 client) {
    Unk_7ee6b0* poke = vf253(client);
    if (poke == nullptr)
        return false;
    Unk_7eebd0(out, poke);
    if (field_58 != nullptr && Unk_7c56e0_check(static_cast<const Unk_7c56e0*>(field_58), 0x1000) &&
        (client == 4 || client == 2)) {
        if (Unk_7eef50(out, 13) == 0)
            Unk_7f13e0(out, 1);
    }
    return true;
}

// 0x71008a91b0
u64 Unk_23b9048::vf255(u8 client) {
    Unk_7ee6b0* poke = vf253(client);
    Unk_7ee6b0* found = Unk_7ed220(vf252(), Unk_7ee6b0_getField7d(poke));
    return Unk_7ef320_getField60(reinterpret_cast<const Unk_7ef320*>(found));
}

// 0x71008a9210
const Unk_7fc430_Party* Unk_23b9048::vf256() {
    return vf259(Unk_7dfdb0_getField2a6(static_cast<const Unk_7dfdb0*>(field_60)));
}

// 0x71008a9250
const Unk_7fc430_Party* Unk_23b9048::vf257() {
    return vf259(Unk_7cb860(reinterpret_cast<u64>(field_58)));
}

// 0x71008a9290
// NON_MATCHING: Unk_7cb8c0 takes a second argument (it passes it on as w3),
// which its name (_Z10Unk_7cb8c0m) leaves out; the code is the original's.
const Unk_7fc430_Party* Unk_23b9048::vf258(u32 value) {
    return vf259(Unk_7cb8c0(reinterpret_cast<u64>(field_58), value));
}

// 0x71008a92d0
const Unk_7fc430_Party* Unk_23b9048::vf259(u8 client) {
    return Unk_7ed1a0(vf252(), client);
}
