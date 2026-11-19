// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "gflib3/Unk_239a418.h"

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_fddd80(void* self);
void Unk_fdde60(void* self);

// Lifted through their own placeholder structs (cast_member).
struct Unk_fddd60 {
    u8 _0[0x88];
    Unk_239a418* field_88;
};
PKMN_OFFSET_ASSERT(Unk_fddd60, field_88, 0x88);

class Unk_2404e78 {
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
};

// 0x7100fddd60
void Unk_2404e78::vf9() {
    Unk_fddd60* self = reinterpret_cast<Unk_fddd60*>(this);
    Unk_239a418* v0 = self->field_88;
    self->field_88 = nullptr;
    if (v0 != nullptr) {
        static_cast<Unk_239a458*>(v0)->vf5();
    }
}

// 0x7100fdde40
void Unk_2404e78::vf11() {
    Unk_fddd80(this);
}

// 0x7100fddf20
void Unk_2404e78::vf12() {
    Unk_fdde60(this);
}
