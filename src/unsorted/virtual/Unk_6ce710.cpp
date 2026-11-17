// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_6ce780(void* self);

class Unk_23a45c8 {
public:
    virtual ~Unk_23a45c8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7() = 0;
    virtual void vf8() = 0;
    virtual void vf9() = 0;
};

// 0x71006ce710
void Unk_23a45c8::vf6() {
    Unk_6ce780(this);
}

class Unk_23a4628 {
public:
    virtual ~Unk_23a4628();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71006ce740
void Unk_23a4628::vf5() {
    Unk_6ce780(this);
}

class Unk_23a4668 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71006ce750
void Unk_23a4668::vf0() {
    Unk_6ce780(this);
}
