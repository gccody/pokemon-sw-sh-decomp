// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_1520be0(void* self);
void Unk_1527c70(void* self);
void Unk_1529770(void* self);
void Unk_152a880(void* self);
void Unk_152ee70(void* self);
void Unk_1532a80(void* self);
void Unk_153ad80(void* self);

class Unk_2447af8 {
public:
    virtual ~Unk_2447af8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7101520b70
void Unk_2447af8::vf6() {
    Unk_1520be0(this);
}

class Unk_2447b40 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101520ba0
void Unk_2447b40::vf5() {
    Unk_1520be0(this);
}

class Unk_2447b80 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101520bb0
void Unk_2447b80::vf0() {
    Unk_1520be0(this);
}

class Unk_2447cf0 {
public:
    virtual ~Unk_2447cf0();
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

// 0x7101527c00
void Unk_2447cf0::vf6() {
    Unk_1527c70(this);
}

// 0x7101523aa0
void Unk_2447cf0::vf10() {}

class Unk_2447d88 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101527c30
void Unk_2447d88::vf5() {
    Unk_1527c70(this);
}

class Unk_2447dc8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101527c40
void Unk_2447dc8::vf0() {
    Unk_1527c70(this);
}

class Unk_2447e50 {
public:
    virtual ~Unk_2447e50();
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

// 0x7101529700
void Unk_2447e50::vf6() {
    Unk_1529770(this);
}

class Unk_2447ee8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101529730
void Unk_2447ee8::vf5() {
    Unk_1529770(this);
}

class Unk_2447f28 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101529740
void Unk_2447f28::vf0() {
    Unk_1529770(this);
}

class Unk_2448020 {
public:
    virtual ~Unk_2448020();
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
    virtual u32 vf16();
};

// 0x710152a810
void Unk_2448020::vf6() {
    Unk_152a880(this);
}

// 0x710152a6b0
void Unk_2448020::vf8() {}

// 0x710152a6c0
void Unk_2448020::vf10() {}

// 0x710152a6d0
u32 Unk_2448020::vf16() {
    return 0;
}

class Unk_24480b8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710152a840
void Unk_24480b8::vf5() {
    Unk_152a880(this);
}

class Unk_24480f8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710152a850
void Unk_24480f8::vf0() {
    Unk_152a880(this);
}

class Unk_24482c0 {
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

// 0x710152ecc0
void Unk_24482c0::vf6() {
    Unk_152ee70(this);
}

// 0x710152bf60
void Unk_24482c0::vf10() {}

class Unk_2448358 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710152ed90
void Unk_2448358::vf5() {
    Unk_152ee70(this);
}

class Unk_2448398 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710152eda0
void Unk_2448398::vf0() {
    Unk_152ee70(this);
}

class Unk_24483f0 {
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
PKMN_OFFSET_ASSERT(Unk_24483f0, field_e8, 0xe8);

// 0x710152f6c0
u32 Unk_24483f0::vf10() {
    return field_e8;
}

class Unk_2448660 {
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

// 0x7101532890
void Unk_2448660::vf6() {
    Unk_1532a80(this);
}

// 0x7101531390
void Unk_2448660::vf10() {}

class Unk_24486f8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101532980
void Unk_24486f8::vf5() {
    Unk_1532a80(this);
}

class Unk_2448738 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101532990
void Unk_2448738::vf0() {
    Unk_1532a80(this);
}

class Unk_2449338 {
public:
    virtual ~Unk_2449338();
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

// 0x710153ad50
void Unk_2449338::vf6() {
    Unk_153ad80(this);
}

// 0x7101539eb0
u32 Unk_2449338::vf7() {
    return 1;
}

class Unk_24493a0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710153ad60
void Unk_24493a0::vf5() {
    Unk_153ad80(this);
}

class Unk_24493e0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710153ad70
void Unk_24493e0::vf0() {
    Unk_153ad80(this);
}

class Unk_2449408 {
public:
    virtual ~Unk_2449408();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0xd0];
    u64 field_d8;
};
PKMN_OFFSET_ASSERT(Unk_2449408, field_d8, 0xd8);

// 0x710153b630
u64 Unk_2449408::vf3() {
    return field_d8;
}

class Unk_2449448_Obj {
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

struct Unk_2449448_Entry {
    void* field_0;
    Unk_2449448_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_2449448_Entry, 0x20);

class Unk_2449448 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_2449448_Entry m_entries[5];
};
PKMN_OFFSET_ASSERT(Unk_2449448, m_entries, 0x8);

// 0x710153b7c0
u32 Unk_2449448::vf0() {
    return 5;
}

// 0x710153b7d0
void* Unk_2449448::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x710153b7e0
void* Unk_2449448::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x710153b7f0
void Unk_2449448::vf3(u64 index) {
    if (Unk_2449448_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}
