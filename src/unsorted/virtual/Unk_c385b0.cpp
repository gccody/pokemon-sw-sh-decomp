// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23dabf8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

// 0x7100c385b0
void Unk_23dabf8::vf1() {}

class Unk_23dac30 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100c385c0
void Unk_23dac30::vf0() {}

// 0x7100c385d0
void Unk_23dac30::vf1() {}

class Unk_23dac60 {
public:
    virtual ~Unk_23dac60();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x50];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_23dac60, field_58, 0x58);

// 0x7100c38e50
u64 Unk_23dac60::vf3() {
    return field_58;
}

class Unk_23dace0_Obj {
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

struct Unk_23dace0_Entry {
    void* field_0;
    Unk_23dace0_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23dace0_Entry, 0x20);

class Unk_23dace0 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23dace0_Entry m_entries[1];
};
PKMN_OFFSET_ASSERT(Unk_23dace0, m_entries, 0x8);

// 0x7100c38ff0
u32 Unk_23dace0::vf0() {
    return 1;
}

// 0x7100c39000
void* Unk_23dace0::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7100c39010
void* Unk_23dace0::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7100c39020
void Unk_23dace0::vf3(u64 index) {
    if (Unk_23dace0_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_23dad10_Obj {
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

struct Unk_23dad10_Entry {
    void* field_0;
    Unk_23dad10_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23dad10_Entry, 0x20);

class Unk_23dad10 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23dad10_Entry m_entries[1];
};
PKMN_OFFSET_ASSERT(Unk_23dad10, m_entries, 0x8);

// 0x7100c39120
u32 Unk_23dad10::vf0() {
    return 1;
}

// 0x7100c39130
void* Unk_23dad10::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7100c39140
void* Unk_23dad10::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7100c39150
void Unk_23dad10::vf3(u64 index) {
    if (Unk_23dad10_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_23dad40 {
public:
    virtual ~Unk_23dad40();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x50];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_23dad40, field_58, 0x58);

// 0x7100c397b0
u64 Unk_23dad40::vf3() {
    return field_58;
}

class Unk_23dad80_Obj {
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

struct Unk_23dad80_Entry {
    void* field_0;
    Unk_23dad80_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23dad80_Entry, 0x20);

class Unk_23dad80 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23dad80_Entry m_entries[1];
};
PKMN_OFFSET_ASSERT(Unk_23dad80, m_entries, 0x8);

// 0x7100c39920
u32 Unk_23dad80::vf0() {
    return 1;
}

// 0x7100c39930
void* Unk_23dad80::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7100c39940
void* Unk_23dad80::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7100c39950
void Unk_23dad80::vf3(u64 index) {
    if (Unk_23dad80_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_23dadb0 {
public:
    virtual ~Unk_23dadb0();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x50];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_23dadb0, field_58, 0x58);

// 0x7100c3a510
u64 Unk_23dadb0::vf3() {
    return field_58;
}

class Unk_23dadf0_Obj {
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

struct Unk_23dadf0_Entry {
    void* field_0;
    Unk_23dadf0_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23dadf0_Entry, 0x20);

class Unk_23dadf0 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23dadf0_Entry m_entries[1];
};
PKMN_OFFSET_ASSERT(Unk_23dadf0, m_entries, 0x8);

// 0x7100c3a680
u32 Unk_23dadf0::vf0() {
    return 1;
}

// 0x7100c3a690
void* Unk_23dadf0::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7100c3a6a0
void* Unk_23dadf0::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7100c3a6b0
void Unk_23dadf0::vf3(u64 index) {
    if (Unk_23dadf0_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}
