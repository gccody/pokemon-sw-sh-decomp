// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"

void Unk_938ab0(void*, u64, u32, u32);

// 0x7100938aa0
void Unk_938aa0_call(void* self, u64 value, bool arg2) {
    Unk_938ab0(self, value, arg2, 0);
}

void Unk_938ab0(void*, u64, u32, u32);

// 0x7100938d00
void Unk_938d00_call(void* self, u64 value) {
    Unk_938ab0(self, value, 0, 0);
}

void Unk_9394d0(void*, u64, u32, u32);

// 0x7100939600
void Unk_939600_call(void* self, u64 value, bool arg2) {
    Unk_9394d0(self, value, arg2, 1);
}

void Unk_9394d0(void*, u64, u32, u32);

// 0x7100939610
void Unk_939610_call(void* self, u64 value, bool arg2) {
    Unk_9394d0(self, value, arg2, 2);
}

void Unk_9394d0(void*, u64, u32, u32);

// 0x7100939620
void Unk_939620_call(void* self, u64 value, bool arg2) {
    Unk_9394d0(self, value, arg2, 3);
}

struct Unk_939650 {
    u8 _0[0x38];
    u64 field_38;
};
PKMN_OFFSET_ASSERT(Unk_939650, field_38, 0x38);

// 0x7100939650
void Unk_939650_setField38(Unk_939650* self, u64 value) {
    self->field_38 = value;
}

struct Unk_93a2a0 {
    u8 _0[0x20];
    void* field_20;
};
PKMN_OFFSET_ASSERT(Unk_93a2a0, field_20, 0x20);

void Unk_93d6e0(void*);

// 0x710093a2a0
void Unk_93a2a0_call(const Unk_93a2a0* self) {
    Unk_93d6e0(self->field_20);
}

struct Unk_93c880_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_93c880_arg1, field_0, 0x0);

struct Unk_93c880_0 {
    u8 _0[0x680];
    u32 field_680;
    u32 field_684;
    u8 field_688;
};
PKMN_OFFSET_ASSERT(Unk_93c880_0, field_680, 0x680);
PKMN_OFFSET_ASSERT(Unk_93c880_0, field_684, 0x684);
PKMN_OFFSET_ASSERT(Unk_93c880_0, field_688, 0x688);

struct Unk_93c880 {
    Unk_93c880_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_93c880, field_0, 0x0);

// 0x710093c880
void Unk_93c880_set(const Unk_93c880* self, const Unk_93c880_arg1* value) {
    Unk_93c880_0* p0 = self->field_0;
    u32 v0 = value->field_0;
    p0->field_680 = v0 != 0;
    p0->field_688 = 1;
    p0->field_684 = v0;
}

// 0x710093c8b0
void Unk_93c8b0_update() {}

struct Unk_93c8c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_93c8c0_arg1, field_0, 0x0);

struct Unk_93c8c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_93c8c0, field_0, 0x0);

// 0x710093c8c0
void Unk_93c8c0_set(const Unk_93c8c0* self, Unk_93c8c0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_93c8d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_93c8d0_arg1, field_0, 0x0);

struct Unk_93c8d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_93c8d0, field_0, 0x0);

// 0x710093c8d0
void Unk_93c8d0_set(const Unk_93c8d0* self, Unk_93c8d0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_93cae0 {
    u8 _0[0x68];
    Unk_239a418* field_68;
    u64 field_70;
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_93cae0, field_68, 0x68);
PKMN_OFFSET_ASSERT(Unk_93cae0, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_93cae0, field_78, 0x78);

// 0x710093cae0
void Unk_93cae0_call(Unk_93cae0* self) {
    self->field_70 = 0;
    self->field_78 = 0;
    if (self->field_68 != nullptr) {
        static_cast<Unk_239a458*>(self->field_68)->vf5();
        self->field_68 = nullptr;
    }
}

struct Unk_93cbb0 {
    u8 _0[0x68];
    void* field_68;
};
PKMN_OFFSET_ASSERT(Unk_93cbb0, field_68, 0x68);

void Unk_67db60(void*);

// 0x710093cbb0
void Unk_93cbb0_call(const Unk_93cbb0* self) {
    if (self->field_68 != nullptr) {
        Unk_67db60(self->field_68);
    }
}

struct Unk_93cbc0_68 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9(u64);
};

struct Unk_93cbc0 {
    u8 _0[0x68];
    Unk_93cbc0_68* field_68;
};
PKMN_OFFSET_ASSERT(Unk_93cbc0, field_68, 0x68);

// 0x710093cbc0
void Unk_93cbc0_call(const Unk_93cbc0* self, u64 value) {
    if (self->field_68 != nullptr) {
        self->field_68->vf9(value);
    }
}

struct Unk_93cbe0 {
    u8 _0[0x68];
    void* field_68;
};
PKMN_OFFSET_ASSERT(Unk_93cbe0, field_68, 0x68);

void Unk_1309ba0(void*, void*);

// 0x710093cbe0
void Unk_93cbe0_call(const Unk_93cbe0* self, void* value) {
    if (self->field_68 != nullptr) {
        Unk_1309ba0(self->field_68, value);
    }
}

struct Unk_93cc10_70 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_93cc10_70, field_58, 0x58);

struct Unk_93cc10 {
    u8 _0[0x70];
    Unk_93cc10_70* field_70;
};
PKMN_OFFSET_ASSERT(Unk_93cc10, field_70, 0x70);

// 0x710093cc10
void Unk_93cc10_set(const Unk_93cc10* self, bool value) {
    if (self->field_70 != nullptr) {
        self->field_70->field_58 = (self->field_70->field_58 & 0xfffffffe) | (value);
    }
}

struct Unk_93cc30 {
    u8 _0[0x68];
    void* field_68;
};
PKMN_OFFSET_ASSERT(Unk_93cc30, field_68, 0x68);

void Unk_1308930(void*, u64, u32);

// 0x710093cc30
void Unk_93cc30_call(const Unk_93cc30* self, u64 value) {
    if (self->field_68 != nullptr) {
        Unk_1308930(self->field_68, value, 0);
    }
}

struct Unk_1309a70;
struct Unk_93cc50 {
    u8 _0[0x68];
    Unk_1309a70* field_68;
};
PKMN_OFFSET_ASSERT(Unk_93cc50, field_68, 0x68);

void Unk_1309a70_set(Unk_1309a70*, bool);

// 0x710093cc50
void Unk_93cc50_call(const Unk_93cc50* self, bool value) {
    if (self->field_68 != nullptr) {
        Unk_1309a70_set(self->field_68, value);
    }
}

struct Unk_1309a80;
struct Unk_93cc70 {
    u8 _0[0x68];
    Unk_1309a80* field_68;
};
PKMN_OFFSET_ASSERT(Unk_93cc70, field_68, 0x68);

void Unk_1309a80_set(Unk_1309a80*);

// 0x710093cc70
void Unk_93cc70_call(const Unk_93cc70* self) {
    if (self->field_68 != nullptr) {
        Unk_1309a80_set(self->field_68);
    }
}

struct Unk_93cc80 {
    u8 _0[0x68];
    void* field_68;
};
PKMN_OFFSET_ASSERT(Unk_93cc80, field_68, 0x68);

void Unk_67e9d0(void*, u32, u32);

// 0x710093cc80
void Unk_93cc80_call(const Unk_93cc80* self, u32 value, u32 arg2) {
    if (self->field_68 != nullptr) {
        Unk_67e9d0(self->field_68, value, arg2);
    }
}

struct Unk_93cc90_78 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_93cc90_78, field_58, 0x58);

struct Unk_93cc90 {
    u8 _0[0x78];
    Unk_93cc90_78* field_78;
    u8 _80[0x10];
    bool field_90;
};
PKMN_OFFSET_ASSERT(Unk_93cc90, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_93cc90, field_90, 0x90);

// 0x710093cc90
void Unk_93cc90_set(Unk_93cc90* self, bool value, bool arg2) {
    self->field_90 = value;
    self->field_78->field_58 = (self->field_78->field_58 & 0xfffffffe) | (arg2);
}

struct Unk_93ccb0 {
    u8 _0[0x68];
    void* field_68;
};
PKMN_OFFSET_ASSERT(Unk_93ccb0, field_68, 0x68);

void Unk_67ea60(void*);

// 0x710093ccb0
void Unk_93ccb0_call(const Unk_93ccb0* self) {
    if (self->field_68 != nullptr) {
        Unk_67ea60(self->field_68);
    }
}

void Unk_eb6230(void*, u32);

// 0x710093d6d0
void Unk_93d6d0_call(void* self) {
    Unk_eb6230(self, 3);
}

// 0x710093fee0
void Unk_93fee0_update() {}

struct Unk_93fef0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_93fef0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_93fef0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_93fef0, field_10, 0x10);

// 0x710093fef0
void Unk_93fef0_set(const Unk_93fef0* self, Unk_93fef0* value) {
    *value = *self;
}

struct Unk_93ff10 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_93ff10, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_93ff10, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_93ff10, field_10, 0x10);

// 0x710093ff10
void Unk_93ff10_set(const Unk_93ff10* self, Unk_93ff10* value) {
    *value = *self;
}

struct Unk_952910 {
    u8 _0[0x4c8];
    void* field_4c8;
};
PKMN_OFFSET_ASSERT(Unk_952910, field_4c8, 0x4c8);

void Unk_9a8190(void*, u32);

// 0x7100952910
void Unk_952910_call(const Unk_952910* self, u32 value) {
    Unk_9a8190(self->field_4c8, value);
}

struct Unk_952920 {
    u8 _0[0x4c8];
    void* field_4c8;
};
PKMN_OFFSET_ASSERT(Unk_952920, field_4c8, 0x4c8);

void Unk_9a8a10_call(void*);

// 0x7100952920
void Unk_952920_call(const Unk_952920* self) {
    Unk_9a8a10_call(self->field_4c8);
}

struct Unk_952930 {
    u8 _0[0x4c8];
    void* field_4c8;
};
PKMN_OFFSET_ASSERT(Unk_952930, field_4c8, 0x4c8);

void Unk_9a8a20(void*);

// 0x7100952930
void Unk_952930_call(const Unk_952930* self) {
    Unk_9a8a20(self->field_4c8);
}

struct Unk_953950_458 {
    u8 _0[0x90];
    u64 field_90;
    u64 field_98;
};
PKMN_OFFSET_ASSERT(Unk_953950_458, field_90, 0x90);
PKMN_OFFSET_ASSERT(Unk_953950_458, field_98, 0x98);

struct Unk_953950_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_953950_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_953950_arg1, field_8, 0x8);

struct Unk_953950 {
    u8 _0[0x458];
    Unk_953950_458* field_458;
};
PKMN_OFFSET_ASSERT(Unk_953950, field_458, 0x458);

// 0x7100953950
void Unk_953950_set(const Unk_953950* self, const Unk_953950_arg1* value) {
    Unk_953950_458* p0 = self->field_458;
    p0->field_98 = value->field_8;
    p0->field_90 = value->field_0;
}

struct Unk_95abc0 {
    u8 _0[0x608];
    void* field_608;
};
PKMN_OFFSET_ASSERT(Unk_95abc0, field_608, 0x608);

void Unk_9bbed0(void*, u32);

// 0x710095abc0
void Unk_95abc0_call(const Unk_95abc0* self) {
    Unk_9bbed0(self->field_608, 4);
}

struct Unk_95abd0 {
    u8 _0[0xa0];
    u32 field_a0;
};
PKMN_OFFSET_ASSERT(Unk_95abd0, field_a0, 0xa0);

// 0x710095abd0
bool Unk_95abd0_check(const Unk_95abd0* self) {
    return self->field_a0 == 0;
}

struct Unk_95abe0 {
    u8 _0[0x608];
    void* field_608;
};
PKMN_OFFSET_ASSERT(Unk_95abe0, field_608, 0x608);

void Unk_9bc580(void*);

// 0x710095abe0
void Unk_95abe0_call(const Unk_95abe0* self) {
    Unk_9bc580(self->field_608);
}

struct Unk_95abf0 {
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
    virtual u32 vf228();
};

void Unk_95aa90(void*, u32);

// 0x710095abf0
void Unk_95abf0_call(Unk_95abf0* self) {
    u32 r0 = self->vf228();
    Unk_95aa90(self, r0);
}
