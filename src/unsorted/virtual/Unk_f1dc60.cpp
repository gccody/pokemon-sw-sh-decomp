// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_f1f170(void* self);

class Unk_2443000 {
public:
    virtual ~Unk_2443000();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100f1dc60
void Unk_2443000::vf2() {}

// 0x7100f1dc70
void Unk_2443000::vf3() {}

class Unk_23fb870 {
public:
    virtual ~Unk_23fb870();
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

// 0x7100f1efc0
void Unk_23fb870::vf6() {
    Unk_f1f170(this);
}

// 0x7100f1deb0
u32 Unk_23fb870::vf7() {
    return 1;
}

class Unk_23fb8d8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100f1eff0
void Unk_23fb8d8::vf5() {
    Unk_f1f170(this);
}

class Unk_23fb918 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100f1f000
void Unk_23fb918::vf0() {
    Unk_f1f170(this);
}

class Unk_23fb958 {
public:
    virtual ~Unk_23fb958();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x50];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_23fb958, field_58, 0x58);

// 0x7100f1f930
u64 Unk_23fb958::vf3() {
    return field_58;
}

class Unk_23fb998_Obj {
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

struct Unk_23fb998_Entry {
    void* field_0;
    Unk_23fb998_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23fb998_Entry, 0x20);

class Unk_23fb998 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23fb998_Entry m_entries[1];
};
PKMN_OFFSET_ASSERT(Unk_23fb998, m_entries, 0x8);

// 0x7100f1faa0
u32 Unk_23fb998::vf0() {
    return 1;
}

// 0x7100f1fab0
void* Unk_23fb998::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7100f1fac0
void* Unk_23fb998::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7100f1fad0
void Unk_23fb998::vf3(u64 index) {
    if (Unk_23fb998_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}
