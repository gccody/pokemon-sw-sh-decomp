// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_95bd00 {
    u8 _0[0x5c8];
    u64 field_5c8;
};
PKMN_OFFSET_ASSERT(Unk_95bd00, field_5c8, 0x5c8);

void Unk_98a6f0(u64);

// 0x710095bd00
void Unk_95bd00_call(const Unk_95bd00* self) {
    Unk_98a6f0(self->field_5c8);
}

struct Unk_95bde0 {
    u8 _0[0x5c8];
    u64 field_5c8;
};
PKMN_OFFSET_ASSERT(Unk_95bde0, field_5c8, 0x5c8);

void Unk_98aaa0(u64, u32);

// 0x710095bde0
void Unk_95bde0_call(const Unk_95bde0* self) {
    Unk_98aaa0(self->field_5c8, 0);
}

struct Unk_95bdf0 {
    u8 _0[0x5c8];
    u64 field_5c8;
};
PKMN_OFFSET_ASSERT(Unk_95bdf0, field_5c8, 0x5c8);

void Unk_98a8d0(u64);

// 0x710095bdf0
void Unk_95bdf0_call(const Unk_95bdf0* self) {
    Unk_98a8d0(self->field_5c8);
}

struct Unk_95be00 {
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
    virtual void vf223();
    virtual void vf224();
    virtual void vf225();
    virtual void vf226();
    virtual void vf227();
    virtual void vf228();
    virtual void vf229();
    virtual void vf230();
    virtual void vf231();
    virtual void vf232();
    virtual void vf233();
    virtual void vf234();
    virtual void vf235();
    virtual void vf236();
    virtual void vf237();
    virtual void vf238();
    virtual void vf239();
    virtual void vf240();
    virtual void vf241();
    virtual void vf242();
    virtual void vf243();
    virtual void vf244();
    virtual void vf245();
    virtual void vf246();
    virtual void vf247();
    virtual void vf248();
    virtual void vf249();
    virtual void vf250();
    virtual void vf251();
    virtual void vf252();
    virtual void vf253();
    virtual void vf254();
    virtual void vf255();
    virtual void vf256();
    virtual void vf257();
    virtual void vf258();
    virtual void vf259();
    virtual void vf260();
    virtual void vf261();
    virtual void vf262();
    virtual void vf263();
    virtual void vf264();
    virtual void vf265();
    virtual void vf266();
    virtual void vf267();
    virtual void vf268();
    virtual void vf269();
    virtual void vf270();
    virtual void vf271();
    virtual void vf272();
    virtual void vf273();
    virtual void vf274();
    virtual void vf275();
    virtual void vf276();
    virtual void vf277();
    virtual void vf278();
    virtual void vf279();
    virtual void vf280();
    virtual void vf281();
    virtual void vf282();
    virtual void vf283();
    virtual void vf284();
    virtual void vf285();
    virtual void vf286();
    virtual void vf287();
    virtual void vf288();
    virtual void vf289();
    virtual void vf290();
    virtual void vf291();
    virtual void vf292();
    virtual void vf293();
    virtual void vf294();
    virtual void vf295();
    virtual void vf296();
    virtual void vf297();
    virtual void vf298();
    virtual void vf299();
    virtual void vf300();
    virtual void vf301();
    virtual void vf302();
    virtual void vf303();
    virtual void vf304();
    virtual void vf305();
    virtual void vf306();
    virtual void vf307();
    virtual void vf308();
    virtual void vf309();
    virtual void vf310();
    virtual void vf311();
    virtual void vf312();
    virtual void vf313();
    virtual void vf314();
    virtual void vf315();
    virtual void vf316();
    virtual void vf317();
    virtual void vf318();
    virtual void vf319();
    virtual void vf320();
    virtual void vf321();
    virtual void vf322();
};

// 0x710095be00
void Unk_95be00_call(Unk_95be00* self) {
    self->vf322();
}

struct Unk_960610 {
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
    virtual void vf223();
    virtual void vf224();
    virtual void vf225();
    virtual void vf226();
    virtual void vf227();
    virtual void vf228();
    virtual void vf229();
    virtual void vf230();
    virtual void vf231(u64);
};

// 0x7100960610
void Unk_960610_call(Unk_960610* self, u64 value) {
    self->vf231(value);
}

struct Unk_965ae0 {
    u8 _0[0x5b8];
    u64 field_5b8;
};
PKMN_OFFSET_ASSERT(Unk_965ae0, field_5b8, 0x5b8);

void Unk_c67c60(u64);

// 0x7100965ae0
void Unk_965ae0_call(const Unk_965ae0* self) {
    if (self->field_5b8 != 0) {
        Unk_c67c60(self->field_5b8);
    }
}

// 0x710096a390
void Unk_96a390_update() {}

// 0x710096a570
void Unk_96a570_update() {}

struct Unk_96a580_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96a580_arg1, field_0, 0x0);

struct Unk_96a580 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96a580, field_0, 0x0);

// 0x710096a580
void Unk_96a580_set(const Unk_96a580* self, Unk_96a580_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_96a590_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96a590_arg1, field_0, 0x0);

struct Unk_96a590 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96a590, field_0, 0x0);

// 0x710096a590
void Unk_96a590_set(const Unk_96a590* self, Unk_96a590_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_96af20 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_96af20, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_96af20, field_8, 0x8);

// 0x710096af20
void Unk_96af20_set(const Unk_96af20* self, Unk_96af20* value) {
    *value = *self;
}

struct Unk_96af30 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_96af30, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_96af30, field_8, 0x8);

// 0x710096af30
void Unk_96af30_set(const Unk_96af30* self, Unk_96af30* value) {
    *value = *self;
}

// 0x710096b000
void Unk_96b000_update() {}

struct Unk_96b010_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96b010_arg1, field_0, 0x0);

struct Unk_96b010 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96b010, field_0, 0x0);

// 0x710096b010
void Unk_96b010_set(const Unk_96b010* self, Unk_96b010_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_96b020_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96b020_arg1, field_0, 0x0);

struct Unk_96b020 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96b020, field_0, 0x0);

// 0x710096b020
void Unk_96b020_set(const Unk_96b020* self, Unk_96b020_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x710096b080
void Unk_96b080_update() {}

struct Unk_96b090_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96b090_arg1, field_0, 0x0);

struct Unk_96b090 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96b090, field_0, 0x0);

// 0x710096b090
void Unk_96b090_set(const Unk_96b090* self, Unk_96b090_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_96b0a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96b0a0_arg1, field_0, 0x0);

struct Unk_96b0a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96b0a0, field_0, 0x0);

// 0x710096b0a0
void Unk_96b0a0_set(const Unk_96b0a0* self, Unk_96b0a0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x710096b2c0
void Unk_96b2c0_update() {}

struct Unk_96b940_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96b940_arg1, field_0, 0x0);

struct Unk_96b940 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96b940, field_0, 0x0);

// 0x710096b940
void Unk_96b940_set(const Unk_96b940* self, Unk_96b940_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_96b950_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96b950_arg1, field_0, 0x0);

struct Unk_96b950 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96b950, field_0, 0x0);

// 0x710096b950
void Unk_96b950_set(const Unk_96b950* self, Unk_96b950_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x710096bb70
void Unk_96bb70_update() {}

struct Unk_96c480 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_96c480, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_96c480, field_8, 0x8);

// 0x710096c480
void Unk_96c480_set(const Unk_96c480* self, Unk_96c480* value) {
    *value = *self;
}

struct Unk_96c490 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_96c490, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_96c490, field_8, 0x8);

// 0x710096c490
void Unk_96c490_set(const Unk_96c490* self, Unk_96c490* value) {
    *value = *self;
}

struct Unk_96c8e0_0 {
    u8 _0[0x3c0];
    u64 field_3c0;
    u64 field_3c8;
};
PKMN_OFFSET_ASSERT(Unk_96c8e0_0, field_3c0, 0x3c0);
PKMN_OFFSET_ASSERT(Unk_96c8e0_0, field_3c8, 0x3c8);

struct Unk_96c8e0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_96c8e0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_96c8e0_arg1, field_8, 0x8);

struct Unk_96c8e0 {
    Unk_96c8e0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_96c8e0, field_0, 0x0);

// 0x710096c8e0
void Unk_96c8e0_set(const Unk_96c8e0* self, const Unk_96c8e0_arg1* value) {
    Unk_96c8e0_0* p0 = self->field_0;
    p0->field_3c8 = value->field_8;
    p0->field_3c0 = value->field_0;
}

// 0x710096c900
void Unk_96c900_update() {}

struct Unk_96c910_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96c910_arg1, field_0, 0x0);

struct Unk_96c910 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96c910, field_0, 0x0);

// 0x710096c910
void Unk_96c910_set(const Unk_96c910* self, Unk_96c910_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_96c920_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96c920_arg1, field_0, 0x0);

struct Unk_96c920 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96c920, field_0, 0x0);

// 0x710096c920
void Unk_96c920_set(const Unk_96c920* self, Unk_96c920_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_96ca70_0 {
    u8 _0[0x440];
    u64 field_440;
    u64 field_448;
};
PKMN_OFFSET_ASSERT(Unk_96ca70_0, field_440, 0x440);
PKMN_OFFSET_ASSERT(Unk_96ca70_0, field_448, 0x448);

struct Unk_96ca70_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_96ca70_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_96ca70_arg1, field_8, 0x8);

struct Unk_96ca70 {
    Unk_96ca70_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_96ca70, field_0, 0x0);

// 0x710096ca70
void Unk_96ca70_set(const Unk_96ca70* self, const Unk_96ca70_arg1* value) {
    Unk_96ca70_0* p0 = self->field_0;
    p0->field_448 = value->field_8;
    p0->field_440 = value->field_0;
}

// 0x710096ca90
void Unk_96ca90_update() {}

struct Unk_96caa0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96caa0_arg1, field_0, 0x0);

struct Unk_96caa0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96caa0, field_0, 0x0);

// 0x710096caa0
void Unk_96caa0_set(const Unk_96caa0* self, Unk_96caa0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_96cab0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96cab0_arg1, field_0, 0x0);

struct Unk_96cab0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96cab0, field_0, 0x0);

// 0x710096cab0
void Unk_96cab0_set(const Unk_96cab0* self, Unk_96cab0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_96cac0_0 {
    u8 _0[0x3f0];
    u64 field_3f0;
    u64 field_3f8;
};
PKMN_OFFSET_ASSERT(Unk_96cac0_0, field_3f0, 0x3f0);
PKMN_OFFSET_ASSERT(Unk_96cac0_0, field_3f8, 0x3f8);

struct Unk_96cac0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_96cac0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_96cac0_arg1, field_8, 0x8);

struct Unk_96cac0 {
    Unk_96cac0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_96cac0, field_0, 0x0);

// 0x710096cac0
void Unk_96cac0_set(const Unk_96cac0* self, const Unk_96cac0_arg1* value) {
    Unk_96cac0_0* p0 = self->field_0;
    p0->field_3f8 = value->field_8;
    p0->field_3f0 = value->field_0;
}

// 0x710096cae0
void Unk_96cae0_update() {}

struct Unk_96caf0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96caf0_arg1, field_0, 0x0);

struct Unk_96caf0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96caf0, field_0, 0x0);

// 0x710096caf0
void Unk_96caf0_set(const Unk_96caf0* self, Unk_96caf0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_96cb00_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96cb00_arg1, field_0, 0x0);

struct Unk_96cb00 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96cb00, field_0, 0x0);

// 0x710096cb00
void Unk_96cb00_set(const Unk_96cb00* self, Unk_96cb00_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_96cb10_0 {
    u8 _0[0x420];
    u64 field_420;
    u64 field_428;
};
PKMN_OFFSET_ASSERT(Unk_96cb10_0, field_420, 0x420);
PKMN_OFFSET_ASSERT(Unk_96cb10_0, field_428, 0x428);

struct Unk_96cb10_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_96cb10_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_96cb10_arg1, field_8, 0x8);

struct Unk_96cb10 {
    Unk_96cb10_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_96cb10, field_0, 0x0);

// 0x710096cb10
void Unk_96cb10_set(const Unk_96cb10* self, const Unk_96cb10_arg1* value) {
    Unk_96cb10_0* p0 = self->field_0;
    p0->field_428 = value->field_8;
    p0->field_420 = value->field_0;
}

// 0x710096cb30
void Unk_96cb30_update() {}

struct Unk_96cb40_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96cb40_arg1, field_0, 0x0);

struct Unk_96cb40 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96cb40, field_0, 0x0);

// 0x710096cb40
void Unk_96cb40_set(const Unk_96cb40* self, Unk_96cb40_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_96cb50_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96cb50_arg1, field_0, 0x0);

struct Unk_96cb50 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96cb50, field_0, 0x0);

// 0x710096cb50
void Unk_96cb50_set(const Unk_96cb50* self, Unk_96cb50_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_96cca0_0 {
    u8 _0[0x430];
    u64 field_430;
    u64 field_438;
};
PKMN_OFFSET_ASSERT(Unk_96cca0_0, field_430, 0x430);
PKMN_OFFSET_ASSERT(Unk_96cca0_0, field_438, 0x438);

struct Unk_96cca0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_96cca0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_96cca0_arg1, field_8, 0x8);

struct Unk_96cca0 {
    Unk_96cca0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_96cca0, field_0, 0x0);

// 0x710096cca0
void Unk_96cca0_set(const Unk_96cca0* self, const Unk_96cca0_arg1* value) {
    Unk_96cca0_0* p0 = self->field_0;
    p0->field_438 = value->field_8;
    p0->field_430 = value->field_0;
}

// 0x710096ccc0
void Unk_96ccc0_update() {}

struct Unk_96ccd0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96ccd0_arg1, field_0, 0x0);

struct Unk_96ccd0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96ccd0, field_0, 0x0);

// 0x710096ccd0
void Unk_96ccd0_set(const Unk_96ccd0* self, Unk_96ccd0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_96cce0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96cce0_arg1, field_0, 0x0);

struct Unk_96cce0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96cce0, field_0, 0x0);

// 0x710096cce0
void Unk_96cce0_set(const Unk_96cce0* self, Unk_96cce0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x710096d2b0
void Unk_96d2b0_update() {}

struct Unk_96d2c0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_96d2c0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_96d2c0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_96d2c0, field_10, 0x10);

// 0x710096d2c0
void Unk_96d2c0_set(const Unk_96d2c0* self, Unk_96d2c0* value) {
    *value = *self;
}

struct Unk_96d2e0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_96d2e0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_96d2e0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_96d2e0, field_10, 0x10);

// 0x710096d2e0
void Unk_96d2e0_set(const Unk_96d2e0* self, Unk_96d2e0* value) {
    *value = *self;
}

struct Unk_96d950_0 {
    u8 _0[0x3c0];
    u64 field_3c0;
    u64 field_3c8;
};
PKMN_OFFSET_ASSERT(Unk_96d950_0, field_3c0, 0x3c0);
PKMN_OFFSET_ASSERT(Unk_96d950_0, field_3c8, 0x3c8);

struct Unk_96d950_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_96d950_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_96d950_arg1, field_8, 0x8);

struct Unk_96d950 {
    Unk_96d950_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_96d950, field_0, 0x0);

// 0x710096d950
void Unk_96d950_set(const Unk_96d950* self, const Unk_96d950_arg1* value) {
    Unk_96d950_0* p0 = self->field_0;
    p0->field_3c8 = value->field_8;
    p0->field_3c0 = value->field_0;
}

// 0x710096d970
void Unk_96d970_update() {}

struct Unk_96d980_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96d980_arg1, field_0, 0x0);

struct Unk_96d980 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96d980, field_0, 0x0);

// 0x710096d980
void Unk_96d980_set(const Unk_96d980* self, Unk_96d980_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_96d990_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96d990_arg1, field_0, 0x0);

struct Unk_96d990 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96d990, field_0, 0x0);

// 0x710096d990
void Unk_96d990_set(const Unk_96d990* self, Unk_96d990_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_96dae0_0 {
    u8 _0[0x3c0];
    u64 field_3c0;
    u64 field_3c8;
};
PKMN_OFFSET_ASSERT(Unk_96dae0_0, field_3c0, 0x3c0);
PKMN_OFFSET_ASSERT(Unk_96dae0_0, field_3c8, 0x3c8);

struct Unk_96dae0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_96dae0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_96dae0_arg1, field_8, 0x8);

struct Unk_96dae0 {
    Unk_96dae0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_96dae0, field_0, 0x0);

// 0x710096dae0
void Unk_96dae0_set(const Unk_96dae0* self, const Unk_96dae0_arg1* value) {
    Unk_96dae0_0* p0 = self->field_0;
    p0->field_3c8 = value->field_8;
    p0->field_3c0 = value->field_0;
}

// 0x710096db00
void Unk_96db00_update() {}

struct Unk_96db10_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96db10_arg1, field_0, 0x0);

struct Unk_96db10 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96db10, field_0, 0x0);

// 0x710096db10
void Unk_96db10_set(const Unk_96db10* self, Unk_96db10_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_96db20_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96db20_arg1, field_0, 0x0);

struct Unk_96db20 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96db20, field_0, 0x0);

// 0x710096db20
void Unk_96db20_set(const Unk_96db20* self, Unk_96db20_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_96db30_0 {
    u8 _0[0x3c0];
    u64 field_3c0;
    u64 field_3c8;
};
PKMN_OFFSET_ASSERT(Unk_96db30_0, field_3c0, 0x3c0);
PKMN_OFFSET_ASSERT(Unk_96db30_0, field_3c8, 0x3c8);

struct Unk_96db30_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_96db30_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_96db30_arg1, field_8, 0x8);

struct Unk_96db30 {
    Unk_96db30_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_96db30, field_0, 0x0);

// 0x710096db30
void Unk_96db30_set(const Unk_96db30* self, const Unk_96db30_arg1* value) {
    Unk_96db30_0* p0 = self->field_0;
    p0->field_3c8 = value->field_8;
    p0->field_3c0 = value->field_0;
}

// 0x710096db50
void Unk_96db50_update() {}

struct Unk_96db60_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96db60_arg1, field_0, 0x0);

struct Unk_96db60 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96db60, field_0, 0x0);

// 0x710096db60
void Unk_96db60_set(const Unk_96db60* self, Unk_96db60_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_96db70_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96db70_arg1, field_0, 0x0);

struct Unk_96db70 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96db70, field_0, 0x0);

// 0x710096db70
void Unk_96db70_set(const Unk_96db70* self, Unk_96db70_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x710096dd70
void Unk_96dd70_update() {}

struct Unk_96deb0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_96deb0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_96deb0, field_8, 0x8);

// 0x710096deb0
void Unk_96deb0_set(const Unk_96deb0* self, Unk_96deb0* value) {
    *value = *self;
}

struct Unk_96dec0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_96dec0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_96dec0, field_8, 0x8);

// 0x710096dec0
void Unk_96dec0_set(const Unk_96dec0* self, Unk_96dec0* value) {
    *value = *self;
}

// 0x710096e0c0
void Unk_96e0c0_update() {}

struct Unk_96e280 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_96e280, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_96e280, field_8, 0x8);

// 0x710096e280
void Unk_96e280_set(const Unk_96e280* self, Unk_96e280* value) {
    *value = *self;
}

struct Unk_96e290 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_96e290, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_96e290, field_8, 0x8);

// 0x710096e290
void Unk_96e290_set(const Unk_96e290* self, Unk_96e290* value) {
    *value = *self;
}

// 0x710096e490
void Unk_96e490_update() {}

struct Unk_96e4a0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_96e4a0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_96e4a0, field_8, 0x8);

// 0x710096e4a0
void Unk_96e4a0_set(const Unk_96e4a0* self, Unk_96e4a0* value) {
    *value = *self;
}

struct Unk_96e4b0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_96e4b0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_96e4b0, field_8, 0x8);

// 0x710096e4b0
void Unk_96e4b0_set(const Unk_96e4b0* self, Unk_96e4b0* value) {
    *value = *self;
}

// 0x710096e6b0
void Unk_96e6b0_update() {}

struct Unk_96e6c0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_96e6c0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_96e6c0, field_8, 0x8);

// 0x710096e6c0
void Unk_96e6c0_set(const Unk_96e6c0* self, Unk_96e6c0* value) {
    *value = *self;
}

struct Unk_96e6d0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_96e6d0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_96e6d0, field_8, 0x8);

// 0x710096e6d0
void Unk_96e6d0_set(const Unk_96e6d0* self, Unk_96e6d0* value) {
    *value = *self;
}

// 0x710096e8d0
void Unk_96e8d0_update() {}

struct Unk_96e8e0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_96e8e0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_96e8e0, field_8, 0x8);

// 0x710096e8e0
void Unk_96e8e0_set(const Unk_96e8e0* self, Unk_96e8e0* value) {
    *value = *self;
}

struct Unk_96e8f0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_96e8f0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_96e8f0, field_8, 0x8);

// 0x710096e8f0
void Unk_96e8f0_set(const Unk_96e8f0* self, Unk_96e8f0* value) {
    *value = *self;
}

// 0x710096eaf0
void Unk_96eaf0_update() {}

struct Unk_96eb00 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_96eb00, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_96eb00, field_8, 0x8);

// 0x710096eb00
void Unk_96eb00_set(const Unk_96eb00* self, Unk_96eb00* value) {
    *value = *self;
}

struct Unk_96eb10 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_96eb10, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_96eb10, field_8, 0x8);

// 0x710096eb10
void Unk_96eb10_set(const Unk_96eb10* self, Unk_96eb10* value) {
    *value = *self;
}

// 0x710096ed10
void Unk_96ed10_update() {}

struct Unk_96ed20 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_96ed20, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_96ed20, field_8, 0x8);

// 0x710096ed20
void Unk_96ed20_set(const Unk_96ed20* self, Unk_96ed20* value) {
    *value = *self;
}

struct Unk_96ed30 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_96ed30, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_96ed30, field_8, 0x8);

// 0x710096ed30
void Unk_96ed30_set(const Unk_96ed30* self, Unk_96ed30* value) {
    *value = *self;
}

// 0x710096ef30
void Unk_96ef30_update() {}

struct Unk_96ef40 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_96ef40, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_96ef40, field_8, 0x8);

// 0x710096ef40
void Unk_96ef40_set(const Unk_96ef40* self, Unk_96ef40* value) {
    *value = *self;
}

struct Unk_96ef50 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_96ef50, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_96ef50, field_8, 0x8);

// 0x710096ef50
void Unk_96ef50_set(const Unk_96ef50* self, Unk_96ef50* value) {
    *value = *self;
}

// 0x710096f150
void Unk_96f150_update() {}

struct Unk_96f160 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_96f160, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_96f160, field_8, 0x8);

// 0x710096f160
void Unk_96f160_set(const Unk_96f160* self, Unk_96f160* value) {
    *value = *self;
}

struct Unk_96f170 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_96f170, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_96f170, field_8, 0x8);

// 0x710096f170
void Unk_96f170_set(const Unk_96f170* self, Unk_96f170* value) {
    *value = *self;
}

// 0x710096f370
void Unk_96f370_update() {}

struct Unk_96f380 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_96f380, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_96f380, field_8, 0x8);

// 0x710096f380
void Unk_96f380_set(const Unk_96f380* self, Unk_96f380* value) {
    *value = *self;
}

struct Unk_96f390 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_96f390, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_96f390, field_8, 0x8);

// 0x710096f390
void Unk_96f390_set(const Unk_96f390* self, Unk_96f390* value) {
    *value = *self;
}

// 0x710096f3c0
void Unk_96f3c0_update() {}

struct Unk_96f3d0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_96f3d0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_96f3d0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_96f3d0, field_10, 0x10);

// 0x710096f3d0
void Unk_96f3d0_set(const Unk_96f3d0* self, Unk_96f3d0* value) {
    *value = *self;
}

struct Unk_96f3f0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_96f3f0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_96f3f0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_96f3f0, field_10, 0x10);

// 0x710096f3f0
void Unk_96f3f0_set(const Unk_96f3f0* self, Unk_96f3f0* value) {
    *value = *self;
}

// 0x710096f500
void Unk_96f500_update() {}

struct Unk_96f510_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96f510_arg1, field_0, 0x0);

struct Unk_96f510 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96f510, field_0, 0x0);

// 0x710096f510
void Unk_96f510_set(const Unk_96f510* self, Unk_96f510_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_96f520_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96f520_arg1, field_0, 0x0);

struct Unk_96f520 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96f520, field_0, 0x0);

// 0x710096f520
void Unk_96f520_set(const Unk_96f520* self, Unk_96f520_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x710096f5d0
void Unk_96f5d0_update() {}

struct Unk_96f5e0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_96f5e0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_96f5e0, field_8, 0x8);

// 0x710096f5e0
void Unk_96f5e0_set(const Unk_96f5e0* self, Unk_96f5e0* value) {
    *value = *self;
}

struct Unk_96f5f0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_96f5f0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_96f5f0, field_8, 0x8);

// 0x710096f5f0
void Unk_96f5f0_set(const Unk_96f5f0* self, Unk_96f5f0* value) {
    *value = *self;
}

// 0x710096fa00
void Unk_96fa00_update() {}

struct Unk_96fa10_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96fa10_arg1, field_0, 0x0);

struct Unk_96fa10 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96fa10, field_0, 0x0);

// 0x710096fa10
void Unk_96fa10_set(const Unk_96fa10* self, Unk_96fa10_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_96fa20_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96fa20_arg1, field_0, 0x0);

struct Unk_96fa20 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_96fa20, field_0, 0x0);

// 0x710096fa20
void Unk_96fa20_set(const Unk_96fa20* self, Unk_96fa20_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x710096fb20
void Unk_96fb20_update() {}

// 0x710096fb30
void Unk_96fb30_update() {}

// 0x710096fb40
void Unk_96fb40_update() {}

struct Unk_97ad20_3b0 {
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
    virtual void vf223();
    virtual void vf224();
    virtual void vf225();
    virtual void vf226();
    virtual void vf227();
    virtual void vf228();
    virtual void vf229();
    virtual void vf230();
    virtual void vf231();
    virtual void vf232();
    virtual void vf233();
    virtual void vf234();
    virtual void vf235();
    virtual void vf236();
    virtual void vf237();
    virtual void vf238();
    virtual void vf239();
    virtual void vf240();
    virtual void vf241();
    virtual void vf242();
    virtual void vf243();
    virtual void vf244();
    virtual void vf245();
    virtual void vf246();
    virtual void vf247();
    virtual void vf248();
    virtual void vf249();
    virtual void vf250();
    virtual void vf251();
    virtual void vf252();
    virtual void vf253();
    virtual void vf254();
    virtual void vf255();
    virtual void vf256();
    virtual void vf257();
    virtual void vf258();
    virtual void vf259();
    virtual void vf260();
    virtual void vf261();
    virtual void vf262();
    virtual void vf263();
    virtual void vf264();
    virtual void vf265();
    virtual void vf266();
    virtual void vf267();
    virtual void vf268();
    virtual void vf269();
    virtual void vf270();
    virtual void vf271();
    virtual void vf272();
    virtual void vf273();
    virtual void vf274();
    virtual void vf275();
    virtual void vf276();
    virtual void vf277();
    virtual void vf278();
    virtual void vf279();
    virtual void vf280();
    virtual void vf281();
    virtual void vf282(u32);
};

struct Unk_97ad20 {
    u8 _0[0x3b0];
    Unk_97ad20_3b0* field_3b0;
    u32 field_3b8;
};
PKMN_OFFSET_ASSERT(Unk_97ad20, field_3b0, 0x3b0);
PKMN_OFFSET_ASSERT(Unk_97ad20, field_3b8, 0x3b8);

// 0x710097ad20
void Unk_97ad20_call(const Unk_97ad20* self) {
    self->field_3b0->vf282(self->field_3b8);
}

struct Unk_981b60 {
    u8 _0[0x541];
    bool field_541;
};
PKMN_OFFSET_ASSERT(Unk_981b60, field_541, 0x541);

// 0x7100981b60
void Unk_981b60_set(Unk_981b60* self, bool value) {
    self->field_541 = value;
}

struct Unk_983f60 {
    u8 _0[0x4b1];
    u8 field_4b1;
};
PKMN_OFFSET_ASSERT(Unk_983f60, field_4b1, 0x4b1);

// 0x7100983f60
u8 Unk_983f60_getField4b1(const Unk_983f60* self) {
    return self->field_4b1;
}

// 0x71009861d0
void Unk_9861d0_update() {}

struct Unk_9861e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_9861e0_arg1, field_0, 0x0);

struct Unk_9861e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_9861e0, field_0, 0x0);

// 0x71009861e0
void Unk_9861e0_set(const Unk_9861e0* self, Unk_9861e0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_9861f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_9861f0_arg1, field_0, 0x0);

struct Unk_9861f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_9861f0, field_0, 0x0);

// 0x71009861f0
void Unk_9861f0_set(const Unk_9861f0* self, Unk_9861f0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100987420
void Unk_987420_update() {}

struct Unk_987430_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_987430_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_987430_arg1, field_8, 0x8);

struct Unk_987430 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_987430, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_987430, field_8, 0x8);

// 0x7100987430
void Unk_987430_set(const Unk_987430* self, Unk_987430_arg1* value) {
    value->field_8 = self->field_8;
    value->field_0 = self->field_0;
}

struct Unk_987450_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_987450_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_987450_arg1, field_8, 0x8);

struct Unk_987450 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_987450, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_987450, field_8, 0x8);

// 0x7100987450
void Unk_987450_set(const Unk_987450* self, Unk_987450_arg1* value) {
    value->field_8 = self->field_8;
    value->field_0 = self->field_0;
}

// 0x71009875b0
void Unk_9875b0_update() {}

struct Unk_9875c0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_9875c0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_9875c0_arg1, field_8, 0x8);

struct Unk_9875c0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_9875c0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_9875c0, field_8, 0x8);

// 0x71009875c0
void Unk_9875c0_set(const Unk_9875c0* self, Unk_9875c0_arg1* value) {
    value->field_8 = self->field_8;
    value->field_0 = self->field_0;
}

struct Unk_9875e0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_9875e0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_9875e0_arg1, field_8, 0x8);

struct Unk_9875e0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_9875e0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_9875e0, field_8, 0x8);

// 0x71009875e0
void Unk_9875e0_set(const Unk_9875e0* self, Unk_9875e0_arg1* value) {
    value->field_8 = self->field_8;
    value->field_0 = self->field_0;
}

struct Unk_987600 {
    f32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_987600, field_0, 0x0);

// 0x7100987600
f32 Unk_987600_get(const Unk_987600* self) {
    return self->field_0;
}

// 0x7100987610
void Unk_987610_update() {}

struct Unk_987620_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_987620_arg1, field_0, 0x0);

struct Unk_987620 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_987620, field_0, 0x0);

// 0x7100987620
void Unk_987620_set(const Unk_987620* self, Unk_987620_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_987630_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_987630_arg1, field_0, 0x0);

struct Unk_987630 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_987630, field_0, 0x0);

// 0x7100987630
void Unk_987630_set(const Unk_987630* self, Unk_987630_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_987770 {
    f32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_987770, field_0, 0x0);

// 0x7100987770
f32 Unk_987770_get(const Unk_987770* self) {
    return self->field_0;
}

// 0x7100987780
void Unk_987780_update() {}

struct Unk_987790_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_987790_arg1, field_0, 0x0);

struct Unk_987790 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_987790, field_0, 0x0);

// 0x7100987790
void Unk_987790_set(const Unk_987790* self, Unk_987790_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_9877a0_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_9877a0_arg1, field_0, 0x0);

struct Unk_9877a0 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_9877a0, field_0, 0x0);

// 0x71009877a0
void Unk_9877a0_set(const Unk_9877a0* self, Unk_9877a0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_9877b0 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_9877b0, field_0, 0x0);

// 0x71009877b0
bool Unk_9877b0_check(const Unk_9877b0* self) {
    return self->field_0 != 0;
}

// 0x71009877c0
void Unk_9877c0_update() {}

struct Unk_9877d0_arg1 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_9877d0_arg1, field_0, 0x0);

struct Unk_9877d0 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_9877d0, field_0, 0x0);

// 0x71009877d0
void Unk_9877d0_set(const Unk_9877d0* self, Unk_9877d0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_9877e0_arg1 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_9877e0_arg1, field_0, 0x0);

struct Unk_9877e0 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_9877e0, field_0, 0x0);

// 0x71009877e0
void Unk_9877e0_set(const Unk_9877e0* self, Unk_9877e0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_987930 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_987930, field_0, 0x0);

// 0x7100987930
bool Unk_987930_check(const Unk_987930* self) {
    return self->field_0 != 0;
}

// 0x7100987940
void Unk_987940_update() {}

struct Unk_987950_arg1 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_987950_arg1, field_0, 0x0);

struct Unk_987950 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_987950, field_0, 0x0);

// 0x7100987950
void Unk_987950_set(const Unk_987950* self, Unk_987950_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_987960_arg1 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_987960_arg1, field_0, 0x0);

struct Unk_987960 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_987960, field_0, 0x0);

// 0x7100987960
void Unk_987960_set(const Unk_987960* self, Unk_987960_arg1* value) {
    value->field_0 = self->field_0;
}
