// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_239a0f8 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71005dffe0
u32 Unk_239a0f8::vf0() {
    return 2;
}

class Unk_239a128 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual u32 vf3();
};

// 0x71005e0070
u32 Unk_239a128::vf3() {
    return 2;
}

class Unk_239a158 {
public:
    virtual ~Unk_239a158();
    virtual void vf2();
    virtual void vf3();
};

// 0x71005e0610
void Unk_239a158::vf2() {}

class Unk_239a188 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x71005e0690
void Unk_239a188::vf0() {}

class Unk_239a1a8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71005e08f0
void Unk_239a1a8::vf2() {}

class Unk_239a1d8 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x71005e0970
void Unk_239a1d8::vf0() {}

class Unk_239a4c0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

// 0x71005e3630
void Unk_239a4c0::vf1() {}

class Unk_239a4f8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71005e3690
void Unk_239a4f8::vf0() {}

// 0x71005e36a0
void Unk_239a4f8::vf1() {}
