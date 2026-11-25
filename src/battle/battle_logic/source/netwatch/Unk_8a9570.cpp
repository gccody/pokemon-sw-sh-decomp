// Scope: common
// Slots 280 to 296 of Unk_23b9048 (Unk_8a9570.h): the main module's clients
// and positions, each with a default for when there's no main module.
#include "battle/battle_logic/source/netwatch/Unk_8a9570.h"

// The main module's functions (src/battle/battle_engine/Unk_7c2d80.cpp).
bool Unk_7ca170(const Unk_7c2d80_Main* self, u8 client);
u8 Unk_7c9b60(void* self, u8 client, u32 index);
// Returns a 32-bit value: Unk_7cb7a0 compares it with a u8 unmasked.
u32 Unk_7cb540(const Unk_7c2d80_Main* self, u8 position);
u8 Unk_7cb660(void* self, u8 value);
void Unk_7cae30(const Unk_7c2d80_Main* self, u8 position, u8* client, u8* index);
u32 Unk_7ccf30(const Unk_7c2d80_Main* self, u8 client);
Unk_8a9570_Name Unk_7ccfe0(const Unk_7c2d80_Main* self, u8 client);
Unk_7c2d80_Ref Unk_7cced0(const Unk_7c2d80_Main* self, u8 client, u16* out);
u8 Unk_7cbf20(const Unk_7c2d80_Main* self, u8 position);

// Leaf functions with their own placeholder types (src/unsorted/leaf).
struct Unk_7cb300;
u8 Unk_7cb300_get(const Unk_7cb300* self);
struct Unk_7ca1c0;
u32 Unk_7ca1c0_getField150(const Unk_7ca1c0* self);

// src/battle/battle_engine/Unk_7fc210.cpp
u8 Unk_7fc2f0(const Unk_7fc430_Party* self);

// 0x71008a9570
bool Unk_23b9048::vf280(u8 client) {
    if (field_58 != nullptr)
        return Unk_7ca170(field_58, client);
    return client == 0;
}

// 0x71008a9590
u32 Unk_23b9048::vf281(u8 client, u32 index) {
    if (field_58 != nullptr)
        return Unk_7cb540(field_58, Unk_7c9b60(field_58, client, index));
    return client;
}

// 0x71008a95d0
u8 Unk_23b9048::vf282(s32 value) {
    if (field_58 == nullptr)
        return value % 2;
    u8 position = vf228(value);
    if (position == 5)
        return 5;
    return Unk_7cb660(field_58, position);
}

// 0x71008a9640
u8 Unk_23b9048::vf283(s32 value) {
    if (field_58 == nullptr)
        return value % 2;
    u8 position = vf228(value);
    if (position == 5)
        return 0;
    u8 client;
    u8 index;
    Unk_7cae30(field_58, position, &client, &index);
    return index;
}

// 0x71008a96c0
u8 Unk_23b9048::vf284(s32 value) {
    if (field_58 == nullptr)
        return value % 2;
    return vf281(vf282(value), 0);
}

// 0x71008a9720
u16 Unk_23b9048::vf285(u8 client) {
    if (field_58 != nullptr)
        return Unk_7ccf30(field_58, client);
    return 0;
}

// 0x71008a9770
Unk_8a9570_Name Unk_23b9048::vf289(u8 client) {
    if (field_58 != nullptr)
        return Unk_7ccfe0(field_58, client);
    return Unk_8a9570_Name::Default();
}

// 0x71008a9840
Unk_7c2d80_Ref Unk_23b9048::vf290(u8 client, u16* out) {
    if (field_58 != nullptr)
        return Unk_7cced0(field_58, client, out);
    return Unk_7c2d80_Ref();
}

// 0x71008a9860
u8 Unk_23b9048::vf292() {
    if (field_58 != nullptr)
        return Unk_7cb300_get(reinterpret_cast<const Unk_7cb300*>(field_58));
    return 0;
}

// 0x71008a9890
bool Unk_23b9048::vf293(u8 client) {
    if (field_58 == nullptr)
        return false;
    if (Unk_7ca1c0_getField150(reinterpret_cast<const Unk_7ca1c0*>(field_58)) == 2 &&
        !Unk_7fc2f0(vf259(client)))
        return true;
    return false;
}

// 0x71008a9900
u8 Unk_23b9048::vf296() {
    if (field_58 == nullptr)
        return 0;
    u8 position = vf276();
    return Unk_7cbf20(field_58, position);
}
