// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_d69340 {
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
    virtual void vf16();
    virtual u32 vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    u8 _8[0x1e0];
    u32 field_1e8;
    u8 _1ec[0x539];
    u8 field_725;
    u8 field_726;
};
PKMN_OFFSET_ASSERT(Unk_d69340, field_1e8, 0x1e8);
PKMN_OFFSET_ASSERT(Unk_d69340, field_725, 0x725);
PKMN_OFFSET_ASSERT(Unk_d69340, field_726, 0x726);

// 0x7100d69340
void Unk_d69340_call(Unk_d69340* self) {
    if (self->field_725 != 0) {
        self->field_725 = 0;
        if (self->field_726 == 0)
            return;
        self->vf45();
        u32 r1 = self->vf17();
        if ((r1 & 1) != 0)
            return;
        self->field_1e8 = 1;
    }
}

struct Unk_d699d0 {
    u8 _0[0x6c0];
    u64 field_6c0;
    u64 field_6c8;
};
PKMN_OFFSET_ASSERT(Unk_d699d0, field_6c0, 0x6c0);
PKMN_OFFSET_ASSERT(Unk_d699d0, field_6c8, 0x6c8);

// 0x7100d699d0
void Unk_d699d0_set(Unk_d699d0* self) {
    if (self->field_6c0 != self->field_6c8) {
        self->field_6c8 = self->field_6c8 - 0x30;
    }
}

struct Unk_d699f0 {
    u8 _0[0x720];
    u8 field_720;
    u8 field_721;
};
PKMN_OFFSET_ASSERT(Unk_d699f0, field_720, 0x720);
PKMN_OFFSET_ASSERT(Unk_d699f0, field_721, 0x721);

// 0x7100d699f0
u8 Unk_d699f0_get(const Unk_d699f0* self) {
    if (self->field_720 != 0) {
        return self->field_720;
    }
    return self->field_721;
}

struct Unk_d69a10 {
    u8 _0[0x721];
    u8 field_721;
};
PKMN_OFFSET_ASSERT(Unk_d69a10, field_721, 0x721);

// 0x7100d69a10
u8 Unk_d69a10_getField721(const Unk_d69a10* self) {
    return self->field_721;
}
