#pragma once
// What measures a bus (vtable 0x71023847d8). Written from the executable.
// Placeholder names.
#include "Unk_24df148.h"

extern void* Unk_23847d8[];

// What measures a bus: 0x48 bytes (vtable 0x71023847d8).
struct Unk_23847d8_T {
    void** field_0;  // vptr
    Unk_24df148_Config field_8;
    void* field_10;
    void* field_18;
    void* field_20;
    void* field_28;
    void* field_30;
    void* field_38;
    u32 field_40;
    u32 field_44;  // what it measures

    Unk_23847d8_T(Unk_24df148_Config config) {
        field_0 = Unk_23847d8 + 2;
        field_8 = config;
        field_10 = nullptr;
        field_18 = nullptr;
        field_20 = nullptr;
        field_28 = nullptr;
        field_30 = nullptr;
        field_38 = nullptr;
        field_40 = 0;
        field_44 = 0;
    }
};
PKMN_SIZE_ASSERT(Unk_23847d8_T, 0x48);
