// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_eb57c0(void* self);
void Unk_eb6100(void* self);
void Unk_eb7ce0(void* self);
void Unk_ebb700(void* self);
void Unk_ec3210(void* self);
void Unk_ec65c0(void* self);
void Unk_ec71b0(void* self);

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_eb5330(void*, u32);

class Unk_23d9830 {
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
};

// 0x7100eb5320
void Unk_23d9830::vf12() {
    Unk_eb5330(this, 0);
}

class Unk_23f5ec8 {
public:
    virtual ~Unk_23f5ec8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7() = 0;
    virtual void vf8() = 0;
    virtual void vf9() = 0;
    virtual void vf10() = 0;
    virtual void vf11() = 0;
    virtual void vf12();
};

// 0x7100eb5790
void Unk_23f5ec8::vf6() {
    Unk_eb57c0(this);
}

class Unk_23f5f40 {
public:
    virtual ~Unk_23f5f40();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100eb57a0
void Unk_23f5f40::vf5() {
    Unk_eb57c0(this);
}

class Unk_23f5f80 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100eb57b0
void Unk_23f5f80::vf0() {
    Unk_eb57c0(this);
}

class Unk_23f5fa8 {
public:
    virtual ~Unk_23f5fa8();
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
    u8 _8[0x5d8];
    u8 field_5e0;
};
PKMN_OFFSET_ASSERT(Unk_23f5fa8, field_5e0, 0x5e0);

// 0x7100eb6090
void Unk_23f5fa8::vf6() {
    Unk_eb6100(this);
}

// 0x7100eb5f60
void Unk_23f5fa8::vf10() {
    field_5e0 = 1;
}

class Unk_23f6040 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100eb60c0
void Unk_23f6040::vf5() {
    Unk_eb6100(this);
}

class Unk_23f6080 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100eb60d0
void Unk_23f6080::vf0() {
    Unk_eb6100(this);
}

class Unk_23f6118 {
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

// 0x7100eb7950
void Unk_23f6118::vf6() {
    Unk_eb7ce0(this);
}

class Unk_23f61b0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100eb7a20
void Unk_23f61b0::vf5() {
    Unk_eb7ce0(this);
}

class Unk_23f61f0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100eb7a30
void Unk_23f61f0::vf0() {
    Unk_eb7ce0(this);
}

class Unk_23bca18 {
public:
    virtual ~Unk_23bca18();
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
    virtual u32 vf18();
};

// 0x7100eb8190
u32 Unk_23bca18::vf18() {
    return 0x2b;
}

struct Unk_23f65d0_6a8 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_23f65d0_6a8, field_58, 0x58);

class Unk_23f65d0 {
public:
    virtual ~Unk_23f65d0();
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
    virtual bool vf17();
    u8 _8[0x6a0];
    Unk_23f65d0_6a8* field_6a8;
};
PKMN_OFFSET_ASSERT(Unk_23f65d0, field_6a8, 0x6a8);

// 0x7100ebca60
void Unk_23f65d0::vf6() {
    Unk_ebb700(this);
}

// 0x7100ebca00
bool Unk_23f65d0::vf17() {
    if (field_6a8 == nullptr) {
        return true;
    }
    return (field_6a8->field_58 & 1) == 0;
}

class Unk_23f6670 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100ebca90
void Unk_23f6670::vf5() {
    Unk_ebb700(this);
}

class Unk_23f66b0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100ebcaa0
void Unk_23f66b0::vf0() {
    Unk_ebb700(this);
}

class Unk_23f67a0 {
public:
    virtual ~Unk_23f67a0();
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
    virtual u32 vf18();
};

// 0x7100ebff40
u32 Unk_23f67a0::vf18() {
    return 0x37;
}

class Unk_23f6a68 {
public:
    virtual ~Unk_23f6a68();
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
    virtual u32 vf18();
};

// 0x7100ec06c0
u32 Unk_23f6a68::vf18() {
    return 0x23;
}

class Unk_23f6c80 {
public:
    virtual ~Unk_23f6c80();
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

// 0x7100ec31a0
void Unk_23f6c80::vf6() {
    Unk_ec3210(this);
}

class Unk_23f6d18 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100ec31d0
void Unk_23f6d18::vf5() {
    Unk_ec3210(this);
}

class Unk_23f6d58 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100ec31e0
void Unk_23f6d58::vf0() {
    Unk_ec3210(this);
}

class Unk_23f6de0 {
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

// 0x7100ec6410
void Unk_23f6de0::vf6() {
    Unk_ec65c0(this);
}

// 0x7100ec6340
void Unk_23f6de0::vf10() {}

class Unk_23f6e78 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100ec64e0
void Unk_23f6e78::vf5() {
    Unk_ec65c0(this);
}

class Unk_23f6eb8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100ec64f0
void Unk_23f6eb8::vf0() {
    Unk_ec65c0(this);
}

class Unk_23f6ee8 {
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

// 0x7100ec6f80
void Unk_23f6ee8::vf6() {
    Unk_ec71b0(this);
}

// 0x7100ec69c0
void Unk_23f6ee8::vf10() {}

class Unk_23f6f80 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100ec7090
void Unk_23f6f80::vf5() {
    Unk_ec71b0(this);
}

class Unk_23f6fc0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100ec70a0
void Unk_23f6fc0::vf0() {
    Unk_ec71b0(this);
}
