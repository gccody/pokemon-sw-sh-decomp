// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_141ea90(void* self);
void Unk_1420e40(void* self);
void Unk_1425a50(void* self);
void Unk_1429f10(void* self);
void Unk_142c700(void* self);

class Unk_2438e00 {
public:
    virtual ~Unk_2438e00();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x50];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_2438e00, field_58, 0x58);

// 0x7101418580
u64 Unk_2438e00::vf3() {
    return field_58;
}

class Unk_2438e40_Obj {
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

struct Unk_2438e40_Entry {
    void* field_0;
    Unk_2438e40_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_2438e40_Entry, 0x20);

class Unk_2438e40 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_2438e40_Entry m_entries[1];
};
PKMN_OFFSET_ASSERT(Unk_2438e40, m_entries, 0x8);

// 0x71014186f0
u32 Unk_2438e40::vf0() {
    return 1;
}

// 0x7101418700
void* Unk_2438e40::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7101418710
void* Unk_2438e40::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7101418720
void Unk_2438e40::vf3(u64 index) {
    if (Unk_2438e40_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

struct Unk_2438f20_708 {
    u8 _0[0x170];
    u8 field_170;
};
PKMN_OFFSET_ASSERT(Unk_2438f20_708, field_170, 0x170);

class Unk_2438f20 {
public:
    virtual ~Unk_2438f20();
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
    virtual bool vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual u32 vf25();
    u8 _8[0x700];
    Unk_2438f20_708* field_708;
    u8 _710[0x110];
    u64 field_820;
    u64 field_828;
    u64 field_830;
};
PKMN_OFFSET_ASSERT(Unk_2438f20, field_708, 0x708);
PKMN_OFFSET_ASSERT(Unk_2438f20, field_820, 0x820);
PKMN_OFFSET_ASSERT(Unk_2438f20, field_828, 0x828);
PKMN_OFFSET_ASSERT(Unk_2438f20, field_830, 0x830);

// 0x7101419010
bool Unk_2438f20::vf20() {
    if (field_708 == nullptr) {
        return false;
    }
    return field_708->field_170 != 0;
}

// 0x7101419450
void Unk_2438f20::vf22() {}

// 0x7101419540
u32 Unk_2438f20::vf25() {
    field_830 = 0;
    field_828 = 0;
    field_820 = 0;
    return 1;
}

class Unk_2439068 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

// 0x710141a460
void Unk_2439068::vf1() {}

class Unk_24390a0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x710141a470
void Unk_24390a0::vf0() {}

// 0x710141a480
void Unk_24390a0::vf1() {}

class Unk_2439200 {
public:
    virtual ~Unk_2439200();
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

// 0x710141ea20
void Unk_2439200::vf6() {
    Unk_141ea90(this);
}

class Unk_2439298 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710141ea50
void Unk_2439298::vf5() {
    Unk_141ea90(this);
}

class Unk_24392d8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710141ea60
void Unk_24392d8::vf0() {
    Unk_141ea90(this);
}

class Unk_2439318 {
public:
    virtual ~Unk_2439318();
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

// 0x7101420dd0
void Unk_2439318::vf6() {
    Unk_1420e40(this);
}

// 0x7101420c30
void Unk_2439318::vf9() {}

class Unk_2439380 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101420e00
void Unk_2439380::vf5() {
    Unk_1420e40(this);
}

class Unk_24393c0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101420e10
void Unk_24393c0::vf0() {
    Unk_1420e40(this);
}

class Unk_2439538 {
public:
    virtual ~Unk_2439538();
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

// 0x71014220d0
u32 Unk_2439538::vf20() {
    return 1;
}

// 0x71014220e0
void Unk_2439538::vf21() {}

// 0x71014220f0
void Unk_2439538::vf22() {}

// 0x71014221e0
u32 Unk_2439538::vf25() {
    return 1;
}

class Unk_2439680 {
public:
    virtual ~Unk_2439680();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x50];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_2439680, field_58, 0x58);

// 0x7101422840
u64 Unk_2439680::vf3() {
    return field_58;
}

class Unk_24396c0_Obj {
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

struct Unk_24396c0_Entry {
    void* field_0;
    Unk_24396c0_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_24396c0_Entry, 0x20);

class Unk_24396c0 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_24396c0_Entry m_entries[1];
};
PKMN_OFFSET_ASSERT(Unk_24396c0, m_entries, 0x8);

// 0x71014229b0
u32 Unk_24396c0::vf0() {
    return 1;
}

// 0x71014229c0
void* Unk_24396c0::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x71014229d0
void* Unk_24396c0::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x71014229e0
void Unk_24396c0::vf3(u64 index) {
    if (Unk_24396c0_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_2439890 {
public:
    virtual ~Unk_2439890();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x50];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_2439890, field_58, 0x58);

// 0x71014242a0
u64 Unk_2439890::vf3() {
    return field_58;
}

class Unk_24398d0_Obj {
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

struct Unk_24398d0_Entry {
    void* field_0;
    Unk_24398d0_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_24398d0_Entry, 0x20);

class Unk_24398d0 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_24398d0_Entry m_entries[1];
};
PKMN_OFFSET_ASSERT(Unk_24398d0, m_entries, 0x8);

// 0x7101424410
u32 Unk_24398d0::vf0() {
    return 1;
}

// 0x7101424420
void* Unk_24398d0::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7101424430
void* Unk_24398d0::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7101424440
void Unk_24398d0::vf3(u64 index) {
    if (Unk_24398d0_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_24399b0 {
public:
    virtual ~Unk_24399b0();
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

// 0x7101424f50
void Unk_24399b0::vf21() {}

// 0x7101424f60
void Unk_24399b0::vf22() {}

class Unk_2439900 {
public:
    virtual ~Unk_2439900();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7101425990
void Unk_2439900::vf6() {
    Unk_1425a50(this);
}

class Unk_2439948 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71014259c0
void Unk_2439948::vf5() {
    Unk_1425a50(this);
}

class Unk_2439988 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71014259d0
void Unk_2439988::vf0() {
    Unk_1425a50(this);
}

class Unk_2439b28_Obj {
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

struct Unk_2439b28_Entry {
    void* field_0;
    Unk_2439b28_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_2439b28_Entry, 0x20);

class Unk_2439b28 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_2439b28_Entry m_entries[1];
};
PKMN_OFFSET_ASSERT(Unk_2439b28, m_entries, 0x8);

// 0x7101425a00
u32 Unk_2439b28::vf0() {
    return 1;
}

// 0x7101425a10
void* Unk_2439b28::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x7101425a20
void* Unk_2439b28::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x7101425a30
void Unk_2439b28::vf3(u64 index) {
    if (Unk_2439b28_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_243a0d0 {
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

// 0x7101429d60
void Unk_243a0d0::vf6() {
    Unk_1429f10(this);
}

// 0x7101429c90
void Unk_243a0d0::vf9() {}

class Unk_243a138 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101429e30
void Unk_243a138::vf5() {
    Unk_1429f10(this);
}

class Unk_243a178 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101429e40
void Unk_243a178::vf0() {
    Unk_1429f10(this);
}

class Unk_243a308 {
public:
    virtual ~Unk_243a308();
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

// 0x710142c6d0
void Unk_243a308::vf6() {
    Unk_142c700(this);
}

// 0x710142bd00
u32 Unk_243a308::vf7() {
    return 1;
}

// 0x710142bd10
void Unk_243a308::vf8() {}

// 0x710142bd20
void Unk_243a308::vf10() {}

class Unk_243a370 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710142c6e0
void Unk_243a370::vf5() {
    Unk_142c700(this);
}

class Unk_243a3b0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710142c6f0
void Unk_243a3b0::vf0() {
    Unk_142c700(this);
}

class Unk_243a3d8 {
public:
    virtual ~Unk_243a3d8();
    virtual u32 vf2();
    virtual u32 vf3();
    virtual void vf4();
    virtual u32 vf5();
    virtual u32 vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual u8 vf10();
    u8 _8[0x278];
    u32 field_280;
    u32 field_284;
    u8 _288[0x8];
    u8 field_290;
};
PKMN_OFFSET_ASSERT(Unk_243a3d8, field_280, 0x280);
PKMN_OFFSET_ASSERT(Unk_243a3d8, field_284, 0x284);
PKMN_OFFSET_ASSERT(Unk_243a3d8, field_290, 0x290);

// 0x710142c970
u32 Unk_243a3d8::vf2() {
    return field_280;
}

// 0x710142c980
u32 Unk_243a3d8::vf3() {
    return field_284;
}

// 0x710142ca00
u32 Unk_243a3d8::vf5() {
    return 0;
}

// 0x710142ca10
u32 Unk_243a3d8::vf6() {
    return 0;
}

// 0x710142cbc0
u8 Unk_243a3d8::vf10() {
    return field_290;
}

class Unk_243a440 {
public:
    virtual ~Unk_243a440();
    virtual void vf2() = 0;
    virtual void vf3() = 0;
    virtual void vf4() = 0;
    virtual void vf5() = 0;
    virtual void vf6() = 0;
    virtual u32 vf7();
    virtual void vf8() = 0;
    virtual void vf9() = 0;
    virtual u32 vf10();
};

// 0x710142cc40
u32 Unk_243a440::vf7() {
    return 1;
}

// 0x710142cc50
u32 Unk_243a440::vf10() {
    return 0;
}
