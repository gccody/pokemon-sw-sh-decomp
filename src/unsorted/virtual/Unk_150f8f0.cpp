// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_150fd80(void* self);

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_1063fe0(u64);

// Globals other TUs define, named after their addresses.
extern u64 Unk_24ba5b8;

class Unk_2447078 {
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

// 0x710150fd50
void Unk_2447078::vf6() {
    Unk_150fd80(this);
}

// 0x710150f8f0
u32 Unk_2447078::vf7() {
    return 1;
}

// 0x710150f900
void Unk_2447078::vf8() {
    Unk_1063fe0(Unk_24ba5b8);
}

// 0x710150f910
void Unk_2447078::vf10() {}

class Unk_24470e0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710150fd60
void Unk_24470e0::vf5() {
    Unk_150fd80(this);
}

class Unk_2447120 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710150fd70
void Unk_2447120::vf0() {
    Unk_150fd80(this);
}

class Unk_2447148 {
public:
    virtual ~Unk_2447148();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x50];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_2447148, field_58, 0x58);

// 0x71015103b0
u64 Unk_2447148::vf3() {
    return field_58;
}

class Unk_2447188_Obj {
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

struct Unk_2447188_Entry {
    void* field_0;
    Unk_2447188_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_2447188_Entry, 0x20);

class Unk_2447188 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_2447188_Entry m_entries[1];
};
PKMN_OFFSET_ASSERT(Unk_2447188, m_entries, 0x8);

// 0x7101510520
u32 Unk_2447188::vf0() {
    return 1;
}

// 0x7101510530
void* Unk_2447188::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7101510540
void* Unk_2447188::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7101510550
void Unk_2447188::vf3(u64 index) {
    if (Unk_2447188_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}
