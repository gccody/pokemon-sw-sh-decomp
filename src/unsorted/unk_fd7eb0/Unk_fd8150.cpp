// Scope: common
// The object built at 0x7100fd7eb0: its state, its settings and what it tells
// its listener. Placeholder names: rename once the class is known.
#include "unsorted/unk_fd7eb0/Unk_fd7eb0.h"

u32 Unk_67c120(u64, u64, u16);
u32 Unk_7c2af0(u8 kind, bool flag);

// 0x7100fd8150
// NON_MATCHING: the two compares fold into a range check (sub, cmp, cset) here;
// the original keeps them as a compare-and-branch chain (2, then 1).
bool Unk_fd8150_check(const Unk_fd7eb0* self) {
    u8 state = self->field_60->field_54;
    return state == 2 || state == 1;
}

// 0x7100fd8190
void Unk_fd8190_setInfo(Unk_fd7eb0* self, const Unk_fd7eb0_Info& info) {
    self->field_80 = info;
}

// 0x7100fd81f0
Unk_fd7eb0_Info Unk_fd81f0_getInfo(const Unk_fd7eb0* self) {
    return self->field_80;
}

// 0x7100fd8220
void Unk_fd8220_setSetup(Unk_fd7eb0* self, const Unk_fd7eb0_Setup& setup) {
    self->field_68->field_68 = setup;
}

// 0x7100fd8290
Unk_fd7eb0_Setup Unk_fd8290_getSetup(const Unk_fd7eb0* self) {
    return self->field_68->field_68;
}

// 0x7100fd8300
void Unk_fd8300_setRef(Unk_fd7eb0* self, const Unk_fd7eb0_Ref& ref) {
    Unk_fd7eb0_Assign(self->field_68->field_ee8, ref);
}

// 0x7100fd8360
void Unk_fd8360_setEntries(Unk_fd7eb0* self,
                           const Unk_fd7eb0_Optional<Unk_fd7eb0_Entries>& entries) {
    self->field_68->field_ef8 = entries;
}

// 0x7100fd8480
void Unk_fd8480_setRange(Unk_fd7eb0* self, const Unk_fd7eb0_Optional<Unk_fd7eb0_Range>& range) {
    self->field_68->field_f30 = range;
}

// 0x7100fd84f0
void Unk_fd84f0_setSlot(Unk_fd7eb0* self, u8 index, const u16* name, u8 value, u8 a, u8 b) {
    Unk_67c120(reinterpret_cast<u64>(self->field_60->field_b8[index].field_0),
               reinterpret_cast<u64>(name), 13);
    self->field_60->field_b8[index].field_1c = value;
    self->field_60->field_b8[index].field_1a = a;
    self->field_60->field_b8[index].field_1b = b;
    if (Unk_fd7eb0_Listener* listener = self->field_60->field_198.Get())
        listener->vf1();
}

// 0x7100fd85d0
void Unk_fd85d0_notify(Unk_fd7eb0* self) {
    if (Unk_fd7eb0_Listener* listener = self->field_60->field_198.Get())
        listener->vf0();
}

// 0x7100fd8600
void Unk_fd8600_setName(Unk_fd7eb0* self, const u16* name, u8 kind) {
    Unk_67c120(reinterpret_cast<u64>(self->field_60->field_168), reinterpret_cast<u64>(name), 11);
    self->field_60->field_184 = Unk_7c2af0(kind, false);
}
