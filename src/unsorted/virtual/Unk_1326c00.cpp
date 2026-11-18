// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_24303c0 {
public:
    virtual ~Unk_24303c0();
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
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual u32 vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual u32 vf25();
};

// 0x7101326c00
u32 Unk_24303c0::vf20() {
    return 1;
}

// 0x7101326d40
void Unk_24303c0::vf22() {}

// 0x71013270b0
u32 Unk_24303c0::vf25() {
    return 1;
}

class Unk_2430508 {
public:
    virtual ~Unk_2430508();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x50];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_2430508, field_58, 0x58);

// 0x7101327790
u64 Unk_2430508::vf3() {
    return field_58;
}

class Unk_2430548_Obj {
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

struct Unk_2430548_Entry {
    void* field_0;
    Unk_2430548_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_2430548_Entry, 0x20);

class Unk_2430548 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_2430548_Entry m_entries[1];
};
PKMN_OFFSET_ASSERT(Unk_2430548, m_entries, 0x8);

// 0x7101327900
u32 Unk_2430548::vf0() {
    return 1;
}

// 0x7101327910
void* Unk_2430548::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7101327920
void* Unk_2430548::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7101327930
void Unk_2430548::vf3(u64 index) {
    if (Unk_2430548_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}
