// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_b334b0 {
    u8 _0[0x58];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_b334b0, field_58, 0x58);

void Unk_b34480(u64);

// 0x7100b334b0
void Unk_b334b0_call(const Unk_b334b0* self) {
    Unk_b34480(self->field_58);
}

struct Unk_b334e0 {
    u8 _0[0x58];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_b334e0, field_58, 0x58);

void Unk_b37020(u64);

// 0x7100b334e0
void Unk_b334e0_call(const Unk_b334e0* self) {
    Unk_b37020(self->field_58);
}

struct Unk_b334f0 {
    u8 _0[0x58];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_b334f0, field_58, 0x58);

void Unk_b374b0(u64);

// 0x7100b334f0
void Unk_b334f0_call(const Unk_b334f0* self) {
    Unk_b374b0(self->field_58);
}

struct Unk_b33500 {
    u8 _0[0x58];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_b33500, field_58, 0x58);

void Unk_b37230(u64);

// 0x7100b33500
void Unk_b33500_call(const Unk_b33500* self) {
    Unk_b37230(self->field_58);
}

struct Unk_b37010 {
    u8 _0[0x48];
    u64 field_48;
};
PKMN_OFFSET_ASSERT(Unk_b37010, field_48, 0x48);

// 0x7100b37010
u64 Unk_b37010_getField48(const Unk_b37010* self) {
    return self->field_48;
}

struct Unk_b46a10_90 {
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
    virtual void vf29(u32);
};

struct Unk_b46a10 {
    u8 _0[0x90];
    Unk_b46a10_90* field_90;
};
PKMN_OFFSET_ASSERT(Unk_b46a10, field_90, 0x90);

// 0x7100b46a10
void Unk_b46a10_call(const Unk_b46a10* self, bool value) {
    self->field_90->vf29(value);
}

struct Unk_b47a40_90 {
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
    virtual void vf31(u64, u64);
};

struct Unk_b47a40 {
    u8 _0[0x90];
    Unk_b47a40_90* field_90;
};
PKMN_OFFSET_ASSERT(Unk_b47a40, field_90, 0x90);

// 0x7100b47a40
void Unk_b47a40_call(const Unk_b47a40* self, u64 value, u64 arg2) {
    self->field_90->vf31(value, arg2);
}

struct Unk_b47a50_90 {
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
    virtual void vf34(u32, u64, u64, u64, u32);
};

struct Unk_b47a50 {
    u8 _0[0x90];
    Unk_b47a50_90* field_90;
};
PKMN_OFFSET_ASSERT(Unk_b47a50, field_90, 0x90);

// 0x7100b47a50
void Unk_b47a50_call(const Unk_b47a50* self, bool value, u64 arg2, u64 arg3, u64 arg4, bool arg5) {
    self->field_90->vf34(value, arg2, arg3, arg4, arg5);
}

struct Unk_b47a70_90 {
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
};

struct Unk_b47a70 {
    u8 _0[0x90];
    Unk_b47a70_90* field_90;
};
PKMN_OFFSET_ASSERT(Unk_b47a70, field_90, 0x90);

// 0x7100b47a70
void Unk_b47a70_call(const Unk_b47a70* self) {
    self->field_90->vf35();
}

struct Unk_b47a80_90 {
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
};

struct Unk_b47a80 {
    u8 _0[0x90];
    Unk_b47a80_90* field_90;
};
PKMN_OFFSET_ASSERT(Unk_b47a80, field_90, 0x90);

// 0x7100b47a80
void Unk_b47a80_call(const Unk_b47a80* self) {
    self->field_90->vf36();
}

struct Unk_b47a90_90 {
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
};

struct Unk_b47a90 {
    u8 _0[0x90];
    Unk_b47a90_90* field_90;
};
PKMN_OFFSET_ASSERT(Unk_b47a90, field_90, 0x90);

// 0x7100b47a90
void Unk_b47a90_call(const Unk_b47a90* self) {
    self->field_90->vf32();
}

struct Unk_b47aa0_90 {
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
    virtual void vf33(u64);
};

struct Unk_b47aa0 {
    u8 _0[0x90];
    Unk_b47aa0_90* field_90;
};
PKMN_OFFSET_ASSERT(Unk_b47aa0, field_90, 0x90);

// 0x7100b47aa0
void Unk_b47aa0_call(const Unk_b47aa0* self, u64 value) {
    self->field_90->vf33(value);
}

struct Unk_b47ab0_90 {
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
    virtual void vf37(u64, u64);
};

struct Unk_b47ab0 {
    u8 _0[0x90];
    Unk_b47ab0_90* field_90;
};
PKMN_OFFSET_ASSERT(Unk_b47ab0, field_90, 0x90);

// 0x7100b47ab0
void Unk_b47ab0_call(const Unk_b47ab0* self, u64 value, u64 arg2) {
    self->field_90->vf37(value, arg2);
}

struct Unk_b48260_90 {
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
    virtual void vf44(u64);
};

struct Unk_b48260 {
    u8 _0[0x90];
    Unk_b48260_90* field_90;
};
PKMN_OFFSET_ASSERT(Unk_b48260, field_90, 0x90);

// 0x7100b48260
void Unk_b48260_call(const Unk_b48260* self, u64 value) {
    self->field_90->vf44(value);
}

struct Unk_b48270_90 {
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
    virtual u64 vf45();
};

struct Unk_b48270 {
    u8 _0[0x90];
    Unk_b48270_90* field_90;
};
PKMN_OFFSET_ASSERT(Unk_b48270, field_90, 0x90);

void Unk_b49620(u64, u32);

// 0x7100b48270
void Unk_b48270_call(const Unk_b48270* self, bool value) {
    u64 r0 = self->field_90->vf45();
    if (r0 != 0) {
        Unk_b49620(r0, value);
    }
}

struct Unk_b4a380 {
    u8 _0[0x198];
    bool field_198;
};
PKMN_OFFSET_ASSERT(Unk_b4a380, field_198, 0x198);

// 0x7100b4a380
void Unk_b4a380_set(Unk_b4a380* self, bool value) {
    self->field_198 = value;
}

struct Unk_b4a450 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_b4a450, field_8, 0x8);

// 0x7100b4a450
void Unk_b4a450_setField8(Unk_b4a450* self, u64 value) {
    self->field_8 = value;
}

struct Unk_b4c050 {
    u8 _0[0x3830];
    u64 field_3830;
};
PKMN_OFFSET_ASSERT(Unk_b4c050, field_3830, 0x3830);

void Unk_b565e0(u64);

// 0x7100b4c050
void Unk_b4c050_call(const Unk_b4c050* self) {
    if (self->field_3830 != 0) {
        Unk_b565e0(self->field_3830);
    }
}

struct Unk_b4c060 {
    u8 _0[0x3830];
    u64 field_3830;
};
PKMN_OFFSET_ASSERT(Unk_b4c060, field_3830, 0x3830);

void Unk_b56610(u64);

// 0x7100b4c060
void Unk_b4c060_call(const Unk_b4c060* self) {
    Unk_b56610(self->field_3830);
}

struct Unk_b4c070 {
    u8 _0[0x3830];
    u64 field_3830;
};
PKMN_OFFSET_ASSERT(Unk_b4c070, field_3830, 0x3830);

void Unk_b56630(u64);

// 0x7100b4c070
void Unk_b4c070_call(const Unk_b4c070* self) {
    Unk_b56630(self->field_3830);
}

struct Unk_b4c080 {
    u8 _0[0x3830];
    u64 field_3830;
};
PKMN_OFFSET_ASSERT(Unk_b4c080, field_3830, 0x3830);

void Unk_b56650(u64);

// 0x7100b4c080
void Unk_b4c080_call(const Unk_b4c080* self) {
    Unk_b56650(self->field_3830);
}

struct Unk_b57170 {
    u8 _0[0x240];
    u64 field_240;
};
PKMN_OFFSET_ASSERT(Unk_b57170, field_240, 0x240);

// 0x7100b57170
u64 Unk_b57170_getField240(const Unk_b57170* self) {
    return self->field_240;
}

struct Unk_b57180 {
    u8 _0[0x248];
    u64 field_248;
};
PKMN_OFFSET_ASSERT(Unk_b57180, field_248, 0x248);

// 0x7100b57180
u64 Unk_b57180_getField248(const Unk_b57180* self) {
    return self->field_248;
}

struct Unk_b571b0 {
    u8 _0[0x250];
    u64 field_250;
};
PKMN_OFFSET_ASSERT(Unk_b571b0, field_250, 0x250);

// 0x7100b571b0
u64 Unk_b571b0_getField250(const Unk_b571b0* self) {
    return self->field_250;
}

struct Unk_b571c0 {
    u8 _0[0x258];
    u64 field_258;
};
PKMN_OFFSET_ASSERT(Unk_b571c0, field_258, 0x258);

// 0x7100b571c0
u64 Unk_b571c0_getField258(const Unk_b571c0* self) {
    return self->field_258;
}

struct Unk_b571d0 {
    u8 _0[0x260];
    u64 field_260;
};
PKMN_OFFSET_ASSERT(Unk_b571d0, field_260, 0x260);

// 0x7100b571d0
u64 Unk_b571d0_getField260(const Unk_b571d0* self) {
    return self->field_260;
}

struct Unk_b571e0 {
    u8 _0[0x268];
    u64 field_268;
};
PKMN_OFFSET_ASSERT(Unk_b571e0, field_268, 0x268);

// 0x7100b571e0
u64 Unk_b571e0_getField268(const Unk_b571e0* self) {
    return self->field_268;
}

struct Unk_b571f0 {
    u8 _0[0x270];
    u64 field_270;
};
PKMN_OFFSET_ASSERT(Unk_b571f0, field_270, 0x270);

// 0x7100b571f0
u64 Unk_b571f0_getField270(const Unk_b571f0* self) {
    return self->field_270;
}

struct Unk_b57200 {
    u8 _0[0x278];
    u64 field_278;
};
PKMN_OFFSET_ASSERT(Unk_b57200, field_278, 0x278);

// 0x7100b57200
u64 Unk_b57200_getField278(const Unk_b57200* self) {
    return self->field_278;
}

struct Unk_b57210 {
    u8 _0[0x280];
    u64 field_280;
};
PKMN_OFFSET_ASSERT(Unk_b57210, field_280, 0x280);

// 0x7100b57210
u64 Unk_b57210_getField280(const Unk_b57210* self) {
    return self->field_280;
}

// 0x7100b572c0
void Unk_b572c0_update() {}

struct Unk_b572d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_b572d0_arg1, field_0, 0x0);

struct Unk_b572d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_b572d0, field_0, 0x0);

// 0x7100b572d0
void Unk_b572d0_set(const Unk_b572d0* self, Unk_b572d0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_b572e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_b572e0_arg1, field_0, 0x0);

struct Unk_b572e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_b572e0, field_0, 0x0);

// 0x7100b572e0
void Unk_b572e0_set(const Unk_b572e0* self, Unk_b572e0_arg1* value) {
    value->field_0 = self->field_0;
}
