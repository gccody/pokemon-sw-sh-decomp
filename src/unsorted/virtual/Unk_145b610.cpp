// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_1457c40(void* self);
void Unk_145ef80(void* self);
void Unk_145f440(void* self);
void Unk_145f930(void* self);
void Unk_145fdd0(void* self);

class Unk_243ce10 {
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
PKMN_OFFSET_ASSERT(Unk_243ce10, field_e8, 0xe8);

// 0x710145b610
u32 Unk_243ce10::vf10() {
    return field_e8;
}

class Unk_243cee0 {
public:
    virtual ~Unk_243cee0();
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

// 0x710145ef10
void Unk_243cee0::vf6() {
    Unk_145ef80(this);
}

class Unk_243cf78 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710145ef40
void Unk_243cf78::vf5() {
    Unk_145ef80(this);
}

class Unk_243cfb8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710145ef50
void Unk_243cfb8::vf0() {
    Unk_145ef80(this);
}

class Unk_243cff8 {
public:
    virtual ~Unk_243cff8();
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

// 0x710145f3d0
void Unk_243cff8::vf6() {
    Unk_145f440(this);
}

class Unk_243d090 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710145f400
void Unk_243d090::vf5() {
    Unk_145f440(this);
}

class Unk_243d0d0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710145f410
void Unk_243d0d0::vf0() {
    Unk_145f440(this);
}

class Unk_243d0f8 {
public:
    virtual ~Unk_243d0f8();
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

// 0x710145f8c0
void Unk_243d0f8::vf6() {
    Unk_145f930(this);
}

class Unk_243d160 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710145f8f0
void Unk_243d160::vf5() {
    Unk_145f930(this);
}

class Unk_243d1a0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710145f900
void Unk_243d1a0::vf0() {
    Unk_145f930(this);
}

class Unk_243d1c8 {
public:
    virtual ~Unk_243d1c8();
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

// 0x710145fd60
void Unk_243d1c8::vf6() {
    Unk_145fdd0(this);
}

class Unk_243d260 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710145fd90
void Unk_243d260::vf5() {
    Unk_145fdd0(this);
}

class Unk_243d2a0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710145fda0
void Unk_243d2a0::vf0() {
    Unk_145fdd0(this);
}

class Unk_243d2c8 {
public:
    virtual ~Unk_243d2c8();
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

// 0x7101460610
void Unk_243d2c8::vf6() {
    Unk_1457c40(this);
}

class Unk_243d330 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101460640
void Unk_243d330::vf5() {
    Unk_1457c40(this);
}

class Unk_243d370 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101460650
void Unk_243d370::vf0() {
    Unk_1457c40(this);
}
