// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_242f710 {
public:
    virtual ~Unk_242f710();
    virtual void vf2();
    virtual void vf3();
};

// 0x710130f630
void Unk_242f710::vf2() {}

class Unk_242f740 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x710130f6b0
void Unk_242f740::vf0() {}

class Unk_242f760_Obj {
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

struct Unk_242f760_Entry {
    void* field_0;
    Unk_242f760_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_242f760_Entry, 0x20);

class Unk_242f760 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_242f760_Entry m_entries[2];
};
PKMN_OFFSET_ASSERT(Unk_242f760, m_entries, 0x8);

// 0x710130f730
u32 Unk_242f760::vf0() {
    return 2;
}

// 0x710130f740
void* Unk_242f760::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x710130f750
void* Unk_242f760::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x710130f760
void Unk_242f760::vf3(u64 index) {
    if (Unk_242f760_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_242f978 {
public:
    virtual ~Unk_242f978();
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

// 0x710131a3d0
void Unk_242f978::vf22() {}

class Unk_242fac0 {
public:
    virtual ~Unk_242fac0();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x50];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_242fac0, field_58, 0x58);

// 0x710131b190
u64 Unk_242fac0::vf3() {
    return field_58;
}

class Unk_242fb00_Obj {
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

struct Unk_242fb00_Entry {
    void* field_0;
    Unk_242fb00_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_242fb00_Entry, 0x20);

class Unk_242fb00 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_242fb00_Entry m_entries[1];
};
PKMN_OFFSET_ASSERT(Unk_242fb00, m_entries, 0x8);

// 0x710131b300
u32 Unk_242fb00::vf0() {
    return 1;
}

// 0x710131b310
void* Unk_242fb00::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x710131b320
void* Unk_242fb00::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x710131b330
void Unk_242fb00::vf3(u64 index) {
    if (Unk_242fb00_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_242fb30 {
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

// 0x710131d2e0
void Unk_242fb30::vf10() {}

class Unk_242fc60 {
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
PKMN_OFFSET_ASSERT(Unk_242fc60, field_e8, 0xe8);

// 0x710131fef0
u32 Unk_242fc60::vf10() {
    return field_e8;
}
