// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_236d0b8 {
public:
    virtual ~Unk_236d0b8();
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
    virtual void vf14(bool value);
    virtual void vf15();
    virtual void* vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    u8 _8[0x10];
    bool field_18;
    u8 _19[0x77];
    bool field_90;
};
PKMN_OFFSET_ASSERT(Unk_236d0b8, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_236d0b8, field_90, 0x90);

// 0x7100002550
void Unk_236d0b8::vf14(bool value) {
    field_18 = value;
    field_90 = value;
}

class Unk_236d1f8_Obj {
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

struct Unk_236d1f8_Entry {
    void* field_0;
    Unk_236d1f8_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_236d1f8_Entry, 0x20);

class Unk_236d1f8 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_236d1f8_Entry m_entries[21];
};
PKMN_OFFSET_ASSERT(Unk_236d1f8, m_entries, 0x8);

// 0x71000032f0
u32 Unk_236d1f8::vf0() {
    return 0x15;
}

// 0x7100003300
void* Unk_236d1f8::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7100003310
void* Unk_236d1f8::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7100003320
void Unk_236d1f8::vf3(u64 index) {
    if (Unk_236d1f8_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}
