// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_236d328 {
public:
    virtual ~Unk_236d328();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100007c10
void Unk_236d328::vf2() {}

class Unk_236d358 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x7100007c90
void Unk_236d358::vf0() {}

class Unk_236d418 {
public:
    virtual ~Unk_236d418();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100008680
void Unk_236d418::vf2() {}

class Unk_236d448 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x7100008700
void Unk_236d448::vf0() {}

class Unk_236d468 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100008cb0
void Unk_236d468::vf2() {}

class Unk_236d498 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x7100008d30
void Unk_236d498::vf0() {}

class Unk_236d4f8 {
public:
    virtual ~Unk_236d4f8();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100009180
void Unk_236d4f8::vf2() {}

class Unk_236d528 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x7100009200
void Unk_236d528::vf0() {}

class Unk_236d548 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100009490
void Unk_236d548::vf2() {}

class Unk_236d578 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x7100009510
void Unk_236d578::vf0() {}

class Unk_236d598 {
public:
    virtual ~Unk_236d598();
    virtual void vf2();
    virtual void vf3();
};

// 0x710000a7d0
void Unk_236d598::vf2() {}

class Unk_236d5c8 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x710000a850
void Unk_236d5c8::vf0() {}

class Unk_236d5e8_Obj {
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

struct Unk_236d5e8_Entry {
    void* field_0;
    Unk_236d5e8_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_236d5e8_Entry, 0x20);

class Unk_236d5e8 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_236d5e8_Entry m_entries[1];
};
PKMN_OFFSET_ASSERT(Unk_236d5e8, m_entries, 0x8);

// 0x710000a8e0
u32 Unk_236d5e8::vf0() {
    return 1;
}

// 0x710000a8f0
void* Unk_236d5e8::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x710000a900
void* Unk_236d5e8::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x710000a910
void Unk_236d5e8::vf3(u64 index) {
    if (Unk_236d5e8_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_236d678 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x710000af20
void Unk_236d678::vf2() {}

class Unk_236d6a8 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x710000afa0
void Unk_236d6a8::vf0() {}

class Unk_236d6c8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x710000b330
void Unk_236d6c8::vf2() {}

class Unk_236d6f8 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x710000b3b0
void Unk_236d6f8::vf0() {}

class Unk_236d718 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x710000b740
void Unk_236d718::vf2() {}

class Unk_236d748 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x710000b7c0
void Unk_236d748::vf0() {}

class Unk_236d768 {
public:
    virtual ~Unk_236d768();
    virtual void vf2();
    virtual void vf3();
};

// 0x710000bd50
void Unk_236d768::vf2() {}

class Unk_236d798 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x710000bdd0
void Unk_236d798::vf0() {}

class Unk_236d7b8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x710000c460
void Unk_236d7b8::vf2() {}

class Unk_236d7e8 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x710000c4e0
void Unk_236d7e8::vf0() {}

class Unk_236d808 {
public:
    virtual ~Unk_236d808();
    virtual void vf2();
    virtual void vf3();
};

// 0x710000c5b0, 0x710000c560
Unk_236d808::~Unk_236d808() {}

class Unk_236d838 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x710000cab0
void Unk_236d838::vf2() {}

class Unk_236d868 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x710000cb30
void Unk_236d868::vf0() {}
