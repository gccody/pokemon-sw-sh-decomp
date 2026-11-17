// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_f019e0(void* self);
void Unk_f04310(void* self);
void Unk_f045c0(void* self);
void Unk_f048f0(void* self);
void Unk_f04b30(void* self);
void Unk_f04f10(void* self);
void Unk_f054e0(void* self);
void Unk_f05610(void* self);
void Unk_f06430(void* self);
void Unk_f08690(void* self);
void Unk_f08cc0(void* self);
void Unk_f09800(void* self);
void Unk_f09930(void* self);
void Unk_f0a9a0(void* self);
void Unk_f0b8d0(void* self);
void Unk_f0e420(void* self);
void Unk_f0eeb0(void* self);
void Unk_f14070(void* self);
void Unk_f16300(void* self);

class Unk_23f9c00 {
public:
    virtual ~Unk_23f9c00();
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
    virtual u32 vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
};

// 0x7100f00600
u32 Unk_23f9c00::vf20() {
    return 1;
}

// 0x7100f00610
void Unk_23f9c00::vf21() {}

// 0x7100f00620
void Unk_23f9c00::vf22() {}

class Unk_23f9b50 {
public:
    virtual ~Unk_23f9b50();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100f01860
void Unk_23f9b50::vf6() {
    Unk_f019e0(this);
}

class Unk_23f9b98 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100f01890
void Unk_23f9b98::vf5() {
    Unk_f019e0(this);
}

class Unk_23f9bd8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100f018a0
void Unk_23f9bd8::vf0() {
    Unk_f019e0(this);
}

class Unk_23f9d90 {
public:
    virtual ~Unk_23f9d90();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual u32 vf8();
    virtual void vf9();
    virtual void vf10();
};

// 0x7100f042a0
void Unk_23f9d90::vf6() {
    Unk_f04310(this);
}

// 0x7100f04270
u32 Unk_23f9d90::vf8() {
    return 1;
}

// 0x7100f04280
void Unk_23f9d90::vf9() {}

class Unk_23f9df8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100f042d0
void Unk_23f9df8::vf5() {
    Unk_f04310(this);
}

class Unk_23f9e38 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100f042e0
void Unk_23f9e38::vf0() {
    Unk_f04310(this);
}

class Unk_23f9e60 {
public:
    virtual ~Unk_23f9e60();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
};

// 0x7100f04550
void Unk_23f9e60::vf6() {
    Unk_f045c0(this);
}

// 0x7100f04530
void Unk_23f9e60::vf9() {}

class Unk_23f9ec8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100f04580
void Unk_23f9ec8::vf5() {
    Unk_f045c0(this);
}

class Unk_23f9f08 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100f04590
void Unk_23f9f08::vf0() {
    Unk_f045c0(this);
}

class Unk_23f9f30 {
public:
    virtual ~Unk_23f9f30();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
};

// 0x7100f04880
void Unk_23f9f30::vf6() {
    Unk_f048f0(this);
}

// 0x7100f04860
void Unk_23f9f30::vf9() {}

class Unk_23f9f98 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100f048b0
void Unk_23f9f98::vf5() {
    Unk_f048f0(this);
}

class Unk_23f9fd8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100f048c0
void Unk_23f9fd8::vf0() {
    Unk_f048f0(this);
}

class Unk_23fa000 {
public:
    virtual ~Unk_23fa000();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
};

// 0x7100f04ea0
void Unk_23fa000::vf6() {
    Unk_f04f10(this);
}

// 0x7100f04e80
void Unk_23fa000::vf9() {}

class Unk_23fa068 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100f04ed0
void Unk_23fa068::vf5() {
    Unk_f04f10(this);
}

class Unk_23fa0a8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100f04ee0
void Unk_23fa0a8::vf0() {
    Unk_f04f10(this);
}

class Unk_23fa0d0 {
public:
    virtual ~Unk_23fa0d0();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
};

// 0x7100f05470
void Unk_23fa0d0::vf6() {
    Unk_f054e0(this);
}

// 0x7100f05450
void Unk_23fa0d0::vf9() {}

class Unk_23fa138 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100f054a0
void Unk_23fa138::vf5() {
    Unk_f054e0(this);
}

class Unk_23fa178 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100f054b0
void Unk_23fa178::vf0() {
    Unk_f054e0(this);
}

class Unk_23fa1a0 {
public:
    virtual ~Unk_23fa1a0();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
};

// 0x7100f05910
void Unk_23fa1a0::vf9() {}

class Unk_23fa270 {
public:
    virtual ~Unk_23fa270();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
};

// 0x7100f05ae0
void Unk_23fa270::vf9() {}

class Unk_23fa340 {
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
};

// 0x7100f06240
void Unk_23fa340::vf6() {
    Unk_f06430(this);
}

// 0x7100f05f60
void Unk_23fa340::vf9() {}

class Unk_23fa3a8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100f06330
void Unk_23fa3a8::vf5() {
    Unk_f06430(this);
}

class Unk_23fa3e8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100f06340
void Unk_23fa3e8::vf0() {
    Unk_f06430(this);
}

class Unk_23fa490 {
public:
    virtual ~Unk_23fa490();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100f080e0
void Unk_23fa490::vf4() {}

class Unk_23fa4d8 {
public:
    virtual ~Unk_23fa4d8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100f08210
void Unk_23fa4d8::vf4() {}

class Unk_23fa520 {
public:
    virtual ~Unk_23fa520();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
};

// 0x7100f083a0
void Unk_23fa520::vf9() {}

class Unk_23fa5f0 {
public:
    virtual ~Unk_23fa5f0();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
};

// 0x7100f08620
void Unk_23fa5f0::vf6() {
    Unk_f08690(this);
}

// 0x7100f08600
void Unk_23fa5f0::vf9() {}

class Unk_23fa658 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100f08650
void Unk_23fa658::vf5() {
    Unk_f08690(this);
}

class Unk_23fa698 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100f08660
void Unk_23fa698::vf0() {
    Unk_f08690(this);
}

class Unk_23fa6c0 {
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
};

// 0x7100f08b10
void Unk_23fa6c0::vf6() {
    Unk_f08cc0(this);
}

class Unk_23fa728 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100f08be0
void Unk_23fa728::vf5() {
    Unk_f08cc0(this);
}

class Unk_23fa768 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100f08bf0
void Unk_23fa768::vf0() {
    Unk_f08cc0(this);
}

class Unk_23fa790 {
public:
    virtual ~Unk_23fa790();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
};

// 0x7100f09040
void Unk_23fa790::vf9() {}

class Unk_23fa860 {
public:
    virtual ~Unk_23fa860();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
};

// 0x7100f092a0
void Unk_23fa860::vf9() {}

class Unk_23fa930 {
public:
    virtual ~Unk_23fa930();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
};

// 0x7100f09790
void Unk_23fa930::vf6() {
    Unk_f09800(this);
}

// 0x7100f09770
void Unk_23fa930::vf9() {}

class Unk_23fa998 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100f097c0
void Unk_23fa998::vf5() {
    Unk_f09800(this);
}

class Unk_23fa9d8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100f097d0
void Unk_23fa9d8::vf0() {
    Unk_f09800(this);
}

class Unk_23faa00 {
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
};

// 0x7100f09ef0
void Unk_23faa00::vf9() {}

class Unk_23faad0 {
public:
    virtual ~Unk_23faad0();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual u32 vf8();
    virtual void vf9();
    virtual void vf10();
};

// 0x7100f0a4e0
u32 Unk_23faad0::vf8() {
    return 1;
}

// 0x7100f0a4f0
void Unk_23faad0::vf9() {}

class Unk_23faba0 {
public:
    virtual ~Unk_23faba0();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
};

// 0x7100f0a790
void Unk_23faba0::vf9() {}

class Unk_23fac70 {
public:
    virtual ~Unk_23fac70();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u32 vf7();
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

// 0x7100f0a930
void Unk_23fac70::vf6() {
    Unk_f0a9a0(this);
}

// 0x7100f0a7f0
u32 Unk_23fac70::vf7() {
    return 1;
}

class Unk_23fad08 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100f0a960
void Unk_23fad08::vf5() {
    Unk_f0a9a0(this);
}

class Unk_23fad48 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100f0a970
void Unk_23fad48::vf0() {
    Unk_f0a9a0(this);
}

class Unk_23fad70 {
public:
    virtual ~Unk_23fad70();
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

// 0x7100f0b460
void Unk_23fad70::vf6() {
    Unk_f04b30(this);
}

class Unk_23fae08 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100f0b490
void Unk_23fae08::vf5() {
    Unk_f04b30(this);
}

class Unk_23fae48 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100f0b4a0
void Unk_23fae48::vf0() {
    Unk_f04b30(this);
}

class Unk_23faea0 {
public:
    virtual ~Unk_23faea0();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u32 vf7();
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

// 0x7100f0b860
void Unk_23faea0::vf6() {
    Unk_f0b8d0(this);
}

// 0x7100f0b4d0
u32 Unk_23faea0::vf7() {
    return 1;
}

class Unk_23faf38 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100f0b890
void Unk_23faf38::vf5() {
    Unk_f0b8d0(this);
}

class Unk_23faf78 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100f0b8a0
void Unk_23faf78::vf0() {
    Unk_f0b8d0(this);
}

class Unk_23fafb8 {
public:
    virtual ~Unk_23fafb8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u32 vf7();
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

// 0x7100f0c4e0
void Unk_23fafb8::vf6() {
    Unk_f09930(this);
}

// 0x7100f0ba00
u32 Unk_23fafb8::vf7() {
    return 1;
}

class Unk_23fb050 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100f0c510
void Unk_23fb050::vf5() {
    Unk_f09930(this);
}

class Unk_23fb090 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100f0c520
void Unk_23fb090::vf0() {
    Unk_f09930(this);
}

class Unk_23fb0b8 {
public:
    virtual ~Unk_23fb0b8();
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
    u8 _8[0x5c4];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_23fb0b8, field_5cc, 0x5cc);

// 0x7100f0cbb0
void Unk_23fb0b8::vf6() {
    Unk_f05610(this);
}

// 0x7100f0c810
void Unk_23fb0b8::vf10() {
    field_5cc = 1;
}

class Unk_23fb150 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100f0cbe0
void Unk_23fb150::vf5() {
    Unk_f05610(this);
}

class Unk_23fb190 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100f0cbf0
void Unk_23fb190::vf0() {
    Unk_f05610(this);
}

class Unk_23fb1d0 {
public:
    virtual ~Unk_23fb1d0();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100f0e3b0
void Unk_23fb1d0::vf6() {
    Unk_f0e420(this);
}

class Unk_23fb218 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100f0e3e0
void Unk_23fb218::vf5() {
    Unk_f0e420(this);
}

class Unk_23fb258 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100f0e3f0
void Unk_23fb258::vf0() {
    Unk_f0e420(this);
}

class Unk_23fb3d0 {
public:
    virtual ~Unk_23fb3d0();
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

// 0x7100f11320
void Unk_23fb3d0::vf6() {
    Unk_f0eeb0(this);
}

class Unk_23fb468 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100f11350
void Unk_23fb468::vf5() {
    Unk_f0eeb0(this);
}

class Unk_23fb4a8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100f11360
void Unk_23fb4a8::vf0() {
    Unk_f0eeb0(this);
}

class Unk_23fb650 {
public:
    virtual ~Unk_23fb650();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
};

// 0x7100f14000
void Unk_23fb650::vf6() {
    Unk_f14070(this);
}

// 0x7100f13fe0
void Unk_23fb650::vf9() {}

class Unk_23fb6b8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100f14030
void Unk_23fb6b8::vf5() {
    Unk_f14070(this);
}

class Unk_23fb6f8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100f14040
void Unk_23fb6f8::vf0() {
    Unk_f14070(this);
}

class Unk_23fb720 {
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
};

// 0x7100f160d0
void Unk_23fb720::vf6() {
    Unk_f16300(this);
}

class Unk_23fb788 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100f161e0
void Unk_23fb788::vf5() {
    Unk_f16300(this);
}

class Unk_23fb7c8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100f161f0
void Unk_23fb7c8::vf0() {
    Unk_f16300(this);
}

class Unk_23fb7f0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100f1a850
void Unk_23fb7f0::vf2() {}

class Unk_23fb820 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x7100f1a8d0
void Unk_23fb820::vf0() {}
