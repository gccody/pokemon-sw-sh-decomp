// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_583240_arg1 {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
};
PKMN_OFFSET_ASSERT(Unk_583240_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_583240_arg1, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_583240_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_583240_arg1, field_c, 0xc);

struct Unk_583240 {
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
    virtual void vf17();
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
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50(u32, u32);
};

// 0x7100583240
u32 Unk_583240_call(Unk_583240* self, const Unk_583240_arg1* value) {
    self->vf50(value->field_0, 1);
    self->vf50(value->field_4, 1);
    self->vf50(value->field_8, 1);
    self->vf50(value->field_c, 1);
    return 1;
}

struct Unk_5832c0_arg1 {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
};
PKMN_OFFSET_ASSERT(Unk_5832c0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_5832c0_arg1, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_5832c0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_5832c0_arg1, field_c, 0xc);

struct Unk_5832c0 {
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
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual u32 vf27(u32);
};

// 0x71005832c0
u32 Unk_5832c0_call(Unk_5832c0* self, Unk_5832c0_arg1* value) {
    u32 r0 = self->vf27(1);
    value->field_0 = r0;
    u32 r1 = self->vf27(1);
    value->field_4 = r1;
    u32 r2 = self->vf27(1);
    value->field_8 = r2;
    u32 r3 = self->vf27(1);
    value->field_c = r3;
    return 1;
}
