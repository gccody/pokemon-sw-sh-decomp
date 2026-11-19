// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23bc860 {
public:
    virtual ~Unk_23bc860();
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
    virtual u32 vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
};

// 0x71008e4150
u32 Unk_23bc860::vf20() {
    return 1;
}

// 0x71008e4a50
void Unk_23bc860::vf22() {}

class Unk_23bc9a8 {
public:
    virtual ~Unk_23bc9a8();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x50];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_23bc9a8, field_58, 0x58);

// 0x71008e54e0
u64 Unk_23bc9a8::vf3() {
    return field_58;
}

class Unk_23bc9e8_Obj {
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

struct Unk_23bc9e8_Entry {
    void* field_0;
    Unk_23bc9e8_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23bc9e8_Entry, 0x20);

class Unk_23bc9e8 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23bc9e8_Entry m_entries[1];
};
PKMN_OFFSET_ASSERT(Unk_23bc9e8, m_entries, 0x8);

// 0x71008e5650
u32 Unk_23bc9e8::vf0() {
    return 1;
}

// 0x71008e5660
void* Unk_23bc9e8::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x71008e5670
void* Unk_23bc9e8::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x71008e5680
void Unk_23bc9e8::vf3(u64 index) {
    if (Unk_23bc9e8_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_23bcd20 {
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
};

// 0x71008e8730
void Unk_23bcd20::vf9() {}

class Unk_23bcec0 {
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
};

// 0x71008e9560
void Unk_23bcec0::vf9() {}

class Unk_23bcf90 {
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
};

// 0x71008e9910
void Unk_23bcf90::vf9() {}

class Unk_23bd060 {
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
};

// 0x71008e9d50
void Unk_23bd060::vf9() {}

class Unk_23bd130 {
public:
    virtual ~Unk_23bd130();
    virtual void vf2();
};

// 0x71008eb220, 0x71008eb1f0
Unk_23bd130::~Unk_23bd130() {}
