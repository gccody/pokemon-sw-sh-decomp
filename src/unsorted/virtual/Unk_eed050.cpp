// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_eed340(void* self);
void Unk_eee3a0(void* self);
void Unk_eeee20(void* self);
void Unk_ef0c60(void* self);
void Unk_ef2c60(void* self);
void Unk_efbfb0(void* self);
void Unk_efe300(void* self);
void Unk_eff3f0(void* self);

class Unk_23f87b0 {
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

// 0x7100eed310
void Unk_23f87b0::vf6() {
    Unk_eed340(this);
}

// 0x7100eed050
u32 Unk_23f87b0::vf7() {
    return 1;
}

// 0x7100eed060
void Unk_23f87b0::vf8() {}

// 0x7100eed070
void Unk_23f87b0::vf10() {}

class Unk_23f8818 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100eed320
void Unk_23f8818::vf5() {
    Unk_eed340(this);
}

class Unk_23f8858 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100eed330
void Unk_23f8858::vf0() {
    Unk_eed340(this);
}

class Unk_23f8880 {
public:
    virtual ~Unk_23f8880();
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

// 0x7100eed8a0
u32 Unk_23f8880::vf20() {
    return 1;
}

// 0x7100eed8b0
void Unk_23f8880::vf21() {}

// 0x7100eed8c0
void Unk_23f8880::vf22() {}

// 0x7100eed9b0
u32 Unk_23f8880::vf25() {
    return 1;
}

class Unk_23f89c8 {
public:
    virtual ~Unk_23f89c8();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x50];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_23f89c8, field_58, 0x58);

// 0x7100eee010
u64 Unk_23f89c8::vf3() {
    return field_58;
}

class Unk_23f8a08_Obj {
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

struct Unk_23f8a08_Entry {
    void* field_0;
    Unk_23f8a08_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23f8a08_Entry, 0x20);

class Unk_23f8a08 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23f8a08_Entry m_entries[1];
};
PKMN_OFFSET_ASSERT(Unk_23f8a08, m_entries, 0x8);

// 0x7100eee180
u32 Unk_23f8a08::vf0() {
    return 1;
}

// 0x7100eee190
void* Unk_23f8a08::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7100eee1a0
void* Unk_23f8a08::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7100eee1b0
void Unk_23f8a08::vf3(u64 index) {
    if (Unk_23f8a08_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_23f8b08 {
public:
    virtual ~Unk_23f8b08();
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

// 0x7100eef790
void Unk_23f8b08::vf6() {
    Unk_eeee20(this);
}

// 0x7100eef380
u32 Unk_23f8b08::vf16() {
    return 0;
}

class Unk_23f8ba0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100eef7c0
void Unk_23f8ba0::vf5() {
    Unk_eeee20(this);
}

class Unk_23f8be0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100eef7d0
void Unk_23f8be0::vf0() {
    Unk_eeee20(this);
}

class Unk_23f8c20 {
public:
    virtual ~Unk_23f8c20();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100eef890
void Unk_23f8c20::vf6() {
    Unk_eee3a0(this);
}

class Unk_23f8c68 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100eef8c0
void Unk_23f8c68::vf5() {
    Unk_eee3a0(this);
}

class Unk_23f8ca8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100eef8d0
void Unk_23f8ca8::vf0() {
    Unk_eee3a0(this);
}

class Unk_23f8d10 {
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

// 0x7100ef0ab0
void Unk_23f8d10::vf6() {
    Unk_ef0c60(this);
}

// 0x7100ef07a0
u32 Unk_23f8d10::vf7() {
    return 1;
}

// 0x7100ef07b0
void Unk_23f8d10::vf8() {}

// 0x7100ef07c0
void Unk_23f8d10::vf10() {}

class Unk_23f8d78 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100ef0b80
void Unk_23f8d78::vf5() {
    Unk_ef0c60(this);
}

class Unk_23f8db8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100ef0b90
void Unk_23f8db8::vf0() {
    Unk_ef0c60(this);
}

class Unk_23f8de0 {
public:
    virtual ~Unk_23f8de0();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x50];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_23f8de0, field_58, 0x58);

// 0x7100ef12a0
u64 Unk_23f8de0::vf3() {
    return field_58;
}

class Unk_23f8e20_Obj {
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

struct Unk_23f8e20_Entry {
    void* field_0;
    Unk_23f8e20_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23f8e20_Entry, 0x20);

class Unk_23f8e20 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23f8e20_Entry m_entries[1];
};
PKMN_OFFSET_ASSERT(Unk_23f8e20, m_entries, 0x8);

// 0x7100ef1410
u32 Unk_23f8e20::vf0() {
    return 1;
}

// 0x7100ef1420
void* Unk_23f8e20::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7100ef1430
void* Unk_23f8e20::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7100ef1440
void Unk_23f8e20::vf3(u64 index) {
    if (Unk_23f8e20_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_23f8f98 {
public:
    virtual ~Unk_23f8f98();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100ef2920
void Unk_23f8f98::vf6() {
    Unk_ef2c60(this);
}

class Unk_23f8fe0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100ef2950
void Unk_23f8fe0::vf5() {
    Unk_ef2c60(this);
}

class Unk_23f9020 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100ef2960
void Unk_23f9020::vf0() {
    Unk_ef2c60(this);
}

class Unk_23f9178 {
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
PKMN_OFFSET_ASSERT(Unk_23f9178, field_e8, 0xe8);

// 0x7100ef4130
u32 Unk_23f9178::vf10() {
    return field_e8;
}

class Unk_23f9678 {
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

// 0x7100efbf80
void Unk_23f9678::vf6() {
    Unk_efbfb0(this);
}

// 0x7100efba60
u32 Unk_23f9678::vf7() {
    return 1;
}

// 0x7100efba70
void Unk_23f9678::vf8() {}

// 0x7100efba80
void Unk_23f9678::vf10() {}

class Unk_23f96e0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100efbf90
void Unk_23f96e0::vf5() {
    Unk_efbfb0(this);
}

class Unk_23f9720 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100efbfa0
void Unk_23f9720::vf0() {
    Unk_efbfb0(this);
}

class Unk_23f9748 {
public:
    virtual ~Unk_23f9748();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x70];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_23f9748, field_78, 0x78);

// 0x7100efc640
u64 Unk_23f9748::vf3() {
    return field_78;
}

class Unk_23f9788_Obj {
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

struct Unk_23f9788_Entry {
    void* field_0;
    Unk_23f9788_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_23f9788_Entry, 0x20);

class Unk_23f9788 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_23f9788_Entry m_entries[2];
};
PKMN_OFFSET_ASSERT(Unk_23f9788, m_entries, 0x8);

// 0x7100efc7d0
u32 Unk_23f9788::vf0() {
    return 2;
}

// 0x7100efc7e0
void* Unk_23f9788::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7100efc7f0
void* Unk_23f9788::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7100efc800
void Unk_23f9788::vf3(u64 index) {
    if (Unk_23f9788_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_23f9868 {
public:
    virtual ~Unk_23f9868();
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

// 0x7100efdbf0
void Unk_23f9868::vf22() {}

class Unk_23f97b8 {
public:
    virtual ~Unk_23f97b8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100efdeb0
void Unk_23f97b8::vf6() {
    Unk_efe300(this);
}

class Unk_23f9800 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100efdec0
void Unk_23f9800::vf5() {
    Unk_efe300(this);
}

class Unk_23f9840 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100efded0
void Unk_23f9840::vf0() {
    Unk_efe300(this);
}

class Unk_23f9a80 {
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

// 0x7100eff3c0
void Unk_23f9a80::vf6() {
    Unk_eff3f0(this);
}

// 0x7100efeff0
u32 Unk_23f9a80::vf7() {
    return 1;
}

// 0x7100eff0e0
void Unk_23f9a80::vf10() {}

class Unk_23f9ae8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100eff3d0
void Unk_23f9ae8::vf5() {
    Unk_eff3f0(this);
}

class Unk_23f9b28 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100eff3e0
void Unk_23f9b28::vf0() {
    Unk_eff3f0(this);
}
