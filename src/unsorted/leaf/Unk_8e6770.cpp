// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

struct Unk_8e6770 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_8e6770, field_0, 0x0);

// 0x71008e6770
void Unk_8e6770_call(Unk_8e6770* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_8e67b0_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_8e67b0_arg1, field_0, 0x0);

struct Unk_8e67b0 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_8e67b0, field_0, 0x0);

// 0x71008e67b0
void Unk_8e67b0_call(const Unk_8e67b0* self, Unk_8e67b0_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_8e67d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8e67d0_arg1, field_0, 0x0);

struct Unk_8e67d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8e67d0, field_0, 0x0);

// 0x71008e67d0
void Unk_8e67d0_set(Unk_8e67d0* self, Unk_8e67d0_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_8e6820 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_8e6820, field_0, 0x0);

// 0x71008e6820
void Unk_8e6820_call(Unk_8e6820* self) {
    if (self->field_0 != nullptr) {
        static_cast<Unk_239a458*>(self->field_0)->vf5();
        self->field_0 = nullptr;
    }
}

struct Unk_8e6860_arg1 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_8e6860_arg1, field_0, 0x0);

struct Unk_8e6860 {
    Unk_239a418* field_0;
};
PKMN_OFFSET_ASSERT(Unk_8e6860, field_0, 0x0);

// 0x71008e6860
void Unk_8e6860_call(const Unk_8e6860* self, Unk_8e6860_arg1* value) {
    Unk_239a418* v0 = self->field_0;
    value->field_0 = v0;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf4();
    }
}

struct Unk_8e6880_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8e6880_arg1, field_0, 0x0);

struct Unk_8e6880 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8e6880, field_0, 0x0);

// 0x71008e6880
void Unk_8e6880_set(Unk_8e6880* self, Unk_8e6880_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_8e6f20 {
    u8 _0[0x6fc];
    u8 field_6fc;
};
PKMN_OFFSET_ASSERT(Unk_8e6f20, field_6fc, 0x6fc);

void Unk_eb8a30(void*, u32);

// 0x71008e6f20
void Unk_8e6f20_call(Unk_8e6f20* self) {
    Unk_eb8a30(self, 1);
    self->field_6fc = 0;
}

struct Unk_8e80e0 {
    u8 _0[0x5cc];
    u8 field_5cc;
    u8 _5cd[0x103];
    u64 field_6d0;
};
PKMN_OFFSET_ASSERT(Unk_8e80e0, field_5cc, 0x5cc);
PKMN_OFFSET_ASSERT(Unk_8e80e0, field_6d0, 0x6d0);

void Unk_14e1a30(u64, u32);

// 0x71008e80e0
void Unk_8e80e0_call(Unk_8e80e0* self) {
    Unk_14e1a30(self->field_6d0, 1);
    if (self->field_5cc != 0) {
        self->field_5cc = 0;
    }
}

// 0x71008e84a0
void Unk_8e84a0_update() {}

struct Unk_8e84b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8e84b0_arg1, field_0, 0x0);

struct Unk_8e84b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8e84b0, field_0, 0x0);

// 0x71008e84b0
void Unk_8e84b0_set(const Unk_8e84b0* self, Unk_8e84b0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_8e84c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8e84c0_arg1, field_0, 0x0);

struct Unk_8e84c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8e84c0, field_0, 0x0);

// 0x71008e84c0
void Unk_8e84c0_set(const Unk_8e84c0* self, Unk_8e84c0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71008e8530
void Unk_8e8530_update() {}

struct Unk_8e8540 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_8e8540, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_8e8540, field_8, 0x8);

// 0x71008e8540
void Unk_8e8540_set(const Unk_8e8540* self, Unk_8e8540* value) {
    *value = *self;
}

struct Unk_8e8550 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_8e8550, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_8e8550, field_8, 0x8);

// 0x71008e8550
void Unk_8e8550_set(const Unk_8e8550* self, Unk_8e8550* value) {
    *value = *self;
}

// 0x71008e85b0
void Unk_8e85b0_update() {}

struct Unk_8e85c0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_8e85c0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_8e85c0, field_8, 0x8);

// 0x71008e85c0
void Unk_8e85c0_set(const Unk_8e85c0* self, Unk_8e85c0* value) {
    *value = *self;
}

struct Unk_8e85d0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_8e85d0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_8e85d0, field_8, 0x8);

// 0x71008e85d0
void Unk_8e85d0_set(const Unk_8e85d0* self, Unk_8e85d0* value) {
    *value = *self;
}

// 0x71008e8630
void Unk_8e8630_update() {}

struct Unk_8e8640 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_8e8640, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_8e8640, field_8, 0x8);

// 0x71008e8640
void Unk_8e8640_set(const Unk_8e8640* self, Unk_8e8640* value) {
    *value = *self;
}

struct Unk_8e8650 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_8e8650, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_8e8650, field_8, 0x8);

// 0x71008e8650
void Unk_8e8650_set(const Unk_8e8650* self, Unk_8e8650* value) {
    *value = *self;
}

void Unk_8ea2b0(void*, u32, bool, bool, bool);

// 0x71008ea3a0
void Unk_8ea3a0_call(void* self, u64 value, bool arg2, bool arg3) {
    Unk_8ea2b0(self, value, arg2, 1, arg3);
}

struct Unk_8eace0 {
    u8 _0[0x20];
    void* field_20;
};
PKMN_OFFSET_ASSERT(Unk_8eace0, field_20, 0x20);

void Unk_8ef110(void*, u32, u32);

// 0x71008eace0
void Unk_8eace0_call(const Unk_8eace0* self) {
    Unk_8ef110(self->field_20, 1, 1);
}

struct Unk_8eacf0 {
    u8 _0[0x20];
    void* field_20;
};
PKMN_OFFSET_ASSERT(Unk_8eacf0, field_20, 0x20);

void Unk_8ef160(void*, u32, u32);

// 0x71008eacf0
void Unk_8eacf0_call(const Unk_8eacf0* self, u8 value, u8 arg2, u32 /*unused*/) {
    Unk_8ef160(self->field_20, value, arg2);
}

struct Unk_8ead00 {
    u8 _0[0x20];
    void* field_20;
};
PKMN_OFFSET_ASSERT(Unk_8ead00, field_20, 0x20);

void Unk_8ef110(void*, u32, u32);

// 0x71008ead00
void Unk_8ead00_call(const Unk_8ead00* self) {
    Unk_8ef110(self->field_20, 1, 0);
}

struct Unk_8eae10_10_370 {
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
};

struct Unk_8eae10_10 {
    u8 _0[0x370];
    Unk_8eae10_10_370* field_370;
};
PKMN_OFFSET_ASSERT(Unk_8eae10_10, field_370, 0x370);

struct Unk_8eae10 {
    u8 _0[0x10];
    Unk_8eae10_10* field_10;
    u8 _18[0x8];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_8eae10, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_8eae10, field_20, 0x20);

u32 Unk_8ebc70();
void Unk_900780(u64, u32);

// 0x71008eae10
void Unk_8eae10_call(const Unk_8eae10* self) {
    self->field_10->field_370->vf227();
    u32 r1 = Unk_8ebc70();
    Unk_900780(self->field_20, r1 & 1);
}

struct Unk_8eae50_10_370 {
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
};

struct Unk_8eae50_10 {
    u8 _0[0x370];
    Unk_8eae50_10_370* field_370;
};
PKMN_OFFSET_ASSERT(Unk_8eae50_10, field_370, 0x370);

struct Unk_8eae50 {
    u8 _0[0x10];
    Unk_8eae50_10* field_10;
    u8 _18[0x8];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_8eae50, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_8eae50, field_20, 0x20);

u32 Unk_8ebc70();
void Unk_900640(u64, u32);

// 0x71008eae50
void Unk_8eae50_call(const Unk_8eae50* self) {
    self->field_10->field_370->vf227();
    u32 r1 = Unk_8ebc70();
    Unk_900640(self->field_20, r1 & 1);
}

struct Unk_8eae90_10_370 {
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
};

struct Unk_8eae90_10 {
    u8 _0[0x370];
    Unk_8eae90_10_370* field_370;
};
PKMN_OFFSET_ASSERT(Unk_8eae90_10, field_370, 0x370);

struct Unk_8eae90 {
    u8 _0[0x10];
    Unk_8eae90_10* field_10;
    u8 _18[0x8];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_8eae90, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_8eae90, field_20, 0x20);

u32 Unk_8ebc70();
void Unk_900780(u64, u32);

// 0x71008eae90
void Unk_8eae90_call(const Unk_8eae90* self) {
    self->field_10->field_370->vf227();
    u32 r1 = Unk_8ebc70();
    Unk_900780(self->field_20, r1 & 1);
}

struct Unk_8eaf40_10_370 {
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
};

struct Unk_8eaf40_10 {
    u8 _0[0x370];
    Unk_8eaf40_10_370* field_370;
};
PKMN_OFFSET_ASSERT(Unk_8eaf40_10, field_370, 0x370);

struct Unk_8eaf40 {
    u8 _0[0x10];
    Unk_8eaf40_10* field_10;
    u8 _18[0x8];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_8eaf40, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_8eaf40, field_20, 0x20);

u32 Unk_8ebc70();
void Unk_900780(u64, u32);

// 0x71008eaf40
void Unk_8eaf40_call(const Unk_8eaf40* self) {
    self->field_10->field_370->vf227();
    u32 r1 = Unk_8ebc70();
    Unk_900780(self->field_20, r1 & 1);
}

struct Unk_8eb1e0 {
    u8 _0[0x20];
    void* field_20;
};
PKMN_OFFSET_ASSERT(Unk_8eb1e0, field_20, 0x20);

void Unk_8f4820(void*);

// 0x71008eb1e0
void Unk_8eb1e0_call(const Unk_8eb1e0* self) {
    Unk_8f4820(self->field_20);
}
