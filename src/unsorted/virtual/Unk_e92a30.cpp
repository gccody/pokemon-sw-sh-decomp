// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

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
