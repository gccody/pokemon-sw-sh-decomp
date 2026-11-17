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
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
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
    u8 _8[0xa0];
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

class Unk_239de08 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual u8* vf5();
    virtual u8* vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
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
    u8 _8[0x28];
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

class Unk_239ded0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual u8* vf5();
    virtual u8* vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
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
    u8 _8[0x20];
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

class Unk_239dfe0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual u8* vf5();
    virtual u8* vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
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
    u8 _8[0x18];
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

class Unk_239e0c0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual u8* vf5();
    virtual u8* vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
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
    u8 _8[0x10];
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

class Unk_239e1d8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual u8* vf5();
    virtual u8* vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
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
    u8 _8[0x8];
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
