// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_7a8db0(void* self);
void Unk_7aaf50(void* self);

class Unk_23a8f48 {
public:
    virtual ~Unk_23a8f48();
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

// 0x71007a8d40
void Unk_23a8f48::vf6() {
    Unk_7a8db0(this);
}

class Unk_23a8fe0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71007a8d70
void Unk_23a8fe0::vf5() {
    Unk_7a8db0(this);
}

class Unk_23a9020 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71007a8d80
void Unk_23a9020::vf0() {
    Unk_7a8db0(this);
}

class Unk_23a9048 {
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

// 0x71007aada0
void Unk_23a9048::vf6() {
    Unk_7aaf50(this);
}

class Unk_23a90e0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71007aae70
void Unk_23a90e0::vf5() {
    Unk_7aaf50(this);
}

class Unk_23a9120 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71007aae80
void Unk_23a9120::vf0() {
    Unk_7aaf50(this);
}
