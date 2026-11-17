// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_1417f00(void* self);
void Unk_1419ab0(void* self);
void Unk_141c270(void* self);
void Unk_141ea90(void* self);
void Unk_1420e40(void* self);
void Unk_1421c60(void* self);
void Unk_14232c0(void* self);
void Unk_1423c50(void* self);
void Unk_1425a50(void* self);
void Unk_14273a0(void* self);
void Unk_1427960(void* self);
void Unk_1428950(void* self);
void Unk_1428d30(void* self);
void Unk_14294d0(void* self);
void Unk_1429850(void* self);
void Unk_1429f10(void* self);
void Unk_142c700(void* self);

class Unk_2438d30 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u32 vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
};

// 0x7101417ed0
void Unk_2438d30::vf6() {
    Unk_1417f00(this);
}

// 0x7101417c20
u32 Unk_2438d30::vf7() {
    return 1;
}

// 0x7101417c30
void Unk_2438d30::vf8() {}

// 0x7101417c40
void Unk_2438d30::vf10() {}

class Unk_2438d98 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101417ee0
void Unk_2438d98::vf5() {
    Unk_1417f00(this);
}

class Unk_2438dd8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101417ef0
void Unk_2438dd8::vf0() {
    Unk_1417f00(this);
}

class Unk_2438e40 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71014186f0
u32 Unk_2438e40::vf0() {
    return 1;
}

class Unk_2438f20 {
public:
    virtual ~Unk_2438f20();
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
};

// 0x7101419450
void Unk_2438f20::vf22() {}

class Unk_2438e70 {
public:
    virtual ~Unk_2438e70();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7101419a40
void Unk_2438e70::vf6() {
    Unk_1419ab0(this);
}

class Unk_2438eb8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101419a70
void Unk_2438eb8::vf5() {
    Unk_1419ab0(this);
}

class Unk_2438ef8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101419a80
void Unk_2438ef8::vf0() {
    Unk_1419ab0(this);
}

class Unk_2439068 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

// 0x710141a460
void Unk_2439068::vf1() {}

class Unk_24390a0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x710141a470
void Unk_24390a0::vf0() {}

// 0x710141a480
void Unk_24390a0::vf1() {}

class Unk_24390d0 {
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
};

// 0x710141bfc0
void Unk_24390d0::vf6() {
    Unk_141c270(this);
}

class Unk_2439168 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710141c110
void Unk_2439168::vf5() {
    Unk_141c270(this);
}

class Unk_24391a8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710141c120
void Unk_24391a8::vf0() {
    Unk_141c270(this);
}

class Unk_2439200 {
public:
    virtual ~Unk_2439200();
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

// 0x710141ea20
void Unk_2439200::vf6() {
    Unk_141ea90(this);
}

class Unk_2439298 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710141ea50
void Unk_2439298::vf5() {
    Unk_141ea90(this);
}

class Unk_24392d8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710141ea60
void Unk_24392d8::vf0() {
    Unk_141ea90(this);
}

class Unk_2439318 {
public:
    virtual ~Unk_2439318();
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

// 0x7101420dd0
void Unk_2439318::vf6() {
    Unk_1420e40(this);
}

// 0x7101420c30
void Unk_2439318::vf9() {}

class Unk_2439380 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101420e00
void Unk_2439380::vf5() {
    Unk_1420e40(this);
}

class Unk_24393c0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101420e10
void Unk_24393c0::vf0() {
    Unk_1420e40(this);
}

class Unk_2439468 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u32 vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
};

// 0x7101421c30
void Unk_2439468::vf6() {
    Unk_1421c60(this);
}

// 0x7101421970
u32 Unk_2439468::vf7() {
    return 1;
}

// 0x7101421980
void Unk_2439468::vf8() {}

// 0x7101421990
void Unk_2439468::vf10() {}

class Unk_24394d0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101421c40
void Unk_24394d0::vf5() {
    Unk_1421c60(this);
}

class Unk_2439510 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101421c50
void Unk_2439510::vf0() {
    Unk_1421c60(this);
}

class Unk_2439538 {
public:
    virtual ~Unk_2439538();
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
    virtual u32 vf25();
};

// 0x71014220d0
u32 Unk_2439538::vf20() {
    return 1;
}

// 0x71014220e0
void Unk_2439538::vf21() {}

// 0x71014220f0
void Unk_2439538::vf22() {}

// 0x71014221e0
u32 Unk_2439538::vf25() {
    return 1;
}

class Unk_24396c0 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71014229b0
u32 Unk_24396c0::vf0() {
    return 1;
}

class Unk_24396f0 {
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

// 0x7101423110
void Unk_24396f0::vf6() {
    Unk_14232c0(this);
}

// 0x7101423040
void Unk_24396f0::vf9() {}

class Unk_2439758 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71014231e0
void Unk_2439758::vf5() {
    Unk_14232c0(this);
}

class Unk_2439798 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71014231f0
void Unk_2439798::vf0() {
    Unk_14232c0(this);
}

class Unk_24397c0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u32 vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
};

// 0x7101423c20
void Unk_24397c0::vf6() {
    Unk_1423c50(this);
}

// 0x71014239f0
u32 Unk_24397c0::vf7() {
    return 1;
}

class Unk_2439828 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101423c30
void Unk_2439828::vf5() {
    Unk_1423c50(this);
}

class Unk_2439868 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101423c40
void Unk_2439868::vf0() {
    Unk_1423c50(this);
}

class Unk_24398d0 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7101424410
u32 Unk_24398d0::vf0() {
    return 1;
}

class Unk_24399b0 {
public:
    virtual ~Unk_24399b0();
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
};

// 0x7101424f50
void Unk_24399b0::vf21() {}

// 0x7101424f60
void Unk_24399b0::vf22() {}

class Unk_2439900 {
public:
    virtual ~Unk_2439900();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7101425990
void Unk_2439900::vf6() {
    Unk_1425a50(this);
}

class Unk_2439948 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71014259c0
void Unk_2439948::vf5() {
    Unk_1425a50(this);
}

class Unk_2439988 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71014259d0
void Unk_2439988::vf0() {
    Unk_1425a50(this);
}

class Unk_2439b28 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7101425a00
u32 Unk_2439b28::vf0() {
    return 1;
}

class Unk_2439b60 {
public:
    virtual ~Unk_2439b60();
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

// 0x7101427330
void Unk_2439b60::vf6() {
    Unk_14273a0(this);
}

class Unk_2439bf8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101427360
void Unk_2439bf8::vf5() {
    Unk_14273a0(this);
}

class Unk_2439c38 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101427370
void Unk_2439c38::vf0() {
    Unk_14273a0(this);
}

class Unk_2439c60 {
public:
    virtual ~Unk_2439c60();
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

// 0x71014278f0
void Unk_2439c60::vf6() {
    Unk_1427960(this);
}

class Unk_2439cf8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101427920
void Unk_2439cf8::vf5() {
    Unk_1427960(this);
}

class Unk_2439d38 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101427930
void Unk_2439d38::vf0() {
    Unk_1427960(this);
}

class Unk_2439d60 {
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
};

// 0x7101428760
void Unk_2439d60::vf6() {
    Unk_1428950(this);
}

class Unk_2439df8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101428850
void Unk_2439df8::vf5() {
    Unk_1428950(this);
}

class Unk_2439e38 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101428860
void Unk_2439e38::vf0() {
    Unk_1428950(this);
}

class Unk_2439e60 {
public:
    virtual ~Unk_2439e60();
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

// 0x7101428cc0
void Unk_2439e60::vf6() {
    Unk_1428d30(this);
}

// 0x7101428ca0
void Unk_2439e60::vf9() {}

class Unk_2439ec8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101428cf0
void Unk_2439ec8::vf5() {
    Unk_1428d30(this);
}

class Unk_2439f08 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101428d00
void Unk_2439f08::vf0() {
    Unk_1428d30(this);
}

class Unk_2439f30 {
public:
    virtual ~Unk_2439f30();
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

// 0x7101429460
void Unk_2439f30::vf6() {
    Unk_14294d0(this);
}

class Unk_2439f98 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101429490
void Unk_2439f98::vf5() {
    Unk_14294d0(this);
}

class Unk_2439fd8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71014294a0
void Unk_2439fd8::vf0() {
    Unk_14294d0(this);
}

class Unk_243a000 {
public:
    virtual ~Unk_243a000();
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

// 0x71014297e0
void Unk_243a000::vf6() {
    Unk_1429850(this);
}

// 0x71014297c0
void Unk_243a000::vf9() {}

class Unk_243a068 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101429810
void Unk_243a068::vf5() {
    Unk_1429850(this);
}

class Unk_243a0a8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101429820
void Unk_243a0a8::vf0() {
    Unk_1429850(this);
}

class Unk_243a0d0 {
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

// 0x7101429d60
void Unk_243a0d0::vf6() {
    Unk_1429f10(this);
}

// 0x7101429c90
void Unk_243a0d0::vf9() {}

class Unk_243a138 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101429e30
void Unk_243a138::vf5() {
    Unk_1429f10(this);
}

class Unk_243a178 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101429e40
void Unk_243a178::vf0() {
    Unk_1429f10(this);
}

class Unk_243a308 {
public:
    virtual ~Unk_243a308();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u32 vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
};

// 0x710142c6d0
void Unk_243a308::vf6() {
    Unk_142c700(this);
}

// 0x710142bd00
u32 Unk_243a308::vf7() {
    return 1;
}

// 0x710142bd10
void Unk_243a308::vf8() {}

// 0x710142bd20
void Unk_243a308::vf10() {}

class Unk_243a370 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710142c6e0
void Unk_243a370::vf5() {
    Unk_142c700(this);
}

class Unk_243a3b0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710142c6f0
void Unk_243a3b0::vf0() {
    Unk_142c700(this);
}

class Unk_243a3d8 {
public:
    virtual ~Unk_243a3d8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual u32 vf5();
    virtual u32 vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
};

// 0x710142ca00
u32 Unk_243a3d8::vf5() {
    return 0;
}

// 0x710142ca10
u32 Unk_243a3d8::vf6() {
    return 0;
}

class Unk_243a440 {
public:
    virtual ~Unk_243a440();
    virtual void vf2() = 0;
    virtual void vf3() = 0;
    virtual void vf4() = 0;
    virtual void vf5() = 0;
    virtual void vf6() = 0;
    virtual u32 vf7();
    virtual void vf8() = 0;
    virtual void vf9() = 0;
    virtual u32 vf10();
};

// 0x710142cc40
u32 Unk_243a440::vf7() {
    return 1;
}

// 0x710142cc50
u32 Unk_243a440::vf10() {
    return 0;
}
