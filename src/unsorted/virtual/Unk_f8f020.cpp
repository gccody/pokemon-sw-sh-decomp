// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_f89c80(void*, u32);

class Unk_24016b8 {
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
    virtual void vf17();
    virtual u32 vf18();
};

// 0x7100f8f020
void Unk_24016b8::vf14() {
    Unk_f89c80(this, 2);
}

// 0x7100f8f030
void Unk_24016b8::vf15() {
    Unk_f89c80(this, 3);
}

// 0x7100f8f940
u32 Unk_24016b8::vf18() {
    return 0;
}
