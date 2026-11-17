// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_242d1e8 {
public:
    virtual ~Unk_242d1e8();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x90];
    u64 field_98;
};
PKMN_OFFSET_ASSERT(Unk_242d1e8, field_98, 0x98);

// 0x71012cdc10
u64 Unk_242d1e8::vf3() {
    return field_98;
}

class Unk_242d228_Obj {
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

struct Unk_242d228_Entry {
    void* field_0;
    Unk_242d228_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_242d228_Entry, 0x20);

class Unk_242d228 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_242d228_Entry m_entries[3];
};
PKMN_OFFSET_ASSERT(Unk_242d228, m_entries, 0x8);

// 0x71012cdda0
u32 Unk_242d228::vf0() {
    return 3;
}

// 0x71012cddb0
void* Unk_242d228::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x71012cddc0
void* Unk_242d228::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x71012cddd0
void Unk_242d228::vf3(u64 index) {
    if (Unk_242d228_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}
