// Scope: common
// Battle event handlers (0x7100880c80-0x7100880f10), after the TU of
// Unk_880840.cpp. Placeholder names.
#include "unsorted/unk_82e410/Unk_880840.h"

// 0x7100880c80
void Unk_880c80(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) == pokeId)
        Unk_819640_call(static_cast<const Unk_819640*>(self), 0x48, 1);
}

// NON_MATCHING: Unk_880b40 is named (void*, u64, u32), so the u8 is extended
// (and the registers swap). Matches with Unk_880b40(void*, u8, u32).
// 0x7100880cd0
void Unk_880cd0(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) == pokeId)
        Unk_880b40(self, pokeId, 2);
}

// 0x7100880d50
void Unk_880d50(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 0, Unk_81b7e0(flow, pokeId, 3));
}

// NON_MATCHING: Unk_880b40 is named (void*, u64, u32), so the u8 is extended
// (and the registers swap). Matches with Unk_880b40(void*, u8, u32).
// 0x7100880d80
void Unk_880d80(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) == pokeId)
        Unk_880b40(self, pokeId, 3);
}

// 0x7100880e00
void Unk_880e00(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 0, Unk_81b7e0(flow, pokeId, 5));
}

// 0x7100880e30
void Unk_880e30(void* self, u8 pokeId) {
    Unk_880b40_Arg arg;
    arg.field_26 = 1;
    arg.field_0 = pokeId;
    arg.field_8 = pokeId;
    arg.field_4 = 5;
    Unk_819c80(static_cast<const Unk_819600_Self*>(self), &arg);
}

// 0x7100880ee0
void Unk_880ee0(void* self, u8 pokeId) {
    const Unk_819600_Self* flow = static_cast<const Unk_819600_Self*>(self);
    Unk_8196b0_call(static_cast<const Unk_8196b0*>(self), 0, Unk_81b7e0(flow, pokeId, 4));
}

// NON_MATCHING: Unk_880b40 is named (void*, u64, u32), so the u8 is extended
// (and the registers swap). Matches with Unk_880b40(void*, u8, u32).
// 0x7100880f10
void Unk_880f10(void* self, u8 pokeId) {
    if (Unk_819600_call(static_cast<const Unk_819600*>(self), 2) == pokeId)
        Unk_880b40(self, pokeId, 4);
}
