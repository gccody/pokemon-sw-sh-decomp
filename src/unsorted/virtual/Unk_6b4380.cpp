// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Globals other TUs define, named after their addresses.
extern u64 Unk_27fc0a8;

class Unk_23a3108 {
public:
    virtual ~Unk_23a3108();
    virtual u32 vf2();
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
    virtual u8 vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    u8 _8[0x4ed];
    u8 field_4f5;
};
PKMN_OFFSET_ASSERT(Unk_23a3108, field_4f5, 0x4f5);

// 0x71006b6400
u32 Unk_23a3108::vf2() {
    return 3;
}

// 0x71006b4380
u8 Unk_23a3108::vf22() {
    return field_4f5;
}

class Unk_23a32b8 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual u32 vf2();
    virtual void vf3();
    virtual void vf4();
    virtual const char* vf5();
    u8 _8[0x8];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_23a32b8, field_10, 0x10);

// 0x71006b4f60
u32 Unk_23a32b8::vf0() {
    if (Unk_27fc0a8 == 0) {
        return 0;
    }
    field_10 = 0;
    return 1;
}

// 0x71006b6450
u32 Unk_23a32b8::vf2() {
    return 0;
}

// 0x71006b6460
const char* Unk_23a32b8::vf5() {
    return "BrowseJoinSession";
}

class Unk_23a31f8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual const char* vf5();
};

// 0x71006b6410
const char* Unk_23a31f8::vf5() {
    return "RandomSession";
}

class Unk_23a3238 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual u32 vf2();
    virtual void vf3();
    virtual void vf4();
    virtual const char* vf5();
};

// 0x71006b6420
u32 Unk_23a3238::vf2() {
    return 0;
}

// 0x71006b6430
const char* Unk_23a3238::vf5() {
    return "SearchSession";
}

class Unk_23a3278 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual const char* vf5();
};

// 0x71006b6440
const char* Unk_23a3278::vf5() {
    return "JoinSession";
}

class Unk_23a32f8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual u32 vf2();
    virtual void vf3();
    virtual void vf4();
    virtual const char* vf5();
};

// 0x71006b6470
u32 Unk_23a32f8::vf2() {
    return 0;
}

// 0x71006b6480
const char* Unk_23a32f8::vf5() {
    return "CreateSession";
}

class Unk_23a3338 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual u32 vf2();
    virtual void vf3();
    virtual void vf4();
    virtual const char* vf5();
};

// 0x71006b6490
u32 Unk_23a3338::vf2() {
    return 0;
}

// 0x71006b64a0
const char* Unk_23a3338::vf5() {
    return "UpdateSettingSession";
}

class Unk_23a3378 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual u32 vf2();
    virtual void vf3();
    virtual void vf4();
    virtual const char* vf5();
};

// 0x71006b64b0
u32 Unk_23a3378::vf2() {
    return 1;
}

// 0x71006b64c0
const char* Unk_23a3378::vf5() {
    return "CheckBlock";
}
