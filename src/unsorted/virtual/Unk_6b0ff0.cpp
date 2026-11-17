// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_6b1000(void* self);

class Unk_23a2cd8 {
public:
    virtual ~Unk_23a2cd8();
    virtual void vf2() = 0;
    virtual void vf3() = 0;
    virtual void vf4();
    virtual void vf5() = 0;
    virtual void vf6() = 0;
    virtual void vf7() = 0;
    virtual void vf8() = 0;
    virtual void vf9();
    virtual void vf10() = 0;
    virtual void vf11() = 0;
    virtual void vf12() = 0;
    virtual void vf13() = 0;
    virtual void vf14();
    virtual u8 vf15();
    virtual u8 vf16();
    virtual u8 vf17();
    virtual u8 vf18();
    virtual u8 vf19();
    virtual u32 vf20();
    virtual void vf21();
    virtual void vf22() = 0;
    virtual u32 vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26() = 0;
    virtual void vf27() = 0;
    u8 _8[0x4e9];
    u8 field_4f1;
    u8 field_4f2;
    u8 field_4f3;
    u8 field_4f4;
    u8 _4f5[0x1];
    u8 field_4f6;
};
PKMN_OFFSET_ASSERT(Unk_23a2cd8, field_4f1, 0x4f1);
PKMN_OFFSET_ASSERT(Unk_23a2cd8, field_4f2, 0x4f2);
PKMN_OFFSET_ASSERT(Unk_23a2cd8, field_4f3, 0x4f3);
PKMN_OFFSET_ASSERT(Unk_23a2cd8, field_4f4, 0x4f4);
PKMN_OFFSET_ASSERT(Unk_23a2cd8, field_4f6, 0x4f6);

// 0x71006b0ff0
void Unk_23a2cd8::vf14() {
    Unk_6b1000(this);
}

// 0x71006b1480
u8 Unk_23a2cd8::vf15() {
    return field_4f3;
}

// 0x71006b2f70
u8 Unk_23a2cd8::vf16() {
    return field_4f1;
}

// 0x71006b2f80
u8 Unk_23a2cd8::vf17() {
    return field_4f4;
}

// 0x71006b2f90
u8 Unk_23a2cd8::vf18() {
    return field_4f6;
}

// 0x71006b2fa0
u8 Unk_23a2cd8::vf19() {
    return field_4f2;
}

// 0x71006b2fb0
u32 Unk_23a2cd8::vf20() {
    return 0x18;
}

// 0x71006b2fc0
u32 Unk_23a2cd8::vf23() {
    return 1;
}

// 0x71006b2fd0
void Unk_23a2cd8::vf24() {}

class Unk_23a2fc8 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual u32 vf2();
    virtual void vf3();
    virtual void vf4();
    virtual const char* vf5();
};

// 0x71006b21b0
u32 Unk_23a2fc8::vf0() {
    return 1;
}

// 0x71006b3100
u32 Unk_23a2fc8::vf2() {
    return 0;
}

// 0x71006b3110
const char* Unk_23a2fc8::vf5() {
    return "NotifyErrorFunc";
}

class Unk_23a2dc8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual u32 vf2();
    virtual void* vf3();
    virtual void vf4();
    virtual const char* vf5();
};

// 0x71006b2fe0
u32 Unk_23a2dc8::vf2() {
    return 0;
}

// 0x71006b2ff0
void* Unk_23a2dc8::vf3() {
    return nullptr;
}

// 0x71006b3000
const char* Unk_23a2dc8::vf5() {
    return "LeaveSession";
}

class Unk_23a2e08 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual u32 vf2();
    virtual void vf3();
    virtual void vf4();
    virtual const char* vf5();
};

// 0x71006b3010
u32 Unk_23a2e08::vf2() {
    return 0;
}

// 0x71006b3020
const char* Unk_23a2e08::vf5() {
    return "StartSession";
}

class Unk_23a2e48 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual u32 vf2();
    virtual void vf3();
    virtual void vf4();
    virtual const char* vf5();
};

// 0x71006b3030
u32 Unk_23a2e48::vf2() {
    return 0;
}

// 0x71006b3040
const char* Unk_23a2e48::vf5() {
    return "CleanupSession";
}

class Unk_23a2e88 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual u32 vf2();
    virtual void vf3();
    virtual u32 vf4();
    virtual const char* vf5();
};

// 0x71006b3050
u32 Unk_23a2e88::vf2() {
    return 0;
}

// 0x71006b3060
u32 Unk_23a2e88::vf4() {
    return 0;
}

// 0x71006b3070
const char* Unk_23a2e88::vf5() {
    return "CloseSession";
}

class Unk_23a2ec8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual u32 vf2();
    virtual void vf3();
    virtual void vf4();
    virtual const char* vf5();
};

// 0x71006b3080
u32 Unk_23a2ec8::vf2() {
    return 1;
}

// 0x71006b3090
const char* Unk_23a2ec8::vf5() {
    return "ExecSuccess";
}

class Unk_23a2f08 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual u32 vf2();
    virtual void vf3();
    virtual void vf4();
    virtual const char* vf5();
};

// 0x71006b30a0
u32 Unk_23a2f08::vf2() {
    return 1;
}

// 0x71006b30b0
const char* Unk_23a2f08::vf5() {
    return "ExecCancel";
}

class Unk_23a2f48 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual u32 vf2();
    virtual void vf3();
    virtual void vf4();
    virtual const char* vf5();
};

// 0x71006b30c0
u32 Unk_23a2f48::vf2() {
    return 1;
}

// 0x71006b30d0
const char* Unk_23a2f48::vf5() {
    return "ExecTimeout";
}

class Unk_23a2f88 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual u32 vf2();
    virtual void vf3();
    virtual void vf4();
    virtual const char* vf5();
};

// 0x71006b30e0
u32 Unk_23a2f88::vf2() {
    return 1;
}

// 0x71006b30f0
const char* Unk_23a2f88::vf5() {
    return "IndexSelectSession";
}

class Unk_23a3008 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual u32 vf2();
    virtual void vf3();
    virtual void vf4();
    virtual const char* vf5();
};

// 0x71006b3120
u32 Unk_23a3008::vf2() {
    return 1;
}

// 0x71006b3130
const char* Unk_23a3008::vf5() {
    return "WaitMemberConnection";
}

class Unk_23a3048 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual u32 vf2();
    virtual void vf3();
    virtual void vf4();
    virtual const char* vf5();
};

// 0x71006b3140
u32 Unk_23a3048::vf2() {
    return 0;
}

// 0x71006b3150
const char* Unk_23a3048::vf5() {
    return "CancelJoinRandomSession";
}

class Unk_23a3088 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual u32 vf2();
    virtual void vf3();
    virtual void vf4();
    virtual const char* vf5();
};

// 0x71006b3160
u32 Unk_23a3088::vf2() {
    return 0;
}

// 0x71006b3170
const char* Unk_23a3088::vf5() {
    return "CancelJoinSession";
}

class Unk_23a30c8 {
public:
    virtual u32 vf0();
    virtual u32 vf1();
    virtual u32 vf2();
    virtual void vf3();
    virtual void vf4();
    virtual const char* vf5();
};

// 0x71006b3180
u32 Unk_23a30c8::vf0() {
    return 1;
}

// 0x71006b3190
u32 Unk_23a30c8::vf1() {
    return 1;
}

// 0x71006b31a0
u32 Unk_23a30c8::vf2() {
    return 0;
}

// 0x71006b31b0
const char* Unk_23a30c8::vf5() {
    return "NullFunc";
}
