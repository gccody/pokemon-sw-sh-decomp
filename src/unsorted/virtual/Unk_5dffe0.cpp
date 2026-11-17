// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_239a0f8_Obj {
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

struct Unk_239a0f8_Entry {
    void* field_0;
    Unk_239a0f8_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_239a0f8_Entry, 0x20);

class Unk_239a0f8 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_239a0f8_Entry m_entries[2];
};
PKMN_OFFSET_ASSERT(Unk_239a0f8, m_entries, 0x8);

// 0x71005dffe0
u32 Unk_239a0f8::vf0() {
    return 2;
}

// 0x71005dfff0
void* Unk_239a0f8::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x71005e0000
void* Unk_239a0f8::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x71005e0010
void Unk_239a0f8::vf3(u64 index) {
    if (Unk_239a0f8_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_239a128 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual u32 vf3();
};

// 0x71005e0070
u32 Unk_239a128::vf3() {
    return 2;
}

class Unk_239a158 {
public:
    virtual ~Unk_239a158();
    virtual void vf2();
    virtual void vf3();
};

// 0x71005e0610
void Unk_239a158::vf2() {}

class Unk_239a188 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x71005e0690
void Unk_239a188::vf0() {}

class Unk_239a1a8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71005e08f0
void Unk_239a1a8::vf2() {}

class Unk_239a1d8 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x71005e0970
void Unk_239a1d8::vf0() {}

class Unk_239a4c0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

// 0x71005e3630
void Unk_239a4c0::vf1() {}

class Unk_239a4f8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71005e3690
void Unk_239a4f8::vf0() {}

// 0x71005e36a0
void Unk_239a4f8::vf1() {}
