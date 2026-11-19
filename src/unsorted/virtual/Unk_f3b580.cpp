// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23fd518 {
public:
    virtual ~Unk_23fd518();
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

// 0x7100f3b580
u32 Unk_23fd518::vf7() {
    return 1;
}

class Unk_23fd5e8 {
public:
    virtual ~Unk_23fd5e8();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0xb0];
    u64 field_b8;
};
PKMN_OFFSET_ASSERT(Unk_23fd5e8, field_b8, 0xb8);

// 0x7100f3d480
u64 Unk_23fd5e8::vf3() {
    return field_b8;
}

class Unk_23fd628_Obj {
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

struct Unk_23fd628_Entry {
    void* field_0;
    Unk_23fd628_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23fd628_Entry, 0x20);

class Unk_23fd628 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23fd628_Entry m_entries[4];
};
PKMN_OFFSET_ASSERT(Unk_23fd628, m_entries, 0x8);

// 0x7100f3d610
u32 Unk_23fd628::vf0() {
    return 4;
}

// 0x7100f3d620
void* Unk_23fd628::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7100f3d630
void* Unk_23fd628::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7100f3d640
void Unk_23fd628::vf3(u64 index) {
    if (Unk_23fd628_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}
