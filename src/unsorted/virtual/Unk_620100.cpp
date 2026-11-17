// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_59b970(void* self);
void Unk_61e5b0(void* self);
void Unk_634540(void* self);
void Unk_64c9b0(void* self);
void Unk_64d460(void* self);
void Unk_64f430(void* self);
void Unk_65b030(void* self);
void Unk_699410(void* self);

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_60f060(u64);
void Unk_63c770(u64);

class Unk_239cfd0 {
public:
    virtual ~Unk_239cfd0();
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
    virtual void vf16() = 0;
    virtual void vf17() = 0;
};

// 0x7100620100
void Unk_239cfd0::vf6() {
    Unk_61e5b0(this);
}

// 0x7100620110
void Unk_239cfd0::vf15() {}

class Unk_239d070 {
public:
    virtual ~Unk_239d070();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100620140
void Unk_239d070::vf5() {
    Unk_61e5b0(this);
}

class Unk_239d0b0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100620150
void Unk_239d0b0::vf0() {
    Unk_61e5b0(this);
}

class Unk_239d210 {
public:
    virtual ~Unk_239d210();
    virtual void vf2();
    virtual void vf3();
    virtual u32 vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
};

// 0x7100622350
u32 Unk_239d210::vf4() {
    return 2;
}

class Unk_239d280 {
public:
    virtual ~Unk_239d280();
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
    u8 _8[0x200];
    u64 field_208;
};
PKMN_OFFSET_ASSERT(Unk_239d280, field_208, 0x208);

// 0x7100623580
void Unk_239d280::vf15() {
    Unk_60f060(field_208);
}

struct Unk_239d658_1a8_a0 {
    u8 _0[0xc8];
    f32 field_c8;
    f32 field_cc;
    f32 field_d0;
};
PKMN_OFFSET_ASSERT(Unk_239d658_1a8_a0, field_c8, 0xc8);
PKMN_OFFSET_ASSERT(Unk_239d658_1a8_a0, field_cc, 0xcc);
PKMN_OFFSET_ASSERT(Unk_239d658_1a8_a0, field_d0, 0xd0);

struct Unk_239d658_1a8 {
    u8 _0[0xa0];
    Unk_239d658_1a8_a0* field_a0;
    u8 field_a8;
    u8 _a9[0x17];
    u8 field_c0;
    u8 _c1[0xf];
    u8 field_d0;
    u8 _d1[0xf];
    u8 field_e0;
    u8 _e1[0xf];
    u8 field_f0;
    u8 _f1[0xf];
    u8 field_100;
    u8 _101[0xf];
    u8 field_110;
    u8 _111[0xf];
    u8 field_120;
    u8 _121[0x17];
    u8 field_138;
    u8 _139[0x7];
    f32 field_140;
    f32 field_144;
};
PKMN_OFFSET_ASSERT(Unk_239d658_1a8, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_239d658_1a8, field_a8, 0xa8);
PKMN_OFFSET_ASSERT(Unk_239d658_1a8, field_c0, 0xc0);
PKMN_OFFSET_ASSERT(Unk_239d658_1a8, field_d0, 0xd0);
PKMN_OFFSET_ASSERT(Unk_239d658_1a8, field_e0, 0xe0);
PKMN_OFFSET_ASSERT(Unk_239d658_1a8, field_f0, 0xf0);
PKMN_OFFSET_ASSERT(Unk_239d658_1a8, field_100, 0x100);
PKMN_OFFSET_ASSERT(Unk_239d658_1a8, field_110, 0x110);
PKMN_OFFSET_ASSERT(Unk_239d658_1a8, field_120, 0x120);
PKMN_OFFSET_ASSERT(Unk_239d658_1a8, field_138, 0x138);
PKMN_OFFSET_ASSERT(Unk_239d658_1a8, field_140, 0x140);
PKMN_OFFSET_ASSERT(Unk_239d658_1a8, field_144, 0x144);

class Unk_239d658 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7(f32 fvalue);
    virtual f32 vf8();
    virtual void vf9(f32 fvalue);
    virtual f32 vf10();
    virtual void vf11(f32 fvalue);
    virtual f32 vf12();
    virtual void vf13();
    virtual u8* vf14();
    virtual void vf15();
    virtual u32 vf16();
    virtual void vf17();
    virtual u8* vf18();
    virtual void vf19();
    virtual u32 vf20();
    virtual void vf21(f32 fvalue);
    virtual f32 vf22();
    virtual void vf23();
    virtual void vf24();
    virtual u8* vf25();
    virtual void vf26(f32 fvalue);
    virtual f32 vf27();
    virtual void vf28();
    virtual u8* vf29();
    virtual void vf30();
    virtual u8* vf31();
    virtual void vf32();
    virtual u8* vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual u8* vf37();
    virtual void vf38();
    virtual u8* vf39();
    u8 _8[0x1a0];
    Unk_239d658_1a8* field_1a8;
};
PKMN_OFFSET_ASSERT(Unk_239d658, field_1a8, 0x1a8);

// 0x7100632360
void Unk_239d658::vf7(f32 fvalue) {
    field_1a8->field_a0->field_c8 = fvalue;
}

// 0x7100632620
f32 Unk_239d658::vf8() {
    return field_1a8->field_a0->field_c8;
}

// 0x7100632370
void Unk_239d658::vf9(f32 fvalue) {
    field_1a8->field_a0->field_cc = fvalue;
}

// 0x7100632630
f32 Unk_239d658::vf10() {
    return field_1a8->field_a0->field_cc;
}

// 0x7100632380
void Unk_239d658::vf11(f32 fvalue) {
    field_1a8->field_a0->field_d0 = fvalue;
}

// 0x7100632640
f32 Unk_239d658::vf12() {
    return field_1a8->field_a0->field_d0;
}

// 0x7100632650
u8* Unk_239d658::vf14() {
    return &field_1a8->field_a8;
}

// 0x71006327c0
u32 Unk_239d658::vf16() {
    return (field_1a8->field_138 >> 2) & 1;
}

// 0x71006327d0
u8* Unk_239d658::vf18() {
    return &field_1a8->field_d0;
}

// 0x71006327e0
u32 Unk_239d658::vf20() {
    return (field_1a8->field_138 >> 3) & 1;
}

// 0x7100632350
void Unk_239d658::vf21(f32 fvalue) {
    field_1a8->field_144 = fvalue;
}

// 0x71006327f0
f32 Unk_239d658::vf22() {
    return field_1a8->field_144;
}

// 0x7100632870
u8* Unk_239d658::vf25() {
    return &field_1a8->field_e0;
}

// 0x7100632880
void Unk_239d658::vf26(f32 fvalue) {
    field_1a8->field_140 = fvalue;
}

// 0x7100632890
f32 Unk_239d658::vf27() {
    return field_1a8->field_140;
}

// 0x71006328c0
u8* Unk_239d658::vf29() {
    return &field_1a8->field_c0;
}

// 0x71006328d0
u8* Unk_239d658::vf31() {
    return &field_1a8->field_110;
}

// 0x71006328e0
u8* Unk_239d658::vf33() {
    return &field_1a8->field_f0;
}

// 0x7100632930
u8* Unk_239d658::vf37() {
    return &field_1a8->field_120;
}

// 0x7100632960
u8* Unk_239d658::vf39() {
    return &field_1a8->field_100;
}

struct Unk_239d810_20_a0 {
    u8 _0[0xc8];
    f32 field_c8;
    f32 field_cc;
    f32 field_d0;
};
PKMN_OFFSET_ASSERT(Unk_239d810_20_a0, field_c8, 0xc8);
PKMN_OFFSET_ASSERT(Unk_239d810_20_a0, field_cc, 0xcc);
PKMN_OFFSET_ASSERT(Unk_239d810_20_a0, field_d0, 0xd0);

struct Unk_239d810_20 {
    u8 _0[0xa0];
    Unk_239d810_20_a0* field_a0;
    u8 field_a8;
    u8 _a9[0x47];
    u8 field_f0;
    u8 _f1[0xf];
    u8 field_100;
    u8 _101[0xf];
    u8 field_110;
    u8 _111[0xf];
    u8 field_120;
};
PKMN_OFFSET_ASSERT(Unk_239d810_20, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_239d810_20, field_a8, 0xa8);
PKMN_OFFSET_ASSERT(Unk_239d810_20, field_f0, 0xf0);
PKMN_OFFSET_ASSERT(Unk_239d810_20, field_100, 0x100);
PKMN_OFFSET_ASSERT(Unk_239d810_20, field_110, 0x110);
PKMN_OFFSET_ASSERT(Unk_239d810_20, field_120, 0x120);

class Unk_239d810 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual u8* vf5();
    virtual u8* vf6();
    virtual void vf7(f32 fvalue);
    virtual f32 vf8();
    virtual void vf9(f32 fvalue);
    virtual f32 vf10();
    virtual void vf11(f32 fvalue);
    virtual f32 vf12();
    virtual void vf13();
    virtual u8* vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual u8* vf18();
    virtual void vf19();
    virtual u8* vf20();
    virtual void vf21();
    virtual void vf22();
    u8 _8[0x18];
    Unk_239d810_20* field_20;
};
PKMN_OFFSET_ASSERT(Unk_239d810, field_20, 0x20);

// 0x7100632fb0
u8* Unk_239d810::vf5() {
    return &field_20->field_110;
}

// 0x7100632fc0
u8* Unk_239d810::vf6() {
    return &field_20->field_f0;
}

// 0x7100632fd0
void Unk_239d810::vf7(f32 fvalue) {
    field_20->field_a0->field_c8 = fvalue;
}

// 0x7100632fe0
f32 Unk_239d810::vf8() {
    return field_20->field_a0->field_c8;
}

// 0x7100632ff0
void Unk_239d810::vf9(f32 fvalue) {
    field_20->field_a0->field_cc = fvalue;
}

// 0x7100633000
f32 Unk_239d810::vf10() {
    return field_20->field_a0->field_cc;
}

// 0x7100633010
void Unk_239d810::vf11(f32 fvalue) {
    field_20->field_a0->field_d0 = fvalue;
}

// 0x7100633020
f32 Unk_239d810::vf12() {
    return field_20->field_a0->field_d0;
}

// 0x7100633040
u8* Unk_239d810::vf14() {
    return &field_20->field_a8;
}

// 0x7100633090
u8* Unk_239d810::vf18() {
    return &field_20->field_120;
}

// 0x71006330c0
u8* Unk_239d810::vf20() {
    return &field_20->field_100;
}

struct Unk_239d8d8_18_a0 {
    u8 _0[0xc8];
    f32 field_c8;
    f32 field_cc;
    f32 field_d0;
};
PKMN_OFFSET_ASSERT(Unk_239d8d8_18_a0, field_c8, 0xc8);
PKMN_OFFSET_ASSERT(Unk_239d8d8_18_a0, field_cc, 0xcc);
PKMN_OFFSET_ASSERT(Unk_239d8d8_18_a0, field_d0, 0xd0);

struct Unk_239d8d8_18 {
    u8 _0[0xa0];
    Unk_239d8d8_18_a0* field_a0;
    u8 field_a8;
    u8 _a9[0x17];
    u8 field_c0;
    u8 _c1[0xf];
    u8 field_d0;
    u8 _d1[0x1f];
    u8 field_f0;
    u8 _f1[0xf];
    u8 field_100;
    u8 _101[0xf];
    u8 field_110;
    u8 _111[0xf];
    u8 field_120;
    u8 _121[0x17];
    u8 field_138;
    u8 _139[0xb];
    f32 field_144;
};
PKMN_OFFSET_ASSERT(Unk_239d8d8_18, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_239d8d8_18, field_a8, 0xa8);
PKMN_OFFSET_ASSERT(Unk_239d8d8_18, field_c0, 0xc0);
PKMN_OFFSET_ASSERT(Unk_239d8d8_18, field_d0, 0xd0);
PKMN_OFFSET_ASSERT(Unk_239d8d8_18, field_f0, 0xf0);
PKMN_OFFSET_ASSERT(Unk_239d8d8_18, field_100, 0x100);
PKMN_OFFSET_ASSERT(Unk_239d8d8_18, field_110, 0x110);
PKMN_OFFSET_ASSERT(Unk_239d8d8_18, field_120, 0x120);
PKMN_OFFSET_ASSERT(Unk_239d8d8_18, field_138, 0x138);
PKMN_OFFSET_ASSERT(Unk_239d8d8_18, field_144, 0x144);

class Unk_239d8d8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual u8* vf5();
    virtual u8* vf6();
    virtual void vf7(f32 fvalue);
    virtual f32 vf8();
    virtual void vf9(f32 fvalue);
    virtual f32 vf10();
    virtual void vf11(f32 fvalue);
    virtual f32 vf12();
    virtual void vf13();
    virtual u8* vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual u8* vf18();
    virtual void vf19();
    virtual u8* vf20();
    virtual void vf21();
    virtual void vf22();
    virtual u32 vf23();
    virtual void vf24();
    virtual u8* vf25();
    virtual void vf26();
    virtual u32 vf27();
    virtual void vf28(f32 fvalue);
    virtual f32 vf29();
    virtual void vf30();
    virtual u8* vf31();
    u8 _8[0x10];
    Unk_239d8d8_18* field_18;
};
PKMN_OFFSET_ASSERT(Unk_239d8d8, field_18, 0x18);

// 0x7100633300
u8* Unk_239d8d8::vf5() {
    return &field_18->field_110;
}

// 0x7100633310
u8* Unk_239d8d8::vf6() {
    return &field_18->field_f0;
}

// 0x7100633320
void Unk_239d8d8::vf7(f32 fvalue) {
    field_18->field_a0->field_c8 = fvalue;
}

// 0x7100633330
f32 Unk_239d8d8::vf8() {
    return field_18->field_a0->field_c8;
}

// 0x7100633340
void Unk_239d8d8::vf9(f32 fvalue) {
    field_18->field_a0->field_cc = fvalue;
}

// 0x7100633350
f32 Unk_239d8d8::vf10() {
    return field_18->field_a0->field_cc;
}

// 0x7100633360
void Unk_239d8d8::vf11(f32 fvalue) {
    field_18->field_a0->field_d0 = fvalue;
}

// 0x7100633370
f32 Unk_239d8d8::vf12() {
    return field_18->field_a0->field_d0;
}

// 0x7100633390
u8* Unk_239d8d8::vf14() {
    return &field_18->field_a8;
}

// 0x71006333e0
u8* Unk_239d8d8::vf18() {
    return &field_18->field_120;
}

// 0x7100633410
u8* Unk_239d8d8::vf20() {
    return &field_18->field_100;
}

// 0x71006335a0
u32 Unk_239d8d8::vf23() {
    return (field_18->field_138 >> 2) & 1;
}

// 0x71006335d0
u8* Unk_239d8d8::vf25() {
    return &field_18->field_d0;
}

// 0x7100633610
u32 Unk_239d8d8::vf27() {
    return (field_18->field_138 >> 3) & 1;
}

// 0x7100633620
void Unk_239d8d8::vf28(f32 fvalue) {
    field_18->field_144 = fvalue;
}

// 0x7100633630
f32 Unk_239d8d8::vf29() {
    return field_18->field_144;
}

// 0x7100633660
u8* Unk_239d8d8::vf31() {
    return &field_18->field_c0;
}

struct Unk_239d9e8_10_a0 {
    u8 _0[0xc8];
    f32 field_c8;
    f32 field_cc;
    f32 field_d0;
};
PKMN_OFFSET_ASSERT(Unk_239d9e8_10_a0, field_c8, 0xc8);
PKMN_OFFSET_ASSERT(Unk_239d9e8_10_a0, field_cc, 0xcc);
PKMN_OFFSET_ASSERT(Unk_239d9e8_10_a0, field_d0, 0xd0);

struct Unk_239d9e8_10 {
    u8 _0[0xa0];
    Unk_239d9e8_10_a0* field_a0;
    u8 field_a8;
    u8 _a9[0x47];
    u8 field_f0;
    u8 _f1[0xf];
    u8 field_100;
    u8 _101[0xf];
    u8 field_110;
    u8 _111[0xf];
    u8 field_120;
    u8 _121[0x1f];
    f32 field_140;
};
PKMN_OFFSET_ASSERT(Unk_239d9e8_10, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_239d9e8_10, field_a8, 0xa8);
PKMN_OFFSET_ASSERT(Unk_239d9e8_10, field_f0, 0xf0);
PKMN_OFFSET_ASSERT(Unk_239d9e8_10, field_100, 0x100);
PKMN_OFFSET_ASSERT(Unk_239d9e8_10, field_110, 0x110);
PKMN_OFFSET_ASSERT(Unk_239d9e8_10, field_120, 0x120);
PKMN_OFFSET_ASSERT(Unk_239d9e8_10, field_140, 0x140);

class Unk_239d9e8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual u8* vf5();
    virtual u8* vf6();
    virtual void vf7(f32 fvalue);
    virtual f32 vf8();
    virtual void vf9(f32 fvalue);
    virtual f32 vf10();
    virtual void vf11(f32 fvalue);
    virtual f32 vf12();
    virtual void vf13();
    virtual u8* vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual u8* vf18();
    virtual void vf19();
    virtual u8* vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24(f32 fvalue);
    virtual f32 vf25();
    u8 _8[0x8];
    Unk_239d9e8_10* field_10;
};
PKMN_OFFSET_ASSERT(Unk_239d9e8, field_10, 0x10);

// 0x7100633860
u8* Unk_239d9e8::vf5() {
    return &field_10->field_110;
}

// 0x7100633870
u8* Unk_239d9e8::vf6() {
    return &field_10->field_f0;
}

// 0x7100633880
void Unk_239d9e8::vf7(f32 fvalue) {
    field_10->field_a0->field_c8 = fvalue;
}

// 0x7100633890
f32 Unk_239d9e8::vf8() {
    return field_10->field_a0->field_c8;
}

// 0x71006338a0
void Unk_239d9e8::vf9(f32 fvalue) {
    field_10->field_a0->field_cc = fvalue;
}

// 0x71006338b0
f32 Unk_239d9e8::vf10() {
    return field_10->field_a0->field_cc;
}

// 0x71006338c0
void Unk_239d9e8::vf11(f32 fvalue) {
    field_10->field_a0->field_d0 = fvalue;
}

// 0x71006338d0
f32 Unk_239d9e8::vf12() {
    return field_10->field_a0->field_d0;
}

// 0x71006338f0
u8* Unk_239d9e8::vf14() {
    return &field_10->field_a8;
}

// 0x7100633940
u8* Unk_239d9e8::vf18() {
    return &field_10->field_120;
}

// 0x7100633970
u8* Unk_239d9e8::vf20() {
    return &field_10->field_100;
}

// 0x7100633a10
void Unk_239d9e8::vf24(f32 fvalue) {
    field_10->field_140 = fvalue;
}

// 0x7100633a20
f32 Unk_239d9e8::vf25() {
    return field_10->field_140;
}

struct Unk_239dac8_8_a0 {
    u8 _0[0xc8];
    f32 field_c8;
    f32 field_cc;
    f32 field_d0;
};
PKMN_OFFSET_ASSERT(Unk_239dac8_8_a0, field_c8, 0xc8);
PKMN_OFFSET_ASSERT(Unk_239dac8_8_a0, field_cc, 0xcc);
PKMN_OFFSET_ASSERT(Unk_239dac8_8_a0, field_d0, 0xd0);

struct Unk_239dac8_8 {
    u8 _0[0xa0];
    Unk_239dac8_8_a0* field_a0;
    u8 field_a8;
    u8 _a9[0x27];
    u8 field_d0;
    u8 _d1[0xf];
    u8 field_e0;
    u8 _e1[0xf];
    u8 field_f0;
    u8 _f1[0xf];
    u8 field_100;
    u8 _101[0xf];
    u8 field_110;
    u8 _111[0xf];
    u8 field_120;
    u8 _121[0x17];
    u8 field_138;
    u8 _139[0xb];
    f32 field_144;
};
PKMN_OFFSET_ASSERT(Unk_239dac8_8, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_239dac8_8, field_a8, 0xa8);
PKMN_OFFSET_ASSERT(Unk_239dac8_8, field_d0, 0xd0);
PKMN_OFFSET_ASSERT(Unk_239dac8_8, field_e0, 0xe0);
PKMN_OFFSET_ASSERT(Unk_239dac8_8, field_f0, 0xf0);
PKMN_OFFSET_ASSERT(Unk_239dac8_8, field_100, 0x100);
PKMN_OFFSET_ASSERT(Unk_239dac8_8, field_110, 0x110);
PKMN_OFFSET_ASSERT(Unk_239dac8_8, field_120, 0x120);
PKMN_OFFSET_ASSERT(Unk_239dac8_8, field_138, 0x138);
PKMN_OFFSET_ASSERT(Unk_239dac8_8, field_144, 0x144);

class Unk_239dac8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual u8* vf5();
    virtual u8* vf6();
    virtual void vf7(f32 fvalue);
    virtual f32 vf8();
    virtual void vf9(f32 fvalue);
    virtual f32 vf10();
    virtual void vf11(f32 fvalue);
    virtual f32 vf12();
    virtual void vf13();
    virtual u8* vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual u8* vf18();
    virtual void vf19();
    virtual u8* vf20();
    virtual void vf21();
    virtual void vf22();
    virtual u32 vf23();
    virtual void vf24();
    virtual u8* vf25();
    virtual void vf26();
    virtual u32 vf27();
    virtual void vf28(f32 fvalue);
    virtual f32 vf29();
    virtual void vf30();
    virtual void vf31();
    virtual u8* vf32();
    Unk_239dac8_8* field_8;
};
PKMN_OFFSET_ASSERT(Unk_239dac8, field_8, 0x8);

// 0x7100633c20
u8* Unk_239dac8::vf5() {
    return &field_8->field_110;
}

// 0x7100633c30
u8* Unk_239dac8::vf6() {
    return &field_8->field_f0;
}

// 0x7100633c40
void Unk_239dac8::vf7(f32 fvalue) {
    field_8->field_a0->field_c8 = fvalue;
}

// 0x7100633c50
f32 Unk_239dac8::vf8() {
    return field_8->field_a0->field_c8;
}

// 0x7100633c60
void Unk_239dac8::vf9(f32 fvalue) {
    field_8->field_a0->field_cc = fvalue;
}

// 0x7100633c70
f32 Unk_239dac8::vf10() {
    return field_8->field_a0->field_cc;
}

// 0x7100633c80
void Unk_239dac8::vf11(f32 fvalue) {
    field_8->field_a0->field_d0 = fvalue;
}

// 0x7100633c90
f32 Unk_239dac8::vf12() {
    return field_8->field_a0->field_d0;
}

// 0x7100633cb0
u8* Unk_239dac8::vf14() {
    return &field_8->field_a8;
}

// 0x7100633d00
u8* Unk_239dac8::vf18() {
    return &field_8->field_120;
}

// 0x7100633d30
u8* Unk_239dac8::vf20() {
    return &field_8->field_100;
}

// 0x7100633ec0
u32 Unk_239dac8::vf23() {
    return (field_8->field_138 >> 2) & 1;
}

// 0x7100633ef0
u8* Unk_239dac8::vf25() {
    return &field_8->field_d0;
}

// 0x7100633f30
u32 Unk_239dac8::vf27() {
    return (field_8->field_138 >> 3) & 1;
}

// 0x7100633f40
void Unk_239dac8::vf28(f32 fvalue) {
    field_8->field_144 = fvalue;
}

// 0x7100633f50
f32 Unk_239dac8::vf29() {
    return field_8->field_144;
}

// 0x7100633fd0
u8* Unk_239dac8::vf32() {
    return &field_8->field_e0;
}

struct Unk_239dbe0_a0 {
    u8 _0[0xc8];
    f32 field_c8;
    f32 field_cc;
    f32 field_d0;
};
PKMN_OFFSET_ASSERT(Unk_239dbe0_a0, field_c8, 0xc8);
PKMN_OFFSET_ASSERT(Unk_239dbe0_a0, field_cc, 0xcc);
PKMN_OFFSET_ASSERT(Unk_239dbe0_a0, field_d0, 0xd0);

class Unk_239dbe0 {
public:
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
    virtual void vf14(f32 fvalue);
    virtual f32 vf15();
    virtual void vf16(f32 fvalue);
    virtual f32 vf17();
    virtual void vf18(f32 fvalue);
    virtual f32 vf19();
    virtual void vf20();
    virtual u8* vf21();
    virtual u32 vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual u8* vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29(f32 fvalue);
    virtual f32 vf30();
    virtual void vf31();
    virtual void vf32();
    virtual u8* vf33();
    virtual void vf34(f32 fvalue);
    virtual f32 vf35();
    virtual void vf36();
    virtual u8* vf37();
    virtual void vf38();
    virtual u8* vf39();
    virtual void vf40();
    virtual u8* vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual u8* vf45();
    virtual void vf46();
    virtual u8* vf47();
    u8 _8[0x98];
    Unk_239dbe0_a0* field_a0;
    u8 field_a8;
    u8 _a9[0x17];
    u8 field_c0;
    u8 _c1[0xf];
    u8 field_d0;
    u8 _d1[0xf];
    u8 field_e0;
    u8 _e1[0xf];
    u8 field_f0;
    u8 _f1[0xf];
    u8 field_100;
    u8 _101[0xf];
    u8 field_110;
    u8 _111[0xf];
    u8 field_120;
    u8 _121[0x17];
    u32 field_138;
    u8 _13c[0x4];
    f32 field_140;
    f32 field_144;
};
PKMN_OFFSET_ASSERT(Unk_239dbe0, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_239dbe0, field_a8, 0xa8);
PKMN_OFFSET_ASSERT(Unk_239dbe0, field_c0, 0xc0);
PKMN_OFFSET_ASSERT(Unk_239dbe0, field_d0, 0xd0);
PKMN_OFFSET_ASSERT(Unk_239dbe0, field_e0, 0xe0);
PKMN_OFFSET_ASSERT(Unk_239dbe0, field_f0, 0xf0);
PKMN_OFFSET_ASSERT(Unk_239dbe0, field_100, 0x100);
PKMN_OFFSET_ASSERT(Unk_239dbe0, field_110, 0x110);
PKMN_OFFSET_ASSERT(Unk_239dbe0, field_120, 0x120);
PKMN_OFFSET_ASSERT(Unk_239dbe0, field_138, 0x138);
PKMN_OFFSET_ASSERT(Unk_239dbe0, field_140, 0x140);
PKMN_OFFSET_ASSERT(Unk_239dbe0, field_144, 0x144);

// 0x7100634530
void Unk_239dbe0::vf12() {
    Unk_634540(this);
}

// 0x7100635630
void Unk_239dbe0::vf14(f32 fvalue) {
    field_a0->field_c8 = fvalue;
}

// 0x7100635640
f32 Unk_239dbe0::vf15() {
    return field_a0->field_c8;
}

// 0x7100635650
void Unk_239dbe0::vf16(f32 fvalue) {
    field_a0->field_cc = fvalue;
}

// 0x7100635660
f32 Unk_239dbe0::vf17() {
    return field_a0->field_cc;
}

// 0x7100635670
void Unk_239dbe0::vf18(f32 fvalue) {
    field_a0->field_d0 = fvalue;
}

// 0x7100635680
f32 Unk_239dbe0::vf19() {
    return field_a0->field_d0;
}

// 0x71006356a0
u8* Unk_239dbe0::vf21() {
    return &field_a8;
}

// 0x7100635310
u32 Unk_239dbe0::vf22() {
    return field_138 & 1;
}

// 0x7100635830
u8* Unk_239dbe0::vf26() {
    return &field_d0;
}

// 0x7100635860
void Unk_239dbe0::vf29(f32 fvalue) {
    field_144 = fvalue;
}

// 0x7100635870
f32 Unk_239dbe0::vf30() {
    return field_144;
}

// 0x71006358f0
u8* Unk_239dbe0::vf33() {
    return &field_e0;
}

// 0x7100635900
void Unk_239dbe0::vf34(f32 fvalue) {
    field_140 = fvalue;
}

// 0x7100635910
f32 Unk_239dbe0::vf35() {
    return field_140;
}

// 0x7100635940
u8* Unk_239dbe0::vf37() {
    return &field_c0;
}

// 0x7100635970
u8* Unk_239dbe0::vf39() {
    return &field_110;
}

// 0x71006359a0
u8* Unk_239dbe0::vf41() {
    return &field_f0;
}

// 0x7100635a90
u8* Unk_239dbe0::vf45() {
    return &field_120;
}

// 0x7100635ac0
u8* Unk_239dbe0::vf47() {
    return &field_100;
}

struct Unk_239de08_28 {
    u8 _0[0xc8];
    f32 field_c8;
    f32 field_cc;
    f32 field_d0;
};
PKMN_OFFSET_ASSERT(Unk_239de08_28, field_c8, 0xc8);
PKMN_OFFSET_ASSERT(Unk_239de08_28, field_cc, 0xcc);
PKMN_OFFSET_ASSERT(Unk_239de08_28, field_d0, 0xd0);

class Unk_239de08 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual u8* vf5();
    virtual u8* vf6();
    virtual void vf7(f32 fvalue);
    virtual f32 vf8();
    virtual void vf9(f32 fvalue);
    virtual f32 vf10();
    virtual void vf11(f32 fvalue);
    virtual f32 vf12();
    virtual void vf13();
    virtual u8* vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual u8* vf18();
    virtual void vf19();
    virtual u8* vf20();
    virtual void vf21();
    virtual void vf22();
    u8 _8[0x20];
    Unk_239de08_28* field_28;
    u8 field_30;
    u8 _31[0x47];
    u8 field_78;
    u8 _79[0xf];
    u8 field_88;
    u8 _89[0xf];
    u8 field_98;
    u8 _99[0xf];
    u8 field_a8;
};
PKMN_OFFSET_ASSERT(Unk_239de08, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_239de08, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_239de08, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_239de08, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_239de08, field_98, 0x98);
PKMN_OFFSET_ASSERT(Unk_239de08, field_a8, 0xa8);

// 0x71006362d0
u8* Unk_239de08::vf5() {
    return &field_98;
}

// 0x71006362e0
u8* Unk_239de08::vf6() {
    return &field_78;
}

// 0x71006362f0
void Unk_239de08::vf7(f32 fvalue) {
    field_28->field_c8 = fvalue;
}

// 0x7100636300
f32 Unk_239de08::vf8() {
    return field_28->field_c8;
}

// 0x7100636310
void Unk_239de08::vf9(f32 fvalue) {
    field_28->field_cc = fvalue;
}

// 0x7100636320
f32 Unk_239de08::vf10() {
    return field_28->field_cc;
}

// 0x7100636330
void Unk_239de08::vf11(f32 fvalue) {
    field_28->field_d0 = fvalue;
}

// 0x7100636340
f32 Unk_239de08::vf12() {
    return field_28->field_d0;
}

// 0x7100636360
u8* Unk_239de08::vf14() {
    return &field_30;
}

// 0x7100636450
u8* Unk_239de08::vf18() {
    return &field_a8;
}

// 0x7100636480
u8* Unk_239de08::vf20() {
    return &field_88;
}

struct Unk_239ded0_20 {
    u8 _0[0xc8];
    f32 field_c8;
    f32 field_cc;
    f32 field_d0;
};
PKMN_OFFSET_ASSERT(Unk_239ded0_20, field_c8, 0xc8);
PKMN_OFFSET_ASSERT(Unk_239ded0_20, field_cc, 0xcc);
PKMN_OFFSET_ASSERT(Unk_239ded0_20, field_d0, 0xd0);

class Unk_239ded0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual u8* vf5();
    virtual u8* vf6();
    virtual void vf7(f32 fvalue);
    virtual f32 vf8();
    virtual void vf9(f32 fvalue);
    virtual f32 vf10();
    virtual void vf11(f32 fvalue);
    virtual f32 vf12();
    virtual void vf13();
    virtual u8* vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual u8* vf18();
    virtual void vf19();
    virtual u8* vf20();
    virtual void vf21();
    virtual void vf22();
    virtual u32 vf23();
    virtual void vf24();
    virtual u8* vf25();
    virtual void vf26();
    virtual u32 vf27();
    virtual void vf28(f32 fvalue);
    virtual f32 vf29();
    virtual void vf30();
    virtual u8* vf31();
    u8 _8[0x18];
    Unk_239ded0_20* field_20;
    u8 field_28;
    u8 _29[0x17];
    u8 field_40;
    u8 _41[0xf];
    u8 field_50;
    u8 _51[0x1f];
    u8 field_70;
    u8 _71[0xf];
    u8 field_80;
    u8 _81[0xf];
    u8 field_90;
    u8 _91[0xf];
    u8 field_a0;
    u8 _a1[0x17];
    u8 field_b8;
    u8 _b9[0xb];
    f32 field_c4;
};
PKMN_OFFSET_ASSERT(Unk_239ded0, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_239ded0, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_239ded0, field_40, 0x40);
PKMN_OFFSET_ASSERT(Unk_239ded0, field_50, 0x50);
PKMN_OFFSET_ASSERT(Unk_239ded0, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_239ded0, field_80, 0x80);
PKMN_OFFSET_ASSERT(Unk_239ded0, field_90, 0x90);
PKMN_OFFSET_ASSERT(Unk_239ded0, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_239ded0, field_b8, 0xb8);
PKMN_OFFSET_ASSERT(Unk_239ded0, field_c4, 0xc4);

// 0x7100636760
u8* Unk_239ded0::vf5() {
    return &field_90;
}

// 0x7100636770
u8* Unk_239ded0::vf6() {
    return &field_70;
}

// 0x7100636780
void Unk_239ded0::vf7(f32 fvalue) {
    field_20->field_c8 = fvalue;
}

// 0x7100636790
f32 Unk_239ded0::vf8() {
    return field_20->field_c8;
}

// 0x71006367a0
void Unk_239ded0::vf9(f32 fvalue) {
    field_20->field_cc = fvalue;
}

// 0x71006367b0
f32 Unk_239ded0::vf10() {
    return field_20->field_cc;
}

// 0x71006367c0
void Unk_239ded0::vf11(f32 fvalue) {
    field_20->field_d0 = fvalue;
}

// 0x71006367d0
f32 Unk_239ded0::vf12() {
    return field_20->field_d0;
}

// 0x71006367f0
u8* Unk_239ded0::vf14() {
    return &field_28;
}

// 0x71006368e0
u8* Unk_239ded0::vf18() {
    return &field_a0;
}

// 0x7100636910
u8* Unk_239ded0::vf20() {
    return &field_80;
}

// 0x7100636aa0
u32 Unk_239ded0::vf23() {
    return (field_b8 >> 2) & 1;
}

// 0x7100636ad0
u8* Unk_239ded0::vf25() {
    return &field_50;
}

// 0x7100636b00
u32 Unk_239ded0::vf27() {
    return (field_b8 >> 3) & 1;
}

// 0x7100636b10
void Unk_239ded0::vf28(f32 fvalue) {
    field_c4 = fvalue;
}

// 0x7100636b20
f32 Unk_239ded0::vf29() {
    return field_c4;
}

// 0x7100636b50
u8* Unk_239ded0::vf31() {
    return &field_40;
}

struct Unk_239dfe0_18 {
    u8 _0[0xc8];
    f32 field_c8;
    f32 field_cc;
    f32 field_d0;
};
PKMN_OFFSET_ASSERT(Unk_239dfe0_18, field_c8, 0xc8);
PKMN_OFFSET_ASSERT(Unk_239dfe0_18, field_cc, 0xcc);
PKMN_OFFSET_ASSERT(Unk_239dfe0_18, field_d0, 0xd0);

class Unk_239dfe0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual u8* vf5();
    virtual u8* vf6();
    virtual void vf7(f32 fvalue);
    virtual f32 vf8();
    virtual void vf9(f32 fvalue);
    virtual f32 vf10();
    virtual void vf11(f32 fvalue);
    virtual f32 vf12();
    virtual void vf13();
    virtual u8* vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual u8* vf18();
    virtual void vf19();
    virtual u8* vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24(f32 fvalue);
    virtual f32 vf25();
    u8 _8[0x10];
    Unk_239dfe0_18* field_18;
    u8 field_20;
    u8 _21[0x47];
    u8 field_68;
    u8 _69[0xf];
    u8 field_78;
    u8 _79[0xf];
    u8 field_88;
    u8 _89[0xf];
    u8 field_98;
    u8 _99[0x1f];
    f32 field_b8;
};
PKMN_OFFSET_ASSERT(Unk_239dfe0, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_239dfe0, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_239dfe0, field_68, 0x68);
PKMN_OFFSET_ASSERT(Unk_239dfe0, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_239dfe0, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_239dfe0, field_98, 0x98);
PKMN_OFFSET_ASSERT(Unk_239dfe0, field_b8, 0xb8);

// 0x7100636df0
u8* Unk_239dfe0::vf5() {
    return &field_88;
}

// 0x7100636e00
u8* Unk_239dfe0::vf6() {
    return &field_68;
}

// 0x7100636e10
void Unk_239dfe0::vf7(f32 fvalue) {
    field_18->field_c8 = fvalue;
}

// 0x7100636e20
f32 Unk_239dfe0::vf8() {
    return field_18->field_c8;
}

// 0x7100636e30
void Unk_239dfe0::vf9(f32 fvalue) {
    field_18->field_cc = fvalue;
}

// 0x7100636e40
f32 Unk_239dfe0::vf10() {
    return field_18->field_cc;
}

// 0x7100636e50
void Unk_239dfe0::vf11(f32 fvalue) {
    field_18->field_d0 = fvalue;
}

// 0x7100636e60
f32 Unk_239dfe0::vf12() {
    return field_18->field_d0;
}

// 0x7100636e80
u8* Unk_239dfe0::vf14() {
    return &field_20;
}

// 0x7100636f70
u8* Unk_239dfe0::vf18() {
    return &field_98;
}

// 0x7100636fa0
u8* Unk_239dfe0::vf20() {
    return &field_78;
}

// 0x7100637040
void Unk_239dfe0::vf24(f32 fvalue) {
    field_b8 = fvalue;
}

// 0x7100637050
f32 Unk_239dfe0::vf25() {
    return field_b8;
}

struct Unk_239e0c0_10 {
    u8 _0[0xc8];
    f32 field_c8;
    f32 field_cc;
    f32 field_d0;
};
PKMN_OFFSET_ASSERT(Unk_239e0c0_10, field_c8, 0xc8);
PKMN_OFFSET_ASSERT(Unk_239e0c0_10, field_cc, 0xcc);
PKMN_OFFSET_ASSERT(Unk_239e0c0_10, field_d0, 0xd0);

class Unk_239e0c0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual u8* vf5();
    virtual u8* vf6();
    virtual void vf7(f32 fvalue);
    virtual f32 vf8();
    virtual void vf9(f32 fvalue);
    virtual f32 vf10();
    virtual void vf11(f32 fvalue);
    virtual f32 vf12();
    virtual void vf13();
    virtual u8* vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual u8* vf18();
    virtual void vf19();
    virtual u8* vf20();
    virtual void vf21();
    virtual void vf22();
    virtual u32 vf23();
    virtual void vf24();
    virtual u8* vf25();
    virtual void vf26();
    virtual u32 vf27();
    virtual void vf28(f32 fvalue);
    virtual f32 vf29();
    virtual void vf30();
    virtual void vf31();
    virtual u8* vf32();
    u8 _8[0x8];
    Unk_239e0c0_10* field_10;
    u8 field_18;
    u8 _19[0x27];
    u8 field_40;
    u8 _41[0xf];
    u8 field_50;
    u8 _51[0xf];
    u8 field_60;
    u8 _61[0xf];
    u8 field_70;
    u8 _71[0xf];
    u8 field_80;
    u8 _81[0xf];
    u8 field_90;
    u8 _91[0x17];
    u8 field_a8;
    u8 _a9[0xb];
    f32 field_b4;
};
PKMN_OFFSET_ASSERT(Unk_239e0c0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_239e0c0, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_239e0c0, field_40, 0x40);
PKMN_OFFSET_ASSERT(Unk_239e0c0, field_50, 0x50);
PKMN_OFFSET_ASSERT(Unk_239e0c0, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_239e0c0, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_239e0c0, field_80, 0x80);
PKMN_OFFSET_ASSERT(Unk_239e0c0, field_90, 0x90);
PKMN_OFFSET_ASSERT(Unk_239e0c0, field_a8, 0xa8);
PKMN_OFFSET_ASSERT(Unk_239e0c0, field_b4, 0xb4);

// 0x71006372f0
u8* Unk_239e0c0::vf5() {
    return &field_80;
}

// 0x7100637300
u8* Unk_239e0c0::vf6() {
    return &field_60;
}

// 0x7100637310
void Unk_239e0c0::vf7(f32 fvalue) {
    field_10->field_c8 = fvalue;
}

// 0x7100637320
f32 Unk_239e0c0::vf8() {
    return field_10->field_c8;
}

// 0x7100637330
void Unk_239e0c0::vf9(f32 fvalue) {
    field_10->field_cc = fvalue;
}

// 0x7100637340
f32 Unk_239e0c0::vf10() {
    return field_10->field_cc;
}

// 0x7100637350
void Unk_239e0c0::vf11(f32 fvalue) {
    field_10->field_d0 = fvalue;
}

// 0x7100637360
f32 Unk_239e0c0::vf12() {
    return field_10->field_d0;
}

// 0x7100637380
u8* Unk_239e0c0::vf14() {
    return &field_18;
}

// 0x7100637470
u8* Unk_239e0c0::vf18() {
    return &field_90;
}

// 0x71006374a0
u8* Unk_239e0c0::vf20() {
    return &field_70;
}

// 0x7100637630
u32 Unk_239e0c0::vf23() {
    return (field_a8 >> 2) & 1;
}

// 0x7100637660
u8* Unk_239e0c0::vf25() {
    return &field_40;
}

// 0x7100637690
u32 Unk_239e0c0::vf27() {
    return (field_a8 >> 3) & 1;
}

// 0x71006376a0
void Unk_239e0c0::vf28(f32 fvalue) {
    field_b4 = fvalue;
}

// 0x71006376b0
f32 Unk_239e0c0::vf29() {
    return field_b4;
}

// 0x7100637730
u8* Unk_239e0c0::vf32() {
    return &field_50;
}

struct Unk_239e1d8_8 {
    u8 _0[0xc8];
    f32 field_c8;
    f32 field_cc;
    f32 field_d0;
};
PKMN_OFFSET_ASSERT(Unk_239e1d8_8, field_c8, 0xc8);
PKMN_OFFSET_ASSERT(Unk_239e1d8_8, field_cc, 0xcc);
PKMN_OFFSET_ASSERT(Unk_239e1d8_8, field_d0, 0xd0);

class Unk_239e1d8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual u8* vf5();
    virtual u8* vf6();
    virtual void vf7(f32 fvalue);
    virtual f32 vf8();
    virtual void vf9(f32 fvalue);
    virtual f32 vf10();
    virtual void vf11(f32 fvalue);
    virtual f32 vf12();
    virtual void vf13();
    virtual u8* vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual u8* vf18();
    virtual void vf19();
    virtual u8* vf20();
    virtual void vf21();
    virtual void vf22();
    virtual u32 vf23();
    virtual void vf24();
    virtual u8* vf25();
    virtual u32 vf26();
    virtual void vf27(f32 fvalue);
    virtual f32 vf28();
    virtual void vf29();
    virtual u8* vf30();
    virtual void vf31();
    virtual void vf32();
    virtual u8* vf33();
    virtual void vf34();
    Unk_239e1d8_8* field_8;
    u8 field_10;
    u8 _11[0x17];
    u8 field_28;
    u8 _29[0xf];
    u8 field_38;
    u8 _39[0xf];
    u8 field_48;
    u8 _49[0xf];
    u8 field_58;
    u8 _59[0xf];
    u8 field_68;
    u8 _69[0xf];
    u8 field_78;
    u8 _79[0xf];
    u8 field_88;
    u8 _89[0x17];
    u8 field_a0;
    u8 _a1[0xb];
    f32 field_ac;
};
PKMN_OFFSET_ASSERT(Unk_239e1d8, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_239e1d8, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_239e1d8, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_239e1d8, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_239e1d8, field_48, 0x48);
PKMN_OFFSET_ASSERT(Unk_239e1d8, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_239e1d8, field_68, 0x68);
PKMN_OFFSET_ASSERT(Unk_239e1d8, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_239e1d8, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_239e1d8, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_239e1d8, field_ac, 0xac);

// 0x71006379d0
u8* Unk_239e1d8::vf5() {
    return &field_78;
}

// 0x71006379e0
u8* Unk_239e1d8::vf6() {
    return &field_58;
}

// 0x71006379f0
void Unk_239e1d8::vf7(f32 fvalue) {
    field_8->field_c8 = fvalue;
}

// 0x7100637a00
f32 Unk_239e1d8::vf8() {
    return field_8->field_c8;
}

// 0x7100637a10
void Unk_239e1d8::vf9(f32 fvalue) {
    field_8->field_cc = fvalue;
}

// 0x7100637a20
f32 Unk_239e1d8::vf10() {
    return field_8->field_cc;
}

// 0x7100637a30
void Unk_239e1d8::vf11(f32 fvalue) {
    field_8->field_d0 = fvalue;
}

// 0x7100637a40
f32 Unk_239e1d8::vf12() {
    return field_8->field_d0;
}

// 0x7100637a60
u8* Unk_239e1d8::vf14() {
    return &field_10;
}

// 0x7100637b50
u8* Unk_239e1d8::vf18() {
    return &field_88;
}

// 0x7100637b80
u8* Unk_239e1d8::vf20() {
    return &field_68;
}

// 0x7100637bd0
u32 Unk_239e1d8::vf23() {
    return (field_a0 >> 2) & 1;
}

// 0x7100637c00
u8* Unk_239e1d8::vf25() {
    return &field_38;
}

// 0x7100637c10
u32 Unk_239e1d8::vf26() {
    return (field_a0 >> 3) & 1;
}

// 0x7100637c20
void Unk_239e1d8::vf27(f32 fvalue) {
    field_ac = fvalue;
}

// 0x7100637c30
f32 Unk_239e1d8::vf28() {
    return field_ac;
}

// 0x7100637c60
u8* Unk_239e1d8::vf30() {
    return &field_28;
}

// 0x7100637ce0
u8* Unk_239e1d8::vf33() {
    return &field_48;
}

class Unk_239e3c0 {
public:
    virtual ~Unk_239e3c0();
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
    u8 _8[0xa8];
    u64 field_b0;
};
PKMN_OFFSET_ASSERT(Unk_239e3c0, field_b0, 0xb0);

// 0x710063a140
void Unk_239e3c0::vf7() {
    Unk_63c770(field_b0);
}

class Unk_239eab0 {
public:
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
};

// 0x710064c010
void Unk_239eab0::vf6() {
    Unk_64c9b0(this);
}

class Unk_239eb30 {
public:
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
};

// 0x710064c1a0
void Unk_239eb30::vf5() {
    Unk_64c9b0(this);
}

class Unk_239eba0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710064c1b0
void Unk_239eba0::vf0() {
    Unk_64c9b0(this);
}

class Unk_239ed38 {
public:
    virtual ~Unk_239ed38();
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
};

// 0x710064d3b0
void Unk_239ed38::vf6() {
    Unk_64d460(this);
}

class Unk_239edb8 {
public:
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
};

// 0x710064d3e0
void Unk_239edb8::vf5() {
    Unk_64d460(this);
}

class Unk_239ee28 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710064d3f0
void Unk_239ee28::vf0() {
    Unk_64d460(this);
}

class Unk_239ee90 {
public:
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
};

// 0x710064d9e0
void Unk_239ee90::vf6() {
    Unk_699410(this);
}

class Unk_239ef10 {
public:
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
};

// 0x710064db70
void Unk_239ef10::vf5() {
    Unk_699410(this);
}

class Unk_239ef80 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710064db80
void Unk_239ef80::vf0() {
    Unk_699410(this);
}

class Unk_239f010 {
public:
    virtual ~Unk_239f010();
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
};

// 0x710064f400
void Unk_239f010::vf6() {
    Unk_64f430(this);
}

class Unk_239f090 {
public:
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
};

// 0x710064f410
void Unk_239f090::vf5() {
    Unk_64f430(this);
}

class Unk_239f100 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710064f420
void Unk_239f100::vf0() {
    Unk_64f430(this);
}

class Unk_239f208 {
public:
    virtual ~Unk_239f208();
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
};

// 0x7100652e40
void Unk_239f208::vf15() {
    Unk_59b970(this);
}

class Unk_239f770 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x710065aa90
void Unk_239f770::vf6() {
    Unk_65b030(this);
}

class Unk_239f7b8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710065abc0
void Unk_239f7b8::vf5() {
    Unk_65b030(this);
}

class Unk_239f7f8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710065abd0
void Unk_239f7f8::vf0() {
    Unk_65b030(this);
}
