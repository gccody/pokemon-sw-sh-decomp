// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_240bfb8 {
public:
    virtual ~Unk_240bfb8();
    virtual void vf2();
    virtual void vf3();
};

// 0x710105c3e0
void Unk_240bfb8::vf2() {}

class Unk_240bfe8 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x710105c460
void Unk_240bfe8::vf0() {}

class Unk_240c5a8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

// 0x710105e1b0
void Unk_240c5a8::vf0() {}

// 0x710105e1d0
void Unk_240c5a8::vf2() {}

// 0x710105e220
void Unk_240c5a8::vf4() {}

class Unk_240c5e0_Obj {
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

struct Unk_240c5e0_Entry {
    void* field_0;
    Unk_240c5e0_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_240c5e0_Entry, 0x20);

class Unk_240c5e0 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_240c5e0_Entry m_entries[1];
};
PKMN_OFFSET_ASSERT(Unk_240c5e0, m_entries, 0x8);

// 0x710105e230
u32 Unk_240c5e0::vf0() {
    return 1;
}

// 0x710105e240
void* Unk_240c5e0::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x710105e250
void* Unk_240c5e0::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x710105e260
void Unk_240c5e0::vf3(u64 index) {
    if (Unk_240c5e0_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_240c610 {
public:
    virtual ~Unk_240c610();
    virtual void vf2();
    virtual void vf3();
    virtual u32 vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x710105e280, 0x710105e290
Unk_240c610::~Unk_240c610() {}

// 0x710105e310
u32 Unk_240c610::vf4() {
    return 0xffff;
}

class Unk_240c658 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x710105e430
void Unk_240c658::vf1() {}

// 0x710105e440
void Unk_240c658::vf2() {}

class Unk_240c688 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x710105e4c0
void Unk_240c688::vf0() {}
