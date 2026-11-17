// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_102f5b0(void* self);

class Unk_2409648 {
public:
    virtual ~Unk_2409648();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6() = 0;
    virtual void vf7() = 0;
    virtual void vf8() = 0;
};

// 0x710102f530
void Unk_2409648::vf5() {
    Unk_102f5b0(this);
}

class Unk_24096a0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710102f540
void Unk_24096a0::vf0() {
    Unk_102f5b0(this);
}
