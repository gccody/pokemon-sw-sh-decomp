// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23a7b38 {
public:
    virtual ~Unk_23a7b38();
};

// 0x71007816d0, 0x71007816e0
Unk_23a7b38::~Unk_23a7b38() {}

class Unk_23a7b58 {
public:
    virtual ~Unk_23a7b58();
};

// 0x7100782980, 0x7100782990
Unk_23a7b58::~Unk_23a7b58() {}

class Unk_23a7b78 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual u32 vf5();
};

// 0x7100782ea0
void Unk_23a7b78::vf0() {}

// 0x7100782ec0
void Unk_23a7b78::vf1() {}

// 0x7100783bc0
u32 Unk_23a7b78::vf5() {
    return 0;
}

class Unk_23a7bb8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100782eb0
void Unk_23a7bb8::vf0() {}

// 0x7100782ed0
void Unk_23a7bb8::vf1() {}

class Unk_23a7cf0 {
public:
    virtual ~Unk_23a7cf0();
};

// 0x7100788b30, 0x7100788b40
Unk_23a7cf0::~Unk_23a7cf0() {}

class Unk_23a7d10 {
public:
    virtual ~Unk_23a7d10();
    virtual void vf2();
    virtual u32 vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
};

// 0x710078b020, 0x710078b030
Unk_23a7d10::~Unk_23a7d10() {}

// 0x710078b5d0
u32 Unk_23a7d10::vf3() {
    return 1;
}
