// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_1323f70(void* self);
void Unk_1324b80(void* self);
void Unk_1325d30(void* self);
void Unk_132ad80(void* self);
void Unk_132ba40(void* self);

class Unk_24300a0 {
public:
    virtual ~Unk_24300a0();
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

// 0x7101323f00
void Unk_24300a0::vf6() {
    Unk_1323f70(this);
}

class Unk_2430108 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101323f30
void Unk_2430108::vf5() {
    Unk_1323f70(this);
}

class Unk_2430148 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101323f40
void Unk_2430148::vf0() {
    Unk_1323f70(this);
}

class Unk_2430170 {
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

// 0x71013249d0
void Unk_2430170::vf6() {
    Unk_1324b80(this);
}

// 0x7101324900
void Unk_2430170::vf9() {}

class Unk_24301d8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101324aa0
void Unk_24301d8::vf5() {
    Unk_1324b80(this);
}

class Unk_2430218 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101324ab0
void Unk_2430218::vf0() {
    Unk_1324b80(this);
}

class Unk_24302f0 {
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

// 0x7101325a80
void Unk_24302f0::vf6() {
    Unk_1325d30(this);
}

// 0x71013253c0
u32 Unk_24302f0::vf7() {
    return 1;
}

// 0x71013255a0
void Unk_24302f0::vf10() {}

class Unk_2430358 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101325bd0
void Unk_2430358::vf5() {
    Unk_1325d30(this);
}

class Unk_2430398 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101325be0
void Unk_2430398::vf0() {
    Unk_1325d30(this);
}

class Unk_24303c0 {
public:
    virtual ~Unk_24303c0();
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

// 0x7101326c00
u32 Unk_24303c0::vf20() {
    return 1;
}

// 0x7101326d40
void Unk_24303c0::vf22() {}

// 0x71013270b0
u32 Unk_24303c0::vf25() {
    return 1;
}

class Unk_2430548 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7101327900
u32 Unk_2430548::vf0() {
    return 1;
}

class Unk_2430628 {
public:
    virtual ~Unk_2430628();
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

// 0x710132ad10
void Unk_2430628::vf6() {
    Unk_132ad80(this);
}

// 0x710132aad0
void Unk_2430628::vf9() {}

class Unk_2430690 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710132ad40
void Unk_2430690::vf5() {
    Unk_132ad80(this);
}

class Unk_24306d0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710132ad50
void Unk_24306d0::vf0() {
    Unk_132ad80(this);
}

class Unk_24306f8 {
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
    virtual u32 vf16();
};

// 0x710132b840
void Unk_24306f8::vf6() {
    Unk_132ba40(this);
}

// 0x710132b690
u32 Unk_24306f8::vf16() {
    return 0;
}

class Unk_2430790 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710132b910
void Unk_2430790::vf5() {
    Unk_132ba40(this);
}

class Unk_24307d0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710132b920
void Unk_24307d0::vf0() {
    Unk_132ba40(this);
}
