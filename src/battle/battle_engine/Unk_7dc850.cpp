// Scope: common
// Battle client commands (0x71007dc850 to 0x71007dcd30): each reads the
// command's arguments and calls the matching server command
// (src/battle/battle_engine/Unk_8139c0.cpp), or starts something on the view
// and waits for it. Placeholder names: rename once the class is known.
#include "battle/battle_engine/Unk_7dc850.h"

// The server commands (src/battle/battle_engine/Unk_8139c0.cpp,
// Unk_817a50.cpp and Unk_817e30.cpp).
void Unk_817e00(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_817e30(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_817e90(const Unk_8139c0_Self* self, u8 pokeId, u8 value);
void Unk_817ed0(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_817f00(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_817f30(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_817f60(const Unk_8139c0_Self* self, u8 pokeId, u8 value);
void Unk_818210(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_818240(const Unk_8139c0_Self* self, u8 pokeId);
void Unk_818270(const Unk_8139c0_Self* self, u32 value);

// Not decompiled yet (src/battle/battle_engine/Unk_7c2d80.cpp would hold it).
u8 Unk_7cb690(const Unk_7c2d80_Main* self, u8 position);

// Declared as src/unsorted/leaf names them.
struct Unk_7fc2e0;
u8 Unk_7fc2e0_getField30(const Unk_7fc2e0* self);
struct Unk_7ef330;
u64 Unk_7ef330_getField60(const Unk_7ef330* self);

static inline u8 Unk_7dc850_PartyCount(const Unk_7fc430_Party* party) {
    return Unk_7fc2e0_getField30(reinterpret_cast<const Unk_7fc2e0*>(party));
}

// 0x71007dc850
bool Unk_7dc850(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    u8 value = args[1];
    Unk_817e90(Unk_7cdac0_Server(self), pokeId, value);
    return true;
}

// 0x71007dc890
bool Unk_7dc890(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    Unk_817ed0(Unk_7cdac0_Server(self), pokeId);
    return true;
}

// 0x71007dc8c0
bool Unk_7dc8c0(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    Unk_817f00(Unk_7cdac0_Server(self), pokeId);
    return true;
}

// 0x71007dc8f0
bool Unk_7dc8f0(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    Unk_817f30(Unk_7cdac0_Server(self), pokeId);
    return true;
}

// 0x71007dc920
bool Unk_7dc920(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    u8 value = args[1];
    Unk_817f60(Unk_7cdac0_Server(self), pokeId, value);
    return true;
}

// 0x71007dc960
bool Unk_7dc960(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    Unk_818210(Unk_7cdac0_Server(self), pokeId);
    return true;
}

// 0x71007dc990
bool Unk_7dc990(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    Unk_818240(Unk_7cdac0_Server(self), pokeId);
    return true;
}

// 0x71007dc9c0
bool Unk_7dc9c0(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u32 value = args[0];
    Unk_818270(Unk_7cdac0_Server(self), value);
    return true;
}

// 0x71007dca10
bool Unk_7dca10(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    Unk_817e00(Unk_7cdac0_Server(self), pokeId);
    return true;
}

// 0x71007dca40
bool Unk_7dca40(Unk_7cdac0_Self* self, u32*, const u32* args) {
    u8 pokeId = args[0];
    Unk_817e30(Unk_7cdac0_Server(self), pokeId);
    return true;
}

// 0x71007dcb70
bool Unk_7dcb70(Unk_7cdac0_Self* self, u32* seq, const u32* args) {
    u8 arg1 = args[0];
    u8 pokeId1 = args[1];
    u8 pokeId2 = args[2];
    u8 count1 = Unk_7cb690(self->field_58, pokeId1);
    u8 count2 = Unk_7cb690(self->field_58, pokeId2);
    u8 position1 = Unk_7cb540(self->field_58, pokeId1);
    u8 position2 = Unk_7cb540(self->field_58, pokeId2);
    switch (*seq) {
        case 0:
            Unk_7cdac0_GetView(self)->vf116(arg1, position1, position2, count1, count2);
            (*seq)++;
            break;
        case 1:
            if (Unk_7cdac0_GetView(self)->vf117())
                return true;
            break;
    }
    return false;
}

// 0x71007dcc50
bool Unk_7dcc50(Unk_7cdac0_Self* self, u32*, const u32*) {
    for (s32 i = 5; i >= 0; i--) {
        Unk_7dc850_Counts* counts = &self->field_368[i];
        counts->field_0 = 0;
        counts->field_4 = 0;
        counts->field_8 = 0;
        counts->field_c = 0;
        counts->field_10 = 0;
        counts->field_14 = 0;
        counts->field_18 = 0;
    }
    self->field_360->vf14();
    for (u8 i = 0; i < Unk_7dc850_PartyCount(self->field_340); i++) {
        Unk_7ee6b0* poke = Unk_7fc450(self->field_340, i);
        u64 value = Unk_7ef330_getField60(reinterpret_cast<const Unk_7ef330*>(poke));
        self->field_360->vf5(value);
    }
    return true;
}
