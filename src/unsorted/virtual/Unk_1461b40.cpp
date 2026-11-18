// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_243d538 {
public:
    virtual ~Unk_243d538();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0xb0];
    u64 field_b8;
};
PKMN_OFFSET_ASSERT(Unk_243d538, field_b8, 0xb8);

// 0x7101461b40
u64 Unk_243d538::vf3() {
    return field_b8;
}

class Unk_243d578_Obj {
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

struct Unk_243d578_Entry {
    void* field_0;
    Unk_243d578_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_243d578_Entry, 0x20);

class Unk_243d578 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_243d578_Entry m_entries[4];
};
PKMN_OFFSET_ASSERT(Unk_243d578, m_entries, 0x8);

// 0x7101461cd0
u32 Unk_243d578::vf0() {
    return 4;
}

// 0x7101461ce0
void* Unk_243d578::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7101461cf0
void* Unk_243d578::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7101461d00
void Unk_243d578::vf3(u64 index) {
    if (Unk_243d578_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}
