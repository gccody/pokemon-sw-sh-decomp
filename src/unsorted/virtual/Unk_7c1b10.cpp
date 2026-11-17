// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23aa3c8 {
public:
    virtual ~Unk_23aa3c8();
    virtual void vf2();
    virtual void vf3();
};

// 0x71007c1b10
void Unk_23aa3c8::vf2() {}

class Unk_23aa3f8 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x71007c1b90
void Unk_23aa3f8::vf0() {}

class Unk_23aa418_Obj {
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

struct Unk_23aa418_Entry {
    void* field_0;
    Unk_23aa418_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23aa418_Entry, 0x20);

class Unk_23aa418 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23aa418_Entry m_entries[2];
};
PKMN_OFFSET_ASSERT(Unk_23aa418, m_entries, 0x8);

// 0x71007c1c10
u32 Unk_23aa418::vf0() {
    return 2;
}

// 0x71007c1c20
void* Unk_23aa418::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x71007c1c30
void* Unk_23aa418::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x71007c1c40
void Unk_23aa418::vf3(u64 index) {
    if (Unk_23aa418_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_23aa448 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual bool vf5(u32 value);
};

// 0x71007c2270
bool Unk_23aa448::vf5(u32 value) {
    return value == 0xe5;
}

class Unk_23aa4b8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71007c2ad0
void Unk_23aa4b8::vf0() {}

// 0x71007c2ae0
void Unk_23aa4b8::vf1() {}

// 0x71007c2c00
void Unk_23aa4b8::vf2() {}

class Unk_23aa4e8 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x71007c2c80
void Unk_23aa4e8::vf0() {}
