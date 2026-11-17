// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_d70060(void* self);

class Unk_23ed510 {
public:
    virtual ~Unk_23ed510();
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

// 0x7100d70030
void Unk_23ed510::vf6() {
    Unk_d70060(this);
}

// 0x7100d6f540
u32 Unk_23ed510::vf7() {
    return 1;
}

class Unk_23ed578 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100d70040
void Unk_23ed578::vf5() {
    Unk_d70060(this);
}

class Unk_23ed5b8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100d70050
void Unk_23ed5b8::vf0() {
    Unk_d70060(this);
}
