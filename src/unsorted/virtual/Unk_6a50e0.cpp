// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_15b6e10(void* self);

class Unk_23a25e0 {
public:
    virtual ~Unk_23a25e0();
    virtual void vf2();
    virtual void vf3();
};

// 0x71006a50e0
void Unk_23a25e0::vf2() {}

class Unk_23a2610 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x71006a5160
void Unk_23a2610::vf0() {}

class Unk_23a2650_Obj {
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

struct Unk_23a2650_Entry {
    void* field_0;
    Unk_23a2650_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23a2650_Entry, 0x20);

class Unk_23a2650 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23a2650_Entry m_entries[1];
};
PKMN_OFFSET_ASSERT(Unk_23a2650, m_entries, 0x8);

// 0x71006a5650
u32 Unk_23a2650::vf0() {
    return 1;
}

// 0x71006a5660
void* Unk_23a2650::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x71006a5670
void* Unk_23a2650::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x71006a5680
void Unk_23a2650::vf3(u64 index) {
    if (Unk_23a2650_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_23a2680 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71006a56a0
void Unk_23a2680::vf1() {
    Unk_15b6e10(this);
}
