// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_e94c10(void* self);

class Unk_23f49e8_Obj {
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

struct Unk_23f49e8_Entry {
    void* field_0;
    Unk_23f49e8_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23f49e8_Entry, 0x20);

class Unk_23f49e8 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23f49e8_Entry m_entries[2];
};
PKMN_OFFSET_ASSERT(Unk_23f49e8, m_entries, 0x8);

// 0x7100e92a30
u32 Unk_23f49e8::vf0() {
    return 2;
}

// 0x7100e92a40
void* Unk_23f49e8::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7100e92a50
void* Unk_23f49e8::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7100e92a60
void Unk_23f49e8::vf3(u64 index) {
    if (Unk_23f49e8_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_23f4a18 {
public:
    virtual ~Unk_23f4a18();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100e92fb0
void Unk_23f4a18::vf2() {}

class Unk_23f4a48 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x7100e93030
void Unk_23f4a48::vf0() {}

class Unk_23f4a68 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100e93580
void Unk_23f4a68::vf2() {}

class Unk_23f4a98 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x7100e93600
void Unk_23f4a98::vf0() {}

class Unk_23f4ad8_Obj {
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

struct Unk_23f4ad8_Entry {
    void* field_0;
    Unk_23f4ad8_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23f4ad8_Entry, 0x20);

class Unk_23f4ad8 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23f4ad8_Entry m_entries[7];
};
PKMN_OFFSET_ASSERT(Unk_23f4ad8, m_entries, 0x8);

// 0x7100e93bc0
u32 Unk_23f4ad8::vf0() {
    return 7;
}

// 0x7100e93bd0
void* Unk_23f4ad8::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7100e93be0
void* Unk_23f4ad8::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7100e93bf0
void Unk_23f4ad8::vf3(u64 index) {
    if (Unk_23f4ad8_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_23f4b28_Obj {
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

struct Unk_23f4b28_Entry {
    void* field_0;
    Unk_23f4b28_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23f4b28_Entry, 0x20);

class Unk_23f4b28 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23f4b28_Entry m_entries[6];
};
PKMN_OFFSET_ASSERT(Unk_23f4b28, m_entries, 0x8);

// 0x7100e94930
u32 Unk_23f4b28::vf0() {
    return 6;
}

// 0x7100e94940
void* Unk_23f4b28::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7100e94950
void* Unk_23f4b28::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7100e94960
void Unk_23f4b28::vf3(u64 index) {
    if (Unk_23f4b28_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_23f4b58 {
public:
    virtual ~Unk_23f4b58();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
};

// 0x7100e94b90
void Unk_23f4b58::vf6() {
    Unk_e94c10(this);
}

class Unk_23f4ba8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100e94bd0
void Unk_23f4ba8::vf5() {
    Unk_e94c10(this);
}

class Unk_23f4be8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100e94be0
void Unk_23f4be8::vf0() {
    Unk_e94c10(this);
}

struct Unk_23f4d20_18 {
    u8 _0[0x170];
    u8 field_170;
};
PKMN_OFFSET_ASSERT(Unk_23f4d20_18, field_170, 0x170);

class Unk_23f4d20 {
public:
    virtual ~Unk_23f4d20();
    virtual bool vf2();
    virtual void vf3();
    u8 _8[0x10];
    Unk_23f4d20_18* field_18;
};
PKMN_OFFSET_ASSERT(Unk_23f4d20, field_18, 0x18);

// 0x7100e9ab10
bool Unk_23f4d20::vf2() {
    if (field_18 == nullptr) {
        return false;
    }
    return field_18->field_170 != 0;
}

struct Unk_23f4d50_18 {
    u8 _0[0x170];
    u8 field_170;
};
PKMN_OFFSET_ASSERT(Unk_23f4d50_18, field_170, 0x170);

class Unk_23f4d50 {
public:
    virtual ~Unk_23f4d50();
    virtual bool vf2();
    virtual void vf3();
    u8 _8[0x10];
    Unk_23f4d50_18* field_18;
};
PKMN_OFFSET_ASSERT(Unk_23f4d50, field_18, 0x18);

// 0x7100e9b0b0
bool Unk_23f4d50::vf2() {
    if (field_18 == nullptr) {
        return false;
    }
    return field_18->field_170 != 0;
}

struct Unk_23f4d80_18 {
    u8 _0[0x170];
    u8 field_170;
};
PKMN_OFFSET_ASSERT(Unk_23f4d80_18, field_170, 0x170);

class Unk_23f4d80 {
public:
    virtual ~Unk_23f4d80();
    virtual bool vf2();
    virtual void vf3();
    u8 _8[0x10];
    Unk_23f4d80_18* field_18;
};
PKMN_OFFSET_ASSERT(Unk_23f4d80, field_18, 0x18);

// 0x7100e9b280
bool Unk_23f4d80::vf2() {
    if (field_18 == nullptr) {
        return false;
    }
    return field_18->field_170 != 0;
}
