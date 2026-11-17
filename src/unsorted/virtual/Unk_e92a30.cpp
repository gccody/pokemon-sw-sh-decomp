// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_e94c10(void* self);

class Unk_23f49e8 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100e92a30
u32 Unk_23f49e8::vf0() {
    return 2;
}

class Unk_23f4a18 {
public:
    virtual ~Unk_23f4a18();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100e92fb0
void Unk_23f4a18::vf2() {}

class Unk_23f4a48 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x7100e93030
void Unk_23f4a48::vf0() {}

class Unk_23f4a68 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100e93580
void Unk_23f4a68::vf2() {}

class Unk_23f4a98 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x7100e93600
void Unk_23f4a98::vf0() {}

class Unk_23f4ad8 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100e93bc0
u32 Unk_23f4ad8::vf0() {
    return 7;
}

class Unk_23f4b28 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100e94930
u32 Unk_23f4b28::vf0() {
    return 6;
}

class Unk_23f4b58 {
public:
    virtual ~Unk_23f4b58();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
};

// 0x7100e94b90
void Unk_23f4b58::vf6() {
    Unk_e94c10(this);
}

class Unk_23f4ba8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100e94bd0
void Unk_23f4ba8::vf5() {
    Unk_e94c10(this);
}

class Unk_23f4be8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100e94be0
void Unk_23f4be8::vf0() {
    Unk_e94c10(this);
}
