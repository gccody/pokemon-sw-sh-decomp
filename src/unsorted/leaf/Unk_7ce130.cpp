// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_7ce130 {
    u8 _0[0xa8];
    u64 field_a8;
};
PKMN_OFFSET_ASSERT(Unk_7ce130, field_a8, 0xa8);

// 0x71007ce130
u64 Unk_7ce130_getFielda8(const Unk_7ce130* self) {
    return self->field_a8;
}

struct Unk_7ce140 {
    u8 _0[0x6f];
    u8 field_6f;
};
PKMN_OFFSET_ASSERT(Unk_7ce140, field_6f, 0x6f);

// 0x71007ce140
u32 Unk_7ce140_get(const Unk_7ce140* self) {
    return (self->field_6f >> 6) & 1;
}

struct Unk_7ce150_arg1 {
    u16 field_0;
    u16 field_2;
    u16 field_4;
    u16 field_6;
};
PKMN_OFFSET_ASSERT(Unk_7ce150_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_7ce150_arg1, field_2, 0x2);
PKMN_OFFSET_ASSERT(Unk_7ce150_arg1, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_7ce150_arg1, field_6, 0x6);

struct Unk_7ce150 {
    u8 _0[0x72];
    u16 field_72;
    u16 field_74;
    u16 field_76;
    u16 field_78;
};
PKMN_OFFSET_ASSERT(Unk_7ce150, field_72, 0x72);
PKMN_OFFSET_ASSERT(Unk_7ce150, field_74, 0x74);
PKMN_OFFSET_ASSERT(Unk_7ce150, field_76, 0x76);
PKMN_OFFSET_ASSERT(Unk_7ce150, field_78, 0x78);

// 0x71007ce150
void Unk_7ce150_set(Unk_7ce150* self, const Unk_7ce150_arg1* value) {
    self->field_72 = value->field_0;
    self->field_74 = value->field_2;
    self->field_76 = value->field_4;
    self->field_78 = value->field_6;
}

struct Unk_7cfdd0 {
    u8 _0[0x2b6];
    u8 field_2b6;
};
PKMN_OFFSET_ASSERT(Unk_7cfdd0, field_2b6, 0x2b6);

// 0x71007cfdd0
u8 Unk_7cfdd0_getField2b6(const Unk_7cfdd0* self) {
    return self->field_2b6;
}

struct Unk_7d0a80 {
    u8 _0[0xb8];
    u64 field_b8;
    u8 _c0[0xa];
    u16 field_ca;
    u8 _cc[0x1db];
    u8 field_2a7;
};
PKMN_OFFSET_ASSERT(Unk_7d0a80, field_b8, 0xb8);
PKMN_OFFSET_ASSERT(Unk_7d0a80, field_ca, 0xca);
PKMN_OFFSET_ASSERT(Unk_7d0a80, field_2a7, 0x2a7);

u32 Unk_892e60(u64);

// 0x71007d0a80
void Unk_7d0a80_call(Unk_7d0a80* self, u64 value) {
    self->field_b8 = value;
    self->field_2a7 = 2;
    u32 r0 = Unk_892e60(value);
    self->field_ca = r0;
}

struct Unk_7d0ac0 {
    u8 _0[0x2b5];
    u8 field_2b5;
};
PKMN_OFFSET_ASSERT(Unk_7d0ac0, field_2b5, 0x2b5);

// 0x71007d0ac0
void Unk_7d0ac0_set(Unk_7d0ac0* self) {
    self->field_2b5 = self->field_2b5 | 2;
}

struct Unk_7d0ad0 {
    u8 _0[0x98];
    void* field_98;
};
PKMN_OFFSET_ASSERT(Unk_7d0ad0, field_98, 0x98);

void Unk_892bc0(void*, void*);

// 0x71007d0ad0
void Unk_7d0ad0_call(const Unk_7d0ad0* self, void* value) {
    if (self->field_98 != nullptr) {
        Unk_892bc0(self->field_98, value);
    }
}

struct Unk_7d0b40 {
    u8 _0[0x2b5];
    u8 field_2b5;
    u8 _2b6[0x9a];
    u64 field_350;
};
PKMN_OFFSET_ASSERT(Unk_7d0b40, field_2b5, 0x2b5);
PKMN_OFFSET_ASSERT(Unk_7d0b40, field_350, 0x350);

// 0x71007d0b40
void Unk_7d0b40_set(Unk_7d0b40* self, u64 value) {
    self->field_350 = value;
    self->field_2b5 = self->field_2b5 | 8;
}

struct Unk_7d0b60 {
    u8 _0[0x2b5];
    u8 field_2b5;
    u8 _2b6[0x9a];
    u64 field_350;
};
PKMN_OFFSET_ASSERT(Unk_7d0b60, field_2b5, 0x2b5);
PKMN_OFFSET_ASSERT(Unk_7d0b60, field_350, 0x350);

// 0x71007d0b60
void Unk_7d0b60_set(Unk_7d0b60* self) {
    self->field_350 = 0;
    self->field_2b5 = self->field_2b5 & 0xfffffff7;
}

struct Unk_7d0b80 {
    u8 _0[0xf0];
    u64 field_f0;
};
PKMN_OFFSET_ASSERT(Unk_7d0b80, field_f0, 0xf0);

// 0x71007d0b80
u64 Unk_7d0b80_getFieldf0(const Unk_7d0b80* self) {
    return self->field_f0;
}

struct Unk_7d0b90 {
    u8 _0[0xf0];
    u64 field_f0;
};
PKMN_OFFSET_ASSERT(Unk_7d0b90, field_f0, 0xf0);

// 0x71007d0b90
u64 Unk_7d0b90_getFieldf0(const Unk_7d0b90* self) {
    return self->field_f0;
}

struct Unk_7d0ba0 {
    u8 _0[0x250];
    u64 field_250;
};
PKMN_OFFSET_ASSERT(Unk_7d0ba0, field_250, 0x250);

// 0x71007d0ba0
u64 Unk_7d0ba0_getField250(const Unk_7d0ba0* self) {
    return self->field_250;
}

struct Unk_7d0bb0 {
    u8 _0[0x250];
    u64 field_250;
};
PKMN_OFFSET_ASSERT(Unk_7d0bb0, field_250, 0x250);

// 0x71007d0bb0
u64 Unk_7d0bb0_getField250(const Unk_7d0bb0* self) {
    return self->field_250;
}

struct Unk_7d0bd0_arg1 {
    u64 field_0;
    u16 field_8;
};
PKMN_OFFSET_ASSERT(Unk_7d0bd0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_7d0bd0_arg1, field_8, 0x8);

struct Unk_7d0bd0 {
    u8 _0[0x258];
    u64 field_258;
    u16 field_260;
};
PKMN_OFFSET_ASSERT(Unk_7d0bd0, field_258, 0x258);
PKMN_OFFSET_ASSERT(Unk_7d0bd0, field_260, 0x260);

// 0x71007d0bd0
void Unk_7d0bd0_set(Unk_7d0bd0* self, const Unk_7d0bd0_arg1* value) {
    u64 v0 = value->field_0;
    self->field_260 = value->field_8;
    self->field_258 = v0;
}

struct Unk_7d0c10 {
    u8 _0[0x2b5];
    u8 field_2b5;
};
PKMN_OFFSET_ASSERT(Unk_7d0c10, field_2b5, 0x2b5);

// 0x71007d0c10
void Unk_7d0c10_set(Unk_7d0c10* self) {
    self->field_2b5 = self->field_2b5 | 0x40;
}

void Unk_7d82c0(void*, void*, u32);

// 0x71007d1c90
void Unk_7d1c90_call(void* self, void* value) {
    Unk_7d82c0(self, value, 0);
}

void Unk_7d82c0(void*, void*, u32);

// 0x71007d1ec0
void Unk_7d1ec0_call(void* self, void* value) {
    Unk_7d82c0(self, value, 1);
}

// 0x71007d23f0
u32 Unk_7d23f0_get() {
    return 1;
}

void Unk_7d8d00(void*, void*, u32);

// 0x71007d2990
void Unk_7d2990_call(void* self, void* value) {
    Unk_7d8d00(self, value, 0);
}

struct Unk_7d2c20_358 {
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
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
    virtual void vf70();
    virtual void vf71();
    virtual void vf72();
    virtual void vf73();
    virtual void vf74();
    virtual void vf75();
    virtual void vf76();
    virtual void vf77();
    virtual void vf78();
    virtual void vf79();
    virtual void vf80();
    virtual void vf81();
    virtual void vf82();
    virtual void vf83();
    virtual void vf84();
    virtual void vf85();
    virtual void vf86();
    virtual void vf87();
    virtual void vf88();
    virtual void vf89();
    virtual void vf90();
    virtual void vf91();
    virtual void vf92();
    virtual void vf93();
    virtual void vf94();
    virtual void vf95();
    virtual void vf96();
    virtual void vf97();
    virtual void vf98();
    virtual void vf99();
    virtual void vf100();
    virtual void vf101();
    virtual void vf102();
    virtual void vf103();
    virtual void vf104();
    virtual void vf105();
    virtual void vf106();
    virtual void vf107();
    virtual void vf108();
    virtual void vf109();
    virtual void vf110();
    virtual void vf111();
    virtual void vf112();
    virtual void vf113();
    virtual void vf114();
    virtual void vf115();
    virtual void vf116();
    virtual void vf117();
    virtual void vf118();
    virtual void vf119();
    virtual void vf120();
    virtual void vf121();
    virtual void vf122();
    virtual void vf123();
    virtual void vf124();
    virtual void vf125();
    virtual void vf126();
    virtual void vf127();
    virtual void vf128();
    virtual void vf129();
    virtual void vf130();
    virtual void vf131();
    virtual void vf132();
    virtual void vf133();
    virtual void vf134();
    virtual void vf135();
    virtual void vf136();
    virtual void vf137();
    virtual void vf138();
    virtual void vf139();
    virtual void vf140();
    virtual void vf141();
    virtual void vf142();
    virtual void vf143();
    virtual void vf144();
    virtual void vf145();
    virtual void vf146();
    virtual void vf147();
    virtual void vf148();
    virtual void vf149();
    virtual void vf150();
    virtual void vf151();
    virtual void vf152();
    virtual void vf153();
    virtual void vf154();
    virtual void vf155();
    virtual void vf156();
    virtual void vf157();
    virtual void vf158();
    virtual void vf159();
    virtual void vf160();
    virtual void vf161();
    virtual void vf162();
    virtual void vf163();
    virtual void vf164();
    virtual void vf165();
    virtual void vf166();
    virtual void vf167();
    virtual void vf168();
    virtual void vf169();
    virtual void vf170();
    virtual void vf171();
    virtual void vf172();
    virtual void vf173();
    virtual void vf174();
    virtual void vf175();
    virtual void vf176();
    virtual void vf177();
    virtual void vf178();
    virtual void vf179();
    virtual void vf180();
    virtual void vf181();
    virtual void vf182();
    virtual void vf183();
    virtual void vf184();
    virtual void vf185();
    virtual void vf186();
    virtual void vf187();
    virtual void vf188();
    virtual void vf189();
    virtual void vf190();
    virtual void vf191();
    virtual void vf192();
    virtual void vf193();
    virtual void vf194();
    virtual void vf195();
    virtual void vf196();
    virtual void vf197();
    virtual void vf198();
    virtual void vf199();
    virtual void vf200();
    virtual void vf201();
    virtual void vf202();
    virtual void vf203();
    virtual void vf204();
    virtual void vf205();
    virtual void vf206();
    virtual void vf207();
    virtual void vf208();
    virtual void vf209();
    virtual void vf210();
    virtual void vf211();
    virtual void vf212();
    virtual void vf213();
    virtual void vf214();
    virtual void vf215();
    virtual void vf216();
    virtual void vf217();
    virtual void vf218();
    virtual void vf219();
    virtual void vf220();
    virtual void vf221();
    virtual void vf222();
};

struct Unk_7d2c20 {
    u8 _0[0x358];
    Unk_7d2c20_358* field_358;
};
PKMN_OFFSET_ASSERT(Unk_7d2c20, field_358, 0x358);

// 0x71007d2c20
u32 Unk_7d2c20_call(const Unk_7d2c20* self) {
    self->field_358->vf222();
    return 1;
}

void Unk_7d8960(void*, void*, u32);

// 0x71007d2d30
void Unk_7d2d30_call(void* self, void* value) {
    Unk_7d8960(self, value, 0);
}

struct Unk_7d3a50 {
    u8 _0[0x2b5];
    u8 field_2b5;
};
PKMN_OFFSET_ASSERT(Unk_7d3a50, field_2b5, 0x2b5);

// 0x71007d3a50
u32 Unk_7d3a50_get(const Unk_7d3a50* self) {
    return (self->field_2b5 >> 5) & 1;
}

struct Unk_7d72b0 {
    u8 _0[0x340];
    u64 field_340;
};
PKMN_OFFSET_ASSERT(Unk_7d72b0, field_340, 0x340);

// 0x71007d72b0
u64 Unk_7d72b0_getField340(const Unk_7d72b0* self) {
    return self->field_340;
}

struct Unk_7cb850;
struct Unk_7d90d0 {
    u8 _0[0x58];
    Unk_7cb850* field_58;
};
PKMN_OFFSET_ASSERT(Unk_7d90d0, field_58, 0x58);

u8 Unk_7cb850_getField174(const Unk_7cb850*);
void Unk_8aabb0(void*, u32, u32);
void Unk_8aabe0(void*, u32);

// 0x71007d90d0
void Unk_7d90d0_call(const Unk_7d90d0* self, void* value, u32 arg2) {
    u8 r0 = Unk_7cb850_getField174(self->field_58);
    Unk_8aabb0(value, 1, 0x44);
    Unk_8aabe0(value, r0 & 0xff);
    Unk_8aabe0(value, arg2);
}

struct Unk_7e88f0;
struct Unk_7daa60 {
    u8 _0[0x1f0];
    Unk_7e88f0* field_1f0;
};
PKMN_OFFSET_ASSERT(Unk_7daa60, field_1f0, 0x1f0);

struct Unk_8139c0_Self;
u64 Unk_7e88f0_getField90(const Unk_7e88f0*);
void Unk_817c40(const Unk_8139c0_Self*);

// 0x71007daa60
u32 Unk_7daa60_call(const Unk_7daa60* self) {
    Unk_817c40(reinterpret_cast<const Unk_8139c0_Self*>(Unk_7e88f0_getField90(self->field_1f0)));
    return 1;
}

struct Unk_7e88f0;
struct Unk_7dc9f0 {
    u8 _0[0x1f0];
    Unk_7e88f0* field_1f0;
};
PKMN_OFFSET_ASSERT(Unk_7dc9f0, field_1f0, 0x1f0);

struct Unk_8139c0_Self;
u64 Unk_7e88f0_getField90(const Unk_7e88f0*);
void Unk_817de0(const Unk_8139c0_Self*);

// 0x71007dc9f0
u32 Unk_7dc9f0_call(const Unk_7dc9f0* self) {
    Unk_817de0(reinterpret_cast<const Unk_8139c0_Self*>(Unk_7e88f0_getField90(self->field_1f0)));
    return 1;
}

struct Unk_7de170_358 {
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
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
    virtual void vf70();
    virtual void vf71();
    virtual void vf72();
    virtual void vf73();
    virtual void vf74();
    virtual void vf75();
    virtual void vf76();
    virtual void vf77();
    virtual void vf78();
    virtual void vf79();
    virtual void vf80();
    virtual void vf81();
    virtual void vf82();
    virtual void vf83();
    virtual void vf84();
    virtual void vf85();
    virtual void vf86();
    virtual void vf87();
    virtual void vf88();
    virtual void vf89();
    virtual void vf90();
    virtual void vf91();
    virtual void vf92();
    virtual void vf93();
    virtual void vf94();
    virtual void vf95();
    virtual void vf96();
    virtual void vf97();
    virtual void vf98();
    virtual void vf99();
    virtual void vf100();
    virtual void vf101();
    virtual void vf102();
    virtual void vf103();
    virtual void vf104();
    virtual void vf105();
    virtual void vf106();
    virtual void vf107();
    virtual void vf108();
    virtual void vf109();
    virtual void vf110();
    virtual void vf111();
    virtual void vf112();
    virtual void vf113();
    virtual void vf114();
    virtual void vf115();
    virtual void vf116();
    virtual void vf117();
    virtual void vf118();
    virtual void vf119();
    virtual void vf120();
    virtual void vf121();
    virtual void vf122();
    virtual void vf123();
    virtual void vf124();
    virtual void vf125();
    virtual void vf126();
    virtual void vf127();
    virtual void vf128();
    virtual void vf129();
    virtual void vf130();
    virtual void vf131();
    virtual void vf132();
    virtual void vf133();
    virtual void vf134();
    virtual void vf135();
    virtual void vf136();
    virtual void vf137();
    virtual void vf138();
    virtual void vf139();
    virtual void vf140();
    virtual void vf141();
    virtual void vf142();
    virtual void vf143();
    virtual void vf144();
    virtual void vf145();
    virtual void vf146();
    virtual void vf147();
    virtual void vf148();
    virtual void vf149();
    virtual void vf150();
    virtual void vf151();
    virtual void vf152();
    virtual void vf153();
    virtual void vf154();
    virtual void vf155();
    virtual void vf156();
    virtual void vf157();
    virtual void vf158();
    virtual void vf159();
    virtual void vf160();
    virtual void vf161();
    virtual void vf162();
    virtual void vf163();
    virtual void vf164();
    virtual void vf165();
    virtual void vf166();
    virtual void vf167();
    virtual void vf168();
    virtual void vf169();
    virtual void vf170();
    virtual void vf171();
    virtual void vf172();
    virtual void vf173();
    virtual void vf174();
    virtual void vf175();
    virtual void vf176();
    virtual void vf177();
    virtual void vf178();
    virtual void vf179();
    virtual void vf180();
    virtual void vf181();
    virtual void vf182();
    virtual void vf183();
    virtual void vf184();
    virtual void vf185();
    virtual void vf186();
    virtual void vf187();
    virtual void vf188();
    virtual void vf189();
    virtual void vf190();
    virtual void vf191();
};

struct Unk_7de170 {
    u8 _0[0x358];
    Unk_7de170_358* field_358;
};
PKMN_OFFSET_ASSERT(Unk_7de170, field_358, 0x358);

// 0x71007de170
u32 Unk_7de170_call(const Unk_7de170* self) {
    self->field_358->vf191();
    return 1;
}

// 0x71007dfda0
u32 Unk_7dfda0_get() {
    return 1;
}

struct Unk_7dfdb0 {
    u8 _0[0x2a6];
    u8 field_2a6;
};
PKMN_OFFSET_ASSERT(Unk_7dfdb0, field_2a6, 0x2a6);

// 0x71007dfdb0
u8 Unk_7dfdb0_getField2a6(const Unk_7dfdb0* self) {
    return self->field_2a6;
}

struct Unk_7dfdc0 {
    u8 _0[0x230];
    u64 field_230;
};
PKMN_OFFSET_ASSERT(Unk_7dfdc0, field_230, 0x230);

// 0x71007dfdc0
u64 Unk_7dfdc0_getField230(const Unk_7dfdc0* self) {
    return self->field_230;
}

void Unk_7d64a0(void*, u64, u64, u64);

// 0x71007dfdd0
void Unk_7dfdd0_call(void* self, u64 value, u64 arg2) {
    Unk_7d64a0(self, value, arg2, 0);
}

struct Unk_27cebd0_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u8 _c[0xc];
    u32 field_18;
    u16 field_1c;
    u8 _1e[0x2];
    u32 field_20;
    u16 field_24;
};
PKMN_OFFSET_ASSERT(Unk_27cebd0_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27cebd0_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27cebd0_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27cebd0_Data, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_27cebd0_Data, field_1c, 0x1c);
PKMN_OFFSET_ASSERT(Unk_27cebd0_Data, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_27cebd0_Data, field_24, 0x24);

extern Unk_27cebd0_Data Unk_27cebd0 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71007e3730
void Unk_7e3730_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27cebd0.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27cebd0.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27cebd0.field_24 = 0xffff;
    Unk_27cebd0.field_1c = 0;
    Unk_27cebd0.field_8 = r2;
    Unk_27cebd0.field_18 = 0;
    Unk_27cebd0.field_20 = 0xffffffff;
}
