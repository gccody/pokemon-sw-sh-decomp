// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_a6e930(void* self);
void Unk_a70780(void* self);
void Unk_a71770(void* self);
void Unk_a73040(void* self);
void Unk_a741e0(void* self);
void Unk_a76020(void* self);

class Unk_23c5c28 {
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

// 0x7100a6e900
void Unk_23c5c28::vf6() {
    Unk_a6e930(this);
}

// 0x7100a6e6d0
u32 Unk_23c5c28::vf7() {
    return 1;
}

// 0x7100a6e6e0
void Unk_23c5c28::vf8() {}

// 0x7100a6e6f0
void Unk_23c5c28::vf10() {}

class Unk_23c5c90 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100a6e910
void Unk_23c5c90::vf5() {
    Unk_a6e930(this);
}

class Unk_23c5cd0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100a6e920
void Unk_23c5cd0::vf0() {
    Unk_a6e930(this);
}

class Unk_23c5cf8 {
public:
    virtual ~Unk_23c5cf8();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x50];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_23c5cf8, field_58, 0x58);

// 0x7100a6ef60
u64 Unk_23c5cf8::vf3() {
    return field_58;
}

class Unk_23c5d38_Obj {
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

struct Unk_23c5d38_Entry {
    void* field_0;
    Unk_23c5d38_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23c5d38_Entry, 0x20);

class Unk_23c5d38 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23c5d38_Entry m_entries[1];
};
PKMN_OFFSET_ASSERT(Unk_23c5d38, m_entries, 0x8);

// 0x7100a6f0d0
u32 Unk_23c5d38::vf0() {
    return 1;
}

// 0x7100a6f0e0
void* Unk_23c5d38::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7100a6f0f0
void* Unk_23c5d38::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7100a6f100
void Unk_23c5d38::vf3(u64 index) {
    if (Unk_23c5d38_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_23c5e18 {
public:
    virtual ~Unk_23c5e18();
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
    virtual u32 vf25();
};

// 0x7100a6fd90
u32 Unk_23c5e18::vf20() {
    return 1;
}

// 0x7100a6fda0
void Unk_23c5e18::vf21() {}

// 0x7100a6fdb0
void Unk_23c5e18::vf22() {}

// 0x7100a6ff90
u32 Unk_23c5e18::vf25() {
    return 1;
}

class Unk_23c5d68 {
public:
    virtual ~Unk_23c5d68();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100a70480
void Unk_23c5d68::vf6() {
    Unk_a70780(this);
}

class Unk_23c5db0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100a704b0
void Unk_23c5db0::vf5() {
    Unk_a70780(this);
}

class Unk_23c5df0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100a704c0
void Unk_23c5df0::vf0() {
    Unk_a70780(this);
}

class Unk_23c5f60 {
public:
    virtual ~Unk_23c5f60();
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

// 0x7100a71700
void Unk_23c5f60::vf6() {
    Unk_a71770(this);
}

// 0x7100a716e0
void Unk_23c5f60::vf9() {}

class Unk_23c5fc8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100a71730
void Unk_23c5fc8::vf5() {
    Unk_a71770(this);
}

class Unk_23c6008 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100a71740
void Unk_23c6008::vf0() {
    Unk_a71770(this);
}

class Unk_23c6030 {
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
    virtual u32 vf16();
};

// 0x7100a72d90
void Unk_23c6030::vf6() {
    Unk_a73040(this);
}

// 0x7100a72850
u32 Unk_23c6030::vf16() {
    return 0;
}

class Unk_23c60c8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100a72ee0
void Unk_23c60c8::vf5() {
    Unk_a73040(this);
}

class Unk_23c6108 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100a72ef0
void Unk_23c6108::vf0() {
    Unk_a73040(this);
}

class Unk_23c6148 {
public:
    virtual ~Unk_23c6148();
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

// 0x7100a74170
void Unk_23c6148::vf6() {
    Unk_a741e0(this);
}

// 0x7100a74150
void Unk_23c6148::vf9() {}

class Unk_23c61b0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100a741a0
void Unk_23c61b0::vf5() {
    Unk_a741e0(this);
}

class Unk_23c61f0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100a741b0
void Unk_23c61f0::vf0() {
    Unk_a741e0(this);
}

class Unk_23c6218 {
public:
    virtual ~Unk_23c6218();
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

// 0x7100a75fb0
void Unk_23c6218::vf6() {
    Unk_a76020(this);
}

// 0x7100a74c10
u32 Unk_23c6218::vf7() {
    return 1;
}

class Unk_23c6280 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100a75fc0
void Unk_23c6280::vf5() {
    Unk_a76020(this);
}

class Unk_23c62c0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100a75fd0
void Unk_23c62c0::vf0() {
    Unk_a76020(this);
}

class Unk_23c62e8 {
public:
    virtual ~Unk_23c62e8();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x110];
    u64 field_118;
};
PKMN_OFFSET_ASSERT(Unk_23c62e8, field_118, 0x118);

// 0x7100a76540
u64 Unk_23c62e8::vf3() {
    return field_118;
}

class Unk_23c6328_Obj {
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

struct Unk_23c6328_Entry {
    void* field_0;
    Unk_23c6328_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23c6328_Entry, 0x20);

class Unk_23c6328 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23c6328_Entry m_entries[7];
};
PKMN_OFFSET_ASSERT(Unk_23c6328, m_entries, 0x8);

// 0x7100a766d0
u32 Unk_23c6328::vf0() {
    return 7;
}

// 0x7100a766e0
void* Unk_23c6328::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7100a766f0
void* Unk_23c6328::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7100a76700
void Unk_23c6328::vf3(u64 index) {
    if (Unk_23c6328_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_23c6358 {
public:
    virtual ~Unk_23c6358();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x50];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_23c6358, field_58, 0x58);

// 0x7100a76e20
u64 Unk_23c6358::vf3() {
    return field_58;
}

class Unk_23c6398_Obj {
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

struct Unk_23c6398_Entry {
    void* field_0;
    Unk_23c6398_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23c6398_Entry, 0x20);

class Unk_23c6398 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23c6398_Entry m_entries[1];
};
PKMN_OFFSET_ASSERT(Unk_23c6398, m_entries, 0x8);

// 0x7100a76f90
u32 Unk_23c6398::vf0() {
    return 1;
}

// 0x7100a76fa0
void* Unk_23c6398::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7100a76fb0
void* Unk_23c6398::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7100a76fc0
void Unk_23c6398::vf3(u64 index) {
    if (Unk_23c6398_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}
