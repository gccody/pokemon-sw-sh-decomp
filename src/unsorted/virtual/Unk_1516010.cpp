// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_1516200(void* self);

class Unk_2447498 {
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

// 0x7101516010
void Unk_2447498::vf6() {
    Unk_1516200(this);
}

class Unk_2447530 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101516100
void Unk_2447530::vf5() {
    Unk_1516200(this);
}

class Unk_2447570 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101516110
void Unk_2447570::vf0() {
    Unk_1516200(this);
}

class Unk_2447a88 {
public:
    virtual ~Unk_2447a88();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0xd0];
    u64 field_d8;
};
PKMN_OFFSET_ASSERT(Unk_2447a88, field_d8, 0xd8);

// 0x710151bc50
u64 Unk_2447a88::vf3() {
    return field_d8;
}

class Unk_2447ac8_Obj {
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

struct Unk_2447ac8_Entry {
    void* field_0;
    Unk_2447ac8_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_2447ac8_Entry, 0x20);

class Unk_2447ac8 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_2447ac8_Entry m_entries[5];
};
PKMN_OFFSET_ASSERT(Unk_2447ac8, m_entries, 0x8);

// 0x710151bde0
u32 Unk_2447ac8::vf0() {
    return 5;
}

// 0x710151bdf0
void* Unk_2447ac8::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x710151be00
void* Unk_2447ac8::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x710151be10
void Unk_2447ac8::vf3(u64 index) {
    if (Unk_2447ac8_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}
