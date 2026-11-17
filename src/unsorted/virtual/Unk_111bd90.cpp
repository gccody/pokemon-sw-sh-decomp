// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_2418f90_Obj {
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

struct Unk_2418f90_Entry {
    void* field_0;
    Unk_2418f90_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_2418f90_Entry, 0x20);

class Unk_2418f90 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_2418f90_Entry m_entries[21];
};
PKMN_OFFSET_ASSERT(Unk_2418f90, m_entries, 0x8);

// 0x710111bd90
u32 Unk_2418f90::vf0() {
    return 0x15;
}

// 0x710111bda0
void* Unk_2418f90::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x710111bdb0
void* Unk_2418f90::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x710111bdc0
void Unk_2418f90::vf3(u64 index) {
    if (Unk_2418f90_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_2419160 {
public:
    virtual ~Unk_2419160();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x50];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_2419160, field_58, 0x58);

// 0x71011214f0
u64 Unk_2419160::vf3() {
    return field_58;
}

class Unk_24191a0_Obj {
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

struct Unk_24191a0_Entry {
    void* field_0;
    Unk_24191a0_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_24191a0_Entry, 0x20);

class Unk_24191a0 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_24191a0_Entry m_entries[1];
};
PKMN_OFFSET_ASSERT(Unk_24191a0, m_entries, 0x8);

// 0x7101121660
u32 Unk_24191a0::vf0() {
    return 1;
}

// 0x7101121670
void* Unk_24191a0::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7101121680
void* Unk_24191a0::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7101121690
void Unk_24191a0::vf3(u64 index) {
    if (Unk_24191a0_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_24191d0 {
public:
    virtual ~Unk_24191d0();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x50];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_24191d0, field_58, 0x58);

// 0x7101122160
u64 Unk_24191d0::vf3() {
    return field_58;
}

class Unk_2419210_Obj {
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

struct Unk_2419210_Entry {
    void* field_0;
    Unk_2419210_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_2419210_Entry, 0x20);

class Unk_2419210 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_2419210_Entry m_entries[1];
};
PKMN_OFFSET_ASSERT(Unk_2419210, m_entries, 0x8);

// 0x71011222d0
u32 Unk_2419210::vf0() {
    return 1;
}

// 0x71011222e0
void* Unk_2419210::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x71011222f0
void* Unk_2419210::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7101122300
void Unk_2419210::vf3(u64 index) {
    if (Unk_2419210_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_2419240 {
public:
    virtual ~Unk_2419240();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x50];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_2419240, field_58, 0x58);

// 0x7101122a10
u64 Unk_2419240::vf3() {
    return field_58;
}

class Unk_2419280_Obj {
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

struct Unk_2419280_Entry {
    void* field_0;
    Unk_2419280_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_2419280_Entry, 0x20);

class Unk_2419280 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_2419280_Entry m_entries[1];
};
PKMN_OFFSET_ASSERT(Unk_2419280, m_entries, 0x8);

// 0x7101122b80
u32 Unk_2419280::vf0() {
    return 1;
}

// 0x7101122b90
void* Unk_2419280::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7101122ba0
void* Unk_2419280::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7101122bb0
void Unk_2419280::vf3(u64 index) {
    if (Unk_2419280_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_24192b0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual u32 vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual u32 vf10();
    virtual void vf11();
};

// 0x7101122d20
void Unk_24192b0::vf5() {}

// 0x7101122d30
u32 Unk_24192b0::vf6() {
    return 1;
}

// 0x7101122d40
void Unk_24192b0::vf7() {}

// 0x7101122d50
void Unk_24192b0::vf8() {}

// 0x7101122d60
void Unk_24192b0::vf9() {}

// 0x7101122d70
u32 Unk_24192b0::vf10() {
    return 1;
}

// 0x7101122d80
void Unk_24192b0::vf11() {}
