// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_12ba950(void* self);
void Unk_12be010(void* self);
void Unk_12c2ef0(void* self);

class Unk_242c630 {
public:
    virtual ~Unk_242c630();
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
    virtual u32 vf25();
};

// 0x71012b9fb0
void Unk_242c630::vf22() {}

// 0x71012b9fc0
u32 Unk_242c630::vf25() {
    return 1;
}

class Unk_242c778 {
public:
    virtual ~Unk_242c778();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x70];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_242c778, field_78, 0x78);

// 0x71012ba570
u64 Unk_242c778::vf3() {
    return field_78;
}

class Unk_242c7b8_Obj {
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

struct Unk_242c7b8_Entry {
    void* field_0;
    Unk_242c7b8_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_242c7b8_Entry, 0x20);

class Unk_242c7b8 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_242c7b8_Entry m_entries[2];
};
PKMN_OFFSET_ASSERT(Unk_242c7b8, m_entries, 0x8);

// 0x71012ba700
u32 Unk_242c7b8::vf0() {
    return 2;
}

// 0x71012ba710
void* Unk_242c7b8::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x71012ba720
void* Unk_242c7b8::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x71012ba730
void Unk_242c7b8::vf3(u64 index) {
    if (Unk_242c7b8_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_242c858 {
public:
    virtual ~Unk_242c858();
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

// 0x71012bdf10
void Unk_242c858::vf6() {
    Unk_12be010(this);
}

class Unk_242c8f0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71012bdfd0
void Unk_242c8f0::vf5() {
    Unk_12be010(this);
}

class Unk_242c930 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71012bdfe0
void Unk_242c930::vf0() {
    Unk_12be010(this);
}

class Unk_242c9a0 {
public:
    virtual ~Unk_242c9a0();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x71012bef30
void Unk_242c9a0::vf6() {
    Unk_12ba950(this);
}

class Unk_242c9e8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71012bef60
void Unk_242c9e8::vf5() {
    Unk_12ba950(this);
}

class Unk_242ca28 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71012bef70
void Unk_242ca28::vf0() {
    Unk_12ba950(this);
}

class Unk_242cae8 {
public:
    virtual ~Unk_242cae8();
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

// 0x71012c2e80
void Unk_242cae8::vf6() {
    Unk_12c2ef0(this);
}

class Unk_242cb80 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71012c2eb0
void Unk_242cb80::vf5() {
    Unk_12c2ef0(this);
}

class Unk_242cbc0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71012c2ec0
void Unk_242cbc0::vf0() {
    Unk_12c2ef0(this);
}
