// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23db0d8 {
public:
    virtual ~Unk_23db0d8();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x70];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_23db0d8, field_78, 0x78);

// 0x7100c3ee80
u64 Unk_23db0d8::vf3() {
    return field_78;
}

class Unk_23db118_Obj {
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

struct Unk_23db118_Entry {
    void* field_0;
    Unk_23db118_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23db118_Entry, 0x20);

class Unk_23db118 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23db118_Entry m_entries[2];
};
PKMN_OFFSET_ASSERT(Unk_23db118, m_entries, 0x8);

// 0x7100c3f010
u32 Unk_23db118::vf0() {
    return 2;
}

// 0x7100c3f020
void* Unk_23db118::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7100c3f030
void* Unk_23db118::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7100c3f040
void Unk_23db118::vf3(u64 index) {
    if (Unk_23db118_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_23db148 {
public:
    virtual ~Unk_23db148();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x70];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_23db148, field_78, 0x78);

// 0x7100c3f7d0
u64 Unk_23db148::vf3() {
    return field_78;
}

class Unk_23db188_Obj {
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

struct Unk_23db188_Entry {
    void* field_0;
    Unk_23db188_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23db188_Entry, 0x20);

class Unk_23db188 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23db188_Entry m_entries[2];
};
PKMN_OFFSET_ASSERT(Unk_23db188, m_entries, 0x8);

// 0x7100c3f960
u32 Unk_23db188::vf0() {
    return 2;
}

// 0x7100c3f970
void* Unk_23db188::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7100c3f980
void* Unk_23db188::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7100c3f990
void Unk_23db188::vf3(u64 index) {
    if (Unk_23db188_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}
