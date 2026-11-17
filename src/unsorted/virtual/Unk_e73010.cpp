// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_e74200(void* self);
void Unk_e75330(void* self);
void Unk_e75f40(void* self);

class Unk_23f3840 {
public:
    virtual ~Unk_23f3840();
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

// 0x7100e73010
u32 Unk_23f3840::vf16() {
    return 1;
}

class Unk_23f3940 {
public:
    virtual ~Unk_23f3940();
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

// 0x7100e731c0
u32 Unk_23f3940::vf16() {
    return 2;
}

class Unk_23f3a40 {
public:
    virtual ~Unk_23f3a40();
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

// 0x7100e73370
u32 Unk_23f3a40::vf16() {
    return 3;
}

class Unk_23f3b40 {
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

// 0x7100e741d0
void Unk_23f3b40::vf6() {
    Unk_e74200(this);
}

// 0x7100e73dc0
u32 Unk_23f3b40::vf7() {
    return 1;
}

// 0x7100e73dd0
void Unk_23f3b40::vf8() {}

// 0x7100e73de0
void Unk_23f3b40::vf10() {}

class Unk_23f3ba8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100e741e0
void Unk_23f3ba8::vf5() {
    Unk_e74200(this);
}

class Unk_23f3be8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100e741f0
void Unk_23f3be8::vf0() {
    Unk_e74200(this);
}

class Unk_23f3cc0 {
public:
    virtual ~Unk_23f3cc0();
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

// 0x7100e747a0
u32 Unk_23f3cc0::vf20() {
    return 1;
}

// 0x7100e747b0
void Unk_23f3cc0::vf21() {}

// 0x7100e747c0
void Unk_23f3cc0::vf22() {}

// 0x7100e747d0
u32 Unk_23f3cc0::vf25() {
    return 1;
}

class Unk_23f3c10 {
public:
    virtual ~Unk_23f3c10();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100e74ce0
void Unk_23f3c10::vf6() {
    Unk_e75330(this);
}

class Unk_23f3c58 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100e74d10
void Unk_23f3c58::vf5() {
    Unk_e75330(this);
}

class Unk_23f3c98 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100e74d20
void Unk_23f3c98::vf0() {
    Unk_e75330(this);
}

class Unk_23f3e08 {
public:
    virtual ~Unk_23f3e08();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x50];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_23f3e08, field_58, 0x58);

// 0x7100e74fa0
u64 Unk_23f3e08::vf3() {
    return field_58;
}

class Unk_23f3e48_Obj {
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
    virtual void vf16(u64 value);
};

struct Unk_23f3e48_Entry {
    void* field_0;
    Unk_23f3e48_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23f3e48_Entry, 0x20);

class Unk_23f3e48 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23f3e48_Entry m_entries[1];
};
PKMN_OFFSET_ASSERT(Unk_23f3e48, m_entries, 0x8);

// 0x7100e75110
u32 Unk_23f3e48::vf0() {
    return 1;
}

// 0x7100e75120
void* Unk_23f3e48::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7100e75130
void* Unk_23f3e48::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7100e75140
void Unk_23f3e48::vf3(u64 index) {
    if (Unk_23f3e48_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_23f3f48 {
public:
    virtual ~Unk_23f3f48();
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

// 0x7100e76480
void Unk_23f3f48::vf6() {
    Unk_e75f40(this);
}

class Unk_23f3fe0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100e764b0
void Unk_23f3fe0::vf5() {
    Unk_e75f40(this);
}

class Unk_23f4020 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100e764c0
void Unk_23f4020::vf0() {
    Unk_e75f40(this);
}
