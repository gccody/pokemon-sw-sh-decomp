// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_ba5440(void* self);
void Unk_bb4d40(void* self);

class Unk_23d3130 {
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
};

// 0x7100ba7a20
void Unk_23d3130::vf6() {
    Unk_ba5440(this);
}

// 0x7100ba7a30
void Unk_23d3130::vf17() {}

// 0x7100ba7a40
void Unk_23d3130::vf18() {}

class Unk_23d31d8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100ba7b30
void Unk_23d31d8::vf5() {
    Unk_ba5440(this);
}

class Unk_23d3218 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100ba7b40
void Unk_23d3218::vf0() {
    Unk_ba5440(this);
}

class Unk_23d3240 {
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
    virtual void vf17();
    virtual void vf18();
};

// 0x7100bab600
u32 Unk_23d3240::vf16() {
    return 0;
}

class Unk_23d3368 {
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
    virtual void vf17();
    virtual void vf18();
};

// 0x7100bad500
void Unk_23d3368::vf10() {}

// 0x7100bad6f0
u32 Unk_23d3368::vf16() {
    return 0;
}

class Unk_23d3560 {
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
};

// 0x7100bb40f0
void Unk_23d3560::vf13() {}

class Unk_23d36c8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
};

// 0x7100bb4100
void Unk_23d36c8::vf0() {}

// 0x7100bb4ce0
void Unk_23d36c8::vf2() {}

// 0x7100bb4cf0
void Unk_23d36c8::vf3() {}

// 0x7100bb4d00
void Unk_23d36c8::vf4() {}

// 0x7100bb4d10
void Unk_23d36c8::vf5() {}

// 0x7100bb4d20
void Unk_23d36c8::vf6() {}

// 0x7100bb4d30
void Unk_23d36c8::vf7() {}

class Unk_23d3e88 {
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

// 0x7100bb46f0
void Unk_23d3e88::vf6() {
    Unk_bb4d40(this);
}

class Unk_23d3600 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100bb48e0
void Unk_23d3600::vf5() {
    Unk_bb4d40(this);
}

class Unk_23d3640 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100bb48f0
void Unk_23d3640::vf0() {
    Unk_bb4d40(this);
}

class Unk_23d3b40 {
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
};

// 0x7100bb7b40
void Unk_23d3b40::vf8() {}
