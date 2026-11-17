// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23a4218 {
public:
    virtual ~Unk_23a4218();
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
PKMN_OFFSET_ASSERT(Unk_23a4218, field_4f5, 0x4f5);

// 0x71006cd730
u32 Unk_23a4218::vf2() {
    return 0;
}

// 0x71006ccec0
u8 Unk_23a4218::vf22() {
    return field_4f5;
}

class Unk_23a4308 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual u32 vf2();
    virtual void vf3();
    virtual void vf4();
    virtual const char* vf5();
};

// 0x71006cd5f0
u32 Unk_23a4308::vf2() {
    return 1;
}

// 0x71006cd600
const char* Unk_23a4308::vf5() {
    return "WaitMinMember";
}

class Unk_23a4348 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual u32 vf2();
    virtual void vf3();
    virtual void vf4();
    virtual const char* vf5();
};

// 0x71006cd610
u32 Unk_23a4348::vf2() {
    return 0;
}

// 0x71006cd620
const char* Unk_23a4348::vf5() {
    return "InitializeLdn";
}

class Unk_23a4388 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual u32 vf2();
    virtual void vf3();
    virtual void vf4();
    virtual const char* vf5();
};

// 0x71006cd630
u32 Unk_23a4388::vf2() {
    return 0;
}

// 0x71006cd640
const char* Unk_23a4388::vf5() {
    return "FinalizeLdn";
}

class Unk_23a43c8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual u32 vf2();
    virtual void vf3();
    virtual void vf4();
    virtual const char* vf5();
};

// 0x71006cd650
u32 Unk_23a43c8::vf2() {
    return 0;
}

// 0x71006cd660
const char* Unk_23a43c8::vf5() {
    return "SearchSession";
}

class Unk_23a4408 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual const char* vf5();
};

// 0x71006cd670
const char* Unk_23a4408::vf5() {
    return "JoinSession";
}

class Unk_23a4448 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual const char* vf5();
};

// 0x71006cd680
const char* Unk_23a4448::vf5() {
    return "JoinSessionOnRandom";
}

class Unk_23a4488 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual u32 vf2();
    virtual void vf3();
    virtual void vf4();
    virtual const char* vf5();
};

// 0x71006cd690
u32 Unk_23a4488::vf2() {
    return 0;
}

// 0x71006cd6a0
const char* Unk_23a4488::vf5() {
    return "CreateSession";
}

class Unk_23a44c8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual u32 vf2();
    virtual void vf3();
    virtual void vf4();
    virtual const char* vf5();
};

// 0x71006cd6b0
u32 Unk_23a44c8::vf2() {
    return 0;
}

// 0x71006cd6c0
const char* Unk_23a44c8::vf5() {
    return "UpdateSettingSession";
}

class Unk_23a4508 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual u32 vf2();
    virtual void vf3();
    virtual void vf4();
    virtual const char* vf5();
};

// 0x71006cd6d0
u32 Unk_23a4508::vf2() {
    return 1;
}

// 0x71006cd6e0
const char* Unk_23a4508::vf5() {
    return "BranchSequenceOnRandom";
}

class Unk_23a4548 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual u32 vf2();
    virtual void vf3();
    virtual void vf4();
    virtual const char* vf5();
};

// 0x71006cd6f0
u32 Unk_23a4548::vf2() {
    return 1;
}

// 0x71006cd700
const char* Unk_23a4548::vf5() {
    return "CheckBlock";
}

class Unk_23a4588 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual u32 vf2();
    virtual void vf3();
    virtual void vf4();
    virtual const char* vf5();
};

// 0x71006cd710
u32 Unk_23a4588::vf2() {
    return 1;
}

// 0x71006cd720
const char* Unk_23a4588::vf5() {
    return "LocalCloseSession";
}
