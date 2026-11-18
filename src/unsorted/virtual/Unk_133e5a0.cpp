// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_2431178 {
public:
    virtual ~Unk_2431178();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x50];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_2431178, field_58, 0x58);

// 0x710133e5a0
u64 Unk_2431178::vf3() {
    return field_58;
}

class Unk_24311b8_Obj {
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

struct Unk_24311b8_Entry {
    void* field_0;
    Unk_24311b8_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_24311b8_Entry, 0x20);

class Unk_24311b8 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_24311b8_Entry m_entries[1];
};
PKMN_OFFSET_ASSERT(Unk_24311b8, m_entries, 0x8);

// 0x710133e710
u32 Unk_24311b8::vf0() {
    return 1;
}

// 0x710133e720
void* Unk_24311b8::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x710133e730
void* Unk_24311b8::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x710133e740
void Unk_24311b8::vf3(u64 index) {
    if (Unk_24311b8_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_2431910 {
public:
    virtual ~Unk_2431910();
    virtual u8* vf2();
    virtual u8* vf3();
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_2431910, field_8, 0x8);

// 0x7101346250, 0x7101346260
Unk_2431910::~Unk_2431910() {}

// 0x7101346270
u8* Unk_2431910::vf2() {
    return &field_8;
}

// 0x7101346280
u8* Unk_2431910::vf3() {
    return &field_8;
}

class Unk_2431940 {
public:
    virtual ~Unk_2431940();
    virtual void vf2();
    virtual void vf3();
    virtual u8* vf4();
    virtual u8* vf5();
    u8 _8[0x8];
    u8 field_10;
};
PKMN_OFFSET_ASSERT(Unk_2431940, field_10, 0x10);

// 0x7101346290, 0x71013462a0
Unk_2431940::~Unk_2431940() {}

// 0x71013466f0
u8* Unk_2431940::vf4() {
    return &field_10;
}

// 0x7101346700
u8* Unk_2431940::vf5() {
    return &field_10;
}

class Unk_2431980 {
public:
    virtual void vf0();
    virtual u32 vf1();
    virtual void vf2();
    u8 _8[0x8];
    u32 field_10;
    u32 field_14;
};
PKMN_OFFSET_ASSERT(Unk_2431980, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_2431980, field_14, 0x14);

// 0x7101346710
void Unk_2431980::vf0() {
    field_14 = field_10;
}

// 0x7101346720
u32 Unk_2431980::vf1() {
    return field_14;
}

class Unk_24319a8 {
public:
    virtual ~Unk_24319a8();
    virtual void vf2();
    virtual void vf3();
    virtual u64 vf4();
    virtual void vf5();
    virtual void vf6();
    u8 _8[0x8];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_24319a8, field_10, 0x10);

// 0x7101346750, 0x7101346760
Unk_24319a8::~Unk_24319a8() {}

// 0x7101346800
u64 Unk_24319a8::vf4() {
    return field_10;
}

class Unk_24319f0 {
public:
    virtual ~Unk_24319f0();
    virtual u8* vf2();
    virtual u8* vf3();
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_24319f0, field_8, 0x8);

// 0x7101347ab0, 0x7101347ac0
Unk_24319f0::~Unk_24319f0() {}

// 0x7101347ad0
u8* Unk_24319f0::vf2() {
    return &field_8;
}

// 0x7101347ae0
u8* Unk_24319f0::vf3() {
    return &field_8;
}
