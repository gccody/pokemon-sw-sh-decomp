// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_1299fa0(void*);

class Unk_242b430 {
public:
    virtual ~Unk_242b430();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u32 vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    u8 _8[0x248];
    u8 field_250;
};
PKMN_OFFSET_ASSERT(Unk_242b430, field_250, 0x250);

// 0x7101296c80
u32 Unk_242b430::vf7() {
    return 1;
}

// 0x7101296d40
void Unk_242b430::vf10() {
    Unk_1299fa0(&field_250);
}

class Unk_242b500 {
public:
    virtual ~Unk_242b500();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x50];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_242b500, field_58, 0x58);

// 0x7101297e50
u64 Unk_242b500::vf3() {
    return field_58;
}

class Unk_242b540_Obj {
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

struct Unk_242b540_Entry {
    void* field_0;
    Unk_242b540_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_242b540_Entry, 0x20);

class Unk_242b540 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_242b540_Entry m_entries[1];
};
PKMN_OFFSET_ASSERT(Unk_242b540, m_entries, 0x8);

// 0x7101297fc0
u32 Unk_242b540::vf0() {
    return 1;
}

// 0x7101297fd0
void* Unk_242b540::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7101297fe0
void* Unk_242b540::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7101297ff0
void Unk_242b540::vf3(u64 index) {
    if (Unk_242b540_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}
