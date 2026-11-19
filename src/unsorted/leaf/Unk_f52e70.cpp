// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

u32 Unk_eb6530();

// 0x7100f52e70
u32 Unk_f52e70_call() {
    u32 r0 = Unk_eb6530();
    return ~r0 & 1;
}

struct Unk_f52f50 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_f52f50, field_5cc, 0x5cc);

// 0x7100f52f50
void Unk_f52f50_clearField5cc(Unk_f52f50* self) {
    self->field_5cc = 0;
}

void Unk_f530a0(void*, u64, u64);

// 0x7100f53060
void Unk_f53060_call(void* self, bool value) {
    if ((value) != 0) {
        Unk_f530a0(self, 0x30858e87c637690c, 0x3de4ebb25b188dbc);
        return;
    }
    Unk_f530a0(self, 0x307b9c87c62f2c51, 0x3de4ebb25b188dbc);
}

struct Unk_f531c0 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_f531c0, field_5cc, 0x5cc);

// 0x7100f531c0
u32 Unk_f531c0_getField5cc(const Unk_f531c0* self) {
    return self->field_5cc;
}
