// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_15146d0(void* self);
void Unk_1516200(void* self);
void Unk_1516c70(void* self);
void Unk_1517590(void* self);
void Unk_1517e60(void* self);
void Unk_15185f0(void* self);
void Unk_151b530(void* self);

class Unk_24473b0 {
public:
    virtual ~Unk_24473b0();
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

// 0x7101514660
void Unk_24473b0::vf6() {
    Unk_15146d0(this);
}

// 0x7101514640
void Unk_24473b0::vf9() {}

class Unk_2447418 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101514690
void Unk_2447418::vf5() {
    Unk_15146d0(this);
}

class Unk_2447458 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71015146a0
void Unk_2447458::vf0() {
    Unk_15146d0(this);
}

class Unk_2447498 {
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

// 0x7101516010
void Unk_2447498::vf6() {
    Unk_1516200(this);
}

class Unk_2447530 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101516100
void Unk_2447530::vf5() {
    Unk_1516200(this);
}

class Unk_2447570 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101516110
void Unk_2447570::vf0() {
    Unk_1516200(this);
}

class Unk_24475f8 {
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

// 0x7101516ac0
void Unk_24475f8::vf6() {
    Unk_1516c70(this);
}

// 0x71015169f0
void Unk_24475f8::vf9() {}

class Unk_2447660 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101516b90
void Unk_2447660::vf5() {
    Unk_1516c70(this);
}

class Unk_24476a0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101516ba0
void Unk_24476a0::vf0() {
    Unk_1516c70(this);
}

class Unk_24476c8 {
public:
    virtual ~Unk_24476c8();
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

// 0x7101517520
void Unk_24476c8::vf6() {
    Unk_1517590(this);
}

// 0x7101517500
void Unk_24476c8::vf9() {}

class Unk_2447730 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101517550
void Unk_2447730::vf5() {
    Unk_1517590(this);
}

class Unk_2447770 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101517560
void Unk_2447770::vf0() {
    Unk_1517590(this);
}

class Unk_2447798 {
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

// 0x7101517cb0
void Unk_2447798::vf6() {
    Unk_1517e60(this);
}

// 0x7101517be0
void Unk_2447798::vf9() {}

class Unk_2447800 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101517d80
void Unk_2447800::vf5() {
    Unk_1517e60(this);
}

class Unk_2447840 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101517d90
void Unk_2447840::vf0() {
    Unk_1517e60(this);
}

class Unk_2447868 {
public:
    virtual ~Unk_2447868();
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

// 0x7101518580
void Unk_2447868::vf6() {
    Unk_15185f0(this);
}

class Unk_24478d0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71015185b0
void Unk_24478d0::vf5() {
    Unk_15185f0(this);
}

class Unk_2447910 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71015185c0
void Unk_2447910::vf0() {
    Unk_15185f0(this);
}

class Unk_24479b8 {
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

// 0x710151b500
void Unk_24479b8::vf6() {
    Unk_151b530(this);
}

// 0x710151ad40
u32 Unk_24479b8::vf7() {
    return 1;
}

// 0x710151ad50
void Unk_24479b8::vf8() {}

class Unk_2447a20 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710151b510
void Unk_2447a20::vf5() {
    Unk_151b530(this);
}

class Unk_2447a60 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710151b520
void Unk_2447a60::vf0() {
    Unk_151b530(this);
}

class Unk_2447a88 {
public:
    virtual ~Unk_2447a88();
    virtual void vf2();
    virtual u64 vf3();
    virtual void vf4();
    virtual void vf5();
    u8 _8[0xd0];
    u64 field_d8;
};
PKMN_OFFSET_ASSERT(Unk_2447a88, field_d8, 0xd8);

// 0x710151bc50
u64 Unk_2447a88::vf3() {
    return field_d8;
}

class Unk_2447ac8 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x710151bde0
u32 Unk_2447ac8::vf0() {
    return 5;
}
