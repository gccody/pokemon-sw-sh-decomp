// Scope: common
// Slots 297 to 312 of Unk_23b9048 (Unk_8a9570.h): the main module's
// positions and its setup's flags, each with a default for when there's no
// main module.
#include "battle/battle_logic/source/netwatch/Unk_8a9570.h"

// The main module's functions (src/battle/battle_engine/Unk_7c2d80.cpp).
u8 Unk_7cbf20(const Unk_7c2d80_Main* self, u8 position);
u8 Unk_7cbf50(const Unk_7c2d80_Main* self, u8 position);
u32 Unk_7cab80(const Unk_7c2d80_Main* self);

// Leaf functions with their own placeholder types (src/unsorted/leaf).
struct Unk_7ca9e0;
u32 Unk_7ca9e0_get(const Unk_7ca9e0* self);
struct Unk_7c56e0;
bool Unk_7c56e0_check(const Unk_7c56e0* self, u32 value);
struct Unk_7c5520;
bool Unk_7c5520_check(const Unk_7c5520* self);

// The main module's setup, as these functions read it.
static const Unk_8a9570_Setup* GetSetup(const Unk_7c2d80_Main* main) {
    return reinterpret_cast<const Unk_8a9570_Main*>(main)->field_88;
}

// 0x71008a9940
u8 Unk_23b9048::vf297() {
    if (field_58 == nullptr)
        return 0;
    u8 position = vf277();
    return Unk_7cbf20(field_58, position);
}

// 0x71008a9980
u8 Unk_23b9048::vf298() {
    u8 position = vf276();
    return Unk_7cbf50(field_58, position);
}

// 0x71008a99b0
u8 Unk_23b9048::vf299() {
    if (field_58 == nullptr)
        return 0;
    u8 position = vf277();
    return Unk_7cbf50(field_58, position);
}

// 0x71008a99f0
bool Unk_23b9048::vf300() {
    if (field_58 != nullptr)
        return GetSetup(field_58)->field_a6d != 0;
    return false;
}

// 0x71008a9a30
u32 Unk_23b9048::vf302() {
    if (field_58 != nullptr)
        return Unk_7ca9e0_get(reinterpret_cast<const Unk_7ca9e0*>(field_58));
    return 0;
}

// 0x71008a9a50
bool Unk_23b9048::vf304(u32 value) {
    if (field_58 != nullptr)
        return Unk_7c56e0_check(reinterpret_cast<const Unk_7c56e0*>(field_58), value);
    return false;
}

// 0x71008a9a60
bool Unk_23b9048::vf305() {
    if (field_58 != nullptr)
        return GetSetup(field_58)->field_a50 != 0;
    return false;
}

// 0x71008a9a90
bool Unk_23b9048::vf306() {
    if (field_58 != nullptr)
        return GetSetup(field_58)->field_a71 != 0;
    return false;
}

// 0x71008a9ac0
bool Unk_23b9048::vf307() {
    if (field_58 != nullptr)
        return Unk_7c5520_check(reinterpret_cast<const Unk_7c5520*>(field_58));
    return false;
}

// 0x71008a9ad0
u32 Unk_23b9048::vf310() {
    if (field_58 != nullptr)
        return Unk_7cab80(field_58);
    return 3;
}

// 0x71008a9b00
const Unk_8a9570_Entry* Unk_23b9048::vf312(u8 index) {
    if (field_58 != nullptr)
        return &GetSetup(field_58)->field_3a8[index];
    return nullptr;
}

// 0x71008a9b30
u32 Unk_23b9048::vf309() {
    if (field_58 != nullptr)
        return Unk_7ca9e0_get(reinterpret_cast<const Unk_7ca9e0*>(field_58));
    return 1;
}
