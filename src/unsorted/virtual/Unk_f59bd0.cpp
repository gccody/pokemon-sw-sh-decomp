// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23feb78_Obj {
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

struct Unk_23feb78_Entry {
    void* field_0;
    Unk_23feb78_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23feb78_Entry, 0x20);

class Unk_23feb78 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23feb78_Entry m_entries[1];
};
PKMN_OFFSET_ASSERT(Unk_23feb78, m_entries, 0x8);

// 0x7100f59bd0
u32 Unk_23feb78::vf0() {
    return 1;
}

// 0x7100f59be0
void* Unk_23feb78::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7100f59bf0
void* Unk_23feb78::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7100f59c00
void Unk_23feb78::vf3(u64 index) {
    if (Unk_23feb78_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_23feba8 {
public:
    virtual ~Unk_23feba8();
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

// 0x7100f5a9f0
u32 Unk_23feba8::vf7() {
    return 1;
}
