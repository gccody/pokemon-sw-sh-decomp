// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_24482c0 {
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
    virtual void vf16();
};

// 0x710152bf60
void Unk_24482c0::vf10() {}

class Unk_24483f0 {
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
    virtual u32 vf10();
    u8 _8[0xe0];
    u32 field_e8;
};
PKMN_OFFSET_ASSERT(Unk_24483f0, field_e8, 0xe8);

// 0x710152f6c0
u32 Unk_24483f0::vf10() {
    return field_e8;
}

class Unk_2449408 {
public:
    virtual ~Unk_2449408();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0xd0];
    u64 field_d8;
};
PKMN_OFFSET_ASSERT(Unk_2449408, field_d8, 0xd8);

// 0x710153b630
u64 Unk_2449408::vf3() {
    return field_d8;
}

class Unk_2449448_Obj {
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

struct Unk_2449448_Entry {
    void* field_0;
    Unk_2449448_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_2449448_Entry, 0x20);

class Unk_2449448 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_2449448_Entry m_entries[5];
};
PKMN_OFFSET_ASSERT(Unk_2449448, m_entries, 0x8);

// 0x710153b7c0
u32 Unk_2449448::vf0() {
    return 5;
}

// 0x710153b7d0
void* Unk_2449448::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x710153b7e0
void* Unk_2449448::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x710153b7f0
void Unk_2449448::vf3(u64 index) {
    if (Unk_2449448_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}
