// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_1520be0(void* self);
void Unk_1527c70(void* self);
void Unk_1529770(void* self);
void Unk_152a320(void* self);
void Unk_152a880(void* self);
void Unk_152b010(void* self);
void Unk_152b540(void* self);
void Unk_152ee70(void* self);
void Unk_1530300(void* self);
void Unk_1532a80(void* self);
void Unk_1533550(void* self);
void Unk_1533b10(void* self);
void Unk_1534be0(void* self);
void Unk_15354a0(void* self);
void Unk_15359a0(void* self);
void Unk_1536960(void* self);
void Unk_15392f0(void* self);
void Unk_153ad80(void* self);

class Unk_2447af8 {
public:
    virtual ~Unk_2447af8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7101520b70
void Unk_2447af8::vf6() {
    Unk_1520be0(this);
}

class Unk_2447b40 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101520ba0
void Unk_2447b40::vf5() {
    Unk_1520be0(this);
}

class Unk_2447b80 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101520bb0
void Unk_2447b80::vf0() {
    Unk_1520be0(this);
}

class Unk_2447cf0 {
public:
    virtual ~Unk_2447cf0();
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

// 0x7101527c00
void Unk_2447cf0::vf6() {
    Unk_1527c70(this);
}

// 0x7101523aa0
void Unk_2447cf0::vf10() {}

class Unk_2447d88 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101527c30
void Unk_2447d88::vf5() {
    Unk_1527c70(this);
}

class Unk_2447dc8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101527c40
void Unk_2447dc8::vf0() {
    Unk_1527c70(this);
}

class Unk_2447e50 {
public:
    virtual ~Unk_2447e50();
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

// 0x7101529700
void Unk_2447e50::vf6() {
    Unk_1529770(this);
}

class Unk_2447ee8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101529730
void Unk_2447ee8::vf5() {
    Unk_1529770(this);
}

class Unk_2447f28 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101529740
void Unk_2447f28::vf0() {
    Unk_1529770(this);
}

class Unk_2447f50 {
public:
    virtual ~Unk_2447f50();
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

// 0x710152a2b0
void Unk_2447f50::vf6() {
    Unk_152a320(this);
}

// 0x710152a130
void Unk_2447f50::vf9() {}

class Unk_2447fb8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710152a2e0
void Unk_2447fb8::vf5() {
    Unk_152a320(this);
}

class Unk_2447ff8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710152a2f0
void Unk_2447ff8::vf0() {
    Unk_152a320(this);
}

class Unk_2448020 {
public:
    virtual ~Unk_2448020();
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
    virtual u32 vf16();
};

// 0x710152a810
void Unk_2448020::vf6() {
    Unk_152a880(this);
}

// 0x710152a6b0
void Unk_2448020::vf8() {}

// 0x710152a6c0
void Unk_2448020::vf10() {}

// 0x710152a6d0
u32 Unk_2448020::vf16() {
    return 0;
}

class Unk_24480b8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710152a840
void Unk_24480b8::vf5() {
    Unk_152a880(this);
}

class Unk_24480f8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710152a850
void Unk_24480f8::vf0() {
    Unk_152a880(this);
}

class Unk_2448120 {
public:
    virtual ~Unk_2448120();
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

// 0x710152afa0
void Unk_2448120::vf6() {
    Unk_152b010(this);
}

// 0x710152af80
void Unk_2448120::vf9() {}

class Unk_2448188 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710152afd0
void Unk_2448188::vf5() {
    Unk_152b010(this);
}

class Unk_24481c8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710152afe0
void Unk_24481c8::vf0() {
    Unk_152b010(this);
}

class Unk_24481f0 {
public:
    virtual ~Unk_24481f0();
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

// 0x710152b4d0
void Unk_24481f0::vf6() {
    Unk_152b540(this);
}

// 0x710152b4b0
void Unk_24481f0::vf9() {}

class Unk_2448258 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710152b500
void Unk_2448258::vf5() {
    Unk_152b540(this);
}

class Unk_2448298 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710152b510
void Unk_2448298::vf0() {
    Unk_152b540(this);
}

class Unk_24482c0 {
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

// 0x710152ecc0
void Unk_24482c0::vf6() {
    Unk_152ee70(this);
}

// 0x710152bf60
void Unk_24482c0::vf10() {}

class Unk_2448358 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710152ed90
void Unk_2448358::vf5() {
    Unk_152ee70(this);
}

class Unk_2448398 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710152eda0
void Unk_2448398::vf0() {
    Unk_152ee70(this);
}

class Unk_24483f0 {
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
    virtual u32 vf10();
    u8 _8[0xe0];
    u32 field_e8;
};
PKMN_OFFSET_ASSERT(Unk_24483f0, field_e8, 0xe8);

// 0x710152f6c0
u32 Unk_24483f0::vf10() {
    return field_e8;
}

class Unk_24484c0 {
public:
    virtual ~Unk_24484c0();
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

// 0x7101530290
void Unk_24484c0::vf6() {
    Unk_1530300(this);
}

// 0x7101530270
void Unk_24484c0::vf9() {}

class Unk_2448528 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71015302c0
void Unk_2448528::vf5() {
    Unk_1530300(this);
}

class Unk_2448568 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71015302d0
void Unk_2448568::vf0() {
    Unk_1530300(this);
}

class Unk_2448660 {
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

// 0x7101532890
void Unk_2448660::vf6() {
    Unk_1532a80(this);
}

// 0x7101531390
void Unk_2448660::vf10() {}

class Unk_24486f8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101532980
void Unk_24486f8::vf5() {
    Unk_1532a80(this);
}

class Unk_2448738 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101532990
void Unk_2448738::vf0() {
    Unk_1532a80(this);
}

class Unk_2448878 {
public:
    virtual ~Unk_2448878();
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

// 0x71015334e0
void Unk_2448878::vf6() {
    Unk_1533550(this);
}

// 0x71015334c0
void Unk_2448878::vf9() {}

class Unk_24488e0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101533510
void Unk_24488e0::vf5() {
    Unk_1533550(this);
}

class Unk_2448920 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101533520
void Unk_2448920::vf0() {
    Unk_1533550(this);
}

class Unk_2448948 {
public:
    virtual ~Unk_2448948();
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

// 0x7101533aa0
void Unk_2448948::vf6() {
    Unk_1533b10(this);
}

// 0x7101533a80
void Unk_2448948::vf9() {}

class Unk_24489b0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101533ad0
void Unk_24489b0::vf5() {
    Unk_1533b10(this);
}

class Unk_24489f0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101533ae0
void Unk_24489f0::vf0() {
    Unk_1533b10(this);
}

class Unk_2448bb8 {
public:
    virtual ~Unk_2448bb8();
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

// 0x7101534b70
void Unk_2448bb8::vf6() {
    Unk_1534be0(this);
}

// 0x7101534b50
void Unk_2448bb8::vf9() {}

class Unk_2448c20 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101534ba0
void Unk_2448c20::vf5() {
    Unk_1534be0(this);
}

class Unk_2448c60 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101534bb0
void Unk_2448c60::vf0() {
    Unk_1534be0(this);
}

class Unk_2448c88 {
public:
    virtual ~Unk_2448c88();
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

// 0x7101535430
void Unk_2448c88::vf6() {
    Unk_15354a0(this);
}

// 0x7101535410
void Unk_2448c88::vf9() {}

class Unk_2448cf0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101535460
void Unk_2448cf0::vf5() {
    Unk_15354a0(this);
}

class Unk_2448d30 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101535470
void Unk_2448d30::vf0() {
    Unk_15354a0(this);
}

class Unk_2448d58 {
public:
    virtual ~Unk_2448d58();
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

// 0x7101535930
void Unk_2448d58::vf6() {
    Unk_15359a0(this);
}

// 0x7101535910
void Unk_2448d58::vf9() {}

class Unk_2448dc0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101535960
void Unk_2448dc0::vf5() {
    Unk_15359a0(this);
}

class Unk_2448e00 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101535970
void Unk_2448e00::vf0() {
    Unk_15359a0(this);
}

class Unk_2448e28 {
public:
    virtual ~Unk_2448e28();
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

// 0x71015368f0
void Unk_2448e28::vf6() {
    Unk_1536960(this);
}

// 0x71015368d0
void Unk_2448e28::vf9() {}

class Unk_2448e90 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101536920
void Unk_2448e90::vf5() {
    Unk_1536960(this);
}

class Unk_2448ed0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101536930
void Unk_2448ed0::vf0() {
    Unk_1536960(this);
}

class Unk_2449180 {
public:
    virtual ~Unk_2449180();
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

// 0x7101539280
void Unk_2449180::vf6() {
    Unk_15392f0(this);
}

class Unk_24491e8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71015392b0
void Unk_24491e8::vf5() {
    Unk_15392f0(this);
}

class Unk_2449228 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71015392c0
void Unk_2449228::vf0() {
    Unk_15392f0(this);
}

class Unk_2449338 {
public:
    virtual ~Unk_2449338();
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

// 0x710153ad50
void Unk_2449338::vf6() {
    Unk_153ad80(this);
}

// 0x7101539eb0
u32 Unk_2449338::vf7() {
    return 1;
}

class Unk_24493a0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710153ad60
void Unk_24493a0::vf5() {
    Unk_153ad80(this);
}

class Unk_24493e0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710153ad70
void Unk_24493e0::vf0() {
    Unk_153ad80(this);
}

class Unk_2449408 {
public:
    virtual ~Unk_2449408();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0xd0];
    u64 field_d8;
};
PKMN_OFFSET_ASSERT(Unk_2449408, field_d8, 0xd8);

// 0x710153b630
u64 Unk_2449408::vf3() {
    return field_d8;
}

class Unk_2449448 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x710153b7c0
u32 Unk_2449448::vf0() {
    return 5;
}
