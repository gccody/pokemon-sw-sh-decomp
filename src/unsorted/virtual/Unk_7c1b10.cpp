// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23aa3c8 {
public:
    virtual ~Unk_23aa3c8();
    virtual void vf2();
    virtual void vf3();
};

// 0x71007c1b10
void Unk_23aa3c8::vf2() {}

class Unk_23aa3f8 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x71007c1b90
void Unk_23aa3f8::vf0() {}

class Unk_23aa418 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71007c1c10
u32 Unk_23aa418::vf0() {
    return 2;
}

class Unk_23aa448 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual bool vf5(u32 value);
};

// 0x71007c2270
bool Unk_23aa448::vf5(u32 value) {
    return value == 0xe5;
}

class Unk_23aa4b8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71007c2ad0
void Unk_23aa4b8::vf0() {}

// 0x71007c2ae0
void Unk_23aa4b8::vf1() {}

// 0x71007c2c00
void Unk_23aa4b8::vf2() {}

class Unk_23aa4e8 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x71007c2c80
void Unk_23aa4e8::vf0() {}
