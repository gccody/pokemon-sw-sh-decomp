// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_b3adb0(void* self);
void Unk_b946e0(void* self);
void Unk_ba1390(void* self);
void Unk_ba4690(void* self);

class Unk_23d1de8 {
public:
    virtual ~Unk_23d1de8();
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
    u8 _8[0x138];
    u64 field_140;
};
PKMN_OFFSET_ASSERT(Unk_23d1de8, field_140, 0x140);

// 0x7100b8a630
u64 Unk_23d1de8::vf45() {
    return field_140;
}

class Unk_23d2138 {
public:
    virtual ~Unk_23d2138();
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
};

// 0x7100b94120
void Unk_23d2138::vf6() {
    Unk_b3adb0(this);
}

class Unk_23d22b8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100b94140
void Unk_23d22b8::vf5() {
    Unk_b3adb0(this);
}

class Unk_23d22f8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100b94150
void Unk_23d22f8::vf0() {
    Unk_b3adb0(this);
}

class Unk_23d24b0 {
public:
    virtual ~Unk_23d24b0();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100b99210
void Unk_23d24b0::vf4() {}

class Unk_23d24f8 {
public:
    virtual ~Unk_23d24f8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100b995a0
void Unk_23d24f8::vf4() {}

class Unk_23d2540 {
public:
    virtual ~Unk_23d2540();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100b99930
void Unk_23d2540::vf4() {}

class Unk_23d2588 {
public:
    virtual ~Unk_23d2588();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100b99e00
void Unk_23d2588::vf4() {}

class Unk_23d25d0 {
public:
    virtual ~Unk_23d25d0();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100b9a030
void Unk_23d25d0::vf4() {}

class Unk_23d2618 {
public:
    virtual ~Unk_23d2618();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100b9a260
void Unk_23d2618::vf4() {}

class Unk_23d2660 {
public:
    virtual ~Unk_23d2660();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100b9a340
void Unk_23d2660::vf4() {}

class Unk_23d2970 {
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
};

// 0x7100b9f5f0
void Unk_23d2970::vf6() {
    Unk_b946e0(this);
}

class Unk_23d2af0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100b9f7a0
void Unk_23d2af0::vf5() {
    Unk_b946e0(this);
}

class Unk_23d2b30 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100b9f7b0
void Unk_23d2b30::vf0() {
    Unk_b946e0(this);
}

class Unk_23d2b58 {
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

// 0x7100ba1360
void Unk_23d2b58::vf6() {
    Unk_ba1390(this);
}

// 0x7100ba0a70
u32 Unk_23d2b58::vf7() {
    return 1;
}

// 0x7100ba0a80
void Unk_23d2b58::vf8() {}

// 0x7100ba0a90
void Unk_23d2b58::vf10() {}

class Unk_23d2bc0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100ba1370
void Unk_23d2bc0::vf5() {
    Unk_ba1390(this);
}

class Unk_23d2c00 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100ba1380
void Unk_23d2c00::vf0() {
    Unk_ba1390(this);
}

class Unk_23d2d88 {
public:
    virtual ~Unk_23d2d88();
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

// 0x7100ba3630
void Unk_23d2d88::vf22() {}

class Unk_23d2ee8 {
public:
    virtual ~Unk_23d2ee8();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x50];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_23d2ee8, field_58, 0x58);

// 0x7100ba4030
u64 Unk_23d2ee8::vf3() {
    return field_58;
}

class Unk_23d2f28 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100ba41a0
u32 Unk_23d2f28::vf0() {
    return 1;
}

class Unk_23d2f58 {
public:
    virtual ~Unk_23d2f58();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100ba4620
void Unk_23d2f58::vf6() {
    Unk_ba4690(this);
}

class Unk_23d2fa0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100ba4650
void Unk_23d2fa0::vf5() {
    Unk_ba4690(this);
}

class Unk_23d2fe0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100ba4660
void Unk_23d2fe0::vf0() {
    Unk_ba4690(this);
}
