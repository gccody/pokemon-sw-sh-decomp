// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_1439d80(void* self);
void Unk_143cee0(void* self);
void Unk_1440750(void* self);
void Unk_1443030(void* self);
void Unk_1449740(void* self);
void Unk_144c2d0(void* self);

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_eb8e80(u64);

class Unk_243b490 {
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
    u8 _8[0x88];
    u64 field_90;
};
PKMN_OFFSET_ASSERT(Unk_243b490, field_90, 0x90);

// 0x710143a9c0
void Unk_243b490::vf8() {
    Unk_eb8e80(field_90);
}

// 0x710143a9d0
void Unk_243b490::vf9() {}

struct Unk_243b730_78 {
    u8 _0[0x5cc];
    u8 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_243b730_78, field_5cc, 0x5cc);

class Unk_243b730 {
public:
    virtual ~Unk_243b730();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual bool vf8();
    virtual void vf9();
    virtual void vf10();
    u8 _8[0x70];
    Unk_243b730_78* field_78;
};
PKMN_OFFSET_ASSERT(Unk_243b730, field_78, 0x78);

// 0x710143bb10
bool Unk_243b730::vf8() {
    return field_78->field_5cc != 0;
}

class Unk_243b800 {
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
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual u32 vf16();
};

// 0x710143cbb0
void Unk_243b800::vf6() {
    Unk_143cee0(this);
}

// 0x710143be10
u32 Unk_243b800::vf7() {
    return 1;
}

// 0x710143c910
u32 Unk_243b800::vf16() {
    return 0;
}

class Unk_243b898 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710143cd40
void Unk_243b898::vf5() {
    Unk_143cee0(this);
}

class Unk_243b8d8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710143cd50
void Unk_243b8d8::vf0() {
    Unk_143cee0(this);
}

class Unk_243b980 {
public:
    virtual ~Unk_243b980();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x710143dc20
void Unk_243b980::vf6() {
    Unk_1439d80(this);
}

class Unk_243b9c8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710143dc50
void Unk_243b9c8::vf5() {
    Unk_1439d80(this);
}

class Unk_243ba08 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710143dc60
void Unk_243ba08::vf0() {
    Unk_1439d80(this);
}

class Unk_243ba30 {
public:
    virtual ~Unk_243ba30();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u32 vf7();
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
};

// 0x710143e500
u32 Unk_243ba30::vf7() {
    return 1;
}

class Unk_243bb40_Obj {
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

struct Unk_243bb40_Entry {
    void* field_0;
    Unk_243bb40_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_243bb40_Entry, 0x20);

class Unk_243bb40 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_243bb40_Entry m_entries[1];
};
PKMN_OFFSET_ASSERT(Unk_243bb40, m_entries, 0x8);

// 0x710143eb20
u32 Unk_243bb40::vf0() {
    return 1;
}

// 0x710143eb30
void* Unk_243bb40::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x710143eb40
void* Unk_243bb40::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x710143eb50
void Unk_243bb40::vf3(u64 index) {
    if (Unk_243bb40_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_243bcf0 {
public:
    virtual ~Unk_243bcf0();
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
    virtual u32 vf25();
};

// 0x710143fbd0
void Unk_243bcf0::vf21() {}

// 0x710143fbe0
void Unk_243bcf0::vf22() {}

// 0x710143fbf0
u32 Unk_243bcf0::vf25() {
    return 1;
}

class Unk_243bc40 {
public:
    virtual ~Unk_243bc40();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7101440100
void Unk_243bc40::vf6() {
    Unk_1440750(this);
}

class Unk_243bc88 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101440130
void Unk_243bc88::vf5() {
    Unk_1440750(this);
}

class Unk_243bcc8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101440140
void Unk_243bcc8::vf0() {
    Unk_1440750(this);
}

class Unk_243be38 {
public:
    virtual ~Unk_243be38();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x50];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_243be38, field_58, 0x58);

// 0x71014403c0
u64 Unk_243be38::vf3() {
    return field_58;
}

class Unk_243be78_Obj {
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

struct Unk_243be78_Entry {
    void* field_0;
    Unk_243be78_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_243be78_Entry, 0x20);

class Unk_243be78 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_243be78_Entry m_entries[1];
};
PKMN_OFFSET_ASSERT(Unk_243be78, m_entries, 0x8);

// 0x7101440530
u32 Unk_243be78::vf0() {
    return 1;
}

// 0x7101440540
void* Unk_243be78::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7101440550
void* Unk_243be78::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7101440560
void Unk_243be78::vf3(u64 index) {
    if (Unk_243be78_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_243bf78 {
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
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
};

// 0x7101442e80
void Unk_243bf78::vf6() {
    Unk_1443030(this);
}

// 0x71014420a0
u32 Unk_243bf78::vf7() {
    return 1;
}

class Unk_243c010 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101442f50
void Unk_243c010::vf5() {
    Unk_1443030(this);
}

class Unk_243c050 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101442f60
void Unk_243c050::vf0() {
    Unk_1443030(this);
}

class Unk_243c120 {
public:
    virtual ~Unk_243c120();
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

// 0x71014496d0
void Unk_243c120::vf6() {
    Unk_1449740(this);
}

class Unk_243c1b8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101449700
void Unk_243c1b8::vf5() {
    Unk_1449740(this);
}

class Unk_243c1f8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101449710
void Unk_243c1f8::vf0() {
    Unk_1449740(this);
}

class Unk_243c338 {
public:
    virtual ~Unk_243c338();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x50];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_243c338, field_58, 0x58);

// 0x710144b120
u64 Unk_243c338::vf3() {
    return field_58;
}

class Unk_243c378_Obj {
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

struct Unk_243c378_Entry {
    void* field_0;
    Unk_243c378_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_243c378_Entry, 0x20);

class Unk_243c378 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_243c378_Entry m_entries[1];
};
PKMN_OFFSET_ASSERT(Unk_243c378, m_entries, 0x8);

// 0x710144b290
u32 Unk_243c378::vf0() {
    return 1;
}

// 0x710144b2a0
void* Unk_243c378::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x710144b2b0
void* Unk_243c378::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x710144b2c0
void Unk_243c378::vf3(u64 index) {
    if (Unk_243c378_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_243c458 {
public:
    virtual ~Unk_243c458();
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

// 0x710144b960
u32 Unk_243c458::vf20() {
    return 1;
}

// 0x710144be40
u32 Unk_243c458::vf25() {
    return 1;
}

class Unk_243c3a8 {
public:
    virtual ~Unk_243c3a8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x710144c260
void Unk_243c3a8::vf6() {
    Unk_144c2d0(this);
}

class Unk_243c3f0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710144c290
void Unk_243c3f0::vf5() {
    Unk_144c2d0(this);
}

class Unk_243c430 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710144c2a0
void Unk_243c430::vf0() {
    Unk_144c2d0(this);
}
