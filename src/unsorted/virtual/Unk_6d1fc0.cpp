// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_6d2140(void*, u64, u64, u32);
void Unk_6d26a0(void*, u64, u64, u32);
void Unk_6d2c10(void*, u64, u64, u32);

class Unk_23a4690 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2(u64 value, u64 arg2);
    virtual void vf3(u64 value, u64 arg2);
    virtual void vf4(u64 value, u64 arg2);
    virtual void vf5();
};

// 0x71006d1fc0
void Unk_23a4690::vf2(u64 value, u64 arg2) {
    Unk_6d2140(this, value, arg2, 1);
}

// 0x71006d1fd0
void Unk_23a4690::vf3(u64 value, u64 arg2) {
    Unk_6d26a0(this, value, arg2, 1);
}

// 0x71006d1fe0
void Unk_23a4690::vf4(u64 value, u64 arg2) {
    Unk_6d2c10(this, value, arg2, 1);
}
