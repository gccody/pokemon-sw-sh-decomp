// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_15b6e10(void* self);

class Unk_2410040 {
public:
    virtual ~Unk_2410040();
    virtual void vf2();
    virtual u32 vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
};

// 0x710109efa0
u32 Unk_2410040::vf3() {
    return 1;
}

class Unk_24100b0 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x710109f5c0
void Unk_24100b0::vf1() {
    Unk_15b6e10(this);
}
