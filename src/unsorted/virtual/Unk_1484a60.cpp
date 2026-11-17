// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_1484ad0(void* self);
void Unk_1485050(void* self);

class Unk_243fb80 {
public:
    virtual ~Unk_243fb80();
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

// 0x7101484a60
void Unk_243fb80::vf6() {
    Unk_1484ad0(this);
}

class Unk_243fbe8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101484a90
void Unk_243fbe8::vf5() {
    Unk_1484ad0(this);
}

class Unk_243fc28 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101484aa0
void Unk_243fc28::vf0() {
    Unk_1484ad0(this);
}

class Unk_243fc50 {
public:
    virtual ~Unk_243fc50();
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

// 0x7101484fe0
void Unk_243fc50::vf6() {
    Unk_1485050(this);
}

// 0x7101484fc0
void Unk_243fc50::vf9() {}

class Unk_243fcb8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101485010
void Unk_243fcb8::vf5() {
    Unk_1485050(this);
}

class Unk_243fcf8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101485020
void Unk_243fcf8::vf0() {
    Unk_1485050(this);
}
