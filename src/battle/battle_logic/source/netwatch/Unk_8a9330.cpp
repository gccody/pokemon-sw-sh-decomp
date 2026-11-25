// Scope: common
// Slots 263 to 279 of Unk_23b9048 (Unk_8a8e30.h): questions about the battle
// for the modules at +0x58 (the main module, null when there's none), +0x60
// and +0x68, each with a default for when the module is missing.
#include "battle/battle_logic/source/netwatch/Unk_8a8e30.h"

// Leaf functions with their own placeholder types (src/unsorted/leaf).
struct Unk_7fe1e0;
u64 Unk_7fe1e0_getField28(const Unk_7fe1e0* self);
struct Unk_7fe210;
void Unk_7fe210_call(const Unk_7fe210* self, u32 value, u32 arg2);
struct Unk_7fe230;
void Unk_7fe230_call(const Unk_7fe230* self, u32 value, u32 arg2);
struct Unk_7c58b0;
u32 Unk_7c58b0_get(const Unk_7c58b0* self);
struct Unk_7ca1c0;
u32 Unk_7ca1c0_getField150(const Unk_7ca1c0* self);
struct Unk_7c4c70;
u8 Unk_7c4c70_get(const Unk_7c4c70* self);
struct Unk_7cb2e0;
bool Unk_7cb2e0_check(const Unk_7cb2e0* self);
struct Unk_7cb310;
u32 Unk_7cb310_get(const Unk_7cb310* self);
struct Unk_7dfdb0;
u8 Unk_7dfdb0_getField2a6(const Unk_7dfdb0* self);
struct Unk_7cb390;
void Unk_7cb390_call(const Unk_7cb390* self, u32 value);
struct Unk_7cad30;
bool Unk_7cad30_call(const Unk_7cad30* self, u8 position);

// The main module's functions (src/battle/battle_engine/Unk_7c2d80.cpp).
bool Unk_7ccca0(u64 self, u8 client);

// 0x71008a9320
u64 Unk_23b9048::vf263() {
    return Unk_7fe1e0_getField28(static_cast<const Unk_7fe1e0*>(field_68));
}

// 0x71008a9330
void Unk_23b9048::vf264(u64 value, u64 arg2) {
    Unk_7fe210_call(static_cast<const Unk_7fe210*>(field_68), value, arg2);
}

// 0x71008a9340
void Unk_23b9048::vf265(u64 value, u64 arg2) {
    Unk_7fe230_call(static_cast<const Unk_7fe230*>(field_68), value, arg2);
}

// 0x71008a9350
u32 Unk_23b9048::vf266() {
    if (field_58 != nullptr)
        return Unk_7c58b0_get(static_cast<const Unk_7c58b0*>(field_58));
    return 0;
}

// 0x71008a9360
u32 Unk_23b9048::vf267() {
    if (field_58 != nullptr)
        return Unk_7ca1c0_getField150(static_cast<const Unk_7ca1c0*>(field_58));
    return 0;
}

// 0x71008a9370
u8 Unk_23b9048::vf268() {
    if (field_58 != nullptr)
        return Unk_7c4c70_get(static_cast<const Unk_7c4c70*>(field_58));
    return 0;
}

// 0x71008a9380
bool Unk_23b9048::vf269() {
    const Unk_8a8e30_Main* main = static_cast<const Unk_8a8e30_Main*>(field_58);
    if (main != nullptr && main->field_88 != nullptr && (main->field_88->field_b28 & 0x10))
        return true;
    return vf268() != 0;
}

// 0x71008a93d0
bool Unk_23b9048::vf270() {
    if (field_58 != nullptr && (vf276() == 1 || vf276() == 3))
        return true;
    return false;
}

// 0x71008a9450
bool Unk_23b9048::vf271() {
    if (field_58 != nullptr)
        return Unk_7cb2e0_check(static_cast<const Unk_7cb2e0*>(field_58));
    return false;
}

// 0x71008a9460
// NON_MATCHING: the original passes vf228's whole result on, so
// Unk_7cad30_call takes a u8, where its name
// (_Z15Unk_7cad30_callPK10Unk_7cad30j) says u32; the code is the original's.
bool Unk_23b9048::vf272(s32 value) {
    if (field_58 == nullptr)
        return value < 2;
    u8 position = vf228(value);
    if (position == 5)
        return false;
    return Unk_7cad30_call(static_cast<const Unk_7cad30*>(field_58), position);
}

// 0x71008a94d0
bool Unk_23b9048::vf273() {
    return vf277() != 5;
}

// 0x71008a9500
bool Unk_23b9048::vf274(u8 client) {
    if (field_58 != nullptr)
        return Unk_7ccca0(reinterpret_cast<u64>(field_58), client);
    return client < 2;
}

// 0x71008a9520
u32 Unk_23b9048::vf275() {
    if (field_58 != nullptr)
        return Unk_7cb310_get(static_cast<const Unk_7cb310*>(field_58));
    return 0;
}

// 0x71008a9530
u8 Unk_23b9048::vf276() {
    if (field_60 != nullptr)
        return Unk_7dfdb0_getField2a6(static_cast<const Unk_7dfdb0*>(field_60));
    return 0;
}

// 0x71008a9560
void Unk_23b9048::vf279(u32 value) {
    if (field_58 != nullptr)
        Unk_7cb390_call(static_cast<const Unk_7cb390*>(field_58), value);
}
