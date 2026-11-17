// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_d71fb0(void* self);
void Unk_d72a00(void* self);
void Unk_d73300(void* self);

class Unk_23ed6b0 {
public:
    virtual ~Unk_23ed6b0();
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

// 0x7100d71f40
void Unk_23ed6b0::vf6() {
    Unk_d71fb0(this);
}

// 0x7100d716e0
u32 Unk_23ed6b0::vf7() {
    return 1;
}

// 0x7100d71f20
void Unk_23ed6b0::vf10() {}

class Unk_23ed718 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100d71f70
void Unk_23ed718::vf5() {
    Unk_d71fb0(this);
}

class Unk_23ed758 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100d71f80
void Unk_23ed758::vf0() {
    Unk_d71fb0(this);
}

class Unk_23ed780 {
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

// 0x7100d729d0
void Unk_23ed780::vf6() {
    Unk_d72a00(this);
}

// 0x7100d725e0
u32 Unk_23ed780::vf7() {
    return 1;
}

class Unk_23ed7e8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100d729e0
void Unk_23ed7e8::vf5() {
    Unk_d72a00(this);
}

class Unk_23ed828 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100d729f0
void Unk_23ed828::vf0() {
    Unk_d72a00(this);
}

class Unk_23ed850 {
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

// 0x7100d732d0
void Unk_23ed850::vf6() {
    Unk_d73300(this);
}

// 0x7100d730a0
u32 Unk_23ed850::vf7() {
    return 1;
}

class Unk_23ed8b8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100d732e0
void Unk_23ed8b8::vf5() {
    Unk_d73300(this);
}

class Unk_23ed8f8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100d732f0
void Unk_23ed8f8::vf0() {
    Unk_d73300(this);
}
