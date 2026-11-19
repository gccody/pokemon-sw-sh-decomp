// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23f25c8 {
public:
    virtual ~Unk_23f25c8();
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
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
};

// 0x7100e5f920
void Unk_23f25c8::vf22() {}

class Unk_23f27e0 {
public:
    virtual ~Unk_23f27e0();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x90];
    u64 field_98;
};
PKMN_OFFSET_ASSERT(Unk_23f27e0, field_98, 0x98);

// 0x7100e60930
u64 Unk_23f27e0::vf3() {
    return field_98;
}

class Unk_23f2820_Obj {
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

struct Unk_23f2820_Entry {
    void* field_0;
    Unk_23f2820_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23f2820_Entry, 0x20);

class Unk_23f2820 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23f2820_Entry m_entries[3];
};
PKMN_OFFSET_ASSERT(Unk_23f2820, m_entries, 0x8);

// 0x7100e60ac0
u32 Unk_23f2820::vf0() {
    return 3;
}

// 0x7100e60ad0
void* Unk_23f2820::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7100e60ae0
void* Unk_23f2820::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7100e60af0
void Unk_23f2820::vf3(u64 index) {
    if (Unk_23f2820_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}
