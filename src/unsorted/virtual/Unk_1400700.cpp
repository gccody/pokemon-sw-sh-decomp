// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_14028b0(void* self);

class Unk_24373e8_Obj {
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

struct Unk_24373e8_Entry {
    void* field_0;
    Unk_24373e8_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_24373e8_Entry, 0x20);

class Unk_24373e8 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_24373e8_Entry m_entries[10];
};
PKMN_OFFSET_ASSERT(Unk_24373e8, m_entries, 0x8);

// 0x7101400700
u32 Unk_24373e8::vf0() {
    return 0xa;
}

// 0x7101400710
void* Unk_24373e8::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7101400720
void* Unk_24373e8::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7101400730
void Unk_24373e8::vf3(u64 index) {
    if (Unk_24373e8_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_2437578 {
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
};

// 0x7101402700
void Unk_2437578::vf6() {
    Unk_14028b0(this);
}

// 0x7101401dc0
u32 Unk_2437578::vf7() {
    return 1;
}

class Unk_24375e0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71014027d0
void Unk_24375e0::vf5() {
    Unk_14028b0(this);
}

class Unk_2437620 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71014027e0
void Unk_2437620::vf0() {
    Unk_14028b0(this);
}
