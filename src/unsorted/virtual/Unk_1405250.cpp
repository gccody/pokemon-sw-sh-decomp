// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_14058c0(void* self);
void Unk_140ce80(void* self);
void Unk_140f090(void* self);
void Unk_1412a50(void* self);
void Unk_1413320(void* self);
void Unk_14141c0(void* self);
void Unk_1414dc0(void* self);
void Unk_14158a0(void* self);

class Unk_2437950 {
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
};

// 0x7101405250
void Unk_2437950::vf6() {
    Unk_14058c0(this);
}

class Unk_24379d0 {
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
};

// 0x71014056f0
void Unk_24379d0::vf5() {
    Unk_14058c0(this);
}

class Unk_2437a40 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101405710
void Unk_2437a40::vf0() {
    Unk_14058c0(this);
}

class Unk_2438370 {
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

// 0x710140ce50
void Unk_2438370::vf6() {
    Unk_140ce80(this);
}

// 0x710140cc20
u32 Unk_2438370::vf7() {
    return 1;
}

// 0x710140cc30
void Unk_2438370::vf8() {}

// 0x710140cc40
void Unk_2438370::vf10() {}

class Unk_24383d8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710140ce60
void Unk_24383d8::vf5() {
    Unk_140ce80(this);
}

class Unk_2438418 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710140ce70
void Unk_2438418::vf0() {
    Unk_140ce80(this);
}

class Unk_2438440 {
public:
    virtual ~Unk_2438440();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x50];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_2438440, field_58, 0x58);

// 0x710140d4b0
u64 Unk_2438440::vf3() {
    return field_58;
}

class Unk_2438480_Obj {
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

struct Unk_2438480_Entry {
    void* field_0;
    Unk_2438480_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_2438480_Entry, 0x20);

class Unk_2438480 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_2438480_Entry m_entries[1];
};
PKMN_OFFSET_ASSERT(Unk_2438480, m_entries, 0x8);

// 0x710140d620
u32 Unk_2438480::vf0() {
    return 1;
}

// 0x710140d630
void* Unk_2438480::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x710140d640
void* Unk_2438480::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x710140d650
void Unk_2438480::vf3(u64 index) {
    if (Unk_2438480_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}

class Unk_2438578 {
public:
    virtual ~Unk_2438578();
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

// 0x710140e480
void Unk_2438578::vf21() {}

// 0x710140e490
void Unk_2438578::vf22() {}

// 0x710140ea40
u32 Unk_2438578::vf25() {
    return 1;
}

class Unk_24384b0 {
public:
    virtual ~Unk_24384b0();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x710140ef30
void Unk_24384b0::vf6() {
    Unk_140f090(this);
}

class Unk_24384f8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710140ef60
void Unk_24384f8::vf5() {
    Unk_140f090(this);
}

class Unk_2438538 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710140ef70
void Unk_2438538::vf0() {
    Unk_140f090(this);
}

class Unk_24386c0 {
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

// 0x71014125e0
void Unk_24386c0::vf6() {
    Unk_1412a50(this);
}

// 0x7101411e90
void Unk_24386c0::vf10() {}

class Unk_2438758 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101412810
void Unk_2438758::vf5() {
    Unk_1412a50(this);
}

class Unk_2438798 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101412820
void Unk_2438798::vf0() {
    Unk_1412a50(this);
}

class Unk_2438820 {
public:
    virtual ~Unk_2438820();
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

// 0x71014132b0
void Unk_2438820::vf6() {
    Unk_1413320(this);
}

// 0x7101413290
void Unk_2438820::vf9() {}

class Unk_2438888 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71014132e0
void Unk_2438888::vf5() {
    Unk_1413320(this);
}

class Unk_24388c8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71014132f0
void Unk_24388c8::vf0() {
    Unk_1413320(this);
}

class Unk_24388f0 {
public:
    virtual ~Unk_24388f0();
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

// 0x7101414150
void Unk_24388f0::vf6() {
    Unk_14141c0(this);
}

class Unk_2438958 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101414180
void Unk_2438958::vf5() {
    Unk_14141c0(this);
}

class Unk_2438998 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101414190
void Unk_2438998::vf0() {
    Unk_14141c0(this);
}

class Unk_24389d8 {
public:
    virtual ~Unk_24389d8();
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

// 0x7101414d50
void Unk_24389d8::vf6() {
    Unk_1414dc0(this);
}

class Unk_2438a40 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101414d80
void Unk_2438a40::vf5() {
    Unk_1414dc0(this);
}

class Unk_2438a80 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101414d90
void Unk_2438a80::vf0() {
    Unk_1414dc0(this);
}

class Unk_2438ac0 {
public:
    virtual ~Unk_2438ac0();
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

// 0x7101415830
void Unk_2438ac0::vf6() {
    Unk_14158a0(this);
}

class Unk_2438b28 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101415860
void Unk_2438b28::vf5() {
    Unk_14158a0(this);
}

class Unk_2438b68 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101415870
void Unk_2438b68::vf0() {
    Unk_14158a0(this);
}
