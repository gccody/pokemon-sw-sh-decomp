// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_1476b50(void* self);
void Unk_1478660(void* self);
void Unk_1479c40(void* self);
void Unk_147ba90(void* self);
void Unk_147ddb0(void* self);
void Unk_147f3b0(void* self);
void Unk_147ffc0(void* self);
void Unk_1482030(void* self);

class Unk_243e198 {
public:
    virtual ~Unk_243e198();
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

// 0x7101476ae0
void Unk_243e198::vf6() {
    Unk_1476b50(this);
}

class Unk_243e230 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101476b10
void Unk_243e230::vf5() {
    Unk_1476b50(this);
}

class Unk_243e270 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101476b20
void Unk_243e270::vf0() {
    Unk_1476b50(this);
}

class Unk_243e520 {
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

// 0x71014783f0
void Unk_243e520::vf6() {
    Unk_1478660(this);
}

class Unk_243e5b8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101478520
void Unk_243e5b8::vf5() {
    Unk_1478660(this);
}

class Unk_243e5f8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101478530
void Unk_243e5f8::vf0() {
    Unk_1478660(this);
}

class Unk_243e7d8 {
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

// 0x7101479a90
void Unk_243e7d8::vf6() {
    Unk_1479c40(this);
}

class Unk_243e840 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101479b60
void Unk_243e840::vf5() {
    Unk_1479c40(this);
}

class Unk_243e880 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101479b70
void Unk_243e880::vf0() {
    Unk_1479c40(this);
}

class Unk_243eb18 {
public:
    virtual ~Unk_243eb18();
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

// 0x710147ba20
void Unk_243eb18::vf6() {
    Unk_147ba90(this);
}

// 0x710147b910
void Unk_243eb18::vf9() {}

class Unk_243eb80 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710147ba50
void Unk_243eb80::vf5() {
    Unk_147ba90(this);
}

class Unk_243ebc0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710147ba60
void Unk_243ebc0::vf0() {
    Unk_147ba90(this);
}

class Unk_243ef40 {
public:
    virtual ~Unk_243ef40();
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

// 0x710147dd40
void Unk_243ef40::vf6() {
    Unk_147ddb0(this);
}

// 0x710147dc30
void Unk_243ef40::vf9() {}

class Unk_243efa8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710147dd70
void Unk_243efa8::vf5() {
    Unk_147ddb0(this);
}

class Unk_243efe8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710147dd80
void Unk_243efe8::vf0() {
    Unk_147ddb0(this);
}

class Unk_243f1c8 {
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

// 0x710147f140
void Unk_243f1c8::vf6() {
    Unk_147f3b0(this);
}

// 0x710147f010
void Unk_243f1c8::vf9() {}

class Unk_243f230 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710147f270
void Unk_243f230::vf5() {
    Unk_147f3b0(this);
}

class Unk_243f270 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710147f280
void Unk_243f270::vf0() {
    Unk_147f3b0(this);
}

class Unk_243f298 {
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

// 0x710147fd50
void Unk_243f298::vf6() {
    Unk_147ffc0(this);
}

// 0x710147fc20
void Unk_243f298::vf9() {}

class Unk_243f300 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710147fe80
void Unk_243f300::vf5() {
    Unk_147ffc0(this);
}

class Unk_243f340 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710147fe90
void Unk_243f340::vf0() {
    Unk_147ffc0(this);
}

class Unk_243f848 {
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

// 0x7101481e80
void Unk_243f848::vf6() {
    Unk_1482030(this);
}

// 0x7101481ba0
u32 Unk_243f848::vf7() {
    return 1;
}

// 0x7101481bb0
void Unk_243f848::vf8() {}

// 0x7101481ca0
void Unk_243f848::vf10() {}

class Unk_243f8b0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101481f50
void Unk_243f8b0::vf5() {
    Unk_1482030(this);
}

class Unk_243f8f0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101481f60
void Unk_243f8f0::vf0() {
    Unk_1482030(this);
}

class Unk_243f918 {
public:
    virtual ~Unk_243f918();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0x50];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_243f918, field_58, 0x58);

// 0x7101482810
u64 Unk_243f918::vf3() {
    return field_58;
}

class Unk_243f958_Obj {
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

struct Unk_243f958_Entry {
    void* field_0;
    Unk_243f958_Obj* field_8;
    u64 field_10;
    u8 _18[0x8];
};
PKMN_SIZE_ASSERT(Unk_243f958_Entry, 0x20);

class Unk_243f958 {
public:
    virtual u32 vf0();
    virtual void* vf1(u64 index);
    virtual void* vf2(u64 index);
    virtual void vf3(u64 index);
    Unk_243f958_Entry m_entries[1];
};
PKMN_OFFSET_ASSERT(Unk_243f958, m_entries, 0x8);

// 0x7101482980
u32 Unk_243f958::vf0() {
    return 1;
}

// 0x7101482990
void* Unk_243f958::vf1(u64 index) {
    return m_entries[index].field_0;
}

// 0x71014829a0
void* Unk_243f958::vf2(u64 index) {
    return m_entries[index].field_8;
}

// 0x71014829b0
void Unk_243f958::vf3(u64 index) {
    if (Unk_243f958_Obj* obj = m_entries[index].field_8)
        obj->vf16(m_entries[index].field_10);
}
