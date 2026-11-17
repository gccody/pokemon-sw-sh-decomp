// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_8d0070(void* self);

class Unk_23bb818_Obj {
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

struct Unk_23bb818_Entry {
    void* field_0;
    Unk_23bb818_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23bb818_Entry, 0x20);

class Unk_23bb818 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23bb818_Entry m_entries[12];
};
PKMN_OFFSET_ASSERT(Unk_23bb818, m_entries, 0x8);

// 0x71008cf5c0
u32 Unk_23bb818::vf0() {
    return 0xc;
}

// 0x71008cf5d0
void* Unk_23bb818::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x71008cf5e0
void* Unk_23bb818::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x71008cf5f0
void Unk_23bb818::vf3(u64 index) {
    if (Unk_23bb818_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_23bb848 {
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

// 0x71008d0040
void Unk_23bb848::vf6() {
    Unk_8d0070(this);
}

// 0x71008cfb90
u32 Unk_23bb848::vf7() {
    return 1;
}

// 0x71008cfd00
void Unk_23bb848::vf10() {}

class Unk_23bb8b0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71008d0050
void Unk_23bb8b0::vf5() {
    Unk_8d0070(this);
}

class Unk_23bb8f0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71008d0060
void Unk_23bb8f0::vf0() {
    Unk_8d0070(this);
}

class Unk_23bb918 {
public:
    virtual ~Unk_23bb918();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x50];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_23bb918, field_58, 0x58);

// 0x71008d07d0
u64 Unk_23bb918::vf3() {
    return field_58;
}

class Unk_23bb958_Obj {
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

struct Unk_23bb958_Entry {
    void* field_0;
    Unk_23bb958_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23bb958_Entry, 0x20);

class Unk_23bb958 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23bb958_Entry m_entries[1];
};
PKMN_OFFSET_ASSERT(Unk_23bb958, m_entries, 0x8);

// 0x71008d0940
u32 Unk_23bb958::vf0() {
    return 1;
}

// 0x71008d0950
void* Unk_23bb958::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x71008d0960
void* Unk_23bb958::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x71008d0970
void Unk_23bb958::vf3(u64 index) {
    if (Unk_23bb958_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}
