// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_104ca50(void* self);

class Unk_240b1d8 {
public:
    virtual ~Unk_240b1d8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u32 vf7();
    virtual void vf8();
    virtual u32 vf9();
    virtual void vf10();
};

// 0x710104c920
void Unk_240b1d8::vf6() {
    Unk_104ca50(this);
}

// 0x710104c930
u32 Unk_240b1d8::vf7() {
    return 1;
}

// 0x710104c9d0
u32 Unk_240b1d8::vf9() {
    return 0;
}

// 0x710104c9e0
void Unk_240b1d8::vf10() {}

class Unk_240b240 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710104ca10
void Unk_240b240::vf5() {
    Unk_104ca50(this);
}

class Unk_240b280 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710104ca20
void Unk_240b280::vf0() {
    Unk_104ca50(this);
}

class Unk_240b2a8 {
public:
    virtual ~Unk_240b2a8();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x50];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_240b2a8, field_58, 0x58);

// 0x710104d1c0
u64 Unk_240b2a8::vf3() {
    return field_58;
}

class Unk_240b2e8_Obj {
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

struct Unk_240b2e8_Entry {
    void* field_0;
    Unk_240b2e8_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_240b2e8_Entry, 0x20);

class Unk_240b2e8 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_240b2e8_Entry m_entries[1];
};
PKMN_OFFSET_ASSERT(Unk_240b2e8, m_entries, 0x8);

// 0x710104d330
u32 Unk_240b2e8::vf0() {
    return 1;
}

// 0x710104d340
void* Unk_240b2e8::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x710104d350
void* Unk_240b2e8::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x710104d360
void Unk_240b2e8::vf3(u64 index) {
    if (Unk_240b2e8_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}
