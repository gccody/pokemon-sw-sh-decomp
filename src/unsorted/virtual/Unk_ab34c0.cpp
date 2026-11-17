// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_a8af70(void* self);
void Unk_ab34d0(void* self);
void Unk_ab7560(void* self);

class Unk_23c8530 {
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

// 0x7100ab4330
void Unk_23c8530::vf6() {
    Unk_a8af70(this);
}

// 0x7100ab34c0
void Unk_23c8530::vf8() {
    Unk_ab34d0(this);
}

// 0x7100ab3620
void Unk_23c8530::vf10() {}

class Unk_23c85c8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100ab4400
void Unk_23c85c8::vf5() {
    Unk_a8af70(this);
}

class Unk_23c8608 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100ab4410
void Unk_23c8608::vf0() {
    Unk_a8af70(this);
}

class Unk_23c8660 {
public:
    virtual ~Unk_23c8660();
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

// 0x7100ab7530
void Unk_23c8660::vf6() {
    Unk_ab7560(this);
}

// 0x7100ab4dd0
u32 Unk_23c8660::vf7() {
    return 1;
}

class Unk_23c86c8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100ab7540
void Unk_23c86c8::vf5() {
    Unk_ab7560(this);
}

class Unk_23c8708 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100ab7550
void Unk_23c8708::vf0() {
    Unk_ab7560(this);
}

class Unk_23c8798 {
public:
    virtual ~Unk_23c8798();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x50];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_23c8798, field_58, 0x58);

// 0x7100ab8c20
u64 Unk_23c8798::vf3() {
    return field_58;
}

class Unk_23c87d8_Obj {
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

struct Unk_23c87d8_Entry {
    void* field_0;
    Unk_23c87d8_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23c87d8_Entry, 0x20);

class Unk_23c87d8 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23c87d8_Entry m_entries[1];
};
PKMN_OFFSET_ASSERT(Unk_23c87d8, m_entries, 0x8);

// 0x7100ab8d90
u32 Unk_23c87d8::vf0() {
    return 1;
}

// 0x7100ab8da0
void* Unk_23c87d8::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7100ab8db0
void* Unk_23c87d8::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7100ab8dc0
void Unk_23c87d8::vf3(u64 index) {
    if (Unk_23c87d8_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}
