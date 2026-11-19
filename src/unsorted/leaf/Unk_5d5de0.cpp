// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_5d5df0(void*, void*);

// 0x71005d5de0
void Unk_5d5de0_call(void* self, void* value) {
    Unk_5d5df0(self, value);
}

// 0x71005d9e70
void Unk_5d9e70_update() {}

struct Unk_5d9e80 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_5d9e80, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_5d9e80, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_5d9e80, field_10, 0x10);

// 0x71005d9e80
void Unk_5d9e80_set(const Unk_5d9e80* self, Unk_5d9e80* value) {
    *value = *self;
}

struct Unk_5d9ea0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_5d9ea0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_5d9ea0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_5d9ea0, field_10, 0x10);

// 0x71005d9ea0
void Unk_5d9ea0_set(const Unk_5d9ea0* self, Unk_5d9ea0* value) {
    *value = *self;
}

struct Unk_5dc5d0_arg3 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual u32 vf16(u64);
};

struct Unk_5dc5d0 {
    u8 _0[0x11c];
    u32 field_11c;
};
PKMN_OFFSET_ASSERT(Unk_5dc5d0, field_11c, 0x11c);

void Unk_5dc230();

// 0x71005dc5d0
void Unk_5dc5d0_call(Unk_5dc5d0* self,
                     u32 /*unused*/,
                     u32 /*unused*/,
                     Unk_5dc5d0_arg3* arg3,
                     u64 arg4) {
    Unk_5dc230();
    u32 r1 = arg3->vf16(arg4);
    self->field_11c = r1;
}
