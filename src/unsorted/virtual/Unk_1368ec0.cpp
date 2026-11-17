// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_2432458 {
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
    virtual u8* vf11();
    virtual u32 vf12();
    virtual void vf13();
    u8 _8[0x58];
    u8 field_60;
};
PKMN_OFFSET_ASSERT(Unk_2432458, field_60, 0x60);

// 0x7101368ec0
u8* Unk_2432458::vf11() {
    return &field_60;
}

// 0x7101368ed0
u32 Unk_2432458::vf12() {
    return 0x12f8;
}

class Unk_2432d90_Obj {
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

struct Unk_2432d90_Entry {
    void* field_0;
    Unk_2432d90_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_2432d90_Entry, 0x20);

class Unk_2432d90 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_2432d90_Entry m_entries[2];
};
PKMN_OFFSET_ASSERT(Unk_2432d90, m_entries, 0x8);

// 0x7101380310
u32 Unk_2432d90::vf0() {
    return 2;
}

// 0x7101380320
void* Unk_2432d90::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7101380330
void* Unk_2432d90::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7101380340
void Unk_2432d90::vf3(u64 index) {
    if (Unk_2432d90_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}
