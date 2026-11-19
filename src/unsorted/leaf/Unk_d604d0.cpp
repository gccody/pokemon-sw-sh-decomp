// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_d604d0 {
    u8 _0[0x50];
    u64 field_50;
};
PKMN_OFFSET_ASSERT(Unk_d604d0, field_50, 0x50);

// 0x7100d604d0
void Unk_d604d0_set(Unk_d604d0* self) {
    self->field_50 = 0xcbf29ce484222645;
}

struct Unk_d608a0 {
    u8 _0[0x48];
    u64 field_48;
    u8 _50[0x8];
    void* field_58;
    u8 _60[0x18];
    u8 field_78;
};
PKMN_OFFSET_ASSERT(Unk_d608a0, field_48, 0x48);
PKMN_OFFSET_ASSERT(Unk_d608a0, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_d608a0, field_78, 0x78);

void Unk_791400(void*);

// 0x7100d608a0
void Unk_d608a0_call(Unk_d608a0* self) {
    if (self->field_78 != 0) {
        Unk_791400(self->field_58);
        self->field_78 = 0;
        self->field_48 = 0xcbf29ce484222645;
    }
}

void Unk_d616e0(void*);

// 0x7100d616d0
void Unk_d616d0_call(void* self) {
    Unk_d616e0(self);
}

struct Unk_d61e70 {
    u8 _0[0x4c0];
    u32 field_4c0;
};
PKMN_OFFSET_ASSERT(Unk_d61e70, field_4c0, 0x4c0);

// 0x7100d61e70
bool Unk_d61e70_check(const Unk_d61e70* self, u32 value) {
    return self->field_4c0 == value;
}
