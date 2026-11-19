// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

extern u32 Unk_24e7970 __attribute__((visibility("hidden")));
struct Unk_4b99a0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71004b99a0
void Unk_4b99a0_call(Unk_4b99a0* self) {
    self->vf3();
    Unk_24e7970 = Unk_24e7970 + 1;
}
