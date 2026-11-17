// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_10fc510(u64, u32, u32);

// Globals other TUs define, named after their addresses.
extern u64 Unk_27e4f70;

class Unk_2418218 {
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
};

// 0x7101100500
void Unk_2418218::vf9() {
    if (Unk_27e4f70 != 0) {
        Unk_10fc510(Unk_27e4f70, 0x32, 0x32);
    }
}
