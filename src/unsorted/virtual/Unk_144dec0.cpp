// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_144ea60(void* self);
void Unk_144f040(void* self);

class Unk_243c740 {
public:
    virtual ~Unk_243c740();
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

// 0x710144e9f0
void Unk_243c740::vf6() {
    Unk_144ea60(this);
}

// 0x710144dec0
void Unk_243c740::vf9() {}

class Unk_243c7a8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710144ea20
void Unk_243c7a8::vf5() {
    Unk_144ea60(this);
}

class Unk_243c7e8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710144ea30
void Unk_243c7e8::vf0() {
    Unk_144ea60(this);
}

class Unk_243c828 {
public:
    virtual ~Unk_243c828();
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

// 0x710144efd0
void Unk_243c828::vf6() {
    Unk_144f040(this);
}

// 0x710144efb0
void Unk_243c828::vf9() {}

class Unk_243c890 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710144f000
void Unk_243c890::vf5() {
    Unk_144f040(this);
}

class Unk_243c8d0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710144f010
void Unk_243c8d0::vf0() {
    Unk_144f040(this);
}

class Unk_243c8f8 {
public:
    virtual ~Unk_243c8f8();
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

// 0x710144f650
u32 Unk_243c8f8::vf7() {
    return 1;
}

// 0x7101451c30
void Unk_243c8f8::vf10() {}
