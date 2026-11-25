// Scope: common
// Slots 206, 232 to 238, 246 to 250, 313 and 314 of Unk_23b9048
// (Unk_8a9b50.h), and the function at 0x71008aa360: a pokémon's types, a
// move's type and what a move turns into, and the main module's per-client
// objects, each with a default for when there's no main module.
//
// The constants are the game's IDs: species 0x36d (877, Morpeko) with form 1
// and move 0x30f (783, Aura Wheel) give type 0x10 (Dark); species 0x37a is
// 890 (Eternatus); 0x12 stands for no type.
#include "battle/battle_engine/Unk_7ee6b0.h"
#include "battle/battle_logic/source/netwatch/Unk_8a9b50.h"

// Classes on gflib3's reference-counted object, as far as these functions
// call them (src/unsorted/Unk_136af10.h, src/battle/battle_engine/
// Unk_1379600.h).
class Unk_2432540 : public Unk_239a418 {
public:
    u32 Unk_136b520(Unk_67be60* target);
};

class Unk_2432ae0 : public Unk_239a418 {
public:
    bool Unk_1379b90(u32 species);
};

// The main module's functions (src/battle/battle_engine/Unk_7c2d80.cpp).
u8 Unk_7cc000(void* self, u8 index);
Unk_7c2d80_Ref Unk_7cd0c0(const Unk_7c2d80_Main* self, u8 client);
bool Unk_7ca170(const Unk_7c2d80_Main* self, u8 client);
Unk_7c2d80_Ref Unk_7ca190(const Unk_7c2d80_Main* self, u8 client);
Unk_7c2d80_Ref Unk_7cb050(const Unk_7c2d80_Main* self);
const Unk_7d0b80* Unk_7c58c0(const Unk_7c2d80_Main* self, u8 client);

// The battle's pokémon (src/battle/battle_engine/Unk_7ecc90.cpp,
// Unk_7ee6b0.cpp).
Unk_7ee6b0* Unk_7ed1e0(Unk_7ecc90_Con* self, u8 pokeId);
Unk_7ee6b0* Unk_7ed5e0(Unk_7ecc90_Con* self, u8 position);
u8 Unk_7ef360(const Unk_7ee6b0* self);
u32 Unk_7f05d0(void* object);

// Moves and species (src/unsorted/unk_761f70/Unk_780ae0.cpp, ...).
u16 Unk_780d10(u32 move);
u8 Unk_780d40(u32 move);
u32 Unk_780d70(u32 move);
u16 Unk_780e00(u32 move);
bool Unk_7ebe00(u16 move);
s32 Unk_804700(u32 species, u16 form, bool arg2, bool arg3, u32 move);
u32 Unk_82d9a0(u32 move);
bool Unk_12fa500(u32 species);

u32 Unk_8a8770(void* self, u8 client, u8 pokeId, u32 move, u32 arg4);
bool Unk_8a7df0(void* self, u8 client);
bool Unk_8abfc0(void* self, u8 index);
void Unk_67bfa0(void* self);

// Leaf functions with their own placeholder types (src/unsorted/leaf).
struct Unk_7ca890;
u8 Unk_7ca890_get(const Unk_7ca890* self);
struct Unk_7c58b0;
u32 Unk_7c58b0_get(const Unk_7c58b0* self);
struct Unk_7c56e0;
bool Unk_7c56e0_check(const Unk_7c56e0* self, u32 value);
struct Unk_7cac80;
u8 Unk_7cac80_call(const Unk_7cac80* self, u32 value);
void* Unk_7d0b80_getFieldf0(const Unk_7d0b80* self);
u8 Unk_7ee6b0_getField7d(const Unk_7ee6b0* self);
struct Unk_7eef40;
u16 Unk_7eef40_getField70(const Unk_7eef40* self);
struct Unk_7f29c0;
bool Unk_7f29c0_get(const Unk_7f29c0* self);
struct Unk_7ee810;
struct Unk_7f36f0;
const Unk_7f36f0* Unk_7ee810_getField278(const Unk_7ee810* self);
const void* Unk_7f36f0_getField0(const Unk_7f36f0* self);
struct Unk_7fc7f0;
u8 Unk_7fc7f0_getField0(const Unk_7fc7f0* self);
struct Unk_7fc850;
u8 Unk_7fc850_getField1(const Unk_7fc850* self);
bool Unk_7f7fe0_call(u32 self);
struct Unk_67bdd0;
u32 Unk_67bdd0_getField78(const Unk_67bdd0* self);
struct Unk_67be10;
struct Unk_67be10_arg1;
u32 Unk_67be10_call(Unk_67be10* self, const Unk_67be10_arg1* value);
struct Unk_136b580;
u8 Unk_136b580_getField105(const Unk_136b580* self);
struct Unk_136b590;
u8 Unk_136b590_getField107(const Unk_136b590* self);

template <typename T, typename U>
static T* As(U* object) {
    return reinterpret_cast<T*>(object);
}

// The main module's setup, as far as slot 232 reads it.
struct Unk_8aa230_Setup {
    u8 _0[0xb28];
    u8 field_b28;
};
PKMN_OFFSET_ASSERT(Unk_8aa230_Setup, field_b28, 0xb28);

// The main module, as far as slot 232 reads it.
struct Unk_8aa230_Main {
    u8 _0[0x88];
    const Unk_8aa230_Setup* field_88;
};
PKMN_OFFSET_ASSERT(Unk_8aa230_Main, field_88, 0x88);

// NON_MATCHING: Unk_7cac80_call is named with a u32 parameter, so the
// position gets masked (the original passes it as it is); and the original
// tests the setup's flag before comparing the sides again, where this one
// reuses the first comparison.
// 0x71008aa230
void Unk_23b9048::vf232(u8* out1, u8* out2, const Unk_7ee6b0* poke) {
    u32 types = Unk_7f05d0(const_cast<Unk_7ee6b0*>(poke));
    *out1 = types & 0x1f;
    *out2 = (types >> 5) & 0x1f;
    if (field_58 == nullptr)
        return;
    u8 pokeId = Unk_7ee6b0_getField7d(poke);
    u8 side = Unk_7cc000(field_58, pokeId);
    u8 position = vf276();
    u8 own = Unk_7cac80_call(As<const Unk_7cac80>(field_58), position);
    if (side != own && !vf237(Unk_7ee6b0_getField7d(poke))) {
        *out1 = 0x12;
        *out2 = 0x12;
        return;
    }
    const Unk_8aa230_Setup* setup = As<const Unk_8aa230_Main>(field_58)->field_88;
    if (!(setup->field_b28 & 0x10) && side == own)
        return;
    if (!Unk_7f29c0_get(As<const Unk_7f29c0>(poke)))
        return;
    u8 otherId = Unk_7ef360(poke);
    Unk_7ee6b0* other = Unk_7ed1e0(vf252(), otherId);
    types = Unk_7f05d0(other);
    *out1 = types & 0x1f;
    *out2 = (types >> 5) & 0x1f;
}

// 0x71008aa360
void Unk_23b9048::Unk_8aa360(u32* outMove,
                             s32* outIndex,
                             u32 species,
                             u16 form,
                             bool arg4,
                             bool arg5,
                             u32 move) {
    *outMove = 0;
    *outIndex = -1;
    if (move == 0)
        return;
    s32 index = Unk_804700(species, form, arg4, arg5, move);
    if (index >= 0) {
        *outMove = 0;
        *outIndex = index;
        return;
    }
    if (!arg4) {
        *outMove = move;
        *outIndex = -1;
        return;
    }
    *outMove = Unk_82d9a0(move);
    *outIndex = -1;
    if (move == 0x30f && species == 0x36d && form == 1)
        *outMove = 0x304;
}

// 0x71008aa430
u8 Unk_23b9048::vf233(u32 move, const Unk_7ee6b0* poke) {
    if (move == 0)
        return 0;
    if (move == 0x30f && poke != nullptr &&
        Unk_7eef40_getField70(As<const Unk_7eef40>(poke)) == 0x36d && poke->field_33d == 1)
        return 0x10;
    return Unk_780d40(move);
}

// 0x71008aa4b0
u16 Unk_23b9048::vf234(u32 move) {
    if (move == 0)
        return 0;
    return Unk_780d10(move);
}

// 0x71008aa4d0
u16 Unk_23b9048::vf235(u32 move) {
    if (move == 0)
        return 0;
    return Unk_780e00(move);
}

// 0x71008aa4f0
u32 Unk_23b9048::vf236(u32 move) {
    return Unk_780d70(move);
}

// 0x71008aa500
bool Unk_23b9048::vf246(u8 client, u8 index) {
    if (field_58 == nullptr)
        return false;
    Unk_7c2d80_Ref ref = vf247(client);
    if (ref.m_ptr == nullptr)
        return false;
    return Unk_8abfc0(ref.m_ptr, index);
}

// 0x71008aa590
Unk_7c2d80_Ref Unk_23b9048::vf247(u8 client) {
    Unk_7c2d80_Ref none;
    if (field_58 == nullptr)
        return none;
    Unk_7c2d80_Ref ref = Unk_7cd0c0(field_58, client);
    return ref;
}

// 0x71008aa5e0
bool Unk_23b9048::vf248(u8 client) {
    return vf293(client);
}

// 0x71008aa5f0
u8 Unk_23b9048::vf249() {
    if (field_58 != nullptr)
        return Unk_7ca890_get(As<const Unk_7ca890>(field_58));
    return 0;
}

// NON_MATCHING: the original keeps `kind` at sp+8, this one at sp+12.
// 0x71008aa600
void Unk_23b9048::vf250(Unk_8aa600_Out* out, u8 client) {
    if (out == nullptr)
        return;
    if (out->field_8 != nullptr && Unk_67bdd0_getField78(As<const Unk_67bdd0>(out->field_8)) < 0xd)
        return;
    out->field_0 = nullptr;
    if (out->field_8 != nullptr)
        Unk_67bfa0(out->field_8);
    out->field_10 = 0;
    out->field_11 = 1;
    if (field_58 == nullptr)
        return;
    if (!Unk_7ca170(field_58, client))
        out->field_0 = static_cast<Unk_2432540*>(Unk_7ca190(field_58, client).m_ptr);
    if (out->field_0 != nullptr) {
        if (out->field_8 != nullptr)
            out->field_0->Unk_136b520(out->field_8);
        out->field_10 = Unk_136b580_getField105(As<const Unk_136b580>(out->field_0));
        out->field_11 = Unk_136b590_getField107(As<const Unk_136b590>(out->field_0));
        return;
    }
    u16 kind;
    Unk_7c2d80_Ref ref = vf290(client, &kind);
    if (out->field_8 == nullptr || ref.m_ptr == nullptr)
        return;
    u8 position = vf276();
    Unk_239a418* own = Unk_7ca190(field_58, position).m_ptr;
    Unk_67be10_call(As<Unk_67be10>(out->field_8), As<const Unk_67be10_arg1>(ref.m_ptr));
    out->field_10 = kind & 3;
    out->field_11 = Unk_136b590_getField107(As<const Unk_136b590>(own));
}

// 0x71008aa790
bool Unk_23b9048::vf237(u8 pokeId) {
    u32 mode = Unk_7c58b0_get(As<const Unk_7c58b0>(field_58));
    if (mode == 2 || mode == 3)
        return true;
    u32 species = Unk_7eef40_getField70(As<const Unk_7eef40>(Unk_7ed1e0(vf252(), pokeId)));
    if ((Unk_7c56e0_check(As<const Unk_7c56e0>(field_58), 0x400) ||
         Unk_7c56e0_check(As<const Unk_7c56e0>(field_58), 0x800) ||
         Unk_7c56e0_check(As<const Unk_7c56e0>(field_58), 0x1000)) &&
        species == 0x37a)
        return false;
    if (!Unk_12fa500(species))
        return true;
    return static_cast<Unk_2432ae0*>(Unk_7cb050(field_58).m_ptr)->Unk_1379b90(species);
}

// NON_MATCHING: register allocation (the parameters' callee-saved registers).
// 0x71008aa880
bool Unk_23b9048::vf238(u8 client, u8 pokeId, u32 move, bool* out) {
    if (!vf237(pokeId) || Unk_780d70(move) == 0 || Unk_7ebe00(move)) {
        *out = false;
        return true;
    }
    *out = true;
    return Unk_7f7fe0_call(Unk_8a8770(field_78, client, pokeId, move, 1));
}

// 0x71008aa930
bool Unk_23b9048::vf206(u8 client) {
    if (field_58 == nullptr)
        return false;
    const Unk_7d0b80* object = vf269() ? vf260() : Unk_7c58c0(field_58, client);
    if (object == nullptr)
        return false;
    return Unk_8a7df0(Unk_7d0b80_getFieldf0(object), client);
}

// 0x71008aa9b0
u8 Unk_23b9048::vf313() {
    if (vf267() == 2) {
        Unk_7ee6b0* poke = Unk_7ed5e0(vf252(), 4);
        if (poke != nullptr) {
            const void* object =
                Unk_7f36f0_getField0(Unk_7ee810_getField278(As<const Unk_7ee810>(poke)));
            if (object != nullptr)
                return Unk_7fc7f0_getField0(As<const Unk_7fc7f0>(object));
        }
    }
    return 0;
}

// 0x71008aaa20
u8 Unk_23b9048::vf314() {
    if (vf267() == 2) {
        Unk_7ee6b0* poke = Unk_7ed5e0(vf252(), 4);
        if (poke != nullptr) {
            const void* object =
                Unk_7f36f0_getField0(Unk_7ee810_getField278(As<const Unk_7ee810>(poke)));
            if (object != nullptr)
                return Unk_7fc850_getField1(As<const Unk_7fc850>(object));
        }
    }
    return 0;
}
