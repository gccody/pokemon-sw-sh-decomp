// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_236d0b8 {
public:
    virtual ~Unk_236d0b8();
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
    virtual void vf14(bool value);
    virtual void vf15();
    virtual void* vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    u8 _8[0x10];
    bool field_18;
    u8 _19[0x77];
    bool field_90;
};
PKMN_OFFSET_ASSERT(Unk_236d0b8, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_236d0b8, field_90, 0x90);

// 0x7100002550
void Unk_236d0b8::vf14(bool value) {
    field_18 = value;
    field_90 = value;
}
