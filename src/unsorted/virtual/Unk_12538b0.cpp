// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_2426e88 {
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
    u8 _8[0x60];
    u32 field_68;
};
PKMN_OFFSET_ASSERT(Unk_2426e88, field_68, 0x68);

// 0x71012538b0
u32 Unk_2426e88::vf7() {
    return 1;
}

// 0x71012538c0
void Unk_2426e88::vf8() {
    field_68 = 0;
}

class Unk_2426f58 {
public:
    virtual ~Unk_2426f58();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x50];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_2426f58, field_58, 0x58);

// 0x71012545d0
u64 Unk_2426f58::vf3() {
    return field_58;
}

class Unk_2426f98_Obj {
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

struct Unk_2426f98_Entry {
    void* field_0;
    Unk_2426f98_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_2426f98_Entry, 0x20);

class Unk_2426f98 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_2426f98_Entry m_entries[1];
};
PKMN_OFFSET_ASSERT(Unk_2426f98, m_entries, 0x8);

// 0x7101254740
u32 Unk_2426f98::vf0() {
    return 1;
}

// 0x7101254750
void* Unk_2426f98::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7101254760
void* Unk_2426f98::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7101254770
void Unk_2426f98::vf3(u64 index) {
    if (Unk_2426f98_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}
