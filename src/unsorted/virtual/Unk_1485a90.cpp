// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_1485d90(void* self);

class Unk_243fdf0 {
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

// 0x7101485d60
void Unk_243fdf0::vf6() {
    Unk_1485d90(this);
}

// 0x7101485a90
u32 Unk_243fdf0::vf7() {
    return 1;
}

// 0x7101485aa0
void Unk_243fdf0::vf8() {}

// 0x7101485c40
void Unk_243fdf0::vf10() {}

class Unk_243fe58 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101485d70
void Unk_243fe58::vf5() {
    Unk_1485d90(this);
}

class Unk_243fe98 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101485d80
void Unk_243fe98::vf0() {
    Unk_1485d90(this);
}

class Unk_243fec0 {
public:
    virtual ~Unk_243fec0();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x50];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_243fec0, field_58, 0x58);

// 0x7101486570
u64 Unk_243fec0::vf3() {
    return field_58;
}

class Unk_243ff00_Obj {
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

struct Unk_243ff00_Entry {
    void* field_0;
    Unk_243ff00_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_243ff00_Entry, 0x20);

class Unk_243ff00 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_243ff00_Entry m_entries[1];
};
PKMN_OFFSET_ASSERT(Unk_243ff00, m_entries, 0x8);

// 0x71014866e0
u32 Unk_243ff00::vf0() {
    return 1;
}

// 0x71014866f0
void* Unk_243ff00::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7101486700
void* Unk_243ff00::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7101486710
void Unk_243ff00::vf3(u64 index) {
    if (Unk_243ff00_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}
